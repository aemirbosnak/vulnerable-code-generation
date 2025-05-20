//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <server_ip> <file_path>\n", argv[0]);
        exit(1);
    }

    struct sockaddr_in server;
    int sockfd, n;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("connect");
        exit(1);
    }

    if (send(sockfd, argv[2], strlen(argv[2]), 0) < 0) {
        perror("send");
        exit(1);
    }

    while (1) {
        n = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (n < 0) {
            perror("recv");
            exit(1);
        }
        if (n == 0) {
            break;
        }
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}