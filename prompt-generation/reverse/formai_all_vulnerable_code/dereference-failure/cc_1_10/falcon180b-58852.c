//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define PORT 8080
#define BACKLOG 10
#define MAX_REQUEST_SIZE 4096
#define DOCUMENT_ROOT "./www"

int main() {
    int listen_fd, conn_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len;
    char request[MAX_REQUEST_SIZE];
    FILE *fp;
    char response[4096];

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        addr_len = sizeof(client_addr);
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &addr_len);
        if (conn_fd == -1) {
            perror("accept");
            continue;
        }

        memset(request, 0, MAX_REQUEST_SIZE);
        if (recv(conn_fd, request, MAX_REQUEST_SIZE, 0) == -1) {
            perror("recv");
            close(conn_fd);
            continue;
        }

        fp = fopen(DOCUMENT_ROOT "/index.html", "r");
        if (fp == NULL) {
            snprintf(response, sizeof(response), "HTTP/1.1 404 Not Found\r\nContent-Length: %d\r\n\r\n404 Not Found", strlen(response));
        } else {
            fseek(fp, 0, SEEK_END);
            int file_size = ftell(fp);
            fseek(fp, 0, SEEK_SET);
            char buffer[file_size];
            fread(buffer, 1, file_size, fp);
            fclose(fp);

            snprintf(response, sizeof(response), "HTTP/1.1 200 OK\r\nContent-Length: %d\r\n\r\n%s", strlen(buffer), buffer);
        }

        send(conn_fd, response, strlen(response), 0);
        close(conn_fd);
    }

    return 0;
}