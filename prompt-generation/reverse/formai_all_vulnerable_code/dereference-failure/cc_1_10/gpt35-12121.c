//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Ken Thompson
/*
 * HTTP client program in Ken Thompson style
 * Author: <Your Name>
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

/* prints error message and exits the program */
void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFSIZE];
    char *host;
    char *path;

    if (argc < 3) {
       fprintf(stderr,"usage %s hostname path port\n", argv[0]);
       exit(1);
    }

    host = argv[1];
    path = argv[2];
    portno = atoi(argv[3]);

    /* create socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    /* fill in server address */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(host);
    serv_addr.sin_port = htons(portno);

    /* connect to server */
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    /* send HTTP request */
    sprintf(buffer, "GET %s HTTP/1.1\r\nHost: %s\r\nUser-Agent: KenThompsonStyle/1.0\r\nAccept: */*\r\n\r\n", path, host);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");

    /* read HTTP response */
    bzero(buffer, BUFSIZE);
    while ((n = read(sockfd, buffer, BUFSIZE-1)) > 0) {
        printf("%.*s", n, buffer);
        bzero(buffer, BUFSIZE);
    }

    close(sockfd);
    return 0;
}