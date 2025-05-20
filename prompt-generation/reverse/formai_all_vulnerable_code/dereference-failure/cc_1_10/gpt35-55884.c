//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 4096
#define SERVER_PORT 80
#define HOST "www.google.com"

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    char request[BUFFER_SIZE];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(HOST);
    if (server == NULL) {
        perror("ERROR, no such host");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    sprintf(request, "GET / HTTP/1.0\r\nHost: %s\r\n\r\n", HOST);
    n = write(sockfd, request, strlen(request));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    bzero(buffer, BUFFER_SIZE);
    while ((n = read(sockfd, buffer, BUFFER_SIZE-1)) > 0) {
        printf("%s", buffer);
        bzero(buffer, BUFFER_SIZE);
    }

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    close(sockfd);
    return 0;
}