//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 1024
#define BACKLOG 5

int main(int argc, char *argv[]) {
    int listen_sock, client_sock;
    struct sockaddr_in listen_addr, client_addr;
    char buffer[MAX_LINE];
    int addrlen;
    int opt = 1;
    int client_len;

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(atoi(argv[1]));
    listen_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_sock, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(listen_sock, BACKLOG) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    while (1) {
        addrlen = sizeof(client_addr);
        client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &addrlen);
        if (client_sock == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            bzero(buffer, MAX_LINE);
            client_len = recv(client_sock, buffer, MAX_LINE, 0);
            if (client_len <= 0) {
                printf("Client disconnected\n");
                break;
            }

            send(client_sock, buffer, client_len, 0);
        }

        close(client_sock);
    }

    close(listen_sock);
    return 0;
}