//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 65535

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {

    int port;
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[1]);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) error("Error opening server socket");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
        error("Error binding server socket");

    if (listen(server_socket, 10) < 0)
        error("Error listening on server socket");

    printf("Proxy server started on port %d...\n", port);

    while (true) {

        socklen_t client_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);

        if (client_socket < 0) error("Error accepting client connection");

        char buffer[MAX_BUFFER_SIZE], request[MAX_BUFFER_SIZE], response[MAX_BUFFER_SIZE];

        memset(buffer, 0, sizeof(buffer));
        memset(request, 0, sizeof(request));
        memset(response, 0, sizeof(response));

        int n = read(client_socket, buffer, sizeof(buffer) - 1);

        if (n < 0) error("Error reading request");

        char* hostname = strtok(buffer + 4, " ");

        struct hostent* server_host = gethostbyname(hostname);

        if (server_host == NULL) {
            fprintf(stderr, "Error: Host not found\n");
            close(client_socket);
            continue;
        }

        int server_socket = socket(AF_INET, SOCK_STREAM, 0);

        if (server_socket < 0) {
            fprintf(stderr, "Error: Unable to create server socket\n");
            close(client_socket);
            continue;
        }

        struct sockaddr_in server_addr;

        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        memcpy(&server_addr.sin_addr.s_addr, server_host->h_addr, server_host->h_length);
        server_addr.sin_port = htons(80);

        if (connect(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
            fprintf(stderr, "Error: Unable to connect to server\n");
            close(client_socket);
            continue;
        }

        write(server_socket, buffer, strlen(buffer));

        while ((n = read(server_socket, response, sizeof(response) - 1)) > 0) {
            write(client_socket, response, n);
            memset(response, 0, sizeof(response)); 
        }

        close(server_socket);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}