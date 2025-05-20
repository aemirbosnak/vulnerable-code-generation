//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int server_socket;

struct client {
    int socket;
    char name[256];
    char phone_number[256];
};

struct client clients[100];
int num_clients = 0;

pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while (1) {
        bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }

        buffer[bytes_received] = '\0';

        char *command = strtok(buffer, " ");
        if (strcmp(command, "ADD") == 0) {
            char *name = strtok(NULL, " ");
            char *phone_number = strtok(NULL, " ");

            pthread_mutex_lock(&clients_mutex);
            strcpy(clients[num_clients].name, name);
            strcpy(clients[num_clients].phone_number, phone_number);
            num_clients++;
            pthread_mutex_unlock(&clients_mutex);

            snprintf(buffer, BUFFER_SIZE, "OK");
        } else if (strcmp(command, "GET") == 0) {
            char *name = strtok(NULL, " ");

            pthread_mutex_lock(&clients_mutex);
            int found = 0;
            for (int i = 0; i < num_clients; i++) {
                if (strcmp(clients[i].name, name) == 0) {
                    found = 1;
                    snprintf(buffer, BUFFER_SIZE, "OK %s %s", clients[i].name, clients[i].phone_number);
                    break;
                }
            }
            pthread_mutex_unlock(&clients_mutex);

            if (!found) {
                snprintf(buffer, BUFFER_SIZE, "NOT FOUND");
            }
        } else if (strcmp(command, "LIST") == 0) {
            pthread_mutex_lock(&clients_mutex);
            snprintf(buffer, BUFFER_SIZE, "OK");
            for (int i = 0; i < num_clients; i++) {
                strcat(buffer, "\n");
                strcat(buffer, clients[i].name);
                strcat(buffer, " ");
                strcat(buffer, clients[i].phone_number);
            }
            pthread_mutex_unlock(&clients_mutex);
        } else {
            snprintf(buffer, BUFFER_SIZE, "ERROR");
        }

        send(client_socket, buffer, strlen(buffer), 0);
    }

    close(client_socket);
}

void handle_signal(int signal) {
    for (int i = 0; i < num_clients; i++) {
        close(clients[i].socket);
    }

    close(server_socket);

    exit(0);
}

int main() {
    struct sockaddr_in server_address;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(server_socket, 10) == -1) {
        perror("listen");
        exit(1);
    }

    signal(SIGINT, handle_signal);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        pthread_t thread;
        pthread_create(&thread, NULL, (void *) handle_client, (void *) client_socket);
    }

    return 0;
}