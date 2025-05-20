//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define DEFAULT_PORT 80
#define MAX_HTTP_HEADER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char *host, *path;
    char buffer[MAX_HTTP_HEADER_SIZE];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s host path\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    path = argv[2];

    portno = DEFAULT_PORT;
    server = gethostbyname(host);
    if (server == NULL) {
        error("Error: no such host");
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error: opening socket");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Error: connecting to host");
    }

    sprintf(buffer, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);

    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("Error: writing to socket");
    }

    memset(buffer, 0, MAX_HTTP_HEADER_SIZE);

    while ((n = read(sockfd, buffer, MAX_HTTP_HEADER_SIZE - 1)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    if (n < 0) {
        error("Error: reading from socket");
    }

    close(sockfd);

    return 0;
}