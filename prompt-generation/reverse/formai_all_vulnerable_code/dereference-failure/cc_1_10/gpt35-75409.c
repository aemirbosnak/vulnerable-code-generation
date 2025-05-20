//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

bool is_valid_ip_address(char *ip_address) {
  struct sockaddr_in sa;
  return inet_pton(AF_INET, ip_address, &(sa.sin_addr)) != 0;
}

void proxy_client(int proxy_server_socket, char *client_ip_address, int client_port) {
    struct sockaddr_in client_address;
    socklen_t client_address_size = sizeof(client_address);

    int client_socket = accept(proxy_server_socket, (struct sockaddr *)&client_address, &client_address_size);
    if (client_socket < 0) {
        perror("Error accepting client");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    int n = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        perror("Error receiving message from client");
        exit(EXIT_FAILURE);
    }

    printf("Received from client:\n%s\n", buffer);

    char *ip_address = strtok(buffer, " ");
    ip_address = strtok(NULL, " ");
    int port = 80;
    char *port_string = strstr(ip_address, ":");
    if (port_string != NULL) {
        port = atoi(port_string + 1);
        *port_string = '\0';
    }

    if (!is_valid_ip_address(ip_address)) {
        printf("Invalid IP address: %s\n", ip_address);
        close(client_socket);
        return;
    }

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    if (inet_pton(AF_INET, ip_address, &(server_address.sin_addr)) < 0) {
        perror("Invalid IP address");
        close(client_socket);
        return;
    }
    if (connect(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        close(client_socket);
        return;
    }

    printf("Connected to server: %s:%d\n", ip_address, port);

    if (send(server_socket, buffer, n, 0) < 0) {
        perror("Error sending message to server");
        close(client_socket);
        close(server_socket);
        return;
    }

    printf("Sent to server:\n%s\n", buffer);

    while (true) {
        memset(buffer, 0, BUFFER_SIZE);
        int n = recv(server_socket, buffer, BUFFER_SIZE, 0);
        if (n < 0) {
            perror("Error receiving message from server");
            close(client_socket);
            close(server_socket);
            return;
        }
        if (n == 0) {
            break;
        }
        if (send(client_socket, buffer, n, 0) < 0) {
            perror("Error sending message to client");
            close(client_socket);
            close(server_socket);
            return;
        }
    }

    close(client_socket);
    close(server_socket);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <proxy port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int proxy_port = atoi(argv[1]);
    if (proxy_port < 1024 || proxy_port > 65535) {
        printf("Invalid port number: %d\n", proxy_port);
        return EXIT_FAILURE;
    }

    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket < 0) {
        perror("Error creating socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in proxy_address;
    memset(&proxy_address, 0, sizeof(proxy_address));
    proxy_address.sin_family = AF_INET;
    proxy_address.sin_addr.s_addr = htonl(INADDR_ANY);
    proxy_address.sin_port = htons(proxy_port);

    if (bind(proxy_socket, (struct sockaddr *)&proxy_address, sizeof(proxy_address)) < 0) {
        perror("Error binding socket");
        return EXIT_FAILURE;
    }

    if (listen(proxy_socket, 10) < 0) {
        perror("Error listening on socket");
        return EXIT_FAILURE;
    }

    printf("Proxy server listening on port %d\n", proxy_port);

    while (true) {
        proxy_client(proxy_socket, argv[0], proxy_port);
    }

    close(proxy_socket);

    return EXIT_SUCCESS;
}