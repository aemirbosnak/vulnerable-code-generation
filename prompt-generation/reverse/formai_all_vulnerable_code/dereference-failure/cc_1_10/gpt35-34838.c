//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// function to handle error messages
void error(const char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];

    // check if user entered correct number of arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(0);
    }

    // convert port number to integer
    portno = atoi(argv[2]);

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // get server by hostname
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    // clear server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));

    // set server address structure
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    // HTTP request 
    char header[BUFFER_SIZE];
    snprintf(header, BUFFER_SIZE, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
    //send request
    n = write(sockfd, header, strlen(header));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // receive response
    bzero(buffer, BUFFER_SIZE);
    while ((n = read(sockfd, buffer, BUFFER_SIZE-1)) > 0) {
        printf("%s", buffer);
        bzero(buffer, BUFFER_SIZE);
    }
    if (n < 0) {
        error("ERROR reading from socket");
    }

    // close socket
    close(sockfd);

    return 0;
}