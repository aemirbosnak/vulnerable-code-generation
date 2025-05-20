//Falcon-180B DATASET v1.0 Category: Chat server ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <pthread.h>

#define SERVER_PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients = 0;
char *messages[MAX_CLIENTS][BUFFER_SIZE];
pthread_t threads[MAX_CLIENTS];

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        strcat(messages[client_socket], buffer);
        send(client_socket, buffer, strlen(buffer), 0);
    }
    close(client_socket);
    messages[client_socket][0] = '\0';
}

void *listen_thread(void *arg) {
    int client_socket;
    while (1) {
        client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }
        if (num_clients >= MAX_CLIENTS) {
            close(client_socket);
            continue;
        }
        client_sockets[num_clients] = client_socket;
        pthread_create(&threads[num_clients], NULL, handle_client, (void *)client_socket);
        num_clients++;
        printf("Client %d connected\n", num_clients - 1);
    }
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, 10);
    printf("Server started on port %d\n", SERVER_PORT);
    pthread_create(&listen_thread, NULL, listen_thread, NULL);
    return 0;
}