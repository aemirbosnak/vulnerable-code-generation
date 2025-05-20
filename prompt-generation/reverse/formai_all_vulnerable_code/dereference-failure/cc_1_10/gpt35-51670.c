//FormAI DATASET v1.0 Category: Chat server ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 10

int client_count = 0;
int client_sockets[MAX_CLIENTS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char message[512];
    int n;
    while ((n = read(client_socket, message, sizeof(message))) > 0) {
        message[n] = '\0';
        pthread_mutex_lock(&mutex);
        for (int i = 0; i < client_count; i++) {
            write(client_sockets[i], message, n);
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(int argc, const char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return 1;
    }
    int port = atoi(argv[1]);
    struct sockaddr_in server_address = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(port),
    };
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        return 1;
    }
    if (listen(server_socket, 5) == -1) {
        perror("listen");
        return 1;
    }
    printf("Listening on port %d...\n", port);
    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }
        printf("Client connected from %s:%d\n",
            inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        pthread_t thread;
        pthread_create(&thread, NULL, handle_client, &client_socket);
        pthread_detach(thread);
        pthread_mutex_lock(&mutex);
        if (client_count < MAX_CLIENTS) {
            client_sockets[client_count++] = client_socket;
        }
        pthread_mutex_unlock(&mutex);
    }
    return 0;
}