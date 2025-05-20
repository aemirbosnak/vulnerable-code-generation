//FormAI DATASET v1.0 Category: Networking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int client_count = 0;
int socket_fd, clients[MAX_CLIENTS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *client_handler(void *arg) {
    int client_fd = *(int *)arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int result = recv(client_fd, buffer, BUFFER_SIZE, 0);
        if (result == -1) {
            perror("recv() failed");
            break;
        }
        if (result == 0) {
            printf("Client disconnected\n");
            break;
        }
        printf("Received: %s", buffer);
        pthread_mutex_lock(&mutex);
        for (int i = 0; i < client_count; i++) {
            if (clients[i] != client_fd) {
                send(clients[i], buffer, strlen(buffer), 0);
            }
        }
        pthread_mutex_unlock(&mutex);
    }

    pthread_mutex_lock(&mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i] == client_fd) {
            clients[i] = -1;
        }
    }
    pthread_mutex_unlock(&mutex);
    close(client_fd);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./server <port>\n");
        return 1;
    }
    int port = atoi(argv[1]);

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("socket() failed");
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof addr);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    if (bind(socket_fd, (struct sockaddr *)&addr, sizeof addr) == -1) {
        perror("bind() failed");
        return 1;
    }

    if (listen(socket_fd, MAX_CLIENTS) == -1) {
        perror("listen() failed");
        return 1;
    }

    printf("Listening on port %d...\n", port);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t len = sizeof client_addr;
        int client_fd = accept(socket_fd, (struct sockaddr *)&client_addr, &len);
        if (client_fd == -1) {
            perror("accept() failed");
            continue;
        }

        pthread_mutex_lock(&mutex);
        if (client_count < MAX_CLIENTS) {
            clients[client_count++] = client_fd;
            pthread_t tid;
            pthread_create(&tid, NULL, client_handler, &client_fd);
        } else {
            printf("Max client count reached. Connection rejected.\n");
            close(client_fd);
        }
        pthread_mutex_unlock(&mutex);
    }

    return 0;
}