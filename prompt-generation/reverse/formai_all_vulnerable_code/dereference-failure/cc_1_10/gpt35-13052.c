//FormAI DATASET v1.0 Category: Simple Web Server ; Style: realistic
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void handle_request(int socket_fd) {
    char buffer[256];
    FILE *fd;

    fd = fopen("index.html", "r");

    if (fd) {
        // read the file
        fread(buffer, sizeof(buffer), 1, fd);

        // send response
        write(socket_fd, "HTTP/1.1 200 OK\n", 16);
        write(socket_fd, "Content-Length: 100\n", 20);
        write(socket_fd, "Content-Type: text/html\n\n", 25);

        write(socket_fd, buffer, strlen(buffer));
    } else {
        // send 404 error
        char *error_message = "<html><head><title>404 Not Found</title></head><body><h1>404 Not Found</h1><p>The requested URL was not found on this server.</p></body></html>";

        write(socket_fd, "HTTP/1.1 404 Not Found\n", 22);
        write(socket_fd, "Content-Length: 100\n", 20);
        write(socket_fd, "Content-Type: text/html\n\n", 25);

        write(socket_fd, error_message, strlen(error_message));
    }

    close(socket_fd);
}

int main() {
    int server_socket_fd, new_socket_fd, port_number;
    socklen_t client_length;

    char buffer[256];
    struct sockaddr_in server_address, client_address;

    // create a new socket
    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    // setup server_address
    memset(&server_address, 0, sizeof(server_address));
    port_number = 8080;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // bind socket to address and port
    if (bind(server_socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error binding socket\n");
        return 1;
    }

    // start listening on the socket
    if (listen(server_socket_fd, 5) < 0) {
        printf("Error listening on socket\n");
        return 1;
    }

    // accept connections and handle them
    while (1) {
        client_length = sizeof(client_address);
        new_socket_fd = accept(server_socket_fd, (struct sockaddr *)&client_address, &client_length);

        if (new_socket_fd < 0) {
            printf("Error accepting connection\n");
            continue;
        }

        pid_t pid = fork();

        if (pid < 0) {
            printf("Error forking process\n");
            continue;
        } else if (pid > 0) { // parent process
            close(new_socket_fd);
        } else if (pid == 0) { // child process
            handle_request(new_socket_fd);
            exit(0);
        }
    }

    return 0;
}