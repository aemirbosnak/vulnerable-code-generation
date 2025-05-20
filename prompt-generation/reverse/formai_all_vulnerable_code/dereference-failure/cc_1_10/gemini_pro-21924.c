//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFERSIZE 4096

typedef struct {
    int fd;
    struct sockaddr_in addr;
    socklen_t addrlen;
} connection_t;

void error(char *msg) {
    perror(msg);
    exit(1);
}

void connect_to_server(connection_t *conn, char *host, char *port) {
    struct addrinfo *result;
    struct addrinfo hints = {0};

    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    if (getaddrinfo(host, port, &hints, &result) != 0) {
        error("getaddrinfo");
    }

    conn->fd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (conn->fd == -1) {
        error("socket");
    }

    if (connect(conn->fd, result->ai_addr, result->ai_addrlen) == -1) {
        error("connect");
    }

    freeaddrinfo(result);
}

void handle_client_request(connection_t *client_conn, connection_t *server_conn) {
    char buffer[BUFFERSIZE];
    int n;

    while ((n = read(client_conn->fd, buffer, BUFFERSIZE)) > 0) {
        write(server_conn->fd, buffer, n);
    }

    if (n < 0) {
        error("read");
    }
}

void handle_server_response(connection_t *client_conn, connection_t *server_conn) {
    char buffer[BUFFERSIZE];
    int n;

    while ((n = read(server_conn->fd, buffer, BUFFERSIZE)) > 0) {
        write(client_conn->fd, buffer, n);
    }

    if (n < 0) {
        error("read");
    }
}

int main(int argc, char **argv) {
    int client_fd, server_fd;
    connection_t client_conn, server_conn;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    client_conn.addr.sin_family = AF_INET;
    client_conn.addr.sin_port = htons(0);
    client_conn.addr.sin_addr.s_addr = htonl(INADDR_ANY);
    client_conn.addrlen = sizeof(client_conn.addr);

    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd == -1) {
        error("socket");
    }

    if (bind(client_fd, (struct sockaddr *)&client_conn.addr, client_conn.addrlen) == -1) {
        error("bind");
    }

    if (listen(client_fd, 5) == -1) {
        error("listen");
    }

    while (1) {
        client_conn.addrlen = sizeof(client_conn.addr);
        client_conn.fd = accept(client_fd, (struct sockaddr *)&client_conn.addr, &client_conn.addrlen);
        if (client_conn.fd == -1) {
            error("accept");
        }

        char *host = NULL;
        char *port = NULL;

        char *line = NULL;
        size_t linelen = 0;

        if (getline(&line, &linelen, stdin) == -1) {
            error("getline");
        }

        if (sscanf(line, "CONNECT %ms %ms HTTP/1.1\r\n", &host, &port) != 2) {
            fprintf(stderr, "Invalid CONNECT request\n");
            close(client_conn.fd);
            continue;
        }

        connect_to_server(&server_conn, host, port);

        char response[] = "HTTP/1.1 200 Connection Established\r\n\r\n";
        if (write(client_conn.fd, response, strlen(response)) == -1) {
            error("write");
        }

        pid_t pid = fork();
        if (pid == -1) {
            error("fork");
        } else if (pid == 0) {
            close(client_fd);
            handle_client_request(&client_conn, &server_conn);
            close(client_conn.fd);
            close(server_conn.fd);
            exit(0);
        } else {
            close(client_conn.fd);
            handle_server_response(&client_conn, &server_conn);
            close(client_conn.fd);
            close(server_conn.fd);
            waitpid(pid, NULL, 0);
        }

        free(host);
        free(port);
        free(line);
    }

    close(client_fd);
    return 0;
}