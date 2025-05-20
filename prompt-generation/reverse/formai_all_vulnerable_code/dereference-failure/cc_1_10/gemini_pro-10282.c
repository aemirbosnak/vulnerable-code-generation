//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 5

struct client_data {
    int socket;
    struct sockaddr_in address;
    pthread_t thread;
};

void *handle_client(void *arg) {
    struct client_data *client = (struct client_data *)arg;
    char buffer[1024];
    int len;

    while (1) {
        len = recv(client->socket, buffer, sizeof(buffer), 0);
        if (len <= 0) {
            break;
        }

        printf("Received message: %s\n", buffer);
        len = send(client->socket, buffer, len, 0);
        if (len <= 0) {
            break;
        }
    }

    close(client->socket);
    free(client);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len;
    pthread_t thread;
    struct client_data *client_data;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(1234);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port 1234\n");

    while (1) {
        client_address_len = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }

        client_data = malloc(sizeof(struct client_data));
        client_data->socket = client_socket;
        client_data->address = client_address;

        pthread_create(&thread, NULL, handle_client, client_data);
    }

    close(server_socket);
    return 0;
}