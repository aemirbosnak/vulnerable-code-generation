//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

// Function prototypes
void* handle_client(int client_socket);
void listen_for_clients(int port_number);
void close_client(int client_socket);
void print_error(const char* error_message);

int main(int argc, char** argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port_number = atoi(argv[1]);
    listen_for_clients(port_number);

    return 0;
}

void listen_for_clients(int port_number) {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        print_error("Failed to create socket");
        exit(1);
    }

    struct sockaddr_in server_address;
    bzero((char*) &server_address, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port_number);

    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        print_error("Failed to bind socket");
        exit(1);
    }

    if (listen(server_socket, 5) < 0) {
        print_error("Failed to listen on socket");
        exit(1);
    }

    printf("Chat server is listening on port %d\n", port_number);

    for (;;) {
        int client_socket = accept(server_socket, NULL, NULL);

        if (client_socket < 0) {
            print_error("Failed to accept connection");
            exit(1);
        }

        printf("Client connected: %s\n", inet_ntoa(server_address.sin_addr));

        void* client_handle = handle_client(client_socket);

        if (client_handle == NULL) {
            close_client(client_socket);
        }
    }
}

void* handle_client(int client_socket) {
    char buffer[1024];

    while (1) {
        bzero(buffer, sizeof(buffer));

        ssize_t bytes_read = recv(client_socket, buffer, sizeof(buffer), 0);

        if (bytes_read <= 0) {
            break;
        }

        printf("%s\n", buffer);

        send(client_socket, buffer, bytes_read, 0);
    }

    close(client_socket);
    return NULL;
}

void close_client(int client_socket) {
    close(client_socket);
}

void print_error(const char* error_message) {
    perror(error_message);
    exit(1);
}