//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

void *handle_client(void *arg);
void send_message_to_all(char *message, int client_socket);
void remove_client(int client_socket);

int client_sockets[MAX_CLIENTS];
int client_count = 0;

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int received;

    while ((received = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[received] = '\0';
        printf("Client %d says: %s\n", client_socket, buffer);
        send_message_to_all(buffer, client_socket);
    }

    printf("Client %d disconnected.\n", client_socket);
    remove_client(client_socket);
    close(client_socket);
    free(arg);
    return NULL;
}

void send_message_to_all(char *message, int client_socket) {
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] != client_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
}

void remove_client(int client_socket) {
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == client_socket) {
            client_sockets[i] = client_sockets[client_count - 1];
            client_count--;
            break;
        }
    }
}

int main() {
    int server_socket, *new_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t thread;

    // Hero's Welcome!
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket failed");
        return EXIT_FAILURE;
    }

    // Bind the connection
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        return EXIT_FAILURE;
    }

    // Let the listener awaken
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        return EXIT_FAILURE;
    }

    printf("Server started on port %d.\n", PORT);

    while (1) {
        int *new_sock = malloc(sizeof(int));
        *new_sock = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        
        if (*new_sock < 0) {
            perror("Accept failed");
            free(new_sock);
            continue;
        }

        if (client_count < MAX_CLIENTS) {
            client_sockets[client_count++] = *new_sock;
            printf("Client connected: %d\n", *new_sock);
            pthread_create(&thread, NULL, handle_client, (void *)new_sock);
        } else {
            printf("Too many clients! Connection refused for socket: %d\n", *new_sock);
            close(*new_sock);
            free(new_sock);
        }
    }

    close(server_socket);
    return 0;
}