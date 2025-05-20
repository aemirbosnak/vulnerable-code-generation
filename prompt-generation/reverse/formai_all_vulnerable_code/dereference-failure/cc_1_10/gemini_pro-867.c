//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 100
#define MAX_MESSAGE_LENGTH 1024

struct client_info {
    int socket_fd;
    char name[MAX_MESSAGE_LENGTH];
};

struct client_list {
    struct client_info clients[MAX_CLIENTS];
    int num_clients;
};

struct client_list client_list;

pthread_mutex_t client_list_lock = PTHREAD_MUTEX_INITIALIZER;

void send_message_to_all(char *message) {
    pthread_mutex_lock(&client_list_lock);
    for (int i = 0; i < client_list.num_clients; i++) {
        send(client_list.clients[i].socket_fd, message, strlen(message), 0);
    }
    pthread_mutex_unlock(&client_list_lock);
}

void *handle_client(void *arg) {
    struct client_info *client = (struct client_info *)arg;
    char buffer[MAX_MESSAGE_LENGTH];

    while (1) {
        int recv_len = recv(client->socket_fd, buffer, MAX_MESSAGE_LENGTH, 0);
        if (recv_len <= 0) {
            break;
        }

        buffer[recv_len] = '\0';

        char message[MAX_MESSAGE_LENGTH];
        snprintf(message, MAX_MESSAGE_LENGTH, "%s: %s", client->name, buffer);

        send_message_to_all(message);
    }

    pthread_mutex_lock(&client_list_lock);
    for (int i = 0; i < client_list.num_clients; i++) {
        if (client_list.clients[i].socket_fd == client->socket_fd) {
            client_list.clients[i] = client_list.clients[client_list.num_clients - 1];
            client_list.num_clients--;
            break;
        }
    }
    pthread_mutex_unlock(&client_list_lock);

    close(client->socket_fd);
    free(client);

    return NULL;
}

int main() {
    int server_fd, new_socket_fd, addrlen;
    struct sockaddr_in server_addr, client_addr;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    int bind_status = bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (bind_status < 0) {
        perror("bind() failed");
        exit(EXIT_FAILURE);
    }

    int listen_status = listen(server_fd, MAX_CLIENTS);
    if (listen_status < 0) {
        perror("listen() failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        addrlen = sizeof(client_addr);
        new_socket_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addrlen);
        if (new_socket_fd < 0) {
            perror("accept() failed");
            continue;
        }

        char welcome_message[MAX_MESSAGE_LENGTH];
        snprintf(welcome_message, MAX_MESSAGE_LENGTH, "Welcome to the chat server!\nPlease enter your name: ");
        send(new_socket_fd, welcome_message, strlen(welcome_message), 0);

        char name[MAX_MESSAGE_LENGTH];
        int recv_len = recv(new_socket_fd, name, MAX_MESSAGE_LENGTH, 0);
        if (recv_len <= 0) {
            close(new_socket_fd);
            continue;
        }

        name[recv_len] = '\0';

        pthread_mutex_lock(&client_list_lock);
        if (client_list.num_clients >= MAX_CLIENTS) {
            char error_message[MAX_MESSAGE_LENGTH];
            snprintf(error_message, MAX_MESSAGE_LENGTH, "Sorry, the server is full.\n");
            send(new_socket_fd, error_message, strlen(error_message), 0);
            close(new_socket_fd);
            pthread_mutex_unlock(&client_list_lock);
            continue;
        }

        struct client_info *new_client = malloc(sizeof(struct client_info));
        new_client->socket_fd = new_socket_fd;
        strcpy(new_client->name, name);

        client_list.clients[client_list.num_clients++] = *new_client;
        pthread_mutex_unlock(&client_list_lock);

        char join_message[MAX_MESSAGE_LENGTH];
        snprintf(join_message, MAX_MESSAGE_LENGTH, "%s has joined the chat.\n", name);
        send_message_to_all(join_message);

        pthread_t thread;
        pthread_create(&thread, NULL, handle_client, new_client);
    }

    close(server_fd);
    return 0;
}