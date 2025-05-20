//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LINE 4096
#define SERVER_PORT 8080

void set_socket_non_blocking(int socket_fd) {
    int flags = fcntl(socket_fd, F_GETFL, 0);
    fcntl(socket_fd, F_SETFL, flags | O_NONBLOCK);
}

void handle_client(int client_socket_fd) {
    int server_socket_fd;
    struct sockaddr_in server_address;
    char buffer[MAX_LINE];
    ssize_t bytes_read;

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(SERVER_PORT);

    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    set_socket_non_blocking(server_socket_fd);

    if (connect(server_socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == 0) {
        printf("Connected to server\n");
    } else if (errno != EINPROGRESS) {
        perror("Error connecting to server");
        exit(1);
    }

    while (1) {
        memset(buffer, 0, MAX_LINE);
        bytes_read = recv(client_socket_fd, buffer, MAX_LINE, 0);
        if (bytes_read < 0 && errno != EWOULDBLOCK) {
            perror("Error reading from client");
            exit(1);
        } else if (bytes_read == 0) {
            break;
        } else if (bytes_read > 0) {
            send(server_socket_fd, buffer, bytes_read, 0);
        }

        memset(buffer, 0, MAX_LINE);
        bytes_read = recv(server_socket_fd, buffer, MAX_LINE, 0);
        if (bytes_read < 0 && errno != EWOULDBLOCK) {
            perror("Error reading from server");
            exit(1);
        } else if (bytes_read == 0) {
            break;
        } else if (bytes_read > 0) {
            send(client_socket_fd, buffer, bytes_read, 0);
        }
    }

    close(server_socket_fd);
    close(client_socket_fd);
}

void start_server() {
    struct sockaddr_in server_address, client_address;
    socklen_t client_length;
    int server_socket_fd, client_socket_fd;
    int opt = 1;
    int bind_result;

    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(server_socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    set_socket_non_blocking(server_socket_fd);

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(SERVER_PORT);

    bind_result = bind(server_socket_fd, (struct sockaddr *)&server_address, sizeof(server_address));
    if (bind_result < 0) {
        perror("Error binding server");
        exit(1);
    }

    listen(server_socket_fd, 5);

    while (1) {
        client_length = sizeof(client_address);
        client_socket_fd = accept(server_socket_fd, (struct sockaddr *)&client_address, &client_length);
        if (client_socket_fd < 0 && errno != EWOULDBLOCK) {
            perror("Error accepting client");
            exit(1);
        } else if (client_socket_fd > 0) {
            set_socket_non_blocking(client_socket_fd);
            handle_client(client_socket_fd);
        }
    }
}

int main() {
    start_server();
    return 0;
}