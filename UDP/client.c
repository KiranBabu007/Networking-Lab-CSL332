#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in client= {.sin_family = AF_INET,.sin_addr.s_addr=INADDR_ANY,.sin_port = htons(atoi(argv[1]))};
    char buff[100];
    printf("Enter your message:");
    fgets(buff,100,stdin);
    
    sendto(sockfd, buff, 100, 0, (struct sockaddr *)&client, sizeof(client));
    printf("Sent: %s\n", buff);

    return 0;
}
