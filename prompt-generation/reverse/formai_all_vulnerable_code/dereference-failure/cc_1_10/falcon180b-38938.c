//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define TRUE 1
#define FALSE 0
#define BUF_SIZE 4096

int main(int argc, char *argv[]) {
    int listen_sock, client_sock;
    int opt = TRUE;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUF_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <port> <ip>\n", argv[0]);
        return 1;
    }

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1) {
        printf("Failed to create socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, argv[2], &server_addr.sin_addr);

    if (bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Failed to bind socket\n");
        return 1;
    }

    if (listen(listen_sock, 5) == -1) {
        printf("Failed to listen on socket\n");
        return 1;
    }

    while (opt) {
        socklen_t addr_size;
        client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &addr_size);
        if (client_sock == -1) {
            printf("Failed to accept connection\n");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (TRUE) {
            memset(buffer, 0, BUF_SIZE);
            ssize_t bytes_received = recv(client_sock, buffer, BUF_SIZE - 1, 0);
            if (bytes_received <= 0) {
                printf("Client disconnected\n");
                close(client_sock);
                break;
            }

            send(client_sock, buffer, bytes_received, 0);
        }

        close(client_sock);
    }

    close(listen_sock);
    return 0;
}