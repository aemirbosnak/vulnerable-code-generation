//FormAI DATASET v1.0 Category: Socket programming ; Style: intelligent
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <errno.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 

#define PORT 8080

int main(int argc, char const *argv[]) 
{ 
    int sockfd, connfd, valread; 
    struct sockaddr_in servaddr, cli; 
    
    // Creating socket file descriptor 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("Socket creation failed! Error: %s\n", strerror(errno)); 
        exit(0); 
    } 
    else {
        printf("Socket created successfully!\n"); 
    }
    
    // Filling server information 
    memset(&servaddr, 0, sizeof(servaddr)); 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 
    
    // Bind the socket with the server address 
    if ((bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) { 
        printf("Socket bind failed! Error: %s\n", strerror(errno)); 
        exit(0); 
    } 
    else {
        printf("Socket bind successful!\n"); 
    } 
    
    // Listen for incoming connections 
    if ((listen(sockfd, 5)) != 0) { 
        printf("Listen failed! Error: %s\n", strerror(errno)); 
        exit(0); 
    } 
    else {
        printf("Server listening...\n"); 
    } 
    int len = sizeof(cli); 
    
    // Accept the data packet from client and verify 
    connfd = accept(sockfd, (struct sockaddr *)&cli, &len); 
    if (connfd < 0) { 
        printf("Accept failed! Error: %s", strerror(errno)); 
        exit(0); 
    } 
    else {
        printf("Connection accepted!\n"); 
    } 
    
    // Read the message from client and print it 
    char buffer[1024] = {0}; 
    valread = read(connfd, buffer, 1024); 
    printf("Message from client: %s\n", buffer); 

    // Send a message back to the client 
    char *hello = "Hello from server"; 
    send(connfd, hello, strlen(hello), 0); 
    printf("Message sent to client!\n"); 
    
    // Close the socket 
    close(sockfd); 
    
    return 0; 
}