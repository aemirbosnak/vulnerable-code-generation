//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_LINE 1024

// Function prototypes
int create_socket(int port);
void error(const char *msg);

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    listen_socket = create_socket(atoi(argv[1]));

    while (1) {
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &addrlen);

        if (client_socket == -1) {
            error("accept");
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        char buffer[MAX_LINE];
        while (fgets(buffer, MAX_LINE, stdin)!= NULL) {
            send(client_socket, buffer, strlen(buffer), 0);
        }

        close(client_socket);
    }

    return 0;
}

int create_socket(int port) {
    int socket_fd;
    struct sockaddr_in server_addr;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_fd == -1) {
        error("socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error("bind");
    }

    if (listen(socket_fd, 5) == -1) {
        error("listen");
    }

    return socket_fd;
}

void error(const char *msg) {
    perror(msg);
    exit(1);
}