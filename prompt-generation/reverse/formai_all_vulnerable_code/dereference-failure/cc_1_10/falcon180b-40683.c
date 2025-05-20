//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_LINE 1024
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int listen_sock, client_sock;
    struct sockaddr_in listen_addr, client_addr;
    char buffer[MAX_LINE];
    int numbytes;
    int port = 8080;

    if (argc > 1) {
        port = atoi(argv[1]);
    }

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1) {
        perror("socket");
        exit(1);
    }

    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = INADDR_ANY;
    listen_addr.sin_port = htons(port);

    if (bind(listen_sock, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listen_sock, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    printf("HTTP proxy listening on port %d\n", port);

    while (1) {
        socklen_t addr_size;
        client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &addr_size);
        if (client_sock == -1) {
            perror("accept");
            exit(1);
        }

        printf("Client connected on port %d\n", ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, sizeof(buffer));
            numbytes = recv(client_sock, buffer, MAX_LINE, 0);
            if (numbytes <= 0) {
                close(client_sock);
                break;
            }

            printf("Received %d bytes from client\n", numbytes);

            send(client_sock, buffer, numbytes, 0);
        }
    }

    close(listen_sock);
    return 0;
}