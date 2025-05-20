//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 1024

typedef struct {
    int client_socket;
    int server_socket;
} connection_t;

void *handle_connection(void *arg) {
    connection_t *connection = (connection_t *)arg;

    char request_buffer[BUFFER_SIZE];
    int request_length = read(connection->client_socket, request_buffer, BUFFER_SIZE);

    if (request_length <= 0) {
        perror("Error reading request");
        goto cleanup;
    }

    char *host = strstr(request_buffer, "Host: ");
    if (host == NULL) {
        perror("Error parsing request");
        goto cleanup;
    }
    host += strlen("Host: ");
    char *end_of_host = strchr(host, '\r');
    *end_of_host = '\0';

    struct hostent *server_host = gethostbyname(host);
    if (server_host == NULL) {
        perror("Error resolving hostname");
        goto cleanup;
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    memcpy(&server_address.sin_addr.s_addr, server_host->h_addr_list[0], server_host->h_length);

    connection->server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (connection->server_socket < 0) {
        perror("Error creating socket");
        goto cleanup;
    }

    if (connect(connection->server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        goto cleanup;
    }

    write(connection->server_socket, request_buffer, request_length);

    char response_buffer[BUFFER_SIZE];
    int response_length;
    while ((response_length = read(connection->server_socket, response_buffer, BUFFER_SIZE)) > 0) {
        write(connection->client_socket, response_buffer, response_length);
    }

cleanup:
    close(connection->client_socket);
    close(connection->server_socket);
    free(connection);
    return NULL;
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating socket");
        return 1;
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding socket");
        return 1;
    }

    if (listen(server_socket, MAX_CONNECTIONS) < 0) {
        perror("Error listening on socket");
        return 1;
    }

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("Error accepting connection");
            continue;
        }

        connection_t *connection = malloc(sizeof(connection_t));
        connection->client_socket = client_socket;

        pthread_t thread;
        pthread_create(&thread, NULL, handle_connection, connection);
        pthread_detach(thread);
    }

    close(server_socket);
    return 0;
}