//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 2048

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char buffer[BUFFER_SIZE];

    if(argc != 2) {
        fprintf(stderr, "USAGE: %s <URL>\n", argv[0]);
        exit(1);
    }

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if((rv = getaddrinfo(argv[1], "http", &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }   

    for(p = servinfo; p != NULL; p = p->ai_next) {
        if((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("client: socket");
            continue;
        }

        if(connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("client: connect");
            continue;
        }

        break;
    }

    if(p == NULL) {
        fprintf(stderr, "client: failed to connect\n");
        exit(1);
    }

    freeaddrinfo(servinfo);

    char *request = "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n";
    sprintf(buffer, request, argv[1]);

    if(send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(1);
    }

    int num_bytes;
    while((num_bytes = recv(sockfd, buffer, BUFFER_SIZE-1, 0)) > 0) {
        buffer[num_bytes] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}