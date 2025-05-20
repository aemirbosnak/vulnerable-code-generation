//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: shocked
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_URL_LEN 1024

int main(int argc, char *argv[])
{
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        return 1;
    }

    char url[MAX_URL_LEN];
    strcpy(url, argv[1]);

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int rv = getaddrinfo(url, NULL, &hints, &res);
    if (rv!= 0) {
        fprintf(stderr, "Error getting address info: %s\n", gai_strerror(rv));
        return 1;
    }

    for (struct addrinfo *ptr = res; ptr!= NULL; ptr = ptr->ai_next) {
        int sockfd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (sockfd == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, ptr->ai_addr, ptr->ai_addrlen) == -1) {
            perror("connect");
            close(sockfd);
            continue;
        }

        int optval = 1;
        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(int)) == -1) {
            perror("setsockopt");
            close(sockfd);
            continue;
        }

        char buf[1024];
        int nbytes = read(sockfd, buf, sizeof(buf));
        if (nbytes > 0) {
            buf[nbytes] = '\0';
            printf("Received: %s\n", buf);
        }
        else if (nbytes == 0) {
            printf("Connection closed\n");
        }
        else {
            perror("read");
        }

        close(sockfd);
        break;
    }

    freeaddrinfo(res);

    return 0;
}