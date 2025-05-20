//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

int client_count = 0;
pthread_mutex_t client_mutex = PTHREAD_MUTEX_INITIALIZER;
int client_sockets[MAX_CLIENTS];

void *client_handler(void *socket_desc) {
    int sock = *(int *)socket_desc;
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        buffer[read_size] = '\0';

        // Lock access to the shared client_sockets array
        pthread_mutex_lock(&client_mutex);
        for (int i = 0; i < client_count; i++) {
            if (client_sockets[i] != sock) {
                send(client_sockets[i], buffer, strlen(buffer), 0);
            }
        }
        pthread_mutex_unlock(&client_mutex);
    }

    // Handle socket disconnection
    if (read_size == 0) {
        printf("Client disconnected: %d\n", sock);
        close(sock);
        
        // Remove from client list
        pthread_mutex_lock(&client_mutex);
        for (int i = 0; i < client_count; i++) {
            if (client_sockets[i] == sock) {
                client_sockets[i] = client_sockets[client_count - 1];
                client_count--;
                break;
            }
        }
        pthread_mutex_unlock(&client_mutex);
    }

    free(socket_desc);
    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set socket options error");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    printf("Server listening on port %d\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("Accept failed");
            continue;
        }

        printf("New client connected: %d\n", new_socket);

        pthread_mutex_lock(&client_mutex);
        if (client_count < MAX_CLIENTS) {
            client_sockets[client_count++] = new_socket;
            pthread_t thread_id;
            int *new_sock = malloc(1);
            *new_sock = new_socket;
            if (pthread_create(&thread_id, NULL, client_handler, (void *)new_sock) < 0) {
                perror("Thread creation error");
            }
        } else {
            printf("Maximum clients connected. Connection refused for socket %d\n", new_socket);
            close(new_socket);
        }
        pthread_mutex_unlock(&client_mutex);
    }
    
    return 0;
}