//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <server_port>\n", argv[0]);
        return 1;
    }

    int server_port = atoi(argv[1]);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return 1;
    }

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        close(server_socket);
        return 1;
    }

    if (listen(server_socket, 5) == -1) {
        perror("listen");
        close(server_socket);
        return 1;
    }

    int client_socket = accept(server_socket, NULL, NULL);
    if (client_socket == -1) {
        perror("accept");
        close(server_socket);
        return 1;
    }

    char buffer[256];
    int bytes_read = read(client_socket, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("read");
        close(client_socket);
        close(server_socket);
        return 1;
    }
    buffer[bytes_read] = '\0';

    printf("Received: %s\n", buffer);

    close(client_socket);
    close(server_socket);
    return 0;
}