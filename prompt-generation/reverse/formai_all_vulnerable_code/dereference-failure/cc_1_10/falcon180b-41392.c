//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: distributed
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define PORT 8080
#define BUFFER_SIZE 1024

struct client_info {
    int sock;
    char name[50];
};

void *handle_client(void *arg) {
    struct client_info *client = (struct client_info *) arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client->sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        printf("Client %s sent message: %s\n", client->name, buffer);
    }

    close(client->sock);
    free(client);
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_sock, MAX_CLIENTS);

    printf("Server is listening on port %d\n", PORT);

    struct client_info clients[MAX_CLIENTS];
    int num_clients = 0;

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_size = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &client_size);

        if (num_clients >= MAX_CLIENTS) {
            send(client_sock, "Server is full. Please try again later.\n", strlen("Server is full. Please try again later.\n"), 0);
            close(client_sock);
            continue;
        }

        strcpy(clients[num_clients].name, inet_ntoa(client_addr.sin_addr));
        clients[num_clients].sock = client_sock;
        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, &clients[num_clients - 1]);
    }

    return 0;
}