//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;
    int addrlen;
    int n;
    char buffer[MAX_BUFFER_SIZE];
    char* message;

    if (argc < 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        fprintf(stderr, "socket creation error\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "bind failed\n");
        exit(1);
    }

    listen(sockfd, 3);

    while (1) {
        addrlen = sizeof(cli_addr);

        cli_addr.sin_family = AF_INET;
        cli_addr.sin_addr.s_addr = 0;
        cli_addr.sin_port = htons(0);

        if ((n = accept(sockfd, (struct sockaddr *) &cli_addr, &addrlen)) < 0) {
            fprintf(stderr, "accept failed\n");
            exit(1);
        }

        message = (char *)malloc(MAX_BUFFER_SIZE * sizeof(char));

        bzero(message, MAX_BUFFER_SIZE);

        n = read(n, message, MAX_BUFFER_SIZE);

        printf("received: %s\n", message);

        send(n, message, n, 0);

        free(message);

        close(n);
    }

    close(sockfd);

    return 0;
}