//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: brave
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <errno.h> 
  
#define PORT 8080 
#define MAXLINE 1024 
  
int main() 
{ 
    int sockfd; 
    char buffer[MAXLINE]; 
    char hello[] = "Hello from the other side"; 
    struct sockaddr_in servaddr; 
  
    // Creating socket file descriptor 
    if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) { 
        printf("Socket creation failed due to %s\n", strerror(errno)); 
        return EXIT_FAILURE;
    } 
    else {
        printf("Socket created successfully with file descriptor: %d\n", sockfd); 
    }
  
    memset(&servaddr, 0, sizeof(servaddr)); 
  
    // Filling server information 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(PORT); 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
  
    // connect the client socket to server socket 
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) { 
        printf("Server connection failed due to %s\n", strerror(errno)); 
        return EXIT_FAILURE; 
    }
    else {
        printf("Connection successful with server\n");
    }
    
    // send hello message to server
    if (send(sockfd, hello, strlen(hello), 0) < 0) {
        printf("Failed to send message to server due to %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    else {
        printf("Message sent to server\n");
    }
    
    // read server response
    int n;
    if ((n = read(sockfd, buffer, MAXLINE)) > 0) {
        buffer[n] = '\0';
        printf("Response from server: %s\n", buffer);
    }
    else {
        printf("Failed to read server response due to %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
  
    // close the socket 
    close(sockfd); 
    printf("Connection closed with server\n");
    return EXIT_SUCCESS; 
}