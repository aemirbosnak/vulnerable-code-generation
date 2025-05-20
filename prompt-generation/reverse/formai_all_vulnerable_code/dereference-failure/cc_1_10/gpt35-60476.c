//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_SIZE];
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    char request[MAX_SIZE] = "GET / HTTP/1.1\r\nHost: ";
    strcat(request, argv[1]);
    strcat(request, "\r\nConnection: close\r\n\r\n");
    if (write(sockfd, request, strlen(request)) < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    bzero(buffer, MAX_SIZE);
    while ((n = read(sockfd, buffer, MAX_SIZE-1)) > 0) {
        printf("%s", buffer);
        bzero(buffer, MAX_SIZE);
    }
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    close(sockfd);
    return 0;
}