//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    char buffer[BUFFER_SIZE];
    int rv;
    int portno;

    if (argc!= 4) {
        printf("Usage: ftp_client <hostname> <username> <password>\n");
        exit(1);
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    rv = getaddrinfo(argv[1], "21", &hints, &servinfo);
    if (rv!= 0) {
        printf("getaddrinfo error: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            perror("socket");
            continue;
        }

        rv = connect(sockfd, p->ai_addr, p->ai_addrlen);
        if (rv!= -1) {
            break;
        }

        close(sockfd);
        perror("connect");
    }

    if (p == NULL) {
        exit(1);
    }

    printf("Connected to %s\n", argv[1]);

    snprintf(buffer, BUFFER_SIZE, "USER %s\r\n", argv[2]);
    send(sockfd, buffer, strlen(buffer), 0);

    snprintf(buffer, BUFFER_SIZE, "PASS %s\r\n", argv[3]);
    send(sockfd, buffer, strlen(buffer), 0);

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        rv = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (rv <= 0) {
            break;
        }
        printf("%s", buffer);
    }

    close(sockfd);
    exit(0);
}