//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: ephemeral
#pragma ephemeral

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <string.h>

#define SERVER_PORT 8080
#define MAX_REQUEST_SIZE 1024

struct client_data {
    int socket;
    char *request;
    size_t request_len;
};

void *handle_client(void *arg) {
    struct client_data *client = (struct client_data *)arg;
    printf("Handling client request: %s\n", client->request);

    // Parse the request and send a response

    char *response = "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nHello, Ephemeral Friend!\n";

    write(client->socket, response, strlen(response));
    close(client->socket);

    free(client->request);
    free(client);
    
    pthread_exit(NULL);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;
    pthread_t client_thread;
    int addr_len = sizeof(struct sockaddr_in);

    // Create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket() failed");
        return EXIT_FAILURE;
    }

    // Set the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    // Bind the server socket to the address
    if (bind(server_socket, (struct sockaddr *)&server_addr, addr_len) < 0) {
        perror("bind() failed");
        close(server_socket);
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_socket, 4) < 0) {
        perror("listen() failed");
        close(server_socket);
        return EXIT_FAILURE;
    }

    printf("Server is listening on port %d\n", SERVER_PORT);

    // Accept incoming connections and handle them in separate threads
    while ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len))) {
        struct client_data *client = malloc(sizeof(struct client_data));
        client->socket = client_socket;
        client->request = malloc(MAX_REQUEST_SIZE);
        client->request_len = read(client_socket, client->request, MAX_REQUEST_SIZE);

        pthread_create(&client_thread, NULL, handle_client, client);
    }

    // Close the server socket
    close(server_socket);

    return EXIT_SUCCESS;
}