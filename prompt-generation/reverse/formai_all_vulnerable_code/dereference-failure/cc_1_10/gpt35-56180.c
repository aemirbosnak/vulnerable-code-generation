//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int port = atoi(argv[1]);

    int server_sock_fd, client_sock_fd;
    socklen_t client_len;
    struct sockaddr_in server_addr, client_addr;

    if ((server_sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        error("Failed to create socket");

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_sock_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1)
        error("Failed to bind socket");

    if (listen(server_sock_fd, 5) == -1)
        error("Failed to listen for connections");

    printf("Proxy Server started on port %d...\n", port);

    char buffer[BUFFER_SIZE];
    int bytes_read, bytes_written;

    while (1) {
        client_len = sizeof(client_addr);
        if ((client_sock_fd = accept(server_sock_fd, (struct sockaddr *) &client_addr, &client_len)) == -1)
            error("Failed to accept client connection");

        printf("Client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        if ((bytes_read = read(client_sock_fd, buffer, BUFFER_SIZE)) == -1)
            error("Failed to read from client");

        printf("Request:\n%s\n", buffer);

        char *http_host = strstr(buffer, "Host: ");
        if (http_host == NULL) {
            error("Invalid request");
        }

        char *host = http_host + strlen("Host: ");
        char *end_of_line = strchr(host, '\n');
        if (end_of_line == NULL) {
            error("Invalid request");
        }

        *end_of_line = '\0';

        printf("Connecting to host %s...\n", host);

        struct sockaddr_in server;
        bzero((char *) &server, sizeof(server));
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = inet_addr(host);
        server.sin_port = htons(80);

        int server_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sock_fd < 0)
            error("Failed to create socket");

        if (connect(server_sock_fd, (struct sockaddr *) &server, sizeof(server)) < 0)
            error("Failed to connect to server");

        if (write(server_sock_fd, buffer, bytes_read) < 0)
            error("Failed to write to server");

        bzero(buffer, BUFFER_SIZE);

        while ((bytes_read = read(server_sock_fd, buffer, BUFFER_SIZE)) > 0) {
            if ((bytes_written = write(client_sock_fd, buffer, bytes_read)) < 0)
                error("Failed to write to client");
            bzero(buffer, BUFFER_SIZE);
        }

        if (bytes_read == -1)
            error("Failed to read from server");

        close(client_sock_fd);
        close(server_sock_fd);
    }
    return 0;
}