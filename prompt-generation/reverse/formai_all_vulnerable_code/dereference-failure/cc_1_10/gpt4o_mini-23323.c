//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

int clients[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void* handle_client(void* arg) {
    int client_socket = *((int*)arg);
    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE + 50];

    while (recv(client_socket, buffer, sizeof(buffer), 0) > 0) {
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
        snprintf(message, sizeof(message), "Client: %s\n", buffer);

        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < client_count; i++) {
            send(clients[i], message, strlen(message), 0);
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    close(client_socket);
    return NULL;
}

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);

    while ((new_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_len))) {
        if (client_count < MAX_CLIENTS) {
            clients[client_count++] = new_socket;
            printf("A new client connected. Total clients: %d\n", client_count);
            
            pthread_t tid;
            pthread_create(&tid, NULL, handle_client, (void*)&new_socket);
            pthread_detach(tid);
        } else {
            printf("Maximum clients reached. Rejecting new client.\n");
            close(new_socket);
        }
    }

    close(server_socket);
    return 0;
}