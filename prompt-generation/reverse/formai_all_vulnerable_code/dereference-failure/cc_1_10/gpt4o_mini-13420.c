//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void *handle_client(void *socket_desc) {
    int sock = *(int *)socket_desc;
    char client_message[BUFFER_SIZE];
    int read_size;

    // Communicate with the client
    while ((read_size = recv(sock, client_message, sizeof(client_message) - 1, 0)) > 0) {
        client_message[read_size] = '\0'; // Null terminate the string
        printf("Client: %s\n", client_message);
        
        // Echo the message back to the client
        send(sock, client_message, read_size, 0);
    }

    if (read_size == 0) {
        printf("Client disconnected.\n");
    } else if (read_size == -1) {
        perror("recv failed");
    }

    close(sock);
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
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Chat server listening on port %d...\n", PORT);

    // Accept and interact with clients
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            continue;
        }

        printf("New connection established.\n");

        // Allocate memory for the thread socket descriptor
        int *new_sock = malloc(1);
        *new_sock = new_socket;

        // Create a new thread for the client
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)new_sock) < 0) {
            perror("Could not create thread");
        }

        // Detach the thread to allow for independent execution
        pthread_detach(thread_id);
    }

    // Cleanup and close the server socket (unreachable in this simple loop)
    close(server_fd);
    return 0;
}