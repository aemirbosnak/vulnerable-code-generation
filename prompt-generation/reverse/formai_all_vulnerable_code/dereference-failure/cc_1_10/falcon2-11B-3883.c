//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_BUF 1024

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR: No such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(12345);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to localhost on port 12345\n");
    for (;;) {
        n = read(sockfd, (char *) NULL, MAX_BUF);
        if (n < 0) {
            perror("read failed");
            exit(EXIT_FAILURE);
        }
        printf("Received %d bytes of data from localhost on port 12345\n", n);

        n = write(sockfd, "Hello, localhost on port 12345!", 31);
        if (n < 0) {
            perror("write failed");
            exit(EXIT_FAILURE);
        }
        printf("Sent Hello, localhost on port 12345!\n");
    }

    close(sockfd);
    return 0;
}