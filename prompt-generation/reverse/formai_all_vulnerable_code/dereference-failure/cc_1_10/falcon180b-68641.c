//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/time.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <hostname> <port> <username>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    char *port = argv[2];
    char *username = argv[3];

    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[INET6_ADDRSTRLEN];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(hostname, port, &hints, &servinfo))!= 0) {
        error("getaddrinfo");
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            error("socket");
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen)!= -1) {
            break;
        }

        close(sockfd);
    }

    if (p == NULL) {
        error("connect");
    }

    char buffer[BUFFER_SIZE];
    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);

    char *response = NULL;
    socklen_t response_len = BUFFER_SIZE;

    while (recv(sockfd, buffer, BUFFER_SIZE, 0) > 0) {
        buffer[strcspn(buffer, "\r\n")] = '\0';

        if (response!= NULL) {
            free(response);
        }

        response = strdup(buffer);
        response_len = strlen(response);
    }

    close(sockfd);

    if (response == NULL) {
        fprintf(stderr, "No response from server\n");
        return 1;
    }

    printf("Server response: %s\n", response);

    return 0;
}