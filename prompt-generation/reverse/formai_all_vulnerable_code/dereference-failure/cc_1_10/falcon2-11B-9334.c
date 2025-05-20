//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define PORT 21
#define BUFSIZE 1024
#define MAXLINE 512

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFSIZE];
    char command[MAXLINE];
    char response[MAXLINE];
    char *fileName;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <ftp-server-address>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket error");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connect error");
        exit(1);
    }

    time_t t = time(NULL);
    struct tm *now = localtime(&t);
    sprintf(command, "USER %s", "ftp");
    n = write(sockfd, command, strlen(command));
    if (n < 0) {
        perror("Write error");
        exit(1);
    }

    bzero(command, MAXLINE);
    sprintf(command, "PASS %s", "password");
    n = write(sockfd, command, strlen(command));
    if (n < 0) {
        perror("Write error");
        exit(1);
    }

    bzero(command, MAXLINE);
    sprintf(command, "SYST");
    n = write(sockfd, command, strlen(command));
    if (n < 0) {
        perror("Write error");
        exit(1);
    }

    bzero(command, MAXLINE);
    sprintf(command, "TYPE I");
    n = write(sockfd, command, strlen(command));
    if (n < 0) {
        perror("Write error");
        exit(1);
    }

    bzero(command, MAXLINE);
    sprintf(command, "QUIT");
    n = write(sockfd, command, strlen(command));
    if (n < 0) {
        perror("Write error");
        exit(1);
    }

    close(sockfd);

    return 0;
}