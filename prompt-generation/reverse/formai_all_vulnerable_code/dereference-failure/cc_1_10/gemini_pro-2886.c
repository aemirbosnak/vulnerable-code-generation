//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

void handle_client(int client_sock) {
    char buffer[1024];
    int bytes_received;
    while ((bytes_received = recv(client_sock, buffer, sizeof(buffer), 0)) > 0) {
        char* host = strchr(buffer, '\n') + 1;
        char* path = strchr(host, '/') + 1;
        *host = '\0';
        *path = '\0';
        printf("Host: %s\n", host);
        printf("Path: %s\n", path);

        struct sockaddr_in server_addr;
        int server_sock;
        if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            perror("socket");
            exit(1);
        }

        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(80);
        if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
            perror("inet_pton");
            exit(1);
        }

        if (connect(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
            perror("connect");
            exit(1);
        }

        send(server_sock, buffer, bytes_received, 0);

        char server_buffer[1024];
        int server_bytes_received;
        while ((server_bytes_received = recv(server_sock, server_buffer, sizeof(server_buffer), 0)) > 0) {
            send(client_sock, server_buffer, server_bytes_received, 0);
        }

        close(server_sock);
    }

    if (bytes_received < 0) {
        perror("recv");
    }
}

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr;

    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(server_sock, 5) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        if ((client_sock = accept(server_sock, NULL, NULL)) < 0) {
            perror("accept");
        }

        handle_client(client_sock);

        close(client_sock);
    }

    return 0;
}