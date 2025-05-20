//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define MAXSIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[MAXSIZE];
    char filename[MAXSIZE];

    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    printf("Enter the name of the file to download:");
    bzero(filename, MAXSIZE);
    fgets(filename, MAXSIZE, stdin);
    
    n = write(sockfd, filename, strlen(filename));
    if (n < 0) 
        error("ERROR writing to socket");

    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        error("ERROR creating file");
    }

    bzero(buffer, MAXSIZE);
    while((n = read(sockfd, buffer, MAXSIZE)) > 0) {
        fwrite(buffer, sizeof(char), n, fp);
        bzero(buffer, MAXSIZE);
    }

    printf("File downloaded successfully!\n");

    close(sockfd);
    fclose(fp);
    return 0;
}