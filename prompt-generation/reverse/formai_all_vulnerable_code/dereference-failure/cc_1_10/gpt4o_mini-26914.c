//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

// Structure to hold client data
typedef struct {
    int socket;
    struct sockaddr_in address;
} client_data_t;

// Function to log actions
void log_action(const char *action, const char *client_ip) {
    FILE *log_file = fopen("firewall_log.txt", "a");
    if (log_file) {
        fprintf(log_file, "%s from %s\n", action, client_ip);
        fclose(log_file);
    }
}

// Function to handle client connections
void *handle_client(void *arg) {
    client_data_t client_data = *(client_data_t*)arg;
    free(arg);

    char buffer[BUFFER_SIZE];
    int n;
    char *client_ip = inet_ntoa(client_data.address.sin_addr);
    
    log_action("Connected", client_ip);

    while ((n = recv(client_data.socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[n] = '\0'; // Null-terminate the received string

        if (strcmp(buffer, "EXIT\n") == 0) {
            log_action("Disconnected", client_ip);
            break;
        }
        
        log_action("Received", client_ip);
        send(client_data.socket, buffer, n, 0); // Echo back the message
    }

    close(client_data.socket);
    return NULL;
}

// Function to setup server socket
int setup_server_socket() {
    int server_sock;
    struct sockaddr_in server_addr;

    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to bind socket");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    if (listen(server_sock, BACKLOG) == -1) {
        perror("Failed to listen to socket");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    return server_sock;
}

// Main function
int main() {
    int server_sock = setup_server_socket();
    printf("Firewall server running on port %d...\n", PORT);

    while (1) {
        client_data_t *client_data = malloc(sizeof(client_data_t));
        socklen_t addr_len = sizeof(client_data->address);
        client_data->socket = accept(server_sock, (struct sockaddr*)&client_data->address, &addr_len);

        if (client_data->socket == -1) {
            perror("Failed to accept connection");
            free(client_data);
            continue;
        }

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, client_data) != 0) {
            perror("Failed to create thread");
            close(client_data->socket);
            free(client_data);
        } else {
            pthread_detach(thread_id); // Detach thread so resources are freed on completion
        }
    }

    close(server_sock);
    return 0;
}