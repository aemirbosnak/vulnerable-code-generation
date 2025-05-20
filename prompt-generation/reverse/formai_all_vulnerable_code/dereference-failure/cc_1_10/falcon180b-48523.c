//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int socket_fd;
    struct sockaddr_in server_addr;
    int opt = 1;
    char *message = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: Close\r\n\r\n";
    char buffer[BUFFER_SIZE];
    int addrlen = sizeof(server_addr);

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("socket");
        exit(1);
    }

    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080);

    if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(socket_fd, 5) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        int client_fd = accept(socket_fd, (struct sockaddr *)&server_addr, &addrlen);
        if (client_fd == -1) {
            perror("accept");
            exit(1);
        }

        char *request = (char *)malloc(BUFFER_SIZE);
        memset(request, 0, BUFFER_SIZE);
        read(client_fd, request, BUFFER_SIZE);

        if (strcmp(request, "GET / HTTP/1.1") == 0) {
            send(client_fd, message, strlen(message), 0);
        } else {
            send(client_fd, "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\nConnection: Close\r\n\r\n", strlen("HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\nConnection: Close\r\n\r\n"), 0);
        }

        close(client_fd);
        free(request);
    }

    close(socket_fd);
    return 0;
}