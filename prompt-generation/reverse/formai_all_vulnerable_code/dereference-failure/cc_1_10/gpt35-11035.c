//FormAI DATASET v1.0 Category: Simple Web Server ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

void *connection_handler(void *);

int main(int argc, char *argv[]) {
    int socket_desc, client_sock, c, *new_sock;
    struct sockaddr_in server, client;
    
    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
        return 1;
    }

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    // Bind
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Bind failed");
        return 1;
    }

    // Listen
    listen(socket_desc, 3);
    printf("Server listening on port 8888...\n");

    // Accept incoming connections
    c = sizeof(struct sockaddr_in);
    while ((client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c))) {
        printf("New client connected\n");

        // Create a new thread for each client
        pthread_t sniffer_thread;
        new_sock = malloc(1);
        *new_sock = client_sock;

        if (pthread_create(&sniffer_thread, NULL, connection_handler, (void *)new_sock) < 0) {
            perror("Could not create thread");
            return 1;
        }

        printf("Thread created for client\n");
    }

    if (client_sock < 0) {
        perror("Accept failed");
        return 1;
    }

    return 0;
}

/*
 * This will handle connection for each client
 * */
void *connection_handler(void *socket_desc) {
    // Get the socket descriptor
    int sock = *(int *)socket_desc;
    int read_size;
    char client_message[2000];

    // Send message to the client
    char *message = "Connected to the server!\r\n";
    write(sock, message, strlen(message));

    // Receive messages from the client
    while ((read_size = recv(sock, client_message, 2000, 0)) > 0) {
        // Null terminate the string
        client_message[read_size] = '\0';

        // Send the message back to client
        write(sock, client_message, strlen(client_message));
    }

    if (read_size == 0) {
        puts("Client disconnected");
        fflush(stdout);
    } else if (read_size == -1) {
        perror("Receive failed");
    }

    // Free the socket pointer
    free(socket_desc);

    return 0;
}