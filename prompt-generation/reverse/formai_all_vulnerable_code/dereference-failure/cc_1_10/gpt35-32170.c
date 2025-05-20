//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Check if URL is provided
    if (argc < 2) {
        fprintf(stderr, "Please provide the URL as an argument.\n");
        return 1;
    }
    
    // Parse URL
    char *url = argv[1];
    char hostname[MAX_BUFFER_SIZE], path[MAX_BUFFER_SIZE];
    int port = 80;
    
    if (strncmp(url, "http://", 7) == 0) {
        url += 7;
    }
    
    char *path_start = strchr(url, '/');
    if (path_start != NULL) {
        strncpy(hostname, url, path_start - url);
        hostname[path_start - url] = '\0';
        strncpy(path, path_start, MAX_BUFFER_SIZE);
    } else {
        strncpy(hostname, url, MAX_BUFFER_SIZE);
        strncpy(path, "/", MAX_BUFFER_SIZE);
    }
    
    char *port_start = strchr(hostname, ':');
    if (port_start != NULL) {
        *port_start = '\0';
        port = atoi(port_start + 1);
    }
    
    printf("Hostname: %s\n", hostname);
    printf("Port: %d\n", port);
    printf("Path: %s\n", path);
    
    // Open socket
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Could not resolve hostname.\n");
        return 1;
    }
    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Could not create socket.\n");
        return 1;
    }
    
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Could not connect to server.\n");
        return 1;
    }
    
    // Send HTTP request
    char request[MAX_BUFFER_SIZE];
    snprintf(request, MAX_BUFFER_SIZE, "GET %s HTTP/1.1\r\n", path);
    send(sockfd, request, strlen(request), 0);
    
    snprintf(request, MAX_BUFFER_SIZE, "Host: %s\r\n", hostname);
    send(sockfd, request, strlen(request), 0);
    
    snprintf(request, MAX_BUFFER_SIZE, "Connection: close\r\n\r\n");
    send(sockfd, request, strlen(request), 0);
    
    // Receive response
    char response[MAX_BUFFER_SIZE];
    int received = 0;
    while ((received = recv(sockfd, response, MAX_BUFFER_SIZE - 1, 0)) > 0) {
        response[received] = '\0';
        printf("%s", response);
    }
    
    // Cleanup
    close(sockfd);
    
    return 0;
}