//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buf[MAX_BUF_SIZE];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: gethostbyname() failed\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: socket() failed\n");
        exit(1);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *) &serv_addr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error: connect() failed\n");
        exit(1);
    }

    while (1) {
        printf("> ");
        fgets(buf, MAX_BUF_SIZE, stdin);
        if (strcmp(buf, "quit\n") == 0) {
            break;
        }

        if (send(sockfd, buf, strlen(buf), 0) < 0) {
            fprintf(stderr, "Error: send() failed\n");
            exit(1);
        }

        if (recv(sockfd, buf, MAX_BUF_SIZE, 0) < 0) {
            fprintf(stderr, "Error: recv() failed\n");
            exit(1);
        }

        printf("%s", buf);
    }

    close(sockfd);
    return 0;
}