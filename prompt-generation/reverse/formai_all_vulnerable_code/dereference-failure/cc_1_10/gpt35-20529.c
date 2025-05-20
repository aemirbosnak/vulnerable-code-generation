//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define DEFAULT_PORT 8080

char *change_request(char *request) {
    char *modified = (char *) malloc(BUFFER_SIZE);
    char *token;
    char *method;
    char *path;
    char *protocol;
    char *host;

    token = strtok(request, " ");
    method = token;
    token = strtok(NULL, " ");
    path = token;
    token = strtok(NULL, "\r\n");
    protocol = token;

    snprintf(modified, BUFFER_SIZE, "%s %s %s\r\nHost: %s\r\nConnection: close\r\n\r\n", method, path, protocol, host);

    return modified;
}

int main(int argc, char *argv[]) {
    int proxy_sock, client_sock, server_sock;
    int client_port;
    struct sockaddr_in addr_client, addr_server;
    socklen_t addr_len = sizeof(struct sockaddr_in);

    char buffer[BUFFER_SIZE];
    char *modified_request = NULL;
    ssize_t recv_size;
    int optval = 1;

    if (argc != 2) {
        printf("Usage: %s <port>\nUsing default port %d\n", argv[0], DEFAULT_PORT);
        client_port = DEFAULT_PORT;
    } else {
        client_port = atoi(argv[1]);
    }

    if ((proxy_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(proxy_sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(int)) < 0) {
        perror("setsockopt() failed");
        exit(EXIT_FAILURE);
    }

    memset(&addr_client, 0, addr_len);
    addr_client.sin_family = AF_INET;
    addr_client.sin_addr.s_addr = htonl(INADDR_ANY);
    addr_client.sin_port = htons(client_port);

    if (bind(proxy_sock, (struct sockaddr *) &addr_client, addr_len) < 0) {
        perror("bind() failed");
        exit(EXIT_FAILURE);
    }

    if (listen(proxy_sock, 10) < 0) {
        perror("listen() failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        if ((client_sock = accept(proxy_sock, (struct sockaddr *) &addr_client, &addr_len)) < 0) {
            perror("accept() failed");
            continue;
        }

        if ((server_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
            perror("socket() failed");
            close(client_sock);
            continue;
        }

        if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(int)) < 0) {
            perror("setsockopt() failed");
            close(client_sock);
            close(server_sock);
            continue;
        }

        memset(&addr_server, 0, addr_len);
        addr_server.sin_family = AF_INET;
        addr_server.sin_port = htons(80);

        if (inet_aton("127.0.0.1", &addr_server.sin_addr) == 0) {
            perror("inet_aton() failed");
            close(client_sock);
            close(server_sock);
            continue;
        }

        if (connect(server_sock, (struct sockaddr *) &addr_server, addr_len) < 0) {
            perror("connect() failed");
            close(client_sock);
            close(server_sock);
            continue;
        }

        while ((recv_size = recv(client_sock, buffer, BUFFER_SIZE, 0)) > 0) {
            buffer[recv_size] = '\0';

            if (!modified_request) {
                modified_request = change_request(buffer);
            }

            if (send(server_sock, buffer, recv_size, 0) < 0) {
                perror("send() failed");
                close(client_sock);
                close(server_sock);
                free(modified_request);
                continue;
            }

            if ((recv_size = recv(server_sock, buffer, BUFFER_SIZE, 0)) < 0) {
                perror("recv() failed");
                close(client_sock);
                close(server_sock);
                free(modified_request);
                continue;
            }

            if (recv_size == 0) {
                close(client_sock);
                close(server_sock);
                free(modified_request);
                break;
            }

            if (send(client_sock, buffer, recv_size, 0) < 0) {
                perror("send() failed");
                close(client_sock);
                close(server_sock);
                free(modified_request);
                continue;
            }
        }

        free(modified_request);
        close(client_sock);
        close(server_sock);
    }

    close(proxy_sock);

    return 0;
}