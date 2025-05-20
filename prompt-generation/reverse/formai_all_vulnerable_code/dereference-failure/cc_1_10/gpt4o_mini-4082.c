//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

typedef struct {
    int socket;
    struct sockaddr_in address;
} client_t;

pthread_mutex_t lock;
int active_connections = 0;

void* handle_client(void* args) {
    client_t* client_data = (client_t*)args;
    char buffer[BUFFER_SIZE];
    int client_sock = client_data->socket;

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int read_size = recv(client_sock, buffer, BUFFER_SIZE, 0);
        if (read_size <= 0) {
            pthread_mutex_lock(&lock);
            active_connections--;
            printf("Client disconnected. Active connections: %d\n", active_connections);
            pthread_mutex_unlock(&lock);
            break;
        }
        
        printf("Received message: %s", buffer);

        if (strstr(buffer, "BLOCK") != NULL) {
            // Simulate blocking functionality
            send(client_sock, "Blocking access...\n", 20, 0);
        } else {
            send(client_sock, "Message received.\n", 18, 0);
        }
    }
    close(client_sock);
    free(client_data);
    return NULL;
}

int main() {
    int server_sock, client_sock, addr_len, option = 1;
    struct sockaddr_in server_addr, client_addr;

    // Initialize mutex
    if (pthread_mutex_init(&lock, NULL) != 0) {
        perror("Mutex initialization failed");
        return EXIT_FAILURE;
    }

    // Create socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    // Set socket options
    if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option)) < 0) {
        perror("Set socket options failed");
        close(server_sock);
        return EXIT_FAILURE;
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_sock);
        return EXIT_FAILURE;
    }

    // Start listening for incoming connections
    if (listen(server_sock, MAX_CLIENTS) < 0) {
        perror("Listening failed");
        close(server_sock);
        return EXIT_FAILURE;
    }

    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        addr_len = sizeof(client_addr);
        client_sock = accept(server_sock, (struct sockaddr*)&client_addr, (socklen_t*)&addr_len);
        if (client_sock < 0) {
            perror("Failed to accept connection");
            continue;
        }

        pthread_mutex_lock(&lock);
        active_connections++;
        printf("Client connected. Active connections: %d\n", active_connections);
        pthread_mutex_unlock(&lock);

        client_t* client_data = malloc(sizeof(client_t));
        client_data->socket = client_sock;
        client_data->address = client_addr;

        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, (void*)client_data) != 0) {
            perror("Failed to create thread");
            close(client_sock);
            free(client_data);
            continue;
        }
        pthread_detach(tid); // Automatically free thread resources when finished
    }

    // Cleanup
    close(server_sock);
    pthread_mutex_destroy(&lock);

    return EXIT_SUCCESS;
}