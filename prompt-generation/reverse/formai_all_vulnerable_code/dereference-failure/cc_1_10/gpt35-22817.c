//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAXLINE 1024

//Function to obtain IP address from hostname
int get_ip(char *hostname, char *ip)
{
    struct addrinfo hints, *res;
    int status;
    void *address;
    struct sockaddr_in *ipv4;
    struct sockaddr_in6 *ipv6;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(hostname, NULL, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return 1;
    }

    while(res != NULL) {
        if (res->ai_family == AF_INET) {
            ipv4 = (struct sockaddr_in *)res->ai_addr;
            address = &(ipv4->sin_addr);
            inet_ntop(res->ai_family, address, ip, INET_ADDRSTRLEN);
            return 0;
        } else if (res->ai_family == AF_INET6) {
            ipv6 = (struct sockaddr_in6 *)res->ai_addr;
            address = &(ipv6->sin6_addr);
            inet_ntop(res->ai_family, address, ip, INET6_ADDRSTRLEN);
            return 0;
        }
        res = res->ai_next;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    int sockfd, n;
    char recvline[MAXLINE + 1];
    char ip[INET6_ADDRSTRLEN];
    struct sockaddr_in servaddr;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <IP address or hostname>\n", argv[0]);
        exit(1);
    }

    //get IP address from hostname
    if (get_ip(argv[1], ip)) {
        fprintf(stderr, "error obtaining IP address from hostname\n");
        exit(1);
    }

    //open socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "socket error: %s\n", strerror(errno));
        exit(1);
    }

    //set server address info
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80); //HTTP port

    //convert IP address from string to binary form
    if (inet_pton(AF_INET, ip, &servaddr.sin_addr) <= 0) {
        fprintf(stderr, "inet_pton error: %s\n", strerror(errno));
        exit(1);
    }

    //connect to server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        fprintf(stderr, "connect error: %s\n", strerror(errno));
        exit(1);
    }

    //send HTTP request
    char *http_request = "GET / HTTP/1.1\r\nHost: %s\r\n\r\n";
    char request[strlen(http_request) + strlen(argv[1]) - 1];
    sprintf(request, http_request, argv[1]);
    if (write(sockfd, request, strlen(request)) < 0) {
        fprintf(stderr, "write error: %s\n", strerror(errno));
        exit(1);
    }

    //read HTTP response
    while ((n = read(sockfd, recvline, MAXLINE)) > 0) {
        recvline[n] = '\0';
        printf("%s", recvline);
    }
    if (n < 0) {
        fprintf(stderr, "read error: %s\n", strerror(errno));
        exit(1);
    }

    //close socket
    close(sockfd);
    exit(0);
}