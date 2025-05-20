//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

typedef struct {
    int client_socket;
    int server_socket;
} client_data;

void *handle_client(void *arg) {
    client_data *data = (client_data *)arg;
    int client_socket = data->client_socket;
    int server_socket = data->server_socket;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Receive the HTTP request from the client
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("recv");
        close(client_socket);
        close(server_socket);
        pthread_exit(NULL);
    }

    // Forward the HTTP request to the server
    if (send(server_socket, buffer, bytes_received, 0) < 0) {
        perror("send");
        close(client_socket);
        close(server_socket);
        pthread_exit(NULL);
    }

    // Receive the HTTP response from the server
    bytes_received = recv(server_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("recv");
        close(client_socket);
        close(server_socket);
        pthread_exit(NULL);
    }

    // Forward the HTTP response to the client
    if (send(client_socket, buffer, bytes_received, 0) < 0) {
        perror("send");
        close(client_socket);
        close(server_socket);
        pthread_exit(NULL);
    }

    // Close the client and server sockets
    close(client_socket);
    close(server_socket);

    pthread_exit(NULL);
}

int main() {
    int listen_socket;
    int client_socket;
    int server_socket;
    struct sockaddr_in listen_addr;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len;
    client_data *data;
    pthread_t thread;

    // Create the listen socket
    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket < 0) {
        perror("socket");
        exit(1);
    }

    // Bind the listen socket to the loopback address and port 8080
    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    listen_addr.sin_port = htons(8080);
    if (bind(listen_socket, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Start listening for incoming connections
    if (listen(listen_socket, 5) < 0) {
        perror("listen");
        exit(1);
    }

    // Accept incoming connections and handle them in separate threads
    while (1) {
        client_addr_len = sizeof(client_addr);
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }

        server_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (server_socket < 0) {
            perror("socket");
            close(client_socket);
            continue;
        }

        // Connect to the server
        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        server_addr.sin_port = htons(80);
        if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("connect");
            close(client_socket);
            close(server_socket);
            continue;
        }

        // Create a new thread to handle the client
        data = malloc(sizeof(client_data));
        data->client_socket = client_socket;
        data->server_socket = server_socket;
        if (pthread_create(&thread, NULL, handle_client, data) != 0) {
            perror("pthread_create");
            close(client_socket);
            close(server_socket);
            free(data);
            continue;
        }
    }

    // Close the listen socket
    close(listen_socket);

    return 0;
}