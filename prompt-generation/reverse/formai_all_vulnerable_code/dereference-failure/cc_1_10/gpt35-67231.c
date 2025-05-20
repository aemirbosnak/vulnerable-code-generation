//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 21
#define MAXLINE 1024

void error(char *msg){
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]){
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAXLINE];

    if(argc < 3){
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0){
        error("Error opening socket");
    }

    server = gethostbyname(argv[1]);

    if(server == NULL){
        fprintf(stderr, "Error, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server -> h_addr, (char *) &serv_addr.sin_addr.s_addr, server -> h_length);
    serv_addr.sin_port = htons(PORT);

    if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
        error("Error connecting");
    }

    printf("Connected to FTP server\n");
    printf("Welcome to my FTP client\n");

    while(1){
        bzero(buffer, MAXLINE);
        n = read(sockfd, buffer, MAXLINE);

        if(n < 0){
            error("Error reading from socket");
        }

        printf("%s", buffer);

        if(strstr(buffer, "220 ") != NULL){
            break;
        }
    }

    while(1){
        bzero(buffer, MAXLINE);
        printf("> ");
        fgets(buffer, MAXLINE, stdin);

        if(strcmp(buffer, "quit\n") == 0){
            n = write(sockfd, buffer, strlen(buffer));

            if(n < 0){
                error("Error writing to socket");
            }
            break;
        }

        n = write(sockfd, buffer, strlen(buffer));

        if(n < 0){
            error("Error writing to socket");
        }

        bzero(buffer, MAXLINE);
        n = read(sockfd, buffer, MAXLINE);

        if(n < 0){
            error("Error reading from socket");
        }

        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}