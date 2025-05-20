//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_PORT    8080
#define BUFFER_SIZE    1024

void handle_error(const char *error_message) {
    perror(error_message);
    exit(EXIT_FAILURE);
}

void send_data(int client_socket, char *request, const struct sockaddr_in server_address) {
    struct hostent *server = gethostbyname(request);
    if (server == NULL)
        handle_error("Failed to get server by name");

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0)
        handle_error("Failed to create socket");

    struct sockaddr_in server_sock_address = {.sin_family = AF_INET,
                                               .sin_port = htons(SERVER_PORT)};
    memcpy(&server_sock_address.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

    if (connect(server_socket, (struct sockaddr*)&server_sock_address, sizeof(server_sock_address)) < 0)
        handle_error("Failed to connect to server");

    const char *proxy_response = "HTTP/1.0 200 OK\r\n\r\n";
    send(client_socket, proxy_response, strlen(proxy_response), MSG_NOSIGNAL);

    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        send(server_socket, buffer, bytes_received, MSG_NOSIGNAL);
        memset(buffer, 0, BUFFER_SIZE);
    }

    close(server_socket);
}

void start_server() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0)
        handle_error("Failed to create socket");

    struct sockaddr_in server_address = {.sin_family = AF_INET,
                                         .sin_addr.s_addr = INADDR_ANY,
                                         .sin_port = htons(SERVER_PORT)};

    if (bind(server_socket, (struct sockaddr*) &server_address,sizeof(server_address)) < 0)
        handle_error("Failed to bind");

    if (listen(server_socket, 5) != 0)
        handle_error("Failed to listen");

    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_size = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_address_size);
        if (client_socket < 0)
            handle_error("Failed to accept client connection");

        char buffer[BUFFER_SIZE];
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received < 0)
            handle_error("Failed to read from client");

        printf("Received request:\n%s\n", buffer);

        char *request = strtok(buffer, " ");
        request = strtok(NULL, " ");
        request = strtok(request, "/");
        request = strtok(NULL, "/");

        send_data(client_socket, request, server_address);

        close(client_socket);
    }

    close(server_socket);
}

int main() {
    start_server();
    return 0;
}