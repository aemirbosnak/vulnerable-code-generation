//Falcon-180B DATASET v1.0 Category: Chat server ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

struct client {
    int sock;
    char name[20];
};

void *handle_client(void *arg) {
    struct client *client = (struct client *) arg;
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client->sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        printf("%s: %s\n", client->name, buffer);
        send(client->sock, buffer, strlen(buffer), 0);
    }
    close(client->sock);
    free(client);
    return NULL;
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

    printf("Server started on port %d\n", PORT);

    struct client *clients[MAX_CLIENTS];
    int client_count = 0;

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_size = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &client_size);

        if (client_count >= MAX_CLIENTS) {
            send(client_sock, "Server is full.\n", strlen("Server is full.\n"), 0);
            close(client_sock);
            continue;
        }

        clients[client_count] = (struct client *) malloc(sizeof(struct client));
        clients[client_count]->sock = client_sock;
        strncpy(clients[client_count]->name, inet_ntoa(client_addr.sin_addr), 20);
        client_count++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, clients[client_count - 1]);
    }

    return 0;
}