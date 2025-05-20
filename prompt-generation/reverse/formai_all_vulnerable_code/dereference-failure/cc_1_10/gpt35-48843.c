//FormAI DATASET v1.0 Category: Port Scanner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

// A function to check if a port is open or not
bool is_port_open(const char *ip, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "socket creation failed. Error: %s\n", strerror(errno));
        return false;
    }

    struct sockaddr_in server = {0};
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == 0) {
        close(sockfd);
        return true;
    }

    close(sockfd);
    return false;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s <ip>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip = argv[1];

    // Scan ports and print which ones are open
    printf("Scanning ports for %s...\n", ip);
    for (int port = 1; port <= 65535; port++) {
        if (is_port_open(ip, port)) {
            printf("Port %d is open\n", port);
        }
    }

    printf("Port scan complete\n");

    return 0;
}