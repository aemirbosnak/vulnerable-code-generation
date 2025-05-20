//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int master_socket, client_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int addrlen;
    int opt = 1;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port> <server_ip>\n", argv[0]);
        exit(1);
    }

    master_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (master_socket == -1) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, argv[2], &server_addr.sin_addr);

    if (bind(master_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error binding socket\n");
        exit(1);
    }

    if (listen(master_socket, MAX_CLIENTS) == -1) {
        fprintf(stderr, "Error listening on socket\n");
        exit(1);
    }

    printf("Proxy server started on port %s\n", argv[1]);

    while (1) {
        addrlen = sizeof(client_addr);
        new_socket = accept(master_socket, (struct sockaddr *)&client_addr, &addrlen);

        if (new_socket == -1) {
            fprintf(stderr, "Error accepting connection\n");
            continue;
        }

        printf("New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            int bytes_received = recv(new_socket, buffer, BUFFER_SIZE, 0);

            if (bytes_received <= 0) {
                fprintf(stderr, "Error receiving data from client\n");
                close(new_socket);
                break;
            }

            send(master_socket, buffer, bytes_received, 0);
        }

        close(new_socket);
    }

    return 0;
}