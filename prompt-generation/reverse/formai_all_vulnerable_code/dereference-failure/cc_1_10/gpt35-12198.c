//FormAI DATASET v1.0 Category: Port Scanner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, port, start, end, optval;
    struct sockaddr_in addr;
    optval = 1;

    if (argc != 4) {
        printf("Usage: %s [host] [start port] [end port]\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Set socket options */
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval, sizeof(int)) < 0) {
        perror("setsockopt failed");
        exit(1);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    start = atoi(argv[2]);
    end = atoi(argv[3]);

    int i;
    for (i = start; i <= end; i++) {
        addr.sin_port = htons(i);
        int result = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
        if (result == 0) {
            printf("Port %d is open!\n", i);
        }
    }

    close(sockfd);
    return 0;
}