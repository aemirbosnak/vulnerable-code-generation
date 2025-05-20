//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 25

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    struct addrinfo hints, *servinfo, *p;
    int status, sockfd;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    status = getaddrinfo(argv[1], NULL, &hints, &servinfo);
    if (status!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            continue;
        }

        status = connect(sockfd, p->ai_addr, p->ai_addrlen);
        if (status == -1) {
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Could not connect to server\n");
        exit(1);
    }

    char msg[] = "Subject: Test SMTP client\r\n\r\nHello World!\r\n.\r\n";
    send(sockfd, msg, sizeof(msg), 0);
    printf("Message sent.\n");

    close(sockfd);
    freeaddrinfo(servinfo);
    return 0;
}