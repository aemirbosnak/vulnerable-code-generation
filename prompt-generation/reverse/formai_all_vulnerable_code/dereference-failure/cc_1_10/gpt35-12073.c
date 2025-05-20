//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#define MAXLINE 1024

void error(char * msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char * argv[]) {
    int sockfd, n, m;
    struct sockaddr_in serv_addr;
    struct hostent * server;
    char buffer[MAXLINE];
    int portno = 143; // IMAP port number
    char *host = "localhost"; // default host

    if (argc > 1) {
        host = argv[1];
    }

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // get host by name
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host as %s\n", host);
        exit(0);
    }

    // set up server address
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    // connect to server
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    // receive initial greeting
    bzero(buffer, MAXLINE);
    n = read(sockfd, buffer, MAXLINE-1);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    // send login command
    bzero(buffer, MAXLINE);
    sprintf(buffer, "a001 LOGIN username password\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // receive login response
    bzero(buffer, MAXLINE);
    n = read(sockfd, buffer, MAXLINE-1);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    // send select command
    bzero(buffer, MAXLINE);
    sprintf(buffer, "a002 SELECT INBOX\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // receive select response
    bzero(buffer, MAXLINE);
    n = read(sockfd, buffer, MAXLINE-1);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    // send fetch command
    bzero(buffer, MAXLINE);
    sprintf(buffer, "a003 FETCH 1 BODY[HEADER]\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // receive fetch response
    bzero(buffer, MAXLINE);
    n = read(sockfd, buffer, MAXLINE-1);
    if (n < 0) {
        error("ERROR reading from socket");
    }

    // check if message is multipart
    char * msg = strstr(buffer, "Content-Type: multipart");
    if (msg != NULL) {
        // if multipart, send second fetch command to get second part
        bzero(buffer, MAXLINE);
        sprintf(buffer, "a004 FETCH 1 BODY[2]\r\n");
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            error("ERROR writing to socket");
        }

        // receive second fetch response
        bzero(buffer, MAXLINE);
        n = read(sockfd, buffer, MAXLINE-1);
        if (n < 0) {
            error("ERROR reading from socket");
        }
        // append to first fetch response
        strcat(msg, buffer);
    }

    // print message
    printf("%s", msg);

    // send logout command
    bzero(buffer, MAXLINE);
    sprintf(buffer, "a005 LOGOUT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // receive logout response
    bzero(buffer, MAXLINE);
    n = read(sockfd, buffer, MAXLINE-1);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    close(sockfd);
    return 0;
}