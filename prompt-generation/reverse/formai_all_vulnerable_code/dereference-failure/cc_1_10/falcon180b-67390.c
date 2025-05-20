//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define MAX 100
#define SA struct sockaddr
#define INADDR_ANY INADDR_ANY

void die(const char *s) {
    perror(s);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    int sockfd, newsockfd, portno, clilen, i, valread, sd;
    struct sockaddr_in serv_addr, cli_addr;
    int opt = TRUE;
    char buffer[1024];
    fd_set readfds;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <IP address> <port number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0)
        die("socket failed");

    bzero(&serv_addr, sizeof(serv_addr));

    portno = atoi(argv[2]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (SA *)&serv_addr, sizeof(serv_addr)) < 0)
        die("connect failed");

    printf("Connected to %s:%d\n", argv[1], portno);

    do {
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);
        clilen = sizeof(cli_addr);

        if (select(sockfd + 1, &readfds, NULL, NULL, NULL) == -1)
            die("select failed");

        if (FD_ISSET(sockfd, &readfds)) {
            if ((valread = read(sockfd, buffer, sizeof(buffer))) == 0) {
                fprintf(stderr, "Connection closed by server\n");
                exit(EXIT_FAILURE);
            }
            printf("Received: %s", buffer);
        }

    } while (TRUE);

    close(sockfd);

    return 0;
}