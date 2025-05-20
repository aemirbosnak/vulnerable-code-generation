//Falcon2-11B DATASET v1.0 Category: Wireless Network Scanner ; Style: romantic
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <net/if.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <time.h>

int main(int argc, char *argv[]) {
    struct addrinfo hints, *servinfo;
    int sockfd;
    char *serverName;
    int port;
    struct hostent *host;
    struct in_addr *ipv4;
    struct sockaddr_in address;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(argv[1], "80", &hints, &servinfo)!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errno));
        return 1;
    }

    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (sockfd < 0) {
        fprintf(stderr, "socket: %s\n", strerror(errno));
        return 1;
    }

    serverName = inet_ntoa(((struct sockaddr_in *)servinfo->ai_addr)->sin_addr);
    port = servinfo->ai_addr->sa_family == AF_INET? ntohs(((struct sockaddr_in *)servinfo->ai_addr)->sin_port) : 0;

    if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen)!= 0) {
        perror("connect");
        return 1;
    }

    if (send(sockfd, "GET / HTTP/1.0\r\n\r\n", 29, 0)!= 29) {
        perror("send");
        return 1;
    }

    if (recv(sockfd, &address, sizeof address, 0) < 0) {
        perror("recv");
        return 1;
    }

    printf("Server name: %s\n", serverName);
    printf("Port: %d\n", port);
    printf("IP address: %s\n", inet_ntoa(address.sin_addr));

    return 0;
}