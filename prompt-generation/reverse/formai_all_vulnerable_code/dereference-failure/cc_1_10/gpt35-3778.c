//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void serve_client(int client_socket);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <ip_address> <port>\n", argv[0]);
        return 1;
    }

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Failed to create server socket");
        return 1;
    }

    struct sockaddr_in server_address, client_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(atoi(argv[2]));

    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) != 0) {
        perror("Failed to bind server socket");
        close(server_socket);
        return 1;
    }

    if (listen(server_socket, 5) != 0) {
        perror("Failed to listen for incoming connections");
        close(server_socket);
        return 1;
    }

    while (1) {
        socklen_t client_address_len = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_address_len);
        if (client_socket == -1) {
            perror("Failed to accept client connection");
            continue;
        }

        printf("Received connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        if (fork() == 0) {
            // Child process handles communication with client
            serve_client(client_socket);
            close(client_socket);
            exit(0);
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}

void serve_client(int client_socket) {
    char buffer[4096];
    memset(buffer, 0, sizeof(buffer));
    if (recv(client_socket, buffer, sizeof(buffer)-1, 0) < 0) {
        perror("Failed to receive data from client");
        return;
    }

    printf("Received %zu bytes from client:\n%s", strlen(buffer), buffer);

    char *first_line = strtok(buffer, "\r\n");
    char *method = strtok(first_line, " ");
    char *path = strtok(NULL, " ");
    char *host = strstr(buffer, "Host:");
    if (host == NULL) {
        perror("No Host header found in request");
        return;
    }
    host += 6;  // Skip "Host: "
    char *port_str = strstr(host, ":");
    if (port_str == NULL) {
        port_str = "80";  // Default HTTP port
    } else {
        port_str += 1;  // Skip ":"
    }

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Failed to create server socket");
        return;
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(host);
    server_address.sin_port = htons(atoi(port_str));

    if (connect(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) != 0) {
        perror("Failed to connect to server");
        close(server_socket);
        return;
    }

    if (send(server_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send data to server");
        close(server_socket);
        return;
    }

    printf("Sent %zu bytes to server:\n%s", strlen(buffer), buffer);

    memset(buffer, 0, sizeof(buffer));
    if (recv(server_socket, buffer, sizeof(buffer)-1, 0) < 0) {
        perror("Failed to receive data from server");
        close(server_socket);
        return;
    }

    printf("Received %zu bytes from server:\n%s", strlen(buffer), buffer);

    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send data to client");
        close(server_socket);
        return;
    }

    printf("Sent %zu bytes to client:\n%s", strlen(buffer), buffer);

    close(server_socket);
}