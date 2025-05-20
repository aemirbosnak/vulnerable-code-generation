//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int http_client(char *host, char *page) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[4096];

    portno = 80;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR opening socket\n");
        return 1;
    }

    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;

    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);

    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "ERROR connecting\n");
        return 1;
    }

    char *message = (char *) malloc(sizeof(char) * (strlen(host) + strlen(page) + 22));
    sprintf(message, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", page, host);

    if (send(sockfd, message, strlen(message), 0) < 0) {
        fprintf(stderr, "ERROR sending message\n");
        return 1;
    }

    bzero(buffer, sizeof(buffer));

    while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        printf("%s", buffer);
        bzero(buffer, sizeof(buffer));
    }

    if (n < 0) {
        fprintf(stderr, "ERROR receiving message\n");
        return 1;
    }

    free(message);
    close(sockfd);
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "usage %s hostname page\n", argv[0]);
        return 1;
    }

    return http_client(argv[1], argv[2]);
}