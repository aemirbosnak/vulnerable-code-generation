//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024 // Set buffer size to 1024 bytes

// Function to send HTTP request to web server
void send_http_request(int client_sock, char *http_request) {
    char buffer[BUFFER_SIZE];
    int bytes_sent = 0;
    int total_bytes_sent = 0;

    // Send HTTP request to the web server
    bytes_sent = send(client_sock, http_request, strlen(http_request), 0);

    while (total_bytes_sent < strlen(http_request)) {
        if (bytes_sent == -1) {
            perror("Error sending HTTP request");
            exit(1);
        }
        total_bytes_sent += bytes_sent;
        bytes_sent = send(client_sock, http_request + total_bytes_sent, 
                   strlen(http_request) - total_bytes_sent, 0);
    }
}

// Function to receive HTTP response from web server
void receive_http_response(int client_sock, int server_sock) {
    char buffer[BUFFER_SIZE];
    int bytes_recv = 0;

    // Receive HTTP response from the web server
    while ((bytes_recv = recv(server_sock, buffer, BUFFER_SIZE, 0)) > 0) {
        send(client_sock, buffer, bytes_recv, 0);
        memset(buffer, 0, BUFFER_SIZE);
    }

    if (bytes_recv == -1) {
        perror("Error receiving HTTP response");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    int client_sock, server_sock, port;
    struct sockaddr_in client_addr, server_addr;
    char buffer[BUFFER_SIZE], http_request[BUFFER_SIZE];
    int bytes_recv;
    socklen_t client_addr_len;

    // Check command line arguments
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // Convert port number to integer
    port = atoi(argv[1]);

    // Create socket for the proxy server
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    // Bind socket to port number
    if (bind(server_sock, (struct sockaddr *) &server_addr, 
         sizeof(server_addr)) == -1) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_sock, SOMAXCONN) == -1) {
        perror("Error listening for incoming connections");
        exit(1);
    }

    while (1) {
        client_addr_len = sizeof(client_addr);

        // Accept incoming connections
        client_sock = accept(server_sock, (struct sockaddr *) &client_addr, 
                      &client_addr_len);

        if (client_sock == -1) {
            perror("Error accepting incoming connection");
            exit(1);
        }

        // Receive HTTP request from client
        bytes_recv = recv(client_sock, buffer, BUFFER_SIZE, 0);
        strcpy(http_request, buffer);

        // Forward HTTP request to web server
        server_sock = socket(AF_INET, SOCK_STREAM, 0);
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Web server IP address
        server_addr.sin_port = htons(port); // Web server port number

        if (connect(server_sock, (struct sockaddr *) &server_addr, 
            sizeof(server_addr)) == -1) {
            perror("Error connecting to web server");
            exit(1);
        }

        send_http_request(server_sock, http_request);
        receive_http_response(client_sock, server_sock);

        // Close sockets
        close(client_sock);
        close(server_sock);
    }

    return 0;
}