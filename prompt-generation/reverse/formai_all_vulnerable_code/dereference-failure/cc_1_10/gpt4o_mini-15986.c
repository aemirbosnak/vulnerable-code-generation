//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void *handle_client(void *socket_desc) {
    int sock = *(int*) socket_desc;
    char client_message[BUFFER_SIZE];
    
    //Receive message from client
    while (recv(sock, client_message, sizeof(client_message), 0) > 0) {
        printf("Client message: %s\n", client_message);
        // Echo the message back to the client
        send(sock, client_message, strlen(client_message), 0);
        memset(client_message, 0, sizeof(client_message));
    }
    
    printf("Client disconnected.\n");
    close(sock);
    free(socket_desc);
    return NULL;
}

int main() {
    int server_fd, new_socket, *new_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Prepare sockaddr_in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    
    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    client_len = sizeof(client_addr);
    while ((new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &client_len))) {
        printf("New connection accepted.\n");
        pthread_t thread_id;
        new_sock = malloc(1);
        *new_sock = new_socket;
        pthread_create(&thread_id, NULL, handle_client, (void*) new_sock);
        pthread_detach(thread_id); // Detach the thread
    }

    if (new_socket < 0) {
        perror("Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    return 0;
}