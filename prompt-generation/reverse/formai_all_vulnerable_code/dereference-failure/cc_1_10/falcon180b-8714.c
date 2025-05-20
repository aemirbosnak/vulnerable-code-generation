//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *host = argv[1];
    char *port = argv[2];
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    char buffer[BUFFER_SIZE];
    int bytes;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if ((getaddrinfo(host, port, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errno));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen)!= -1) {
            break;
        } else {
            close(sockfd);
            perror("connect");
        }
    }

    if (p == NULL) {
        exit(1);
    }

    printf("Connected to %s\n", host);

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        fgets(buffer, BUFFER_SIZE, stdin);
        send(sockfd, buffer, strlen(buffer), 0);

        bytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes <= 0) {
            break;
        }
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}