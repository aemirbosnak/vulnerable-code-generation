//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define BUFFER_SIZE 256

void error_handling(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

// Server function
void tcp_server() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[BUFFER_SIZE];

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error_handling("Socket creation failed");
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_handling("Bind failed");
    }

    // Listen for incoming connections
    if (listen(server_fd, 10) < 0) {
        error_handling("Listen failed");
    }
    printf("Server is listening on port %d...\n", PORT);

    // Accept a connection
    addr_size = sizeof(client_addr);
    if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_size)) < 0) {
        error_handling("Accept failed");
    }

    // Communicate with the client
    ssize_t bytes_received;
    while ((bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';  // Null-terminate the string
        printf("Received from client: %s\n", buffer);

        // Echo back the message
        send(client_fd, buffer, bytes_received, 0);
    }

    // Cleanup
    close(client_fd);
    close(server_fd);
    printf("Server closed.\n");
}

// Client function
void tcp_client(const char *server_ip) {
    int client_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error_handling("Socket creation failed");
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        error_handling("Invalid address or address not supported");
    }

    // Connect to the server
    if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_handling("Connection failed");
    }

    // Communicate with the server
    while (1) {
        printf("Enter message to send (or 'exit' to quit): ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0;  // Remove trailing newline

        // Exit loop if user types "exit"
        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        send(client_fd, buffer, strlen(buffer), 0);

        // Receive response from server
        ssize_t bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            error_handling("Connection closed by server");
        }
        buffer[bytes_received] = '\0';  // Null-terminate the string
        printf("Echo from server: %s\n", buffer);
    }

    // Cleanup
    close(client_fd);
    printf("Client closed.\n");
}

// Main function
int main(int argc, char *argv[]) {
    // Check for correct usage
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <server|client> [server_ip]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "server") == 0) {
        tcp_server();
    } else if (strcmp(argv[1], "client") == 0) {
        if (argc != 3) {
            fprintf(stderr, "Usage for client: %s client <server_ip>\n", argv[0]);
            exit(EXIT_FAILURE);
        }
        tcp_client(argv[2]);
    } else {
        fprintf(stderr, "Invalid argument: %s\n", argv[1]);
        fprintf(stderr, "Please use 'server' or 'client'\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}