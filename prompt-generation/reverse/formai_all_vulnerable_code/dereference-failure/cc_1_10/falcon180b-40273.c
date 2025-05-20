//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CONNECTIONS 1024
#define MAX_REQUEST_SIZE 1024
#define THREAD_STACK_SIZE 8192

struct connection {
    int socket;
    struct sockaddr_in address;
    uint8_t request[MAX_REQUEST_SIZE];
    size_t request_size;
};

void *handle_connection(void *arg) {
    struct connection *conn = (struct connection *) arg;
    char response[MAX_REQUEST_SIZE];
    size_t response_size;

    response_size = sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: 0\r\n\r\n");
    send(conn->socket, response, response_size, 0);
    close(conn->socket);
}

void accept_connections(int server_socket) {
    struct sockaddr_in client_address;
    socklen_t address_size = sizeof(client_address);
    while (1) {
        int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &address_size);
        if (client_socket == -1) {
            break;
        }
        struct connection *conn = malloc(sizeof(struct connection));
        conn->socket = client_socket;
        conn->address = client_address;
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_connection, conn);
    }
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(server_socket, MAX_CONNECTIONS) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Server started on port 8080\n");
    accept_connections(server_socket);

    return 0;
}