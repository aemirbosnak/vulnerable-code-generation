//FormAI DATASET v1.0 Category: Simple Web Server ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8080
#define MAX_REQUEST_SIZE 2048

char* read_request(int client_socket) {
    char* request = malloc(sizeof(char) * MAX_REQUEST_SIZE);
    int size = 0;
    char buffer[1];
    while (recv(client_socket, buffer, 1, 0) > 0) {
        request[size++] = buffer[0];
        if (buffer[0] == '\n') {
            break;
        }
    }
    request[size] = '\0';
    return request;
}

void handle_request(int client_socket) {
    char* request = read_request(client_socket);
    printf("Received request: %s", request);
    char* response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello, World!</h1></body></html>";
    send(client_socket, response, strlen(response), 0);
    free(request);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Listening on port %d...\n", PORT);
    
    while (1) {
        if ((client_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        
        handle_request(client_socket);
        
        close(client_socket);
    }
    
    return 0;
}