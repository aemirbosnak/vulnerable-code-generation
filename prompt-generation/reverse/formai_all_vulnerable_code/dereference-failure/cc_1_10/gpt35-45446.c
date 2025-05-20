//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAXSIZE 1024

int main()
{
    int sock;
    struct addrinfo hints, *res;
    char host[MAXSIZE];
    char ipaddr[MAXSIZE];
    char service[MAXSIZE];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    printf("Enter host name or IP address: ");
    fgets(host, MAXSIZE, stdin);
    host[strcspn(host, "\n")] = '\0';

    printf("Enter service name or port number: ");
    fgets(service, MAXSIZE, stdin);
    service[strcspn(service, "\n")] = '\0';

    if (getaddrinfo(host, service, &hints, &res) != 0) {
        printf("Error: Invalid host name or service name/port number\n");
        exit(EXIT_FAILURE);
    }

    while (res != NULL) {
        if (res->ai_family == AF_INET) {
            struct sockaddr_in *ipv4 = (struct sockaddr_in *)res->ai_addr;
            void *addr = &(ipv4->sin_addr);
            inet_ntop(res->ai_family, addr, ipaddr, MAXSIZE);
            printf("IPv4 Address: %s\n", ipaddr);
        }
        else if (res->ai_family == AF_INET6) {
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)res->ai_addr;
            void *addr = &(ipv6->sin6_addr);
            inet_ntop(res->ai_family, addr, ipaddr, MAXSIZE);
            printf("IPv6 Address: %s\n", ipaddr);
        }
        else {
            printf("Unknown address family\n");
        }
        res = res->ai_next;
    }

    freeaddrinfo(res);
    return 0;
}