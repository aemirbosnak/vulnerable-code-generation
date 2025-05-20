//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

void error_handling(char *message) {
    perror(message);
    exit(1);
}

int create_socket(int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error_handling("socket failed");
    }
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error_handling("bind failed");
    }
    if (listen(sockfd, 5) < 0) {
        error_handling("listen failed");
    }
    return sockfd;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <port> <destination>\n", argv[0]);
        return 1;
    }
    int port = atoi(argv[1]);
    char *dest = argv[2];
    int sockfd = create_socket(port);
    while (1) {
        int newsockfd = accept(sockfd, NULL, NULL);
        if (newsockfd < 0) {
            error_handling("accept failed");
        }
        char buffer[BUF_SIZE];
        memset(buffer, 0, BUF_SIZE);
        while (1) {
            int bytes_received = recv(newsockfd, buffer, BUF_SIZE, 0);
            if (bytes_received <= 0) {
                break;
            }
            send(newsockfd, buffer, strlen(buffer), 0);
        }
        close(newsockfd);
    }
    return 0;
}