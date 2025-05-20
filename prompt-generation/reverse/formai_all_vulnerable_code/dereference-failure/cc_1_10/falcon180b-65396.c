//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    char buffer[MAX_LINE];

    if (argc!= 3) {
        printf("Usage: %s <IP> <Port>\n", argv[0]);
        return 1;
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(listen_socket, 5) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    while (1) {
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, MAX_LINE);
            int bytes_received = recv(client_socket, buffer, MAX_LINE, 0);

            if (bytes_received <= 0) {
                printf("Client disconnected\n");
                close(client_socket);
                break;
            }

            send(client_socket, buffer, bytes_received, 0);
        }
    }

    close(listen_socket);
    return 0;
}