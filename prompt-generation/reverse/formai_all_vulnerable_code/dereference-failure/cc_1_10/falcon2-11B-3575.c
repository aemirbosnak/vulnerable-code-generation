//Falcon2-11B DATASET v1.0 Category: Intrusion detection system ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <netdb.h>
#include <netinet/tcp.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>

#define BUF_SIZE 1024
#define PORT 8080
#define MAX_CLIENTS 10

int main(int argc, char *argv[]) {
    struct sockaddr_in server_addr, client_addr;
    int sockfd, connfd, n;
    char buffer[BUF_SIZE];
    struct timeval timeout;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid port number: %s\n", argv[1]);
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(sockfd = socket(AF_INET, SOCK_STREAM, 0), (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;
        connfd = accept(sockfd, (struct sockaddr *)&client_addr, &n);
        if (connfd < 0) {
            perror("accept");
            exit(1);
        }

        if (setsockopt(connfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(struct timeval)) < 0) {
            perror("setsockopt");
            exit(1);
        }

        printf("New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        memset(buffer, 0, BUF_SIZE);
        n = read(connfd, buffer, BUF_SIZE);
        printf("Received data: %s\n", buffer);
        if (n < 0) {
            perror("read");
            exit(1);
        }

        if (write(connfd, "Welcome to our system\n", strlen("Welcome to our system\n")) < 0) {
            perror("write");
            exit(1);
        }
        close(connfd);
    }
    return 0;
}