//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_PORTS 65535
#define BUF_SIZE 1024

void scan_ports(char *hostname, int start_port, int end_port) {
    int sock, max_fd, client_len;
    struct sockaddr_in server, client;
    int opt = 1;
    char buffer[BUF_SIZE];
    int port;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    if (inet_pton(AF_INET, hostname, &server.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address/name\n");
        exit(EXIT_FAILURE);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(start_port);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    for (port = start_port; port <= end_port; port++) {
        if (port == start_port) {
            if (inet_ntop(AF_INET, &server.sin_addr, buffer, BUF_SIZE) == NULL) {
                fprintf(stderr, "inet_ntop() failed\n");
                exit(EXIT_FAILURE);
            }
            printf("Scanning %s:%d - %d\n", buffer, start_port, end_port);
        }

        client_len = sizeof(client);
        if (getsockname(sock, (struct sockaddr *)&client, &client_len) < 0) {
            perror("getsockname");
            exit(EXIT_FAILURE);
        }

        client.sin_port = htons(port);

        if (connect(sock, (struct sockaddr *)&client, sizeof(client)) == 0) {
            printf("%d - Open\n", port);
        } else {
            if (errno!= ECONNREFUSED) {
                perror("connect");
            }
        }
    }

    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <hostname> <start_port> <end_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    scan_ports(argv[1], atoi(argv[2]), atoi(argv[3]));

    return 0;
}