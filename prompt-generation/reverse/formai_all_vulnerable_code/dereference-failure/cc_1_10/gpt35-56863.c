//FormAI DATASET v1.0 Category: Client Server Application ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10

struct Client {
    int socket_fd;
    struct sockaddr_in address;
    char name[20];
};

struct Client clients[MAX_CLIENTS];

int client_count = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *args) {
    char buffer[1024];
    int socket_fd = *(int*)args;
    int n, i;
    int client_index = -1;

    for (i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].socket_fd == socket_fd) {
            client_index = i;
            break;
        }
    }

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        n = read(socket_fd, buffer, sizeof(buffer));
        if (n <= 0) {
            printf("Client %s has disconnected.\n", clients[client_index].name);
            pthread_mutex_lock(&mutex);
            client_count--;
            clients[client_index].socket_fd = -1;
            pthread_mutex_unlock(&mutex);
            close(socket_fd);
            break;
        } else {
            for (i = 0; i < client_count; i++) {
                if (clients[i].socket_fd != -1 && clients[i].socket_fd != socket_fd) {
                    char message[1024];
                    sprintf(message, "%s: %s", clients[client_index].name, buffer);
                    write(clients[i].socket_fd, message, sizeof(message));
                }
            }
        }
    }

    pthread_exit(NULL);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int opt = 1;
    char name[20];

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*) &address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr*) &address, (socklen_t*) &addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        pthread_mutex_lock(&mutex);

        if (client_count == MAX_CLIENTS) {
            printf("Maximum client limit reached. Rejecting new connection.\n");
            close(new_socket);
        } else {
            clients[client_count].socket_fd = new_socket;
            clients[client_count].address = address;
            printf("New client has joined the chat with IP address %s and port %d.\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
            write(new_socket, "Please enter your name: ", 23);
            read(new_socket, name, sizeof(name));
            strcpy(clients[client_count].name, name);
            write(new_socket, "Welcome to the chat!", 21);
            pthread_t thread;
            pthread_create(&thread, NULL, handle_client, &clients[client_count].socket_fd);
            client_count++;
        }

        pthread_mutex_unlock(&mutex);
    }

    return 0;
}