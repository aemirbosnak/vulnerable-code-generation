//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_HTTP_REQUEST_SIZE 2048

int make_request(int sockfd, char* host, char* path) {
    char* request = malloc(MAX_HTTP_REQUEST_SIZE*sizeof(char));
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);
   
    if(write(sockfd, request, strlen(request)) < 0) {
        perror("Error writing to socket");
        return -1;
    }
    free(request);
    return 0;
}

int main(int argc, char* argv[]) {
    if(argc != 3) {
        printf("Usage: %s <host> <path>\n", argv[0]);
        return 1;
    }
   
    struct addrinfo hints;
    struct addrinfo *result, *rp;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;   
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;             /* For wildcard IP address */
    hints.ai_protocol = 0;          
    
    if(getaddrinfo(argv[1], "80", &hints, &result) != 0) {
        perror("Error getting address info");
        return 1;
    }
   
    int sockfd;
    for(rp = result; rp != NULL; rp = rp->ai_next) {
        sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if(sockfd == -1) {
            continue;
        }
        if(connect(sockfd, rp->ai_addr, rp->ai_addrlen) != -1) {
            break;                 
        }
        close(sockfd);
    }
    if(rp == NULL) {             
        fprintf(stderr, "Could not connect\n");
        return 1;
    }
   
    make_request(sockfd, argv[1], argv[2]);
    char buffer[1024];
    int n;
    while((n = read(sockfd, buffer, sizeof(buffer))) > 0) {
        fwrite(buffer, sizeof(char), n, stdout);
    }
    if(n < 0) {
        perror("Error reading from socket");
        return -1;
    }

    close(sockfd);
    return 0;
}