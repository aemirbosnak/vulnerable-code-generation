//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error(char *message) {
    perror(message);
    exit(1);
}

void recursive_http_proxy(int client_socket_fd, struct sockaddr_in server_address) {
    int server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd < 0) {
        error("Error opening server socket");
    }

    if (connect(server_socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        error("Error connecting to server");
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    int read_bytes = read(client_socket_fd, buffer, BUFFER_SIZE);
    if (read_bytes < 0) {
        error("Error reading from client socket");
    }

    if (strstr(buffer, "HTTP/") == NULL) {
        error("Invalid HTTP message");
    }

    if (strstr(buffer, "CONNECT") != NULL) {
        int pos = 0;
        for (int i = 0; i < strlen(buffer); i++) {
            if (buffer[i] == ':') {
                pos = i;
                break;
            }
        }
        int port = atoi(buffer + pos + 1);
        char *response = "HTTP/1.1 200 OK\r\n\r\n";
        if (write(client_socket_fd, response, strlen(response)) < 0) {
            error("Error writing to client socket");
        }

        if (dup2(client_socket_fd, STDOUT_FILENO) < 0) {
            error("Error duplicating socket");
        }
        if (dup2(client_socket_fd, STDERR_FILENO) < 0) {
            error("Error duplicating socket");
        }
        if (dup2(server_socket_fd, STDIN_FILENO) < 0) {
            error("Error duplicating socket");
        }
        char *tcpdump_command = calloc(1, 200);
        snprintf(tcpdump_command, 200, "tcpdump -nni wlan0 -w capture.pcap port %d", port);
        system(tcpdump_command);
        return;
    }

    if (write(server_socket_fd, buffer, strlen(buffer)) < 0) {
        error("Error writing to server socket");
    }

    memset(buffer, 0, BUFFER_SIZE);
    while ((read_bytes = read(server_socket_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(client_socket_fd, buffer, read_bytes) < 0) {
            error("Error writing to client socket");
        }
        memset(buffer, 0, BUFFER_SIZE);
    }
    if (read_bytes < 0) {
        error("Error reading from server socket");
    }

    close(server_socket_fd);

    recursive_http_proxy(client_socket_fd, server_address);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        exit(1);
    }

    int client_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket_fd < 0) {
        error("Error opening client socket");
    }

    int port = atoi(argv[2]);
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(port);

    if (bind(client_socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        error("Error binding client socket");
    }

    if (listen(client_socket_fd, 10) < 0) {
        error("Error listening to client socket");
    }

    printf("Proxy server is listening to %s:%d\n", inet_ntoa(server_address.sin_addr), port);

    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_size = sizeof(client_address);
        int client_connection_fd = accept(client_socket_fd, (struct sockaddr *) &client_address, &client_address_size);
        if (client_connection_fd < 0) {
            error("Error accepting client connection");
        }

        char *client_address_str = inet_ntoa(client_address.sin_addr);
        int client_port = ntohs(client_address.sin_port);
        printf("Accepted connection from %s:%d\n", client_address_str, client_port);

        recursive_http_proxy(client_connection_fd, server_address);
        
        printf("Closed connection from %s:%d\n", client_address_str, client_port);
        close(client_connection_fd);
    }

    close(client_socket_fd);

    return 0;
}