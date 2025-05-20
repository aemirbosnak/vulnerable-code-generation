//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define SERVER "www.example.com"
#define PORT 80

int main(int argc, char *argv[]) {
    struct sockaddr_in server_addr;
    struct hostent *he;
    int sockfd, status, bytes_recv, total_bytes_recv, sent;
    char request[1024], response[4096];
    char *header = "GET / HTTP/1.1\r\nHost: " SERVER "\r\nConnection: close\r\n\r\n";
        
    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Get the IP address of the server
    if ((he = gethostbyname(SERVER)) == NULL) {
        perror("Host name resolution failed");
        exit(EXIT_FAILURE);
    }
    
    // Configure the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);
    server_addr.sin_port = htons(PORT);
    
    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection to server failed");
        exit(EXIT_FAILURE);
    }
    
    // Send the HTTP request to the server
    sent = send(sockfd, header, strlen(header), 0);
    if (sent == -1) {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }
    
    // Receive the HTTP response from the server
    total_bytes_recv = 0;
    while ((bytes_recv = recv(sockfd, response + total_bytes_recv, sizeof(response) - total_bytes_recv, 0)) > 0) {
        total_bytes_recv += bytes_recv;
    }
    if (bytes_recv == -1) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }
    
    // Print the HTTP response
    printf("%s", response);
    
    // Close the socket
    close(sockfd);
    
    return 0;
}