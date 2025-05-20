//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    char *host = argv[1];
    char *port = argv[2];

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));

    struct hostent *host_ent = gethostbyname(host);
    if (host_ent == NULL) {
        fprintf(stderr, "Error resolving host: %s\n", host);
        exit(1);
    }

    memcpy(&server_addr.sin_addr, host_ent->h_addr, host_ent->h_length);

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in client_addr;
    socklen_t client_addr_size = sizeof(client_addr);

    while (1) {
        int new_socket = accept(client_socket, (struct sockaddr *)&client_addr, &client_addr_size);
        if (new_socket == -1) {
            fprintf(stderr, "Error accepting connection: %s\n", strerror(errno));
            exit(1);
        }

        char buffer[BUFFER_SIZE];
        int bytes_received = 0;

        while ((bytes_received = recv(new_socket, buffer, BUFFER_SIZE, 0)) > 0) {
            send(server_socket, buffer, bytes_received, 0);
        }

        close(new_socket);
    }

    return 0;
}