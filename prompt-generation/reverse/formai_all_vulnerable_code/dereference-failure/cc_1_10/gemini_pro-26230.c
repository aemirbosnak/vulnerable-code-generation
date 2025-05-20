//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 80
#define MAX_BUF_SIZE 1024

int main() {
    // Get the server's IP address
    struct hostent *server = gethostbyname("www.example.com");
    if (server == NULL) {
        fprintf(stderr, "Error: Could not resolve hostname.\n");
        return 1;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        fprintf(stderr, "Error: Could not create socket.\n");
        return 1;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy((char *)&server_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error: Could not connect to server.\n");
        return 1;
    }

    // Send a HTTP request to the server
    char request[MAX_BUF_SIZE];
    sprintf(request, "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n");

    if (send(sock, request, strlen(request), 0) < 0) {
        fprintf(stderr, "Error: Could not send request to server.\n");
        return 1;
    }

    // Receive the server's response
    char response[MAX_BUF_SIZE];
    int bytes_received = recv(sock, response, MAX_BUF_SIZE, 0);
    if (bytes_received < 0) {
        fprintf(stderr, "Error: Could not receive response from server.\n");
        return 1;
    }

    // Print the server's response to the console
    printf("%s\n", response);

    // Close the socket
    close(sock);

    return 0;
}