#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080
#define MAX 80

void chat(int sockfd) {
    char buff[MAX];
    while (1) {
        printf("Client: ");
	memset(buff,0,sizeof(buff));
        fgets(buff, MAX, stdin);
        write(sockfd, buff, strlen(buff));
        if (strncmp(buff, "exit", 4) == 0) break;
	memset(buff,0,sizeof(buff));
        read(sockfd, buff, MAX);
        printf("Server: %s", buff);
        if (strncmp(buff, "exit", 4) == 0) break;
    }
}

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in servaddr = {.sin_family = AF_INET, .sin_addr.s_addr = inet_addr("127.0.0.1"), .sin_port = htons(PORT)};
    connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    chat(sockfd);
    close(sockfd);
    return 0;
}
