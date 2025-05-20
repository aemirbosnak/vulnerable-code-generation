//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 4096
#define BACKLOG 10
#define TRUE 1
#define FALSE 0

int main(int argc, char **argv) {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_LINE];
    int addrlen;
    int opt = TRUE;
    setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(listen_socket, BACKLOG) < 0) {
        perror("listen");
        exit(1);
    }

    while (TRUE) {
        addrlen = sizeof(client_addr);
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &addrlen);
        if (client_socket < 0) {
            perror("accept");
            exit(1);
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (TRUE) {
            memset(buffer, 0, MAX_LINE);
            if (recv(client_socket, buffer, MAX_LINE, 0) <= 0) {
                if (errno!= EWOULDBLOCK) {
                    perror("recv");
                    exit(1);
                }
                break;
            }

            send(client_socket, buffer, strlen(buffer), 0);
        }

        close(client_socket);
    }

    close(listen_socket);
    return 0;
}