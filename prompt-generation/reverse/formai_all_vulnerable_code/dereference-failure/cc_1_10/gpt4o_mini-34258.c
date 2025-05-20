//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    char buffer[BUFFER_SIZE];
    
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received <= 0) {
            printf("Client disconnected.\n");
            break;
        }
        printf("Client: %s\n", buffer);
        send(sock, buffer, bytes_received, 0);
    }
    
    close(sock);
    free(client_socket);
    return NULL;
}

int main() {
    int server_socket, *new_socket;
    struct sockaddr_in server_addr, client_addr;
    int addr_len = sizeof(client_addr);
    
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        new_socket = malloc(sizeof(int));
        *new_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addr_len);
        if (*new_socket < 0) {
            perror("Accept failed");
            free(new_socket);
            continue;
        }
        printf("New connection accepted.\n");

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)new_socket) != 0) {
            perror("Could not create thread");
            free(new_socket);
        }
        pthread_detach(thread_id);
    }

    close(server_socket);
    return 0;
}