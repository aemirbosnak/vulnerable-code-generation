//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 100

struct client_info {
    int socket;
    char name[256];
    int balance;
};

struct client_info clients[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *arg) {
    struct client_info *client = (struct client_info *)arg;

    char buffer[256];
    int n;

    while ((n = recv(client->socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[n] = '\0';

        char *command = strtok(buffer, " ");
        char *args = strtok(NULL, "");

        if (strcmp(command, "ADD") == 0) {
            client->balance += atoi(args);
        } else if (strcmp(command, "SUB") == 0) {
            client->balance -= atoi(args);
        } else if (strcmp(command, "GET") == 0) {
            sprintf(buffer, "%d", client->balance);
            send(client->socket, buffer, strlen(buffer), 0);
        } else {
            strcpy(buffer, "Invalid command");
            send(client->socket, buffer, strlen(buffer), 0);
        }
    }

    close(client->socket);

    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return -1;
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen");
        return -1;
    }

    while (1) {
        client_addr_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        clients[num_clients].socket = client_socket;
        strcpy(clients[num_clients].name, inet_ntoa(client_addr.sin_addr));
        clients[num_clients].balance = 0;

        pthread_t thread;
        pthread_create(&thread, NULL, handle_client, &clients[num_clients]);

        num_clients++;
    }

    close(server_socket);

    return 0;
}