//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 8888
#define BUFFER_SIZE 4096

void handle_client(int client_socket);
void error(const char *msg);
void send_to_server(int server_socket, char *request);
void receive_from_server(int server_socket, int client_socket);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) error("Socket creation failed");
    
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) 
        error("Binding failed");
    
    listen(server_socket, 5);
    printf("Proxy server listening on port %d...\n", PORT);
    
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);
        if (client_socket < 0) error("Accept failed");
        
        printf("Accepted connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        handle_client(client_socket);
        close(client_socket);
    }
    
    close(server_socket);
    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    bytes_read = recv(client_socket, buffer, sizeof(buffer)-1, 0);
    if (bytes_read < 0) error("Error reading from socket");
    buffer[bytes_read] = '\0';
    
    char *method = strtok(buffer, " ");
    char *url = strtok(NULL, " ");
    char *protocol = strtok(NULL, "\r\n");
    
    if (strcmp(method, "GET") != 0) {
        printf("Only GET method is supported.\n");
        return;
    }
    
    printf("Request for URL: %s\n", url);
    
    char hostname[BUFFER_SIZE];
    int port = 80;
    sscanf(url, "http://%[^:]:%d", hostname, &port);
    
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) error("Socket creation for server failed");
    
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);
    
    if (connect(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection to server failed");
    }
    
    send_to_server(server_socket, buffer);
    receive_from_server(server_socket, client_socket);
    
    close(server_socket);
}

// Function to send the request to the actual server
void send_to_server(int server_socket, char *request) {
    send(server_socket, request, strlen(request), 0);
}

// Function to receive the server's response and send it back to the client
void receive_from_server(int server_socket, int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;
    
    while ((bytes_received = recv(server_socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        send(client_socket, buffer, bytes_received, 0);
    }
}

// Function to handle errors
void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}