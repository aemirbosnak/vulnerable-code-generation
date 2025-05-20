//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_HOSTNAME 255
#define MAX_PORT_SIZE 6
#define TRUE 1
#define FALSE 0

int ping_host(char *hostname, int port);
void print_usage();

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        print_usage();
        return 1;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    if (ping_host(hostname, port) == TRUE) {
        printf("Host %s is reachable\n", hostname);
    } else {
        printf("Host %s is not reachable\n", hostname);
    }

    return 0;
}

void print_usage() {
    printf("Usage:./ping_host hostname port\n");
    printf("Where hostname is the name of the host to ping and port is the port number to ping\n");
}

int ping_host(char *hostname, int port) {
    int sockfd, retval;
    struct addrinfo hints, *servinfo, *p;
    char s[MAX_HOSTNAME];
    char port_s[MAX_PORT_SIZE];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    snprintf(port_s, MAX_PORT_SIZE, "%d", port);
    retval = getaddrinfo(hostname, port_s, &hints, &servinfo);

    if (retval!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(retval));
        return FALSE;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);

        if (sockfd == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen)!= -1) {
            close(sockfd);
            return TRUE;
        } else if (errno!= ECONNREFUSED) {
            perror("connect");
        }

        close(sockfd);
    }

    return FALSE;
}