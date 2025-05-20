//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <pthread.h>
#include <time.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

typedef struct {
    int client_socket;
    struct sockaddr_in client_addr;
} client_info_t;

void *handle_client(void *arg);
void log_event(const char *message);
void calculate_qos_metrics(int client_socket);

pthread_mutex_t log_mutex = PTHREAD_MUTEX_INITIALIZER;

int main() {
    int server_socket;
    struct sockaddr_in server_addr;
    
    // Creating socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting up the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    // Binding the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    log_event("Server started, waiting for connections...");

    while (1) {
        client_info_t *client_info = malloc(sizeof(client_info_t));
        socklen_t addr_len = sizeof(client_info->client_addr);
        
        // Accepting a client connection
        client_info->client_socket = accept(server_socket, (struct sockaddr *)&client_info->client_addr, &addr_len);
        if (client_info->client_socket < 0) {
            perror("Accept failed");
            free(client_info);
            continue;
        }

        log_event("New client connected");

        // Creating a thread to handle the client
        pthread_t client_thread;
        if (pthread_create(&client_thread, NULL, handle_client, (void *)client_info) != 0) {
            perror("Thread creation failed");
            close(client_info->client_socket);
            free(client_info);
            continue;
        }

        pthread_detach(client_thread); // Detach the thread so we won't have to join later
    }

    // Clean up
    close(server_socket);
    return 0;
}

void *handle_client(void *arg) {
    client_info_t *client_info = (client_info_t *)arg;
    char buffer[BUFFER_SIZE];
    
    // Continuously receive data from the client
    while (1) {
        ssize_t received = recv(client_info->client_socket, buffer, BUFFER_SIZE - 1, 0);
        if (received <= 0) {
            break; // Connection closed or error occurred
        }
        
        buffer[received] = '\0'; // Null-terminate the received string
        printf("Received data: %s\n", buffer);
        
        // Calculate QoS metrics based on received data
        calculate_qos_metrics(client_info->client_socket);
    }

    // Clean up resources
    log_event("Client disconnected");
    close(client_info->client_socket);
    free(client_info);
    return NULL;
}

void log_event(const char *message) {
    pthread_mutex_lock(&log_mutex);
    
    time_t now = time(NULL);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0'; // Remove newline
    
    printf("%s - %s\n", time_str, message);
    
    pthread_mutex_unlock(&log_mutex);
}

void calculate_qos_metrics(int client_socket) {
    // Example placeholder for QoS metrics calculation
    // Here you can implement metrics such as latency, jitter, packet loss, etc.
    log_event("Calculating QoS metrics...");
    // Simulate some metrics calculation
    sleep(1);
}