//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <target_ip> <port>\n", argv[0]);
        return 1;
    }
    
    struct addrinfo hints, *servinfo;
    int yes = 1;
    int rv;
    int sockfd, port;
    struct sockaddr_in serv_addr;
    
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    
    if ((rv = getaddrinfo(argv[1], argv[2], &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }
    
    for (servinfo = servinfo; servinfo!= NULL; servinfo = servinfo->ai_next) {
        sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
        if (sockfd == -1) {
            perror("socket");
            continue;
        }
        
        if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
            perror("connect");
            close(sockfd);
            continue;
        }
        
        printf("Port %d is open\n", ntohs(servinfo->ai_addr->sa_family));
        
        close(sockfd);
    }
    
    freeaddrinfo(servinfo);
    return 0;
}