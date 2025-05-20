//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFSIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFSIZE];
    if (argc < 4) {
        fprintf(stderr,"Usage: %s hostname port filename\n", argv[0]);
        exit(1);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    FILE *fp;
    fp = fopen(argv[3], "r");
    if (fp == NULL) {
        error("ERROR opening file");
    }

    bzero(buffer, BUFSIZE);

    // Read contents from file and transfer to server
    while((n = fread(buffer, 1, BUFSIZE, fp)) > 0) {
        if (write(sockfd, buffer, n) < 0) {
            error("ERROR writing to socket");
        }
        bzero(buffer, BUFSIZE);
    }

    fclose(fp);
    close(sockfd);
    return 0;
}