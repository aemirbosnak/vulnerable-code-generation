//Falcon2-11B DATASET v1.0 Category: Intrusion detection system ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

#define PORT 12345
#define BACKLOG 5

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    int sockfd;
    int len;
    int n;
    struct sockaddr_in serv_addr;
    char buffer[256];
    FILE *fp;

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket: ");
        exit(1);
    }

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket: ");
        exit(1);
    }

    if (listen(sockfd, BACKLOG) < 0) {
        perror("Error listening on socket: ");
        exit(1);
    }

    while (1) {
        len = sizeof(serv_addr);
        sockfd = accept(sockfd, (struct sockaddr *)&serv_addr, &len);
        if (sockfd < 0) {
            perror("Error accepting connection: ");
            exit(1);
        }

        n = read(sockfd, buffer, sizeof(buffer));
        if (n < 0) {
            perror("Error reading from socket: ");
            exit(1);
        }

        printf("Received data: %s\n", buffer);
        close(sockfd);
    }

    fclose(fp);
    return 0;
}