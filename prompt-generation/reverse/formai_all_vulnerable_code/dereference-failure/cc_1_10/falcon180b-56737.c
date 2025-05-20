//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
    int listen_sock, client_sock;
    struct sockaddr_in listen_addr, client_addr;
    int addr_len;
    char buffer[BUFFER_SIZE];
    int bytes_recv;

    if (argc!= 3) {
        printf("Usage: %s <port> <host>\n", argv[0]);
        return 1;
    }

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1) {
        printf("Error: Could not create socket.\n");
        return 1;
    }

    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, argv[2], &listen_addr.sin_addr);

    if (bind(listen_sock, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) {
        printf("Error: Could not bind socket.\n");
        close(listen_sock);
        return 1;
    }

    if (listen(listen_sock, 5) == -1) {
        printf("Error: Could not listen on socket.\n");
        close(listen_sock);
        return 1;
    }

    printf("Server listening on port %d...\n", ntohs(listen_addr.sin_port));

    while (TRUE) {
        addr_len = sizeof(client_addr);
        client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &addr_len);
        if (client_sock == -1) {
            printf("Error: Could not accept connection.\n");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (TRUE) {
            bytes_recv = recv(client_sock, buffer, BUFFER_SIZE, 0);
            if (bytes_recv <= 0) {
                printf("Connection closed by %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                break;
            }

            send(client_sock, buffer, bytes_recv, 0);
        }

        close(client_sock);
    }

    close(listen_sock);
    return 0;
}