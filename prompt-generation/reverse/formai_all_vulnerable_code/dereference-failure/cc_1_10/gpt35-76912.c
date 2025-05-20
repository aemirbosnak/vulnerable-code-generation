//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

void handle_client(int socket_fd);

int main(int argc, char const *argv[]) {
    if (argc != 3) {
        printf("Usage: ./tcp_server <ip_address> <port>\n");
        exit(EXIT_FAILURE);
    }
    
    const char *ip_address = argv[1];
    int port = atoi(argv[2]);

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(ip_address);
    server_address.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 10) < 0) {
        perror("Failed to listen to socket");
        exit(EXIT_FAILURE);
    }

    printf("Server started! Listening on %s:%d\n", ip_address, port);
    
    while (true) {
        int client_fd = accept(server_fd, NULL, NULL);
        if (client_fd < 0) {
            perror("Failed to accept client connection");
            continue;
        }

        printf("New client connected. Client IP: %s\n", inet_ntoa(server_address.sin_addr));

        pid_t pid = fork();
        if (pid < 0) {
            perror("Failed to fork process");
            continue;
        } else if (pid == 0) {
            // child process
            handle_client(client_fd);
            exit(0);
        }
    }

    return 0;
}

/*
 * Handles the communication with a client.
 */
void handle_client(int socket_fd) {
    char buffer[BUFFER_SIZE];

    while (true) {
        memset(buffer, 0, BUFFER_SIZE);

        int num_bytes_received = recv(socket_fd, buffer, BUFFER_SIZE, 0);
        if (num_bytes_received < 0) {
            perror("Failed to receive data from client");
            close(socket_fd);
            return;
        }

        if (num_bytes_received == 0) {
            // client closed connection
            close(socket_fd);
            return;
        }

        printf("Received data from client: %s", buffer);

        // echo the received data back to the client
        if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
            perror("Failed to send data to client");
            close(socket_fd);
            return;
        }
    }
}