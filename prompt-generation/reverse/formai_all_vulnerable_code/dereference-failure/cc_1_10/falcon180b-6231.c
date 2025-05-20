//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients = 0;
int max_clients = 0;
pthread_mutex_t mutex;

void broadcast(int sender_socket, char *message) {
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < num_clients; i++) {
        if (client_sockets[i]!= sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&mutex);
}

void *handle_client(void *client_socket) {
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv((int)client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        char *message = strdup(buffer);
        broadcast((int)client_socket, message);
        free(message);
    }
    close((int)client_socket);
    pthread_exit(NULL);
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in server_addr, client_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, 3);

    printf("Server is running on port 8080\n");

    while (1) {
        struct sockaddr_in client_addr_in;
        socklen_t addr_size = sizeof(client_addr_in);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr_in, &addr_size);

        if (client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        pthread_mutex_lock(&mutex);
        for (int i = 0; i < num_clients; i++) {
            if (client_sockets[i] == 0) {
                client_sockets[i] = client_socket;
                printf("Client %d connected\n", num_clients);
                num_clients++;
                break;
            }
        }
        pthread_mutex_unlock(&mutex);

        if (num_clients >= max_clients) {
            printf("Maximum number of clients reached\n");
            close(client_socket);
            continue;
        }

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)client_socket);
    }

    return 0;
}