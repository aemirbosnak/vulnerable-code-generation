//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Define constants
#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024

// Define global variables
int clients[MAX_CLIENTS];
int server_socket;

// Define functions
void handle_connection(int client_socket);
void send_error_response(int client_socket, int code);
void *handle_client(void *arg);

int main(int argc, char *argv[]) {
    // Validate command line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <listen_port> <destination_host>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int listen_port = atoi(argv[1]);
    char *destination_host = argv[2];

    // Initialize server socket
    server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server_socket < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in server_address = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = htonl(INADDR_ANY),
        .sin_port = htons(listen_port)
    };
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    printf("Proxy server listening on port %d\n", listen_port);

    // Accept client connections
    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_len);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }
        printf("Client connected from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        pthread_t t;
        pthread_create(&t, NULL, handle_client, (void *) (intptr_t) client_socket);
        pthread_detach(t);
    }

    // Close server socket
    close(server_socket);
    return 0;
}

void *handle_client(void *arg) {
    int client_socket = (intptr_t) arg;

    // Add client to list of clients
    int i;
    for (i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == 0) {
            clients[i] = client_socket;
            break;
        }
    }
    if (i == MAX_CLIENTS) {
        send_error_response(client_socket, 503);
        close(client_socket);
        return NULL;
    }

    // Handle client request
    handle_connection(client_socket);

    // Remove client from list of clients
    clients[i] = 0;
    close(client_socket);
    return NULL;
}

void handle_connection(int client_socket) {
    // Receive client request
    char buffer[BUFFER_SIZE];
    ssize_t n = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        perror("recv");
        return;
    }
    buffer[n] = '\0';
    printf("Received request from client:\n%s\n", buffer);

    // Parse client request
    char method[10], url[100], version[10];
    if (sscanf(buffer, "%s %s %s", method, url, version) != 3) {
        send_error_response(client_socket, 400);
        return;
    }

    // Open connection to destination web server
    int dest_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (dest_socket < 0) {
        perror("socket");
        send_error_response(client_socket, 503);
        return;
    }
    struct sockaddr_in dest_address = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = inet_addr("127.0.0.1"),
        .sin_port = htons(80)
    };
    if (connect(dest_socket, (struct sockaddr *) &dest_address, sizeof(dest_address)) < 0) {
        perror("connect");
        send_error_response(client_socket, 503);
        close(dest_socket);
        return;
    }

    // Send client request to destination web server
    send(dest_socket, buffer, n, 0);

    // Receive response from destination web server and forward to client
    while (1) {
        n = recv(dest_socket, buffer, BUFFER_SIZE, 0);
        if (n < 0) {
            perror("recv");
            close(dest_socket);
            return;
        }
        if (n == 0) {
            break;
        }
        send(client_socket, buffer, n, 0);
    }
}

void send_error_response(int client_socket, int code) {
    char *message;
    switch (code) {
        case 400:
            message = "Bad Request";
            break;
        case 503:
            message = "Service Unavailable";
            break;
        default:
            message = "Internal Server Error";
            break;
    }
    char buffer[BUFFER_SIZE];
    snprintf(buffer, BUFFER_SIZE, "HTTP/1.1 %d %s\r\nContent-Length: 0\r\n\r\n", code, message);
    send(client_socket, buffer, strlen(buffer), 0);
}