//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

// Function to handle errors
void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }
    printf("Connected to FTP Server\n");
    bzero(buffer,BUFFER_SIZE);
    n = read(sockfd,buffer,BUFFER_SIZE-1);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s\n", buffer);
    bzero(buffer,BUFFER_SIZE);
    printf("Please enter the filename to download: ");
    fgets(buffer,BUFFER_SIZE,stdin);
    strtok(buffer, "\n");
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }
    bzero(buffer,BUFFER_SIZE);
    FILE *fp;
    fp = fopen(buffer, "w+");
    while((n = read(sockfd, buffer, BUFFER_SIZE-1)) > 0) {
        fwrite(buffer, sizeof(char), n, fp);
        bzero(buffer, BUFFER_SIZE);
    }
    printf("Download Successful\n");
    return 0;
}