//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 8192
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_LINE];
    int addrlen;
    int opt = 1;
    int client_socket;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port> <ip>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket failed");
        exit(1);
    }

    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = inet_addr(argv[2]);

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind failed");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Proxy Server is running on port %s\n", argv[1]);

    while (1) {
        addrlen = sizeof(client_addr);
        client_socket = accept(listen_fd, (struct sockaddr *)&client_addr, &addrlen);

        if (client_socket == -1) {
            perror("accept");
            exit(1);
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, sizeof(buffer));
            if (recv(client_socket, buffer, MAX_LINE, 0) <= 0) {
                break;
            }

            send(client_socket, buffer, strlen(buffer), 0);
        }

        close(client_socket);
    }

    return 0;
}