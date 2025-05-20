//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define BUF_SIZE 4096

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
    int is_client;
} connection_t;

typedef struct {
    int client_sockfd;
    int server_sockfd;
} proxy_connection_t;

void handle_client(proxy_connection_t *proxy_connection) {
    // Read request from client
    char buf[BUF_SIZE];
    int n = read(proxy_connection->client_sockfd, buf, BUF_SIZE);
    if (n < 0) {
        perror("read");
        return;
    }

    // Parse request
    char *method = strtok(buf, " ");
    char *path = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");

    // Connect to server
    int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0) {
        perror("socket");
        return;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    if (inet_aton("127.0.0.1", &server_addr.sin_addr) == 0) {
        perror("inet_aton");
        return;
    }

    if (connect(server_sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return;
    }

    // Send request to server
    write(server_sockfd, buf, n);

    // Read response from server
    n = read(server_sockfd, buf, BUF_SIZE);
    if (n < 0) {
        perror("read");
        return;
    }

    // Send response to client
    write(proxy_connection->client_sockfd, buf, n);

    // Close connections
    close(proxy_connection->client_sockfd);
    close(server_sockfd);
}

void handle_connections(connection_t *client, connection_t *server) {
    if (client->is_client) {
        handle_client((proxy_connection_t *) client);
    } else {
        // TODO: Handle server connection
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    // Create listening socket
    int listen_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(listen_sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt");
        return 1;
    }

    // Bind listening socket
    struct sockaddr_in listen_addr;
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(port);
    listen_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(listen_sockfd, (struct sockaddr *) &listen_addr, sizeof(listen_addr)) < 0) {
        perror("bind");
        return 1;
    }

    // Listen for connections
    if (listen(listen_sockfd, 10) < 0) {
        perror("listen");
        return 1;
    }

    // Accept connections and handle them
    while (1) {
        connection_t client;
        socklen_t client_len = sizeof(client.addr);
        client.sockfd = accept(listen_sockfd, (struct sockaddr *) &client.addr, &client_len);
        if (client.sockfd < 0) {
            perror("accept");
            continue;
        }

        client.is_client = 1;
        connection_t server;
        socklen_t server_len = sizeof(server.addr);
        server.sockfd = accept(listen_sockfd, (struct sockaddr *) &server.addr, &server_len);
        if (server.sockfd < 0) {
            perror("accept");
            continue;
        }

        server.is_client = 0;
        handle_connections(&client, &server);
    }

    return 0;
}