//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LENGTH 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[MAX_LENGTH];
    memset(buffer, 0, MAX_LENGTH);
    
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }
    
    portno = atoi(argv[2]);
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        error("ERROR invalid hostname");
    }
    
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }
    
    printf("FTP Client Connected to %s:%d\n", inet_ntoa(serv_addr.sin_addr), portno);
    
    while (1) {
        printf("FTP> ");
        bzero(buffer, MAX_LENGTH);
        fgets(buffer, MAX_LENGTH-1, stdin);
        
        if (strcasecmp(buffer, "quit\n") == 0) {
            break;
        }
        
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            error("ERROR writing to socket");
        }
        
        bzero(buffer, MAX_LENGTH);
        n = read(sockfd, buffer, MAX_LENGTH-1);
        if (n < 0) {
            error("ERROR reading from socket");
        }
        printf("%s", buffer);
    }
    
    close(sockfd);
    printf("FTP Client Disconnected from %s:%d\n", inet_ntoa(serv_addr.sin_addr), portno);
    return 0;
}