//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Function to handle client requests
void handle_request(int client_socket) {
    char buffer[1024];
    int num_read = recv(client_socket, buffer, 1024, 0);
    if (num_read <= 0) {
        printf("Error reading from client socket.\n");
        close(client_socket);
        return;
    }
    buffer[num_read] = '\0';
    printf("Request: %s", buffer);

    // Parse the request to extract the target host and port
    char* host_start = strstr(buffer, "Host: ");
    if (host_start == NULL) {
        printf("Error parsing request.\n");
        close(client_socket);
        return;
    }
    host_start += strlen("Host: ");
    char* host_end = strstr(host_start, "\r\n");
    if (host_end == NULL) {
        printf("Error parsing request.\n");
        close(client_socket);
        return;
    }
    *host_end = '\0';
    char* port_start = strstr(host_start, ":");
    char* target_host;
    int target_port;
    if (port_start == NULL) {
        target_host = host_start;
        target_port = 80;
    } else {
        *port_start = '\0';
        target_host = host_start;
        target_port = atoi(port_start + 1);
    }
    printf("Target host: %s\n", target_host);
    printf("Target port: %d\n", target_port);

    // Connect to the target server
    int target_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in target_addr;
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(target_port);
    inet_pton(AF_INET, target_host, &target_addr.sin_addr);
    if (connect(target_socket, (struct sockaddr*) &target_addr, sizeof(target_addr)) < 0) {
        printf("Error connecting to target server.\n");
        close(client_socket);
        close(target_socket);
        return;
    }

    // Forward data between client and target until complete
    if (send(target_socket, buffer, num_read, 0) < 0) {
        printf("Error sending data to target server.\n");
        close(client_socket);
        close(target_socket);
        return;
    }
    while (1) {
        num_read = recv(target_socket, buffer, 1024, 0);
        if (num_read <= 0) {
            break;
        }
        if (send(client_socket, buffer, num_read, 0) < 0) {
            printf("Error sending data to client.\n");
            close(client_socket);
            close(target_socket);
            return;
        }
    }
    close(client_socket);
    close(target_socket);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }
    int proxy_port = atoi(argv[1]);

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        printf("Error creating server socket.\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(proxy_port);

    if (bind(server_socket, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding server socket.\n");
        return 1;
    }

    if (listen(server_socket, 10) < 0) {
        printf("Error listening on server socket.\n");
        return 1;
    }

    printf("Proxy server running on port %d...\n", proxy_port);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) {
            printf("Error accepting client connection.\n");
            continue;
        }
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            handle_request(client_socket);
            return 0;
        } else {
            // Parent process
            close(client_socket);
            continue;
        }
    }

    close(server_socket);
    return 0;
}