//FormAI DATASET v1.0 Category: Simple Web Server ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8000
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, n;
    char buffer[BUFSIZE];
    struct sockaddr_in serv_addr, cli_addr;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // fill in server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = PORT;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // bind socket to port
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // wait for connection
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    // read HTTP request
    bzero(buffer, BUFSIZE);
    n = read(newsockfd, buffer, BUFSIZE-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    // send HTTP response
    char response[BUFSIZE];
    sprintf(response, "HTTP/1.1 200 OK\n"
            "Content-Type: text/html\n"
            "\n"
            "<html><body><h1>Welcome to my curious web server!</h1>\n"
            "<p>Your HTTP request was:</p>\n"
            "<pre>%s</pre>\n"
            "</body></html>\n", buffer);
    n = write(newsockfd, response, strlen(response));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // close connection
    close(newsockfd);
    close(sockfd);

    return 0;
}