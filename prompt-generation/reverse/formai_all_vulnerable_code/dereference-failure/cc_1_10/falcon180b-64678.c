//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define BUF_SIZE 1024

void error_handling(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

int main() {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    char s[BUF_SIZE];
    int rv;
    int numbytes;

    // set up hints for getaddrinfo()
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // get address information for "localhost"
    if ((rv = getaddrinfo("localhost", "http", &hints, &servinfo))!= 0) {
        error_handling("getaddrinfo() failed");
    }

    // loop through all the results and connect to the first we can
    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            error_handling("socket() failed");
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL) {
        error_handling("failed to connect");
    }

    // send an HTTP request
    send(sockfd, "GET / HTTP/1.0\r\n\r\n", strlen("GET / HTTP/1.0\r\n\r\n"), 0);

    // read the response from the server
    while ((numbytes = recv(sockfd, s, BUF_SIZE, 0)) > 0) {
        s[numbytes] = '\0';
        printf("%s", s);
    }

    close(sockfd);

    return 0;
}