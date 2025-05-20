//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096
#define HTTP_PORT 80
#define MAX_CLIENTS 10

struct client {
    int sock;
    char ip[16];
    int port;
};

int main(int argc, char *argv[]) {
    int listen_sock, client_sock, addrlen;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int ret;
    int num_clients = 0;
    struct client clients[MAX_CLIENTS];

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(HTTP_PORT);

    ret = bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    ret = listen(listen_sock, MAX_CLIENTS);
    if (ret == -1) {
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

        if (num_clients >= MAX_CLIENTS) {
            send(client_sock, "HTTP/1.1 503 Service Unavailable\r\nContent-Length: 0\r\nConnection: close\r\n\r\n", 78, 0);
            close(client_sock);
            continue;
        }

        clients[num_clients].sock = client_sock;
        strncpy(clients[num_clients].ip, inet_ntoa(client_addr.sin_addr), 16);
        clients[num_clients].port = ntohs(client_addr.sin_port);
        num_clients++;

        printf("Client connected: %s:%d\n", clients[num_clients-1].ip, clients[num_clients-1].port);
    }

    return 0;
}