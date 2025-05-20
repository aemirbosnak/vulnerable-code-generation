//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_MSG_LEN 256

struct client_info {
    int socket_fd;
    char username[20];
};

struct message {
    char sender[20];
    char message[MAX_MSG_LEN];
};

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
struct client_info clients[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *arg) {
    int client_fd = *(int *) arg;
    free(arg);

    char buffer[MAX_MSG_LEN];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        recv(client_fd, buffer, sizeof(buffer), 0);

        struct message msg;
        memcpy(&msg, buffer, sizeof(msg));

        pthread_mutex_lock(&mutex);
        for (int i = 0; i < num_clients; i++) {
            if (clients[i].socket_fd != client_fd) {
                send(clients[i].socket_fd, buffer, sizeof(buffer), 0);
            }
        }
        pthread_mutex_unlock(&mutex);
    }
    close(client_fd);
    return NULL;
}

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5555);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_fd = accept(server_fd, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_fd < 0) {
            perror("accept");
            continue;
        }

        if (num_clients >= MAX_CLIENTS) {
            send(client_fd, "Server is full", strlen("Server is full"), 0);
            close(client_fd);
            continue;
        }

        printf("New client connected: %s\n", inet_ntoa(client_addr.sin_addr));

        struct client_info client;
        client.socket_fd = client_fd;
        strcpy(client.username, inet_ntoa(client_addr.sin_addr));
        clients[num_clients] = client;
        num_clients++;

        pthread_t thread;
        int *arg = malloc(sizeof(int));
        *arg = client_fd;
        if (pthread_create(&thread, NULL, handle_client, arg) != 0) {
            perror("pthread_create");
            close(client_fd);
            continue;
        }
    }

    close(server_fd);
    return 0;
}