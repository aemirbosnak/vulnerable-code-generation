//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX 65535
#define TRUE 1
#define FALSE 0
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, port, opt = TRUE;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP Address> <Port Range>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid IP Address\n");
        exit(EXIT_FAILURE);
    }

    port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        fprintf(stderr, "Socket creation failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    while (port <= MAX) {
        if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            fprintf(stdout, "Port %d is open.\n", port);
        } else {
            fprintf(stdout, "Port %d is closed.\n", port);
        }

        port++;
    }

    close(sockfd);

    return 0;
}