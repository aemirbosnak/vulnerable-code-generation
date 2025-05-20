//FormAI DATASET v1.0 Category: Port Scanner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535

int main(int argc, char *argv[]) {
    char *ip;
    int start_port, end_port;
    struct sockaddr_in target;
    int sockfd, status, i;

    if (argc < 4) {
        printf("Usage: %s ip_address start_port end_port\n", argv[0]);
        exit(1);
    }

    ip = argv[1];
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > MAX_PORTS || start_port > end_port) {
        printf("Invalid port range.\n");
        exit(1);
    }

    memset(&target, 0, sizeof target);
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ip);

    for (i = start_port; i <= end_port; i++) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            perror("socket() error");
            exit(1);
        }

        target.sin_port = htons(i);

        status = connect(sockfd, (struct sockaddr *)&target, sizeof target);
        if (status == 0) {
            printf("Port %d is open.\n", i);
        }

        close(sockfd);
    }

    return 0;
}