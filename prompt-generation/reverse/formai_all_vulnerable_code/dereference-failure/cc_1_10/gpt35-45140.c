//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define PORT 8080

void handle_client(int client_socket_fd) {
    char request_buffer[4096];
    char server_response_buffer[4096];
    char *headers_end = NULL;

    // Read client's HTTP request
    if (recv(client_socket_fd, request_buffer, sizeof(request_buffer), 0) < 0) {
        perror("recv() failed");
        return;
    }

    // Identify the hostname and port from the request
    char *first_endline = strchr(request_buffer, '\n');
    char *second_endline = strchr(first_endline + 1, '\n');
    
    if (!first_endline || !second_endline) {
        fprintf(stderr, "Failed to parse HTTP request: malformed\n");
        return;
    }
    
    size_t host_len = second_endline - (first_endline + 1);
    char *host = malloc(host_len + 1);
    strncpy(host, first_endline + 1, host_len);
    host[host_len] = '\0';

    char *port_str = strchr(host, ':');
    if (port_str) {
        *port_str = '\0';
        port_str++;
    } else {
        port_str = "80";
    }

    printf("Proxy connecting to host: %s, port: %s\n", host, port_str);
    
    // Connect to the remote server
    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(host, port_str, &hints, &result) != 0) {
        fprintf(stderr, "Failed to get the addrinfo of host: %s\n", host);
        return;
    }
    
    int server_socket_fd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (server_socket_fd < 0) {
        perror("socket() failed");
        return;
    }

    if (connect(server_socket_fd, result->ai_addr, result->ai_addrlen) < 0) {
        perror("connect() failed");
        return;
    }

    freeaddrinfo(result);

    // Forward request to the server
    size_t request_len = strlen(request_buffer);
    if (write(server_socket_fd, request_buffer, request_len) != request_len) {
        perror("Failed to write the full request to the server");
        return;
    }

    // Read server's HTTP response
    ssize_t read_result;
    int total_response_len = 0;
    while ((read_result = recv(server_socket_fd, server_response_buffer + total_response_len, sizeof(server_response_buffer) - total_response_len, 0)) > 0) {
        total_response_len += read_result;

        if (!headers_end) {
            headers_end = strstr(server_response_buffer, "\r\n\r\n");
            if (headers_end) {
                *headers_end = '\0';
            }
        }

        send(client_socket_fd, server_response_buffer + total_response_len - read_result, read_result, 0);
    }

    if (read_result < 0) {
        perror("recv() failed");
        return;
    }

    // Close the sockets
    close(server_socket_fd);
    close(client_socket_fd);
}

int main(int argc, char **argv) {
    int server_socket_fd, client_socket_fd;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);

    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd < 0) {
        perror("socket() failed");
        return -1;
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind() failed");
        return -1;
    }

    if (listen(server_socket_fd, 5) < 0) {
        perror("listen() failed");
        return -1;
    }

    while (1) {
        client_socket_fd = accept(server_socket_fd, (struct sockaddr *)&client_address, &client_address_len);
        if (client_socket_fd < 0) {
            perror("accept() failed");
            continue;
        }

        handle_client(client_socket_fd);
    }

    return 0;
}