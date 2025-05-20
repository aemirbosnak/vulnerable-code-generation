//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        exit(0);
    }
    
    // Parse the URL
    char* protocol = strtok(argv[1], "://");
    char* host = strtok(NULL, "/");
    char* path = strtok(NULL, "\0");
    if(!path) path = "/";
    
    // Get the IP address of the server
    struct hostent* server = gethostbyname(host);
    if(!server) {
        printf("Unable to resolve %s\n", host);
        exit(0);
    }
    
    // Create a socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd < 0) {
        printf("Unable to create socket\n");
        exit(0);
    }
    
    // Connect to the server
    struct sockaddr_in server_address;
    memset(&server_address, '0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);
    if(connect(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        printf("Unable to connect to server\n");
        exit(0);
    }
    
    // Build the HTTP request
    char request[MAX_LINE];
    snprintf(request, MAX_LINE, "GET %s HTTP/1.1\nHost: %s\nConnection: close\n\n", path, host);
    
    // Send the request
    send(socket_fd, request, strlen(request), 0);
    
    // Read the response
    char response[MAX_LINE];
    int response_size = 0;
    int read_size;
    while((read_size = recv(socket_fd, response + response_size, MAX_LINE - response_size, 0)) > 0) {
        response_size += read_size;
    }
    response[response_size] = '\0';
    
    // Print the response
    printf("%s", response);
    
    // Close the socket
    close(socket_fd);
    
    return 0;
}