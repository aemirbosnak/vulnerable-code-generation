//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <stdbool.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 256

// Function prototypes
void *client_handler(void *socket_desc);
bool check_intrusion(const char *log_entry);

int main() {
    int server_fd, new_socket, *new_sock;
    struct sockaddr_in addr;
    int opt = 1;
    int addrlen = sizeof(addr);
    
    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Set address and port
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    // Bind the socket to the network address
    if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept a new connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&addr, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Create a new thread for the client
        pthread_t client_thread;
        new_sock = malloc(1);
        *new_sock = new_socket;
        if (pthread_create(&client_thread, NULL, client_handler, (void*)new_sock) < 0) {
            perror("could not create thread");
            free(new_sock);
            exit(EXIT_FAILURE);
        }
    }
    
    return 0;
}

// Function to handle each client in a separate thread
void *client_handler(void *socket_desc) {
    int sock = *(int*)socket_desc;
    char buffer[BUFFER_SIZE];
    
    // Receive data from the client
    while (1) {
        int read_size = recv(sock, buffer, BUFFER_SIZE - 1, 0);
        if (read_size <= 0) {
            perror("client disconnected or send failed");
            break;
        }

        buffer[read_size] = '\0';  // Null terminate the string

        // Check for intrusion
        if (check_intrusion(buffer)) {
            printf("Intrusion detected: %s\n", buffer);
        } else {
            printf("Log entry received: %s\n", buffer);
        }
    }

    close(sock);
    free(socket_desc);
    return 0;
}

// Function to check for known intrusion patterns
bool check_intrusion(const char *log_entry) {
    const char *intrusion_patterns[] = {
        "failed password",
        "unauthorized access",
        "root login attempt",
        "buffer overflow",
        "sql injection"
    };

    for (size_t i = 0; i < sizeof(intrusion_patterns) / sizeof(intrusion_patterns[0]); i++) {
        if (strstr(log_entry, intrusion_patterns[i]) != NULL) {
            return true;
        }
    }
    return false;
}