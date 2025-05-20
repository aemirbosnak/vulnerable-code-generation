//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

// Function to handle HTTP GET requests
void get_request(int sockfd, char* url) {
    char request[1024]; // Request buffer
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", url, url); // Format GET request
    send(sockfd, request, strlen(request), 0); // Send GET request to server
}

int main() {
    struct hostent *he; // Host entry struct
    struct sockaddr_in server; // Server socket address struct
    int sockfd; // Server socket file descriptor

    char* url = "www.example.com"; // URL to GET request
    
    if ((he = gethostbyname(url)) == NULL) { // Get host info from DNS
        perror("Error: Failed to get host info.");
        exit(EXIT_FAILURE);
    }
    
    // Create server socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error: Failed to create socket.");
        exit(EXIT_FAILURE);
    }
    
    // Set server socket address parameters
    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    server.sin_addr = *((struct in_addr *)he->h_addr);
    bzero(&(server.sin_zero), 8);
    
    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1) {
        perror("Error: Failed to connect to server.");
        exit(EXIT_FAILURE);
    }

    // Send GET request
    get_request(sockfd, url);
    
    char response[1024]; // Response buffer
    int n = 0; // Number of bytes read from server
    while ((n = recv(sockfd, response, sizeof(response), 0)) > 0) { // Loop until entire response is received
        printf("%.*s", n, response); // Print response
        bzero(response, sizeof(response)); // Clear buffer
    }

    close(sockfd); // Close server socket

    return 0;
}