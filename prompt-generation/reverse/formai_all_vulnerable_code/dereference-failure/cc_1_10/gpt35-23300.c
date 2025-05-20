//FormAI DATASET v1.0 Category: Networking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sock_fd;
    if ((sock_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr, client_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    char buf[MAX_BUF_SIZE];
    while (1) {
        socklen_t len = sizeof(client_addr);
        ssize_t n_bytes = recvfrom(sock_fd, buf, MAX_BUF_SIZE, 0, (struct sockaddr*)&client_addr, &len);
        if (n_bytes < 0) {
            perror("recvfrom");
            exit(EXIT_FAILURE);
        }

        printf("Received message from %s:%d - %s", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), buf);

        if (sendto(sock_fd, buf, strlen(buf), 0, (struct sockaddr*)&client_addr, len) < 0) {
            perror("sendto");
            exit(EXIT_FAILURE);
        }
    }

    close(sock_fd);
    return 0;
}