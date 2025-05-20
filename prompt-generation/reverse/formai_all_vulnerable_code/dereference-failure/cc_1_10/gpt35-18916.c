//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define HTTP_PORT 80
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        printf("Usage: %s [URL]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    struct hostent *server_addr;
    struct sockaddr_in server;
    
    // Initialize variables
    char *url = strdup(argv[1]);
    char *path = strchr(url, '/');
    char *hostname = url;
    int sockfd, bytes_received;
    char buffer[BUFFER_SIZE];
    
    // Get HTTP hostname and path
    if (path != NULL) {
        *path = '\0';
        path++;
    } else {
        path = "/";
    }
    
    // Get server address info
    server_addr = gethostbyname(hostname);
    if (server_addr == NULL) {
        printf("Could not resolve hostname %s\n", hostname);
        exit(EXIT_FAILURE);
    }
    
    // Fill server address struct
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(HTTP_PORT);
    memcpy(&server.sin_addr.s_addr, server_addr->h_addr, server_addr->h_length);
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed!");
        exit(EXIT_FAILURE);
    }
    
    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Could not connect!");
        exit(EXIT_FAILURE);
    }
    
    // Send HTTP request
    sprintf(buffer, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);
    send(sockfd, buffer, strlen(buffer), 0);
    
    // Receive response
    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE-1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }
    
    // Cleanup
    close(sockfd);
    free(url);
    
    return 0;
}