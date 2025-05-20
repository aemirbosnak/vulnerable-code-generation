//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

void* handle_client(void* arg);
void* check_alive(void* arg);

typedef struct {
    int socket;
    struct sockaddr_in address;
} client_info;

int main(int argc, char *argv[]) {
    int server_fd, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t addr_len = sizeof(client_address);
    pthread_t tid;
    
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);
    
    while (1) {
        client_socket = accept(server_fd, (struct sockaddr *)&client_address, &addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }

        client_info *c_info = malloc(sizeof(client_info));
        c_info->socket = client_socket;
        c_info->address = client_address;

        if (pthread_create(&tid, NULL, handle_client, c_info) != 0) {
            perror("Thread creation failed");
            free(c_info);
        }
        pthread_detach(tid); // Detach the thread to avoid memory leak
    }

    close(server_fd);
    return 0;
}

void* handle_client(void* arg) {
    client_info *c_info = (client_info *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    printf("Client connected: %s:%d\n", inet_ntoa(c_info->address.sin_addr), ntohs(c_info->address.sin_port));
    
    while ((bytes_read = recv(c_info->socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the string
        printf("Received from client: %s", buffer);
        send(c_info->socket, buffer, bytes_read, 0); // Echo back to client
    }

    if (bytes_read == 0) {
        printf("Client disconnected: %s:%d\n", inet_ntoa(c_info->address.sin_addr), ntohs(c_info->address.sin_port));
    } else {
        perror("Recv failed");
    }

    close(c_info->socket);
    free(c_info);
    return NULL;
}