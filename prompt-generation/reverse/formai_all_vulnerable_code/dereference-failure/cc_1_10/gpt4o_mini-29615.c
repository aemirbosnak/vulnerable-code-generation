//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

// Simple firewall rule check
int check_firewall_rule(const char *ip) {
    const char *blocked_ip = "192.168.1.100"; // Example blocked IP
    if (strcmp(ip, blocked_ip) == 0) {
        return 0; // Blocked
    }
    return 1; // Allowed
}

// Client handler function
void *client_handler(void *socket_desc) {
    int sock = *(int *)socket_desc;
    char buffer[BUFFER_SIZE];
    char client_ip[INET_ADDRSTRLEN];
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);

    // Get client IP
    getpeername(sock, (struct sockaddr *)&addr, &addr_len);
    inet_ntop(AF_INET, &addr.sin_addr, client_ip, sizeof(client_ip));

    // Receive message from client
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int read_size = recv(sock, buffer, BUFFER_SIZE, 0);
        if (read_size <= 0) {
            break; // Client disconnected
        }
        
        // Check against firewall rules
        if (check_firewall_rule(client_ip)) {
            printf("Allowed access from %s: %s\n", client_ip, buffer);
            send(sock, "Message received", 16, 0);
        } else {
            printf("Blocked access from %s: %s\n", client_ip, buffer);
            send(sock, "Access denied", 13, 0);
        }
    }

    close(sock);
    free(socket_desc);
    return 0;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    pthread_t thread_id;

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Firewall server started. Listening on port %d...\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("accept");
            close(server_fd);
            exit(EXIT_FAILURE);
        }

        // Create a thread for the new client
        int *new_sock = malloc(1);
        *new_sock = new_socket;
        if (pthread_create(&thread_id, NULL, client_handler, (void *)new_sock) < 0) {
            perror("could not create thread");
            free(new_sock);
            close(new_socket);
        }
    }

    close(server_fd);
    return 0;
}