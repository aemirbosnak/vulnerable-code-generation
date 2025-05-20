//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: brave
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define PORT_HTTP  80
#define PORT_PROXY 8888

typedef struct {
    int client_fd;
    struct sockaddr_in client_addr;
} client_info;

void *handle_client(void *arg) {
    client_info *info = (client_info *)arg;
    char buffer[4096];
    int bytes_read;

    // Get the HTTP request from the client
    bytes_read = recv(info->client_fd, buffer, sizeof(buffer), 0);
    if (bytes_read < 0) {
        perror("recv");
        close(info->client_fd);
        free(info);
        return NULL;
    }

    // Parse the HTTP request
    char *host = NULL;
    char *path = NULL;
    if (sscanf(buffer, "GET %s HTTP/1.1\r\nHost: %s\r\n", path, host) != 2) {
        fprintf(stderr, "Invalid HTTP request: %s", buffer);
        close(info->client_fd);
        free(info);
        return NULL;
    }

    // Connect to the destination server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT_HTTP);
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) != 1) {
        fprintf(stderr, "Invalid hostname: %s", host);
        close(info->client_fd);
        free(info);
        return NULL;
    }

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        close(info->client_fd);
        free(info);
        return NULL;
    }

    if (connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        close(info->client_fd);
        close(server_fd);
        free(info);
        return NULL;
    }

    // Send the HTTP request to the destination server
    if (send(server_fd, buffer, bytes_read, 0) < 0) {
        perror("send");
        close(info->client_fd);
        close(server_fd);
        free(info);
        return NULL;
    }

    // Receive the HTTP response from the destination server
    bytes_read = recv(server_fd, buffer, sizeof(buffer), 0);
    if (bytes_read < 0) {
        perror("recv");
        close(info->client_fd);
        close(server_fd);
        free(info);
        return NULL;
    }

    // Send the HTTP response to the client
    if (send(info->client_fd, buffer, bytes_read, 0) < 0) {
        perror("send");
        close(info->client_fd);
        close(server_fd);
        free(info);
        return NULL;
    }

    // Close the client and server connections
    close(info->client_fd);
    close(server_fd);

    free(info);
    return NULL;
}

int main() {
    int proxy_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_fd < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in proxy_addr;
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_port = htons(PORT_PROXY);
    proxy_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(proxy_fd, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("bind");
        close(proxy_fd);
        return 1;
    }

    if (listen(proxy_fd, 5) < 0) {
        perror("listen");
        close(proxy_fd);
        return 1;
    }

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_fd = accept(proxy_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_fd < 0) {
            perror("accept");
            continue;
        }

        client_info *info = malloc(sizeof(client_info));
        info->client_fd = client_fd;
        info->client_addr = client_addr;

        pthread_t thread;
        pthread_create(&thread, NULL, handle_client, info);
    }

    close(proxy_fd);
    return 0;
}