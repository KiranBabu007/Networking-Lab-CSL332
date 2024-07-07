#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080
#define MAX 80

void chat(int connfd) {
    char buff[MAX];
    while (1) {
    	memset(buff,0,sizeof(buff));
        read(connfd, buff, MAX);
        printf("Client: %s", buff);
        if (strncmp(buff, "exit", 4) == 0) break;
        
        printf("Server: ");
	memset(buff,0,sizeof(buff));
        fgets(buff, MAX, stdin);
        write(connfd, buff, strlen(buff));
        if (strncmp(buff, "exit", 4) == 0) break;
    }
}

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in servaddr = {.sin_family = AF_INET, .sin_addr.s_addr = htonl(INADDR_ANY), .sin_port = htons(PORT)};
    bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    listen(sockfd, 5);
    chat(accept(sockfd,NULL,NULL));
    close(sockfd);
    return 0;
}
