//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc!= 3) {
        fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
        exit(1);
    }

    char *ip_address = argv[1];
    int port = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    struct addrinfo hints, *servinfo;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if(getaddrinfo(ip_address, NULL, &hints, &servinfo)!= 0) {
        fprintf(stderr, "Error resolving IP address: %s\n", gai_strerror(errno));
        exit(1);
    }

    for(struct addrinfo *p = servinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if(sockfd == -1) {
            fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
            exit(1);
        }

        if(connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
            close(sockfd);
            continue;
        }

        break;
    }

    if(sockfd == -1) {
        fprintf(stderr, "Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    char buffer[BUFFER_SIZE];
    while(1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if(bytes_received <= 0) {
            fprintf(stderr, "Error receiving data: %s\n", strerror(errno));
            close(sockfd);
            exit(1);
        }

        printf("Received data: %s", buffer);
    }

    close(sockfd);
    return 0;
}