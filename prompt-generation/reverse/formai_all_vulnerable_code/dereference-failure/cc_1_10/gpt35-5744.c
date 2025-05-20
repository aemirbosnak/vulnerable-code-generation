//FormAI DATASET v1.0 Category: Socket programming ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <errno.h>

#define MAXLINE 4096
#define SERV_PORT 8888

char recvbuff[MAXLINE];
char sendbuff[MAXLINE];

int main(int argc, char **argv) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    struct hostent *he;
    
    if (argc != 2) {
        fprintf(stderr, "usage: client <IPaddress>\n");
        exit(1);
    }

    if ((he = gethostbyname(argv[1])) == NULL) {
        fprintf(stderr, "gethostbyname error: %s\n", hstrerror(h_errno));
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "socket error: %s\n", strerror(errno));
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    memcpy(&servaddr.sin_addr, he->h_addr, he->h_length);
  
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        fprintf(stderr, "connect error: %s\n", strerror(errno));
        exit(1);
    }
  
    // Sending message to server
    sprintf(sendbuff, "Hello, this is client!");
    send(sockfd, sendbuff, strlen(sendbuff), 0);

    // Receiving message from server
    n = recv(sockfd, recvbuff, sizeof(recvbuff), 0);
    recvbuff[n] = '\0';  
    printf("Received from server: %s\n", recvbuff); 

    close(sockfd);
    exit(0);
}