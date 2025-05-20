//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int sockfd, connfd, n;
    struct sockaddr_in serverAddr, clientAddr;
    struct hostent *serverHost;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <server-name>\n", argv[0]);
        exit(1);
    }

    serverHost = gethostbyname(argv[1]);
    if (serverHost == NULL) {
        fprintf(stderr, "ERROR: No such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    memcpy((char *)&serverAddr.sin_addr.s_addr, (char *)serverHost->h_addr, serverHost->h_length);

    if (bind(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        connfd = accept(sockfd, (struct sockaddr *)&clientAddr, (socklen_t *)&n);
        if (connfd < 0) {
            perror("ERROR on accept");
            continue;
        }

        printf("Connected by %s\n", inet_ntoa(clientAddr.sin_addr));

        char buffer[1024];
        while ((n = recv(connfd, buffer, sizeof(buffer), 0)) > 0) {
            send(connfd, buffer, n, 0);
        }

        close(connfd);
    }

    close(sockfd);
    return 0;
}