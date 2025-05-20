//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080

// Structure to hold thread data
typedef struct {
    int client_fd;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len;
} client_data;

// Thread function to handle client connections
void* handle_client(void* arg) {
    client_data* data = (client_data*)arg;
    int client_fd = data->client_fd;
    struct sockaddr_in client_addr = data->client_addr;
    socklen_t client_addr_len = data->client_addr_len;
    free(data); // Free the allocated memory

    // Receive message from client
    char buffer[1024];
    int bytes_received = recv(client_fd, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        perror("recv");
        close(client_fd);
        return NULL;
    }

    // Process client message
    printf("Received message: %s\n", buffer);
    char response[] = "Hello from the server!";
    int bytes_sent = send(client_fd, response, strlen(response), 0);
    if (bytes_sent < 0) {
        perror("send");
        close(client_fd);
        return NULL;
    }

    // Close client connection
    close(client_fd);
    return NULL;
}

int main() {
    // Create server socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set server socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Bind server socket to address and port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, SOMAXCONN) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Accept incoming connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_fd < 0) {
            perror("accept");
            continue;
        }

        // Create thread to handle client connection
        pthread_t thread;
        client_data* data = malloc(sizeof(client_data));
        data->client_fd = client_fd;
        data->client_addr = client_addr;
        data->client_addr_len = client_addr_len;
        if (pthread_create(&thread, NULL, handle_client, (void*)data) != 0) {
            perror("pthread_create");
            close(client_fd);
            continue;
        }
    }

    // Close server socket
    close(server_fd);

    return 0;
}