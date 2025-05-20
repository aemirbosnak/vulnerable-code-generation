//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
 
#define MAXSIZE 1024
 
void error(char *msg) {
    printf("%s\n", msg);
    exit(1);
}
 
int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[MAXSIZE], cmd[MAXSIZE];
 
    if (argc < 3) {
        error("Usage: ./ftpclient <server-ip> <port>\n");
    }
 
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }
 
    memset(&serv_addr, 0, sizeof(serv_addr));
    portno = atoi(argv[2]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        error("Invalid Address");
    }
 
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Connection Failed");
    }
 
    printf("Connected to server.\n");
 
    while (1) {
        bzero(buffer, MAXSIZE);
        printf(">> ");
        fgets(buffer, MAXSIZE, stdin);
        if (strncmp(buffer, "QUIT", 4) == 0) {
            printf("Closing Connection...\n");
            close(sockfd);
            return 1;
        }
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            error("Error writing to socket");
        }
        bzero(buffer, MAXSIZE);
        n = read(sockfd, buffer, MAXSIZE);
        if (n < 0) {
            error("Error reading from socket");
        }
        printf("%s\n", buffer);
    }
    return 0;
}