//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to configure the firewall
void configure_firewall(int server_fd) {
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Forcefully attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }
}

// Function to check for allowed IP addresses
int check_ip_address(const char *client_ip) {
    // Allowed IP list
    const char *allowed_ips[] = {
        "192.168.1.100",
        "192.168.1.101",
        "192.168.1.102"
    };
    int allowed_count = sizeof(allowed_ips) / sizeof(allowed_ips[0]);

    for (int i = 0; i < allowed_count; i++) {
        if (strcmp(client_ip, allowed_ips[i]) == 0) {
            return 1; // IP is allowed
        }
    }
    return 0; // IP is not allowed
}

// Function to handle incoming connections
void handle_connection(int new_socket) {
    char buffer[BUFFER_SIZE] = {0};
    int read_size;
    
    // Read the data sent by client
    read_size = read(new_socket, buffer, BUFFER_SIZE);
    if (read_size <= 0) {
        perror("Read failed");
        return;
    }
    
    printf("Received: %s\n", buffer);
    
    // Respond back to client
    const char *response = "Message received.";
    send(new_socket, response, strlen(response), 0);
}

// Main function
int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Configure firewall
    configure_firewall(server_fd);

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }
    printf("Listening on port %d...\n", PORT);

    while (1) {
        // Accept incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Convert IP address to string format
        char *client_ip = inet_ntoa(address.sin_addr);
        printf("Connection from %s\n", client_ip);

        // Check if IP is allowed
        if (check_ip_address(client_ip)) {
            printf("IP %s is allowed.\n", client_ip);
            handle_connection(new_socket);
        } else {
            printf("IP %s is denied.\n", client_ip);
            const char *denied_response = "Access Denied.";
            send(new_socket, denied_response, strlen(denied_response), 0);
        }

        // Close the socket for the connection
        close(new_socket);
    }

    // Close the server socket
    close(server_fd);
    return 0;
}