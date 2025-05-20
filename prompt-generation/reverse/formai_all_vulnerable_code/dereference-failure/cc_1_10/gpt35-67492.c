//FormAI DATASET v1.0 Category: Port Scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_PORTS 65535

int main(int argc, char **argv)
{
    if(argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    int sockfd, err, sockopt;
    struct sockaddr_in target;
    char hostname[1024];
    struct hostent *host;

    strncpy(hostname, argv[1], sizeof(hostname));
    hostname[sizeof(hostname)-1] = '\0';

    host = gethostbyname(hostname);
    if(host == NULL) {
        printf("Cannot resolve '%s'\n", hostname);
        exit(1);
    }

    bzero((char*) &target, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr*)host->h_addr_list[0]));

    printf("Scanning %s ...\n", hostname);

    for(int port = 1; port <= MAX_PORTS; port++) {

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if(sockfd < 0) {
            printf("Cannot create socket\n");
            exit(1);
        }

        sockopt = fcntl(sockfd, F_GETFL, NULL);
        if(sockopt < 0) {
            printf("Cannot determine socket flags\n");
            exit(1);
        }

        err = connect(sockfd, (struct sockaddr*) &target, sizeof(target));
        if(err == 0) {
            printf("Port %d open\n", port);
        }

        close(sockfd);
    }

    printf("Scan complete\n");

    return 0;
}