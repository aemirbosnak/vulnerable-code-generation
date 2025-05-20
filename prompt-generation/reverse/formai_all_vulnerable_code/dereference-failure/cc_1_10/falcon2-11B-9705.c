//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define PORT 80

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Failed to create socket\n");
        return 1;
    }
    
    // Set the hostname
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(PORT);
    
    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error: Failed to connect to server\n");
        close(sockfd);
        return 1;
    }
    
    // Send a ping request
    char request[100];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", "localhost");
    write(sockfd, request, strlen(request));
    
    // Receive the response
    char response[1000];
    bzero(response, sizeof(response));
    int n = read(sockfd, response, sizeof(response));
    if (n == -1) {
        printf("Error: Failed to read response\n");
        close(sockfd);
        return 1;
    }
    
    // Print the response
    printf("Response: %s\n", response);
    
    // Close the socket
    close(sockfd);
    return 0;
}