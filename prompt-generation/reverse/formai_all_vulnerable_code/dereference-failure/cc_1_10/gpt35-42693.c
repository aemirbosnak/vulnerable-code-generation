//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }
    
    char *hostname = argv[1];
    int port = atoi(argv[2]);
    
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }
    
    // Get host information
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        printf("Error: No such host named '%s'\n", hostname);
        exit(1);
    }
    
    // Set server address
    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(port);
    
    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }
    
    // Send HTTP GET request
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE);
    sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", hostname);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending data to server");
        exit(1);
    }
    
    // Receive response
    memset(buffer, 0, MAX_BUFFER_SIZE);
    int n;
    while ((n = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }
    
    // Close socket
    close(sockfd);
    
    return 0;
}