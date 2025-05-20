//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096
#define MAX_CLIENTS 10

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port> <upstream_server>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    char *upstream_server = argv[2];

    int listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in listen_addr;
    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = INADDR_ANY;
    listen_addr.sin_port = htons(port);

    if (bind(listen_socket, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) {
        fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
        close(listen_socket);
        return 1;
    }

    if (listen(listen_socket, MAX_CLIENTS) == -1) {
        fprintf(stderr, "Error listening on socket: %s\n", strerror(errno));
        close(listen_socket);
        return 1;
    }

    fprintf(stdout, "Proxy server listening on port %d\n", port);

    while (1) {
        int client_socket = accept(listen_socket, NULL, NULL);
        if (client_socket == -1) {
            fprintf(stderr, "Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        fprintf(stdout, "Client connected\n");

        char buffer[BUFFER_SIZE];
        int bytes_read = 0;

        while ((bytes_read = read(client_socket, buffer, BUFFER_SIZE)) > 0) {
            send(client_socket, buffer, bytes_read, 0);
        }

        close(client_socket);
    }

    close(listen_socket);
    return 0;
}