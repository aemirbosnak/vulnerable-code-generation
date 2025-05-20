//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/tcp.h>

#define MAX_PACKET_SIZE 1024
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080

void print_usage() {
    printf("Usage:./net_topology <server_ip> <server_port>\n");
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        print_usage();
    } else {
        char *server_ip = argv[1];
        int server_port = atoi(argv[2]);

        struct addrinfo hints, *servinfo, *p;
        int rv;

        memset(&hints, 0, sizeof(hints));
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;

        if ((rv = getaddrinfo(server_ip, server_port, &hints, &servinfo))!= 0) {
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
                perror("connect");
                close(sockfd);
                continue;
            }

            char buffer[MAX_PACKET_SIZE];
            int n;

            while ((n = recv(sockfd, buffer, MAX_PACKET_SIZE, 0)) > 0) {
                printf("Received: %s\n", buffer);
            }

            close(sockfd);
        }
    }

    return 0;
}