//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_LINE 1024
#define PORT 21

void ftp_client(char *server, int port);

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <server> <port>\n", argv[0]);
        exit(1);
    }

    char *server = argv[1];
    int port = atoi(argv[2]);

    ftp_client(server, port);

    return 0;
}

void ftp_client(char *server, int port) {
    int sockfd, newsockfd;
    struct addrinfo hints, *servinfo, *p;
    char s[INET6_ADDRSTRLEN];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(server, NULL, &hints, &servinfo)!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(EAI_SYSTEM));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);

        if (sockfd == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen)!= -1) {
            break;
        }

        close(sockfd);
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect\n");
        exit(1);
    }

    printf("Connected to %s\n", server);

    while (1) {
        char buffer[MAX_LINE];
        memset(buffer, 0, sizeof(buffer));

        printf("> ");
        fgets(buffer, MAX_LINE, stdin);

        send(sockfd, buffer, strlen(buffer), 0);

        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(sockfd, buffer, MAX_LINE, 0);

        if (bytes_received <= 0) {
            break;
        }

        printf("%s", buffer);
    }

    close(sockfd);
}