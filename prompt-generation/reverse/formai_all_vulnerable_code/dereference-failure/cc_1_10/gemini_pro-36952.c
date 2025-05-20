//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 2048

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
    char *host;
    int port;
} proxy_connection;

proxy_connection *create_connection(char *host, int port) {
    proxy_connection *conn = malloc(sizeof(proxy_connection));
    conn->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (conn->sockfd == -1) {
        perror("Error creating socket");
        return NULL;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(host);
    if (connect(conn->sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("Error connecting to remote host");
        return NULL;
    }

    conn->addr = addr;
    conn->host = strdup(host);
    conn->port = port;

    return conn;
}

void close_connection(proxy_connection *conn) {
    close(conn->sockfd);
    free(conn->host);
    free(conn);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <listen port> <remote host>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int listen_port = atoi(argv[1]);
    char *remote_host = argv[2];

    int listen_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sockfd == -1) {
        perror("Error creating socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(listen_port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(listen_sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("Error binding socket");
        return EXIT_FAILURE;
    }

    if (listen(listen_sockfd, 5) == -1) {
        perror("Error listening on socket");
        return EXIT_FAILURE;
    }

    proxy_connection *remote_conn = create_connection(remote_host, 80);
    if (remote_conn == NULL) {
        perror("Error creating connection to remote host");
        return EXIT_FAILURE;
    }

    printf("Proxy server listening on port %d, forwarding requests to %s\n", listen_port, remote_host);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd = accept(listen_sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sockfd == -1) {
            perror("Error accepting client connection");
            continue;
        }

        char buffer[BUFFER_SIZE];
        int bytes_read;
        while ((bytes_read = read(client_sockfd, buffer, BUFFER_SIZE)) > 0) {
            int bytes_written = write(remote_conn->sockfd, buffer, bytes_read);
            if (bytes_written != bytes_read) {
                perror("Error writing to remote host");
                break;
            }
        }

        if (bytes_read == 0) {
            printf("Client closed connection\n");
        } else {
            perror("Error reading from client");
        }

        close(client_sockfd);
    }

    close_connection(remote_conn);
    close(listen_sockfd);

    return EXIT_SUCCESS;
}