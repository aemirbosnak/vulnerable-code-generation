//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>

int main(int argc, char *argv[]){
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[4096];

    if(argc < 3){
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if(server == NULL){
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        perror("ERROR connecting");
        exit(1);
    }

    char request[1024] = "GET / HTTP/1.1\r\nHost: ";
    strcat(request,argv[1]);
    strcat(request,"\r\nConnection: close\r\n\r\n");
    n = write(sockfd, request, strlen(request));
    if(n < 0){
        perror("ERROR writing to socket");
        exit(1);
    }

    bzero(buffer, 4096);
    while((n = read(sockfd, buffer, 4095)) > 0){
        printf("%s", buffer);
        bzero(buffer, 4096);
    }

    if(n < 0){
        perror("ERROR reading from socket");
        exit(1);
    }

    close(sockfd);
    return 0;
}