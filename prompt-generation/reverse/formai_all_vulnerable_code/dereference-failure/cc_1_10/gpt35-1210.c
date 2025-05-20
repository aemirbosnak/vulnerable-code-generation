//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXBUF 1024

int main(int argc, char *argv[]) {

    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAXBUF];
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    if ((server = gethostbyname(argv[1])) == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
    bzero(buffer,MAXBUF);
    strcat(buffer, "USER username\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer,MAXBUF);
    recv(sockfd, buffer, MAXBUF, 0);
    printf("%s",buffer);
    bzero(buffer,MAXBUF);
    strcat(buffer, "PASS password\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer,MAXBUF);
    recv(sockfd, buffer, MAXBUF, 0);
    printf("%s",buffer);
    bzero(buffer,MAXBUF);
    strcat(buffer, "STAT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer,MAXBUF);
    recv(sockfd, buffer, MAXBUF, 0);
    printf("%s",buffer);
    bzero(buffer,MAXBUF);
    strcat(buffer, "RETR 1\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer,MAXBUF);
    recv(sockfd, buffer, MAXBUF, 0);
    printf("%s",buffer);
    close(sockfd);
    return 0;
}