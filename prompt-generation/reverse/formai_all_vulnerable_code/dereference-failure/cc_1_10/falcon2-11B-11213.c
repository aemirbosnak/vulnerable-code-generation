//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char hostname[1024];
    strcpy(hostname, argv[1]);

    struct addrinfo hints, *servinfo, *p;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int rv = getaddrinfo(hostname, "80", &hints, &servinfo);
    if (rv!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        int sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            continue;
        }

        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));

        while (1) {
            if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
                perror("recv");
                break;
            }

            buffer[strcspn(buffer, "\n")] = '\0';
            printf("%s\n", buffer);

            if (strcmp(buffer, "quit") == 0) {
                break;
            }

            if (send(sockfd, "ack\n", sizeof("ack\n"), 0) == -1) {
                perror("send");
                break;
            }
        }

        close(sockfd);
    }

    freeaddrinfo(servinfo);
    return 0;
}