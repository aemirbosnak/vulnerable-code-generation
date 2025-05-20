//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 8192
#define HTTP_PORT 80

void handle(int client_fd, struct sockaddr_in client_addr, int proxy_fd);
int connect_to_server(char *ip_addr);

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int proxy_port = atoi(argv[1]);
    int proxy_fd;
    struct sockaddr_in proxy_addr;

    proxy_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_fd == -1) {
        perror("socket");
        exit(1);
    }

    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(proxy_port);

    if (bind(proxy_fd, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(proxy_fd, 10) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Waiting for connections...\n");

    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    int client_fd;
    pid_t child_pid;

    while (1) {
        client_fd = accept(proxy_fd, (struct sockaddr *)&client_addr, &client_len);
        if (client_fd == -1) {
            perror("accept");
            continue;
        }

        child_pid = fork();
        if (child_pid == -1) {
            perror("fork");
            exit(1);
        }

        printf("Received connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        if (child_pid == 0) { /* child process */
            close(proxy_fd);
            handle(client_fd, client_addr, connect_to_server("127.0.0.1"));
            close(client_fd);
            exit(0);
        } else { /* parent process */
            close(client_fd);
        }
    }
}

void handle(int client_fd, struct sockaddr_in client_addr, int proxy_fd) {
    char request[BUFSIZE], buffer[BUFSIZE];
    int nbytes_read;

    nbytes_read = read(client_fd, request, BUFSIZE);
    if (nbytes_read == -1) {
        perror("read");
        return;
    }

    printf("Received request from %s:%d of length %d:\n%s\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), nbytes_read, request);

    /* Forward request to server */
    if (write(proxy_fd, request, nbytes_read) == -1) {
        perror("write");
        return;
    }

    /* Read response from server */
    while ((nbytes_read = read(proxy_fd, buffer, BUFSIZE)) > 0) {
        if (write(client_fd, buffer, nbytes_read) == -1) {
            perror("write");
            return;
        }
    }
}

int connect_to_server(char *ip_addr) {
    int server_fd;
    struct sockaddr_in server_addr;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_addr);
    server_addr.sin_port = htons(HTTP_PORT);

    if (connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    return server_fd;
}