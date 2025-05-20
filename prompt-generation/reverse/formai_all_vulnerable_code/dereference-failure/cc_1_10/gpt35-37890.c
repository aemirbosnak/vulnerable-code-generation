//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
 
#define MAXLINE 4096
 
int main(int argc, char** argv) {
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;
    struct hostent *hptr;
 
    if (argc != 2) {
        printf("usage: %s <hostname>\n", argv[0]);
        exit(1);
    }
 
    if ((hptr = gethostbyname(argv[1])) == NULL) {
        printf("gethostbyname error for host: %s: %s", argv[1], hstrerror(h_errno));
        exit(1);
    }
 
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("socket error");
        exit(1);
    }
 
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);
    memcpy(&servaddr.sin_addr, hptr->h_addr, hptr->h_length);
 
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        printf("connect error");
        exit(1);
    }
 
    char request[MAXLINE];
    snprintf(request, MAXLINE, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", argv[1]);
 
    if (write(sockfd, request, strlen(request)) < 0) {
        printf("write error");
        exit(1);
    }
 
    while ((n = read(sockfd, recvline, MAXLINE)) > 0) {
        recvline[n] = '\0';
        printf("%s", recvline);
    }
 
    if (n < 0) {
        printf("read error");
        exit(1);
    }
 
    exit(0);
}