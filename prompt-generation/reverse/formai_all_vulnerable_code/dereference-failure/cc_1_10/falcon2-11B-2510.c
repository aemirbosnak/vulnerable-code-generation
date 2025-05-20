//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: lively
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int listen_socket, client_socket, port_number, n;
    struct sockaddr_in server_addr, client_addr;

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    port_number = atoi(argv[1]);

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket < 0) {
        perror("socket");
        return 1;
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port_number);

    if (bind(listen_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(listen_socket, 5) < 0) {
        perror("listen");
        return 1;
    }

    while (1) {
        client_socket = accept(listen_socket, (struct sockaddr *) &client_addr, (socklen_t *) &n);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }

        printf("Got a connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        char buffer[256];
        bzero(buffer, 256);

        while ((n = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
            printf("Received %d bytes from %s:%d: %s\n", n, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), buffer);
            send(client_socket, buffer, n, 0);
        }

        printf("Connection closed from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        close(client_socket);
    }

    return 0;
}