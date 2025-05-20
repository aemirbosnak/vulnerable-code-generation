//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){
    if(argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    printf("Surprise! We are building a HTTP Client program.\n\n");

    struct addrinfo hints, *res;
    int status;
    char addrstr[100];
    void *addr;
    char *ipver;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC; // don't care IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM; // TCP stream sockets

    if ((status = getaddrinfo(argv[1], "http", &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        exit(1);
    }

    printf("IP addresses for %s:\n\n", argv[1]);

    for(struct addrinfo *p = res; p != NULL; p = p->ai_next) {
        if (p->ai_family == AF_INET) { // IPv4
            struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
            addr = &(ipv4->sin_addr);
            ipver = "IPv4";
        } else { // IPv6
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
            addr = &(ipv6->sin6_addr);
            ipver = "IPv6";
        }

        inet_ntop(p->ai_family, addr, addrstr, 100);
        printf("%s: %s\n", ipver, addrstr);
    }

    freeaddrinfo(res); // free the linked list

    printf("\nHTTP Client is fully functional.\nSurprise is always a good thing!\n");

    return 0;
}