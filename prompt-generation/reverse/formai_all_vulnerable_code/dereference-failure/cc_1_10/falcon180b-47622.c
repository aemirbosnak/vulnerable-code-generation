//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096
#define PROXY_PORT 8080
#define PROXY_HOST "127.0.0.1"

int main(int argc, char **argv) {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PROXY_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(listen_socket, 10) == -1) {
        fprintf(stderr, "Error listening on socket: %s\n", strerror(errno));
        exit(1);
    }

    printf("Proxy server started on port %d\n", atoi(argv[1]));

    while (1) {
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (client_socket == -1) {
            fprintf(stderr, "Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
            send(client_socket, buffer, bytes_received, 0);
        }

        close(client_socket);
    }

    return 0;
}