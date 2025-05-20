//Falcon2-11B DATASET v1.0 Category: Networking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serveraddr;
    char message[] = "Hello, world!";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    serveraddr.sin_port = htons(12345);

    if (bind(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 1) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    portno = htons(atoi(getenv("PORT")));
    if (portno <= 0) {
        fprintf(stderr, "Invalid port number\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        sockfd = accept(sockfd, (struct sockaddr *)NULL, NULL);
        if (sockfd < 0) {
            perror("accept");
            continue;
        }

        printf("Connection established\n");

        n = read(sockfd, message, sizeof(message));
        if (n <= 0) {
            perror("read");
            close(sockfd);
            continue;
        }

        printf("Received message: %s\n", message);

        send(sockfd, message, n, 0);
        close(sockfd);

        printf("Connection closed\n");
    }

    close(sockfd);
    return 0;
}