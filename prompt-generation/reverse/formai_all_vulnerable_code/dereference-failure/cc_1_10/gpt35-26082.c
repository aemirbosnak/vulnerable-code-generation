//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFFER_SIZE 4096

void handle_client(int client_fd, char *proxy_ip, int proxy_port) {
    int server_fd, n;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE], request[BUFFER_SIZE], response[BUFFER_SIZE];

    bzero(buffer, BUFFER_SIZE);
    n = read(client_fd, buffer, BUFFER_SIZE);

    if (n <= 0) {
        perror("read error");
        close(client_fd);
        return;
    }

    sprintf(request, "%s", buffer);

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(proxy_port);
    inet_pton(AF_INET, proxy_ip, &server_addr.sin_addr);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (connect(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect error");
        close(client_fd);
        close(server_fd);
        return;
    }

    write(server_fd, buffer, strlen(buffer));
    bzero(buffer, BUFFER_SIZE);

    while ((n = read(server_fd, buffer, BUFFER_SIZE - 1)) > 0) {
        write(client_fd, buffer, n);
        bzero(buffer, BUFFER_SIZE);
    }

    close(client_fd);
    close(server_fd);
}

int main(int argc, char *argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t len = sizeof(client_addr);

    if (argc != 3) {
        perror("Usage: ./proxy <proxy_ip> <proxy_port>");
        exit(1);
    }

    bzero(&server_addr, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (bind(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) != 0) {
        perror("bind error");
        exit(1);
    }

    if (listen(server_fd, 10) != 0) {
        perror("listen error");
        exit(1);
    }

    while (1) {
        client_fd = accept(server_fd, (struct sockaddr*) &client_addr, &len);
        handle_client(client_fd, argv[1], atoi(argv[2]));
    }

    return 0;
}