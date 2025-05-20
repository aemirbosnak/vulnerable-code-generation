//FormAI DATASET v1.0 Category: Simple Web Server ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, clientlen, portno;
    char buffer[BUFSIZE];
    struct sockaddr_in serveraddr, clientaddr;
    int n;

    if (argc != 2) {
       fprintf(stderr,"usage: %s <port>\n", argv[0]);
       exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    serveraddr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0)
        error("ERROR on binding");

    if (listen(sockfd, 5) < 0)
        error("ERROR on listen");

    clientlen = sizeof(clientaddr);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &clientaddr, &clientlen);
        if (newsockfd < 0)
            error("ERROR on accept");

        memset(buffer, 0, BUFSIZE);
        n = read(newsockfd, buffer, BUFSIZE);
        if (n < 0)
            error("ERROR reading from socket");

        printf("Got request:\n%s\n", buffer);

        char *response =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html; charset=UTF-8\r\n\r\n"
            "<!DOCTYPE html>\r\n"
            "<html><head><title>My First Web Server</title></head>\r\n"
            "<body><h1>Welcome to My First Web Server</h1>\r\n"
            "<p>This is a simple web server written in C.</p>\r\n"
            "</body></html>\r\n";

        n = write(newsockfd, response, strlen(response));
        if (n < 0)
            error("ERROR writing to socket");

        close(newsockfd);
    }

    close(sockfd);
    
    return 0;
}