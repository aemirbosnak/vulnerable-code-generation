//FormAI DATASET v1.0 Category: Port Scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdbool.h>

#define MAX_PORT_NUMBER 65535
#define BUFFER_SIZE 4096

void scan_port(char *host, int port) {
    int sockfd;
    struct sockaddr_in addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(host);

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        printf("Port %d: Open\n", port);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    char host[BUFFER_SIZE];
    int start_port, end_port;

    if (argc < 4) {
        fprintf(stderr, "Usage: %s [host] [start_port] [end_port]\n", argv[0]);
        exit(1);
    }

    strcpy(host, argv[1]);
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    for (int port = start_port; port <= end_port; port++) {
        scan_port(host, port);
    }

    return 0;
}