//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char* argv[])
{
    if (argc!= 2) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }
    
    struct hostent* host;
    struct in_addr* ipv4;
    struct sockaddr_in serv_addr;
    int sockfd;
    int port;
    char buffer[1024];
    int n;
    
    if ((host = gethostbyname(argv[1])) == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }
    
    ipv4 = (struct in_addr*)host->h_addr;
    
    port = atoi(argv[2]);
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    bzero((char*)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = ipv4->s_addr;
    serv_addr.sin_port = htons(port);
    
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }
    
    printf("Connected to %s on port %d\n", argv[1], port);
    
    while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        printf("Received %d bytes: %s\n", n, buffer);
    }
    
    printf("Disconnected from %s on port %d\n", argv[1], port);
    
    close(sockfd);
    return 0;
}