//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define BACKLOG 10

void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the buffer
        printf("Client: %s\n", buffer);
        
        // Echo back the message to the client
        send(sock, buffer, bytes_read, 0);
    }

    if (bytes_read == 0) {
        printf("Client disconnected.\n");
    } else {
        perror("recv failed");
    }
    
    close(sock);
    free(client_socket); // Free dynamically allocated memory
    return NULL;
}

int main() {
    int server_fd, opt = 1;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, BACKLOG) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        int *new_socket = malloc(sizeof(int));
        if ((*new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            free(new_socket); // Avoid memory leak
            continue;
        }

        printf("New connection established.\n");

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)new_socket) != 0) {
            perror("Could not create thread");
            close(*new_socket);
            free(new_socket);
            continue;
        }

        pthread_detach(thread_id); // Detach the thread to avoid resource leak
    }

    close(server_fd);
    return 0;
}