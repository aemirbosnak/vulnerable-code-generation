//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFSIZE 4096

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFSIZE];

    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr,"Error: No such host\n");
        exit(EXIT_FAILURE);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *) &serv_addr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(EXIT_FAILURE);
    }

    bzero(buffer,BUFSIZE);
    n = read(sockfd,buffer,BUFSIZE-1);

    if (n < 0){
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }

    printf("%s\n",buffer);

    sprintf(buffer, "USER username\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    bzero(buffer,BUFSIZE);
    n = read(sockfd, buffer, BUFSIZE-1);
    printf("%s", buffer);

    sprintf(buffer, "PASS password\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    bzero(buffer,BUFSIZE);
    n = read(sockfd, buffer, BUFSIZE-1);
    printf("%s", buffer);

    sprintf(buffer, "LIST\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    bzero(buffer,BUFSIZE);
    n = read(sockfd, buffer, BUFSIZE-1);
    printf("%s", buffer);

    sprintf(buffer, "QUIT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    bzero(buffer,BUFSIZE);
    n = read(sockfd, buffer, BUFSIZE-1);
    printf("%s", buffer);

    close(sockfd);
    return 0;
}