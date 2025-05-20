//Falcon2-11B DATASET v1.0 Category: Networking ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    char *hostname = "example.com"; // replace with desired hostname

    if (argc < 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);

    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0) {
        fprintf(stderr, "inet_pton failed\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("Connected to %s on port %d\n", hostname, portno);
    for (;;) {
        bzero(buffer, BUFFER_SIZE);
        n = read(sockfd, buffer, BUFFER_SIZE);
        if (n < 0) {
            perror("read failed");
            exit(1);
        }
        buffer[n] = '\0';
        printf("Received: %s\n", buffer);
        bzero(buffer, BUFFER_SIZE);
        n = write(sockfd, buffer, BUFFER_SIZE);
        if (n < 0) {
            perror("write failed");
            exit(1);
        }
        printf("Sent: %s\n", buffer);
    }

    return 0;
}