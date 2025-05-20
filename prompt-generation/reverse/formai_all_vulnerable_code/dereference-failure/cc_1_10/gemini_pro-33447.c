//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: minimalist
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFLEN 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFLEN];

    if (argc < 3) {
        fprintf(stderr, "usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        error("gethostbyname");
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("socket");
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("connect");
    }

    printf("POP3 session started with %s\n", argv[1]);

    while (1) {
        bzero(buffer, BUFLEN);
        n = read(sockfd, buffer, BUFLEN);
        if (n < 0) {
            error("read");
        }

        printf("%s", buffer);

        bzero(buffer, BUFLEN);
        fgets(buffer, BUFLEN, stdin);

        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            error("write");
        }

        if (strcmp(buffer, "QUIT\r\n") == 0) {
            break;
        }
    }

    close(sockfd);

    return 0;
}