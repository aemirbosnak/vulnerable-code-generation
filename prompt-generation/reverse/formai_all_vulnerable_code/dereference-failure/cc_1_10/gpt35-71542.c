//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip-address> <port-number>\n", argv[0]);
        exit(1);
    }
    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }
    
    struct addrinfo hints, *servinfo, *p;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    int rv = getaddrinfo(argv[1], argv[2], &hints, &servinfo);
    if (rv) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }
    
    struct timeval tv;
    tv.tv_sec = 5;
    tv.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO,&tv,sizeof(tv)) < 0) {
        perror("setsockopt");
    }
    
    for (p = servinfo; p != NULL; p = p->ai_next) {
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) < 0) {
            perror("connect");
            close(sockfd);
            continue;
        }
        break;
    }
    
    if (p == NULL) {
        fprintf(stderr, "Failed to connect\n");
        exit(1);
    }
    
    freeaddrinfo(servinfo);
    
    char buf[BUF_SIZE];
    int numBytes = recv(sockfd, buf, BUF_SIZE-1, 0);
    if (numBytes <= 0) {
        fprintf(stderr, "No data received\n");
    } else {
        buf[numBytes] = '\0'; 
        printf("Received: %s\n", buf);
    }
    
    close(sockfd);
    return 0;
}