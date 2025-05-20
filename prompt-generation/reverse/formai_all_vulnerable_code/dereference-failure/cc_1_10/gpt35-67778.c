//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 80

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <proxy-port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int proxy_port = atoi(argv[1]);

    int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0) {
        handle_error("Error opening server socket");
    }

    struct sockaddr_in server_address, client_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(proxy_port);

    if (bind(server_sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        handle_error("Error binding server socket");
    }

    listen(server_sockfd, 5);

    printf("Proxy server started on port %d\n", proxy_port);

    while (1) {
        socklen_t client_address_len = sizeof(client_address);
        int client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_address, &client_address_len);

        if (client_sockfd < 0) {
            handle_error("Error accepting client connection");
        }

        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);
        if (read(client_sockfd, buffer, BUFFER_SIZE) < 0) {
            handle_error("Error reading from client socket");
        }

        char *host_start = strstr(buffer, "Host:");
        if (host_start == NULL) {
            close(client_sockfd);
            continue;
        }

        char *host_end = strchr(host_start, '\r');
        if (host_end == NULL) {
            close(client_sockfd);
            continue;
        }

        char host[BUFFER_SIZE];
        memset(host, 0, BUFFER_SIZE);
        strncpy(host, host_start + 6, host_end - host_start - 6);

        int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sockfd < 0) {
            handle_error("Error opening server socket");
        }

        struct sockaddr_in server_address;
        memset(&server_address, 0, sizeof(server_address));
        server_address.sin_family = AF_INET;
        server_address.sin_addr.s_addr = inet_addr(host);
        server_address.sin_port = htons(SERVER_PORT);

        if (connect(server_sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
            handle_error("Error connecting to server");
        }

        if (write(server_sockfd, buffer, strlen(buffer)) < 0) {
            handle_error("Error writing to server socket");
        }

        memset(buffer, 0, BUFFER_SIZE);
        while (read(server_sockfd, buffer, BUFFER_SIZE) > 0) {
            if (write(client_sockfd, buffer, strlen(buffer)) < 0) {
                handle_error("Error writing to client socket");
            }
            memset(buffer, 0, BUFFER_SIZE);
        }

        close(client_sockfd);
        close(server_sockfd);
    }

    return 0;
}