//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: ephemeral
// server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void *connection_handler(void *socket_desc) {
    int sock = *(int*)socket_desc;
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate the received string
        printf("Client: %s\n", buffer);
        send(sock, buffer, read_size, 0); // Echo back the message
    }

    if (read_size == 0) {
        perror("Client disconnected");
    } else if (read_size == -1) {
        perror("recv failed");
    }
    
    free(socket_desc);
    close(sock);
    return 0;
}

int main() {
    int server_fd, new_socket, *new_sock;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);

    // Creating socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Could not create socket");
        return 1;
    }
    
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY; 
    server.sin_port = htons(PORT);

    // Bind
    if (bind(server_fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Bind failed");
        return 1;
    }

    // Listen
    listen(server_fd, 3);
    printf("Waiting for connections on port %d...\n", PORT);

    while ((new_socket = accept(server_fd, (struct sockaddr *)&client, &client_len))) {
        printf("Connection accepted\n");
        pthread_t sniffer_thread;
        new_sock = malloc(1);
        *new_sock = new_socket;

        // Handle connection in a new thread
        if (pthread_create(&sniffer_thread, NULL, connection_handler, (void*)new_sock) < 0) {
            perror("Could not create thread");
            return 1;
        }

        // Allow thread to be cleaned up when finished
        pthread_detach(sniffer_thread);
    }

    if (new_socket < 0) {
        perror("Accept failed");
        return 1;
    }

    close(server_fd);
    return 0;
}