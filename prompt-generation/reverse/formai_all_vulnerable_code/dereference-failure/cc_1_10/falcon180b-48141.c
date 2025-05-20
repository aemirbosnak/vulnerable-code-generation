//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME];
    strcpy(hostname, argv[1]);

    struct addrinfo hints, *servinfo, *p;
    int rv;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(hostname, NULL, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        int sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }

        char send_data[MAX_DATA];
        snprintf(send_data, MAX_DATA, "PING %s\r\n", hostname);

        if (send(sockfd, send_data, strlen(send_data), 0) == -1) {
            perror("send");
            close(sockfd);
            continue;
        }

        char recv_data[MAX_DATA];
        memset(recv_data, 0, MAX_DATA);

        int bytes_received = recv(sockfd, recv_data, MAX_DATA, 0);
        if (bytes_received <= 0) {
            if (bytes_received == 0) {
                printf("No response from %s\n", hostname);
            } else {
                perror("recv");
            }
            close(sockfd);
            continue;
        }

        printf("Response from %s:\n%s", hostname, recv_data);
        close(sockfd);
        break;
    }

    freeaddrinfo(servinfo);
    return 0;
}