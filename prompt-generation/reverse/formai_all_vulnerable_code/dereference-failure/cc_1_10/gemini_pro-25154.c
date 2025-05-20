//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define the HTTP request message
#define HTTP_REQUEST "GET /index.html HTTP/1.1\r\nHost: example.com\r\n\r\n"

// Define the HTTP response buffer size
#define HTTP_RESPONSE_BUFFER_SIZE 1024

int main() {
    // Get the hostname and port number from the user
    char hostname[100];
    int port;
    printf("Enter the hostname: ");
    scanf("%s", hostname);
    printf("Enter the port number: ");
    scanf("%d", &port);

    // Resolve the hostname to an IP address
    struct hostent *host = gethostbyname(hostname);
    if (!host) {
        printf("Error: Could not resolve hostname\n");
        return 1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Could not create socket\n");
        return 1;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Could not connect to server\n");
        return 1;
    }

    // Send the HTTP request
    if (send(sockfd, HTTP_REQUEST, strlen(HTTP_REQUEST), 0) == -1) {
        printf("Error: Could not send HTTP request\n");
        return 1;
    }

    // Receive the HTTP response
    char http_response[HTTP_RESPONSE_BUFFER_SIZE];
    int bytes_received = recv(sockfd, http_response, HTTP_RESPONSE_BUFFER_SIZE - 1, 0);
    if (bytes_received == -1) {
        printf("Error: Could not receive HTTP response\n");
        return 1;
    }

    // Print the HTTP response
    http_response[bytes_received] = '\0';
    printf("%s", http_response);

    // Close the socket
    close(sockfd);

    return 0;
}