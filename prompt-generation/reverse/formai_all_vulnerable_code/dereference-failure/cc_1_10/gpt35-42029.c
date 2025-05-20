//FormAI DATASET v1.0 Category: Networking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 15
#define PORT 5050

int clients[MAX_CLIENTS];
int count = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void broadcast(int sender, char *message) {
    pthread_mutex_lock(&mutex);

    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] != 0 && clients[i] != sender) {
            write(clients[i], message, strlen(message));
        }
    }

    pthread_mutex_unlock(&mutex);
}

void* handle_client(void *arg) {
    int sock = *(int*)arg;
    free(arg);

    pthread_mutex_lock(&mutex);
    clients[count++] = sock;
    pthread_mutex_unlock(&mutex);

    char buffer[1024];
    while (1) {
        int received = read(sock, buffer, 1024);
        if (received <= 0) {
            pthread_mutex_lock(&mutex);

            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (clients[i] == sock) {
                    clients[i] = 0;
                }
            }

            pthread_mutex_unlock(&mutex);
            break;
        }

        buffer[received] = '\0';
        broadcast(sock, buffer);
    }

    close(sock);
    return NULL;
}

int main(int argc, char *argv[]) {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Failed to create server socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in address = {0};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Failed to bind server socket");
        exit(EXIT_FAILURE);
    }

    if (listen(server_sock, 3) < 0) {
        perror("Failed to listen on server socket");
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d\n", PORT);

    while(1) {
        struct sockaddr_in client_address = {0};
        int len = sizeof(client_address);
        int client_sock = accept(server_sock, (struct sockaddr*)&client_address, (socklen_t*)&len);

        if (client_sock < 0) {
            perror("Failed to accept client connection");
            continue;
        }

        pthread_t tid;
        int *ptr = malloc(sizeof(int));
        *ptr = client_sock;

        if (pthread_create(&tid, NULL, handle_client, ptr) != 0) {
            perror("Failed to create thread");
            continue;
        }
    }

    return 0;
}