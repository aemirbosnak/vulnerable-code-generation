//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int listen_socket, client_socket, bytes_received;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <port> <host>\n", argv[0]);
        exit(1);
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        printf("Socket creation failed: %s\n", strerror(errno));
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    if (inet_pton(AF_INET, argv[2], &server_addr.sin_addr) <= 0) {
        printf("Invalid host address\n");
        exit(1);
    }

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Bind failed: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(listen_socket, 5) == -1) {
        printf("Listen failed: %s\n", strerror(errno));
        exit(1);
    }

    printf("Proxy listening on port %s\n", argv[1]);

    while (1) {
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (client_socket == -1) {
            printf("Accept failed: %s\n", strerror(errno));
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
            send(client_socket, buffer, bytes_received, 0);
        }

        close(client_socket);
    }

    return 0;
}