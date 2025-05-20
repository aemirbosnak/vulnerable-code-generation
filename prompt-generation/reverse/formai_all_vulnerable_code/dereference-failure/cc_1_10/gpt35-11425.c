//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void handle_error(const char* message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("Usage: %s remote_host remote_port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *remote_host = argv[1];
    int remote_port = atoi(argv[2]);

    // create socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        handle_error("Error creating socket");
    }

    struct sockaddr_in server_address = {0};
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    // bind socket
    if (bind(server_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        handle_error("Error binding socket");
    }

    // listen
    if (listen(server_fd, 5) < 0) {
        handle_error("Error listening on socket");
    }

    struct sockaddr_in client_address = {0};
    socklen_t client_address_len = sizeof(client_address);

    while (1) {

        // accept incoming connection
        int client_fd = accept(server_fd, (struct sockaddr*)&client_address, &client_address_len);
        if (client_fd < 0) {
            handle_error("Error accepting connection");
        }

        // read request from client
        char buffer[BUFFER_SIZE] = {0};
        ssize_t bytes_read = read(client_fd, buffer, BUFFER_SIZE - 1);
        if (bytes_read < 0) {
            handle_error("Error reading from client");
        }

        // establish connection to remote host
        int remote_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (remote_fd < 0) {
            handle_error("Error creating socket");
        }

        struct sockaddr_in remote_address = {0};
        remote_address.sin_family = AF_INET;
        remote_address.sin_addr.s_addr = inet_addr(remote_host);
        remote_address.sin_port = htons(remote_port);

        if (connect(remote_fd, (struct sockaddr*)&remote_address, sizeof(remote_address)) < 0) {
            handle_error("Error connecting to remote host");
        }

        // forward request to remote host
        if (write(remote_fd, buffer, bytes_read) < 0) {
            handle_error("Error writing to remote host");
        }

        // read response from remote host
        bytes_read = 0;
        do {
            int bytes = read(remote_fd, buffer + bytes_read, BUFFER_SIZE - bytes_read - 1);
            if (bytes < 0) {
                handle_error("Error reading from remote host");
            }
            bytes_read += bytes;
        } while (bytes_read < BUFFER_SIZE && buffer[bytes_read - 1] != '\n');

        // forward response to client
        if (write(client_fd, buffer, bytes_read) < 0) {
            handle_error("Error writing to client");
        }

        close(remote_fd);
        close(client_fd);
    }

    return 0;
}