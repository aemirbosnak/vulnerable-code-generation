//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

typedef struct {
    int socket;
    struct sockaddr_in address;
} client_info;

void *handle_client(void *arg) {
    client_info *client = (client_info *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    printf("Cybernetic connection established with IP: %s, Port: %d\n",
           inet_ntoa(client->address.sin_addr), ntohs(client->address.sin_port));

    while ((bytes_read = read(client->socket, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the string
        printf("Received: %s", buffer);

        // Echo back the received message with cyberpunk flair
        char *response = "Transmitting data through the neon veins...\n";
        write(client->socket, response, strlen(response));
    }

    printf("Connection closed with IP: %s, Port: %d\n",
           inet_ntoa(client->address.sin_addr), ntohs(client->address.sin_port));

    close(client->socket);
    free(client);
    return NULL;
}

void start_server() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_len = sizeof(client_address);
    pthread_t tid;

    // Create server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Set up server address structure
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listening failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Cyberpunk server listening on port %d...\n", PORT);

    while (1) {
        client_info *client = malloc(sizeof(client_info));
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client->address, &client_len)) < 0) {
            perror("Accepting client connection failed");
            free(client);
            continue;
        }

        client->socket = client_socket;
        pthread_create(&tid, NULL, handle_client, client);
        pthread_detach(tid); // No need to join, detach to free resources automatically
    }

    close(server_socket);
}

int main() {
    start_server();
    return 0;
}