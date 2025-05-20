//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_CONNECTIONS 5

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        fprintf(stderr, "Failed to create socket\n");
        return 1;
    }

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Failed to bind socket\n");
        return 1;
    }

    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        fprintf(stderr, "Failed to listen on socket\n");
        return 1;
    }

    while (1) {
        int client_fd = accept(server_fd, NULL, NULL);
        if (client_fd < 0) {
            fprintf(stderr, "Failed to accept connection\n");
            return 1;
        }

        char buffer[256];
        int n = read(client_fd, buffer, sizeof(buffer));
        if (n < 0) {
            fprintf(stderr, "Failed to read from client\n");
            close(client_fd);
            continue;
        }

        printf("Received message from client: %s\n", buffer);
        send(client_fd, buffer, n, 0);

        close(client_fd);
    }

    close(server_fd);
    return 0;
}