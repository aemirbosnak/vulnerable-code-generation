//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    char buffer[BUF_SIZE];
    struct hostent *server;
    struct sockaddr_in serv_addr;

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    printf("Enter the message: ");
    memset(buffer, 0, BUF_SIZE);
    fgets(buffer, BUF_SIZE-1, stdin);

    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    memset(buffer, 0, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE-1);
    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s\n", buffer);
    close(sockfd);
    return 0;
}