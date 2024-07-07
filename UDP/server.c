#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in server = {.sin_family = AF_INET, .sin_addr.s_addr = INADDR_ANY, .sin_port = htons(atoi(argv[1]))};
    bind(sockfd, (struct sockaddr *)&server, sizeof(server));

    char buffer[100];
    socklen_t server_len = sizeof(server);
    printf("Server waiting...\n");
    recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&server, &server_len);
    printf("Got a datagram: %s\n", buffer);

    return 0;
}
