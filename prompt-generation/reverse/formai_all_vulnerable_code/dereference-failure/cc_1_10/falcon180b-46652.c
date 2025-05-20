//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

struct client_data {
    int socket;
    char ip[16];
    int port;
};

void *handle_client(void *arg) {
    struct client_data *client = (struct client_data *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client->socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client %s:%d sent: %s\n", client->ip, client->port, buffer);
    }

    close(client->socket);
    free(arg);
}

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);
    struct client_data *clients[MAX_CLIENTS];

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("Error setting socket option\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, 5) < 0) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server is listening on port 8080...\n");

    while (1) {
        if ((new_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t *)&addrlen)) < 0) {
            printf("Error accepting connection\n");
            exit(1);
        }

        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] == NULL) {
                clients[i] = (struct client_data *) malloc(sizeof(struct client_data));
                clients[i]->socket = new_socket;
                strcpy(clients[i]->ip, inet_ntoa(client_addr.sin_addr));
                clients[i]->port = ntohs(client_addr.sin_port);

                pthread_t thread_id;
                pthread_create(&thread_id, NULL, handle_client, clients[i]);

                break;
            }
        }
    }

    return 0;
}