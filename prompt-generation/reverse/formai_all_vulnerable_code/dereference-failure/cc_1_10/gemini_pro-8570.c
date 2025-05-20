//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <pthread.h>
#include <signal.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_REQUEST_SIZE 8192
#define MAX_HEADER_SIZE 1024
#define MAX_CHUNK_SIZE 8192

struct client_data {
    int client_socket;
    int server_socket;
    char *request;
    size_t request_size;
    size_t request_offset;
    size_t response_size;
    size_t response_offset;
    char *response;
    pthread_t thread;
};

void *handle_client(void *data) {
    // Get the client data
    struct client_data *client = (struct client_data *)data;

    // Read the request
    client->request = malloc(MAX_REQUEST_SIZE);
    client->request_size = read(client->client_socket, client->request, MAX_REQUEST_SIZE);

    if (client->request_size == -1) {
        perror("read");
        close(client->client_socket);
        close(client->server_socket);
        free(client->request);
        free(client);
        return NULL;
    }

    // Parse the request
    char *method = strtok(client->request, " ");
    char *path = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");

    if (strcmp(method, "GET") != 0) {
        // Only support GET requests
        fprintf(stderr, "Only GET requests are supported\n");
        close(client->client_socket);
        close(client->server_socket);
        free(client->request);
        free(client);
        return NULL;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);

    struct hostent *host = gethostbyname(path + 7);
    if (host == NULL) {
        perror("gethostbyname");
        close(client->client_socket);
        close(client->server_socket);
        free(client->request);
        free(client);
        return NULL;
    }

    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    client->server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client->server_socket == -1) {
        perror("socket");
        close(client->client_socket);
        free(client->request);
        free(client);
        return NULL;
    }

    if (connect(client->server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        close(client->client_socket);
        close(client->server_socket);
        free(client->request);
        free(client);
        return NULL;
    }

    // Send the request
    if (write(client->server_socket, client->request, client->request_size) == -1) {
        perror("write");
        close(client->client_socket);
        close(client->server_socket);
        free(client->request);
        free(client);
        return NULL;
    }

    // Read the response
    client->response = malloc(MAX_CHUNK_SIZE);
    client->response_size = 0;

    while ((client->response_offset = read(client->server_socket, client->response + client->response_size, MAX_CHUNK_SIZE)) > 0) {
        client->response_size += client->response_offset;
    }

    if (client->response_offset == -1) {
        perror("read");
        close(client->client_socket);
        close(client->server_socket);
        free(client->request);
        free(client->response);
        free(client);
        return NULL;
    }

    // Send the response
    if (write(client->client_socket, client->response, client->response_size) == -1) {
        perror("write");
        close(client->client_socket);
        close(client->server_socket);
        free(client->request);
        free(client->response);
        free(client);
        return NULL;
    }

    // Close the sockets
    close(client->client_socket);
    close(client->server_socket);

    // Free the memory
    free(client->request);
    free(client->response);
    free(client);

    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    // Create the listening socket
    int listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        perror("socket");
        return 1;
    }

    // Set the socket options
    int optval = 1;
    if (setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        perror("setsockopt");
        close(listen_socket);
        return 1;
    }

    // Bind the socket to the port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listen_socket, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        close(listen_socket);
        return 1;
    }

    // Listen for connections
    if (listen(listen_socket, 5) == -1) {
        perror("listen");
        close(listen_socket);
        return 1;
    }

    // Accept connections
    while (1) {
        int client_socket = accept(listen_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        // Create a new thread to handle the client
        struct client_data *client = malloc(sizeof(struct client_data));
        client->client_socket = client_socket;
        client->server_socket = -1;
        client->request = NULL;
        client->request_size = 0;
        client->request_offset = 0;
        client->response_size = 0;
        client->response_offset = 0;
        client->response = NULL;

        if (pthread_create(&client->thread, NULL, handle_client, client) != 0) {
            perror("pthread_create");
            close(client_socket);
            free(client);
            continue;
        }
    }

    // Close the listening socket
    close(listen_socket);

    return 0;
}