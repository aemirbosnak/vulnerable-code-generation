//FormAI DATASET v1.0 Category: Simple Web Server ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to handle HTTP requests
void handle_request(int client_socket) {
    char buffer[BUFFER_SIZE] = {0};
    int read_val = read(client_socket, buffer, BUFFER_SIZE);

    if (read_val < 0) {
        printf("Error while reading from socket: %s\n", strerror(errno));
        return;
    }
    
    // Parsing HTTP request
    char method[10], path[50], protocol[10];
    sscanf(buffer, "%s %s %s", method, path, protocol);

    printf("Method: %s\n", method);
    printf("Path: %s\n", path);
    printf("Protocol: %s\n\n", protocol);

    char* response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello World!<h1></body></html>\n";
    int write_val = write(client_socket, response, strlen(response));

    if (write_val < 0) {
        printf("Error while writing to socket: %s\n", strerror(errno));
        return;
    }

    close(client_socket); // Closing client socket
}

int main(int argc, char const *argv[]) {
    int server_fd, client_socket, opt = 1;
    struct sockaddr_in server_addr, client_addr;

    // Creating socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        printf("Error while creating socket: %s\n", strerror(errno));
        return -1;
    }

    // Attaching socket to port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        printf("Error while attaching socket to port: %s\n", strerror(errno));
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Binding socket to address and port
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error while binding socket to address and port: %s\n", strerror(errno));
        return -1;
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        printf("Error while listening for incoming connections: %s\n", strerror(errno));
        return -1;
    }

    printf("Server listening on port %d...\n", PORT);

    while(1) {
        // Accepting incoming connection
        int client_addrlen = sizeof(client_addr);
        if ((client_socket = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&client_addrlen)) < 0) {
            printf("Error while accepting incoming connection: %s\n", strerror(errno));
            continue;
        }

        printf("New client connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Handling HTTP request
        handle_request(client_socket);
    }

    return 0;
}