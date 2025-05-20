//Falcon-180B DATASET v1.0 Category: Networking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX 100

int main() {
    int sockfd, newsockfd, portno, clilen, sd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        perror("no such host");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, &serv_addr.sin_addr.s_addr, server->h_length);
    portno = htons(8080);
    serv_addr.sin_port = portno;

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    while (1) {
        bzero(buffer, MAX);
        fgets(buffer, MAX, stdin);
        send(sockfd, buffer, strlen(buffer), 0);

        bzero(buffer, MAX);
        recv(sockfd, buffer, MAX, 0);
        printf("Received: %s", buffer);
    }

    close(sockfd);
    return 0;
}