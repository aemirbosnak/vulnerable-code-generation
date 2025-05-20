//FormAI DATASET v1.0 Category: Networking ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MESSAGE_SIZE 1024

void error(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[MESSAGE_SIZE];
    
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <ip address> <port>\n", argv[0]);
        exit(1);
    }
    
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0) {
        error("ERROR opening socket");
    }
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);
    
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }
    
    printf("Please enter the message: ");
    bzero(buffer, MESSAGE_SIZE);
    fgets(buffer, MESSAGE_SIZE - 1, stdin);
    
    n = write(sockfd, buffer, strlen(buffer));
    
    if (n < 0) {
        error("ERROR writing to socket");
    }
    
    bzero(buffer, MESSAGE_SIZE);
    
    n = read(sockfd, buffer, MESSAGE_SIZE - 1);
    
    if (n < 0) {
        error("ERROR reading from socket");
    }
    
    printf("Server: %s", buffer);
    
    close(sockfd);
    
    return 0;
}