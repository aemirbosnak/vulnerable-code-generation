//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUF_SIZE];
    
    if (argc < 3) {
       printf("Usage: %s hostname port\n", argv[0]);
       exit(1);
    }
    
    portno = atoi(argv[2]);
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }
    
    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
    
    do {
        printf("Enter message: ");
        memset(buffer, 0, BUF_SIZE);
        fgets(buffer, BUF_SIZE-1, stdin);
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("ERROR writing to socket");
            break;
        }
        
        if(strcmp(buffer, "quit\n") == 0) break;
        
        memset(buffer, 0, BUF_SIZE);
        n = read(sockfd, buffer, BUF_SIZE-1);
        if (n < 0) {
            perror("ERROR reading from socket");
            break;
        }
        
        printf("Server response: %s\n", buffer);
        
    } while (1);
    
    close(sockfd);
    return 0;
}