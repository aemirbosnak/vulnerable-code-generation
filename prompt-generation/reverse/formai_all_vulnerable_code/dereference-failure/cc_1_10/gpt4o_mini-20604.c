//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <time.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Structure to hold client information
typedef struct {
    int socket;
    struct sockaddr_in address;
    int addr_len;
} client_t;

client_t *clients[MAX_CLIENTS];

void *handle_client(void *arg);
int calculate_checksum(const char *msg);

int main() {
    int server_fd, new_socket, opt = 1;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Define server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for connections...\n");
    
    while (1) {
        // Accept a new client
        client_t *new_client = (client_t *)malloc(sizeof(client_t));
        new_client->addr_len = sizeof(new_client->address);
        new_client->socket = accept(server_fd, (struct sockaddr *)&new_client->address, (socklen_t*)&new_client->addr_len);
        
        if (new_client->socket < 0) {
            perror("accept");
            free(new_client);
            continue;
        }
        
        printf("New connection accepted: Socket fd is %d\n", new_client->socket);
        
        // Assign client to a thread
        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, (void *)new_client) != 0) {
            perror("pthread_create");
            free(new_client);
        }
        
        // Detached thread to prevent resource leaking
        pthread_detach(tid);
    }
    
    return 0;
}

void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;
    
    while ((bytes_read = read(client->socket, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0';

        // Calculate checksum and verify
        int checksum_received = atoi(buffer + bytes_read - 4);
        buffer[bytes_read - 4] = '\0'; // Remove checksum from message 

        if (calculate_checksum(buffer) == checksum_received) {
            printf("Received message: %s\n", buffer);
            snprintf(buffer, sizeof(buffer), "Message received: %s", buffer);
            write(client->socket, buffer, strlen(buffer));
        } else {
            char *error_msg = "Checksum verification failed";
            write(client->socket, error_msg, strlen(error_msg));
        }
    }
    
    printf("Client disconnected: Socket fd is %d\n", client->socket);
    close(client->socket);
    free(client);
    return NULL;
}

int calculate_checksum(const char *msg) {
    int checksum = 0;
    while (*msg) {
        checksum += *msg++;
    }
    return checksum % 100; // Simple checksum mechanism (0-99)
}