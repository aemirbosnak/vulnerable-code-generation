//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define CLIENT_LIMIT 5

void *client_handler(void *socket_desc) {
    int sock = *(int *)socket_desc;
    char client_message[BUFFER_SIZE];
    int read_size;

    // Receive messages from the client
    while ((read_size = recv(sock, client_message, BUFFER_SIZE, 0)) > 0) {
        client_message[read_size] = '\0'; // Null-terminate the received data
        printf("Client: %s\n", client_message);

        // Echo the message back to the client
        write(sock, client_message, strlen(client_message));
    }

    if (read_size == 0) {
        printf("Client disconnected.\n");
    } else if (read_size == -1) {
        perror("recv failed");
    }

    free(socket_desc);
    close(sock);
    return NULL;
}

int main() {
    int server_fd, new_sock;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Could not create socket");
        return 1;
    }

    // Set up the server structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Bind failed");
        return 1;
    }

    // Listen for connections
    listen(server_fd, CLIENT_LIMIT);
    printf("Server is listening on port %d...\n", PORT);

    // Accept incoming connections
    while (1) {
        new_sock = accept(server_fd, (struct sockaddr *)&client, &client_len);
        if (new_sock < 0) {
            perror("Accept failed");
            continue;
        }

        printf("Connection accepted from %s:%d\n", 
               inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        // Create a thread for each client
        pthread_t client_thread;
        int *new_sock_ptr = malloc(1);
        *new_sock_ptr = new_sock;

        if (pthread_create(&client_thread, NULL, client_handler, (void *)new_sock_ptr) < 0) {
            perror("Could not create thread");
            return 1;
        }

        pthread_detach(client_thread); // Automatically reclaim resources when done
    }

    // Close the socket (this code will never be reached in the infinite loop)
    close(server_fd);
    return 0;
}