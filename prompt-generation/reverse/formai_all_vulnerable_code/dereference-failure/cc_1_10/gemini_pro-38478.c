//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(hostname);
    server_addr.sin_port = htons(port);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));
    int bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    printf("%s", buffer);

    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "USER username\r\n");
    int bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
    if (bytes_sent == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    memset(buffer, 0, sizeof(buffer));
    bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    printf("%s", buffer);

    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "PASS password\r\n");
    bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
    if (bytes_sent == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    memset(buffer, 0, sizeof(buffer));
    bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    printf("%s", buffer);

    close(sockfd);

    return EXIT_SUCCESS;
}