//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void print_usage(char *program_name) {
    printf("Usage: %s <hostname> <start_port> <end_port>\n", program_name);
    exit(1);
}

int is_valid_port(int port) {
    return (port >= 0 && port <= 65535);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage(argv[0]);
    }

    char *hostname = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (!is_valid_port(start_port) ||!is_valid_port(end_port)) {
        printf("Invalid port range.\n");
        exit(1);
    }

    if (start_port > end_port) {
        printf("Start port cannot be greater than end port.\n");
        exit(1);
    }

    int sockfd, newsockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[INET6_ADDRSTRLEN];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(hostname, NULL, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if (p->ai_family == AF_INET) {
            inet_ntop(AF_INET, &((struct sockaddr_in *)p->ai_addr)->sin_addr, s, sizeof(s));
            printf("Scanning %s (%s):", hostname, s);
        } else if (p->ai_family == AF_INET6) {
            inet_ntop(AF_INET6, &((struct sockaddr_in6 *)p->ai_addr)->sin6_addr, s, sizeof(s));
            printf("Scanning %s (%s):", hostname, s);
        }

        for (int port = start_port; port <= end_port; port++) {
            sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);

            if (sockfd == -1) {
                perror("socket");
                exit(1);
            }

            if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
                close(sockfd);
                continue;
            }

            printf("  Port %d: Open\n", port);
            close(sockfd);
        }
    }

    freeaddrinfo(servinfo);

    return 0;
}