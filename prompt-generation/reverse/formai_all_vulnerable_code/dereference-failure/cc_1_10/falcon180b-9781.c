//Falcon-180B DATASET v1.0 Category: Chat server ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_MSG_SIZE 1024

struct client {
    int sock;
    char name[32];
};

void *handle_client(void *arg) {
    struct client *client = (struct client *) arg;
    char buffer[MAX_MSG_SIZE];

    while (1) {
        memset(buffer, 0, MAX_MSG_SIZE);
        int recv_len = recv(client->sock, buffer, MAX_MSG_SIZE, 0);

        if (recv_len <= 0) {
            close(client->sock);
            printf("Client %s disconnected\n", client->name);
            break;
        }

        char msg[MAX_MSG_SIZE];
        sprintf(msg, "Client %s says: %s", client->name, buffer);
        send(client->sock, msg, strlen(msg), 0);
        send(client->sock, buffer, strlen(buffer), 0);
    }

    return NULL;
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_sock, MAX_CLIENTS);

    printf("Server started on port 8080\n");

    struct client clients[MAX_CLIENTS];
    int num_clients = 0;

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_size = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &client_size);

        if (num_clients >= MAX_CLIENTS) {
            send(client_sock, "Server full", 11, 0);
            close(client_sock);
            continue;
        }

        clients[num_clients].sock = client_sock;
        strncpy(clients[num_clients].name, inet_ntoa(client_addr.sin_addr), 32);
        clients[num_clients].name[strlen(clients[num_clients].name) - 1] = '\0';

        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, &clients[num_clients - 1]);
    }

    return 0;
}