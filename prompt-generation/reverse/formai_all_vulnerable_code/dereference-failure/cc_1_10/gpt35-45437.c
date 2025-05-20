//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: systematic
// C program to demonstrate a simple HTTP client

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAX_SIZE 1024

// Main function
int main()
{
    // Initialize variables
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_SIZE];
    
    // Set the port number and host name for the server
    portno = 80;
    server = gethostbyname("www.example.com");
    
    // Create a new socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }
    
    // Initialize the server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    
    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }
    
    // Send an HTTP request to the server
    char *request = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
    n = write(sockfd, request, strlen(request));
    if (n < 0) {
        printf("Error writing to socket\n");
        exit(1);
    }
    
    // Read the server's response
    bzero(buffer, MAX_SIZE);
    n = read(sockfd, buffer, MAX_SIZE-1);
    if (n < 0) {
        printf("Error reading from socket\n");
        exit(1);
    }
    
    // Print the server's response
    printf("%s", buffer);
    
    // Close the socket
    close(sockfd);
    
    return 0;
}