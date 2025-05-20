//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5000
#define BACKLOG 1
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <target>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error opening socket\n");
        exit(EXIT_FAILURE);
    }

    portno = atoi(argv[1]);

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);

    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address\n");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Connection failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s:%d\n", argv[1], portno);

    while (1) {
        n = read(sockfd, buffer, BUFFER_SIZE);
        if (n < 0) {
            fprintf(stderr, "Read error\n");
            exit(EXIT_FAILURE);
        } else if (n == 0) {
            break;
        } else {
            printf("Received: %s\n", buffer);
        }
    }

    close(sockfd);
    return 0;
}