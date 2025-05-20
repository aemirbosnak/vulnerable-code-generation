//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP port

    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) != 1) {
        fprintf(stderr, "invalid IP address: %s\n", argv[1]);
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    char request[100];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
    ssize_t bytes_sent = send(sockfd, request, strlen(request), 0);
    if (bytes_sent == -1) {
        perror("send");
        exit(1);
    }

    char buffer[1024];
    ssize_t bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytes_received == -1) {
        perror("recv");
        exit(1);
    }

    if (bytes_received == 0) {
        fprintf(stderr, "connection closed by peer\n");
        exit(1);
    }

    int dbm;
    if (sscanf(buffer, "%*s %*s %*s\r\nSignal strength: %d dBm", &dbm) == 1) {
        printf("Wi-Fi signal strength: %d dBm\n", dbm);
    } else {
        printf("Wi-Fi signal strength not found\n");
    }

    close(sockfd);
    return 0;
}