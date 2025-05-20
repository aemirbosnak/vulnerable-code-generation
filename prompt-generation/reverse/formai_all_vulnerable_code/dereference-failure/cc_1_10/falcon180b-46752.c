//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int proxy_socket, client_socket;
    struct sockaddr_in proxy_addr, client_addr;
    int opt = 1;
    char buffer[BUFFER_SIZE];

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    setsockopt(proxy_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_port = htons(atoi(argv[1]));
    proxy_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(proxy_socket, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) == -1) {
        printf("Error binding socket: %s\n", strerror(errno));
        return 1;
    }

    if (listen(proxy_socket, 5) == -1) {
        printf("Error listening on socket: %s\n", strerror(errno));
        return 1;
    }

    while (1) {
        client_socket = accept(proxy_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

            if (bytes_received <= 0) {
                printf("Connection closed by client\n");
                close(client_socket);
                break;
            }

            printf("Received %d bytes: %s\n", bytes_received, buffer);

            send(client_socket, buffer, strlen(buffer), 0);
        }
    }

    close(proxy_socket);
    return 0;
}