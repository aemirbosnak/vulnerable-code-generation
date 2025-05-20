//FormAI DATASET v1.0 Category: Networking ; Style: detailed
/*
 
  This is a simple client-server program that uses TCP/IP sockets for communication. 
  The client sends a message to the server, the server receives the message, 
  converts it to title case, and sends the title-cased message back to the client. 
  The client then displays the title-cased message on the console.
 
  Author: Jane Smith
 
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
 
 
#define BUFSIZE 1024
 
void error(char *msg) {
    
    perror(msg);
    exit(1);
}
 
int main(int argc, char *argv[]) {
    
    int sockfd, clientfd;
    struct sockaddr_in serv_addr, cli_addr;
    int cli_len = sizeof(cli_addr);
    char buffer[BUFSIZE];
    int n;
    
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [port number]\n", argv[0]);
        exit(1);
    }
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }
    
    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));
    
    if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR on binding");
    }
    
    listen(sockfd, 5);
    
    printf("Server running on port %d\n", atoi(argv[1]));
    
    while (1) {
        
        clientfd = accept(sockfd, (struct sockaddr*) &cli_addr, &cli_len);
        if (clientfd < 0) {
            error("ERROR on accept");
        }
        
        printf("Incoming connection from %s:%d\n", 
               inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
        
        bzero(buffer, BUFSIZE);
        n = read(clientfd, buffer, BUFSIZE-1);
        if (n < 0) {
            error("ERROR reading from socket");
        }
        
        // convert message to title case 
        for (int i=0; buffer[i]; i++) {
            if (i==0 || (i>0 && buffer[i-1] == ' ')) {
                buffer[i] = toupper(buffer[i]);
            } else {
                buffer[i] = tolower(buffer[i]);
            }
        }
        
        n = write(clientfd, buffer, strlen(buffer));
        if (n < 0) {
            error("ERROR writing to socket");
        }
      
        close(clientfd); 
    }
    
    close(sockfd);
    
    return 0;
}