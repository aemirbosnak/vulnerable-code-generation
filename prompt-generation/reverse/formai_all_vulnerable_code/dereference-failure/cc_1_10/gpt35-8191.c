//FormAI DATASET v1.0 Category: Simple Web Server ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_REQUEST_LENGTH 1024
#define MAX_RESPONSE_LENGTH 4096
#define SERVER_NAME "Dynamic Web Server"
#define SERVER_PORT "8080"
#define DEFAULT_ROOT "/var/www/html"

void handle_client(int client_socket);
void send_response(int client_socket, const char *response, ...);
void send_file_response(int client_socket, const char *file_path);
void send_error_response(int client_socket, int error_code, const char *error_message);

int main(int argc, char **argv) {
    // Create a socket for listening to incoming requests
    int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server_socket == -1) {
        perror("socket");
        exit(1);
    }
    
    // Set up server address
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    struct addrinfo *server_address;
    int getaddr_result = getaddrinfo(NULL, SERVER_PORT, &hints, &server_address);
    if (getaddr_result != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(getaddr_result));
        exit(1);
    }
    
    // Bind server socket to server address
    int bind_result = bind(server_socket, server_address->ai_addr, server_address->ai_addrlen);
    if (bind_result == -1) {
        perror("bind");
        exit(1);
    }
    freeaddrinfo(server_address);
    
    // Listen for incoming requests
    int listen_result = listen(server_socket, SOMAXCONN);
    if (listen_result == -1) {
        perror("listen");
        exit(1);
    }
    
    printf("Server running on port %s\n", SERVER_PORT);
    
    while (1) {
        // Accept incoming request
        struct sockaddr_in client_address;
        socklen_t client_address_size = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }
        
        // Handle client request
        handle_client(client_socket);
        
        // Close client socket
        close(client_socket);
    }
    
    // Close server socket (never actually reached)
    close(server_socket);
    return 0;
}

void handle_client(int client_socket) {
    // Receive request
    char request[MAX_REQUEST_LENGTH];
    memset(request, 0, sizeof(request));
    int recv_result = recv(client_socket, request, sizeof(request) - 1, 0);
    if (recv_result == -1) {
        perror("recv");
        return;
    }
    
    // Extract request method and path
    char method[16];
    char path[MAX_REQUEST_LENGTH];
    sscanf(request, "%s %s", method, path);
    
    // Set default file path (index.html in root directory)
    char file_path[MAX_REQUEST_LENGTH];
    sprintf(file_path, "%s%s", DEFAULT_ROOT, path);
    if (strlen(path) == 1 && path[0] == '/') {
        strcat(file_path, "index.html");
    }
    
    // Send response
    if (strcmp(method, "GET") == 0) {
        send_file_response(client_socket, file_path);
    } else {
        send_error_response(client_socket, 405, "Method Not Allowed");
    }
}

void send_response(int client_socket, const char *response, ...) {
    char formatted_response[MAX_RESPONSE_LENGTH];
    va_list arg_list;
    va_start(arg_list, response);
    vsnprintf(formatted_response, sizeof(formatted_response), response, arg_list);
    va_end(arg_list);
    send(client_socket, formatted_response, strlen(formatted_response), 0);
}

void send_file_response(int client_socket, const char *file_path) {
    // Open file
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        send_error_response(client_socket, 404, "File Not Found");
        return;
    }
    
    // Read file into buffer
    char buffer[MAX_RESPONSE_LENGTH];
    memset(buffer, 0, sizeof(buffer));
    size_t read_result = fread(buffer, 1, sizeof(buffer), file);
    fclose(file);
    
    if (read_result == 0) {
        send_error_response(client_socket, 500, "Internal Server Error");
        return;
    }
    
    // Send response
    send_response(client_socket, "HTTP/1.1 200 OK\r\n");
    send_response(client_socket, "Server: %s\r\n", SERVER_NAME);
    send_response(client_socket, "Content-Type: text/html\r\n");
    send_response(client_socket, "Content-Length: %zd\r\n", read_result);
    send_response(client_socket, "\r\n");
    send(client_socket, buffer, read_result, 0);
}

void send_error_response(int client_socket, int error_code, const char *error_message) {
    send_response(client_socket, "HTTP/1.1 %d %s\r\n", error_code, error_message);
    send_response(client_socket, "Server: %s\r\n", SERVER_NAME);
    send_response(client_socket, "Content-Type: text/plain\r\n");
    send_response(client_socket, "Connection: close\r\n");
    send_response(client_socket, "\r\n");
    send_response(client_socket, "%s\r\n", error_message);
}