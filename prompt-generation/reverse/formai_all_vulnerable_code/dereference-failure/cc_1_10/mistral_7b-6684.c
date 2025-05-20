//MISTRAL-7B DATASET v1.0 Category: Network Ping Test ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_BUFFER 1024
#define TIMEOUT 5000

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname/ip> <port>\n", argv[0]);
        exit(1);
    }

    const char *host = argv[1];
    int port = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) die("socket");

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address/name %s\n", host);
        close(sockfd);
        exit(1);
    }

    char buffer[MAX_BUFFER];
    int sent = sendto(sockfd, "PING", 4, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (sent < 0) {
        perror("sendto");
        close(sockfd);
        exit(1);
    }

    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(sockfd, &read_fds);

    struct timeval timeout;
    timeout.tv_sec = TIMEOUT / 1000;
    timeout.tv_usec = (TIMEOUT % 1000) * 1000;

    int result = select(sockfd + 1, &read_fds, NULL, NULL, &timeout);

    if (result < 0) {
        perror("select");
        close(sockfd);
        exit(1);
    }

    if (FD_ISSET(sockfd, &read_fds)) {
        int received = recvfrom(sockfd, buffer, MAX_BUFFER, 0, NULL, NULL);
        if (received > 0) {
            printf("Reply received: %s\n", buffer);
        } else {
            fprintf(stderr, "No reply\n");
        }
    } else {
        fprintf(stderr, "Timeout\n");
    }

    close(sockfd);
    return 0;
}