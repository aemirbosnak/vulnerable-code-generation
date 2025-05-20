//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 1024

// Function to send HTTP request and receive response
void send_http_request(char* hostname, char* path) {
    struct hostent* server = gethostbyname(hostname); // Get IP address of the host
    if (server == NULL) {
        printf("Error: Host not found\n");
        exit(0);
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Could not create socket\n");
        exit(0);
    }

    // Connect to server
    struct sockaddr_in server_address;
    bzero((char*)&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char*)server->h_addr, (char*)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(80);
    if (connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        printf("Error: Could not connect to server\n");
        exit(0);
    }

    // Construct HTTP request
    char request[MAX_BUFFER_SIZE];
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    // Send HTTP request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        printf("Error: Could not send request\n");
        exit(0);
    }

    // Receive HTTP response
    char buffer[MAX_BUFFER_SIZE];
    bzero(buffer, MAX_BUFFER_SIZE);
    int n;
    while ((n = recv(sockfd, buffer, MAX_BUFFER_SIZE-1, 0)) > 0) {
        printf("%s", buffer);
        bzero(buffer, MAX_BUFFER_SIZE);
    }
}

int main() {
    char hostname[] = "www.example.com";
    char path[] = "/";
    send_http_request(hostname, path);
    return 0;
}