//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <signal.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int client_sockets[MAX_CLIENTS];
pthread_mutex_t lock;

void *client_handler(void *socket_desc);
void add_client_socket(int socket);
void remove_client_socket(int socket);
void broadcast_message(const char *message, int sender_socket);

int main() {
    int server_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    int opt = 1;
    
    // Initialize the mutex
    pthread_mutex_init(&lock, NULL);

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    
    // Bind socket to the port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    
    printf("Chat server is running on port %d...\n", PORT);

    while (1) {
        int new_socket;
        if ((new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("Accept failed");
            continue;
        }
        
        add_client_socket(new_socket);
        
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, client_handler, (void *)&new_socket) != 0) {
            perror("Thread creation failed");
            remove_client_socket(new_socket);
            continue;
        }
    }
    
    // Cleanup
    pthread_mutex_destroy(&lock);
    close(server_fd);
    return 0;
}

void *client_handler(void *socket_desc) {
    int sock = *(int *)socket_desc;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = read(sock, buffer, sizeof(buffer))) > 0) {
        buffer[bytes_read] = '\0';
        printf("Received message: %s\n", buffer);
        broadcast_message(buffer, sock);
    }
    
    if (bytes_read == 0) {
        printf("Client disconnected\n");
    } else {
        perror("Read failed");
    }
    
    remove_client_socket(sock);
    close(sock);
    return NULL;
}

void add_client_socket(int socket) {
    pthread_mutex_lock(&lock);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] == 0) {
            client_sockets[i] = socket;
            break;
        }
    }
    pthread_mutex_unlock(&lock);
    printf("Client connected: socket %d\n", socket);
}

void remove_client_socket(int socket) {
    pthread_mutex_lock(&lock);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] == socket) {
            client_sockets[i] = 0;
            break;
        }
    }
    pthread_mutex_unlock(&lock);
    printf("Client disconnected: socket %d\n", socket);
}

void broadcast_message(const char *message, int sender_socket) {
    pthread_mutex_lock(&lock);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] != 0 && client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&lock);
}