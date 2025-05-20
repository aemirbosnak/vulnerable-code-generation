//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFSIZE 4096

int main(int argc, char *argv[]) {
    // check if user has input valid arguments
    if (argc != 3) {
        fprintf(stderr,"Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    char hostname[100];
    strcpy(hostname, argv[1]);

    int port = atoi(argv[2]);

    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // resolve hostname to ip address
    struct hostent *he;
    if ((he = gethostbyname(hostname)) == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    // set up structure for server address
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    serveraddr.sin_addr = *((struct in_addr *)he->h_addr);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serveraddr, 
                sizeof(serveraddr)) == -1) {
        perror("connect");
        exit(1);
    }

    // send HTTP request
    char request[BUFFSIZE];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s:%d\r\n\r\n", hostname, port);
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        exit(1);
    }

    // receive HTTP response
    char response[BUFFSIZE];
    int bytesRead = 0;   
    while ((bytesRead = recv(sockfd, response, BUFFSIZE - 1, 0)) > 0) {
        response[bytesRead] = '\0';
        printf("%s", response);
    }

    // close socket
    close(sockfd);
    return 0;
}