//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAX_LINE 1024
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_LINE];
    int addrlen;
    int opt = 1;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port> <ip>\n", argv[0]);
        exit(1);
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, argv[2], &server_addr.sin_addr);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error binding socket\n");
        exit(1);
    }

    if (listen(listen_socket, BACKLOG) == -1) {
        fprintf(stderr, "Error listening on socket\n");
        exit(1);
    }

    while (1) {
        addrlen = sizeof(client_addr);
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &addrlen);

        if (client_socket == -1) {
            fprintf(stderr, "Error accepting connection\n");
            continue;
        }

        fprintf(stdout, "Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            bzero(buffer, MAX_LINE);
            memset(buffer, 0, MAX_LINE);

            if (recv(client_socket, buffer, MAX_LINE, 0) <= 0) {
                fprintf(stdout, "Client disconnected\n");
                close(client_socket);
                break;
            }

            send(client_socket, buffer, strlen(buffer), 0);
        }
    }

    close(listen_socket);
    return 0;
}