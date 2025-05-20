//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    // Check command-line arguments
    if (argc != 2) {
        printf("Usage: %s hostname\n", argv[0]);
        return 1;
    }
    
    // Create a socket for the HTTP connection
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Failed to create socket");
        return 1;
    }
    
    // Get the IP address of the hostname
    struct hostent *host_info = gethostbyname(argv[1]);
    if (!host_info) {
        printf("Failed to get IP address for hostname %s\n", argv[1]);
        return 1;
    }
    
    // Set up the server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    memcpy(&server_addr.sin_addr, host_info->h_addr_list[0], host_info->h_length);
    
    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        return 1;
    }
    
    // Send an HTTP GET request for the root page
    const char *request = "GET / HTTP/1.0\r\n\r\n";
    if (send(sock, request, strlen(request), 0) < 0) {
        perror("Failed to send HTTP request");
        return 1;
    }
    
    // Receive the response from the server
    char response[4096];
    memset(response, 0, sizeof(response));
    if (recv(sock, response, sizeof(response), 0) < 0) {
        perror("Failed to receive HTTP response");
        return 1;
    }
    
    // Print the HTTP response
    printf("HTTP response:\n%s", response);
    
    // Close the socket
    close(sock);
    
    return 0;
}