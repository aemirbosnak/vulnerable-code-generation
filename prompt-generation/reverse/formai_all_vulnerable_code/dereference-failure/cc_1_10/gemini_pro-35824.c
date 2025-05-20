//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

struct client {
    int socket;
    char name[BUFFER_SIZE];
    struct client *next;
};

struct client *head = NULL;
pthread_mutex_t client_lock = PTHREAD_MUTEX_INITIALIZER;

void send_message(char *message, struct client *sender) {
    struct client *current = head;
    while (current != NULL) {
        if (current != sender) {
            send(current->socket, message, strlen(message) + 1, 0);
        }
        current = current->next;
    }
}

void *handle_client(void *arg) {
    int socket = *((int *)arg);
    free(arg);

    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        if (strcmp(buffer, "/quit") == 0) {
            break;
        } else if (strncmp(buffer, "/name ", 6) == 0) {
            pthread_mutex_lock(&client_lock);
            struct client *new_client = malloc(sizeof(struct client));
            new_client->socket = socket;
            strcpy(new_client->name, buffer + 6);
            new_client->next = head;
            head = new_client;
            pthread_mutex_unlock(&client_lock);
            send_message("New user joined: ", new_client);
        } else {
            send_message(buffer, NULL);
        }
    }

    close(socket);

    pthread_mutex_lock(&client_lock);
    struct client *prev_client = NULL;
    struct client *current_client = head;
    while (current_client != NULL) {
        if (current_client->socket == socket) {
            if (prev_client == NULL) {
                head = current_client->next;
            } else {
                prev_client->next = current_client->next;
            }
            free(current_client);
            break;
        }
        prev_client = current_client;
        current_client = current_client->next;
    }
    pthread_mutex_unlock(&client_lock);

    send_message("User left: ", NULL);

    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    int address_length = sizeof(client_address);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    printf("Chat server is running on port %d\n", PORT);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &address_length);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        pthread_t thread;
        int *arg = malloc(sizeof(int));
        *arg = client_socket;
        if (pthread_create(&thread, NULL, &handle_client, arg) != 0) {
            perror("pthread_create");
            close(client_socket);
            continue;
        }
    }

    close(server_socket);

    return EXIT_SUCCESS;
}