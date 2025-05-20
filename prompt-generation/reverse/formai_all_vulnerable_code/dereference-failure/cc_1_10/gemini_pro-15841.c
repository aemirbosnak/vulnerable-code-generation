//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: decentralized
#include <arpa/inet.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

typedef struct {
    int fd;
    struct sockaddr_in addr;
    socklen_t addr_len;
} connection;

typedef struct {
    connection* connections;
    size_t count;
    size_t capacity;
} connections;

connections* connections_new() {
    connections* c = malloc(sizeof(connections));
    c->connections = NULL;
    c->count = 0;
    c->capacity = 0;
    return c;
}

void connections_free(connections* c) {
    for (size_t i = 0; i < c->count; i++) {
        close(c->connections[i].fd);
    }
    free(c->connections);
    free(c);
}

bool connections_add(connections* c, connection* conn) {
    if (c->count == c->capacity) {
        size_t new_capacity = c->capacity ? c->capacity * 2 : 1;
        connection* new_connections = realloc(c->connections, new_capacity * sizeof(connection));
        if (!new_connections) {
            return false;
        }
        c->connections = new_connections;
        c->capacity = new_capacity;
    }
    c->connections[c->count++] = *conn;
    return true;
}

void connections_remove(connections* c, connection* conn) {
    for (size_t i = 0; i < c->count; i++) {
        if (c->connections[i].fd == conn->fd) {
            c->connections[i] = c->connections[--c->count];
            return;
        }
    }
}

int socket_bind(int fd, const char* ip, int port) {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if (ip) {
        if (inet_pton(AF_INET, ip, &addr.sin_addr) != 1) {
            return -1;
        }
    } else {
        addr.sin_addr.s_addr = htonl(INADDR_ANY);
    }
    return bind(fd, (struct sockaddr*)&addr, sizeof(addr));
}

bool handle_request(connection* conn) {
    char buf[1024];
    // TODO: Handle HTTP request
    snprintf(buf, sizeof(buf), "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello, world!\n");
    send(conn->fd, buf, strlen(buf), 0);
    return true;
}

int main(int argc, char** argv) {
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    int port = 8080;
    if (argc >= 2) {
        port = atoi(argv[1]);
    }

    if (socket_bind(fd, NULL, port) == -1) {
        perror("socket_bind");
        close(fd);
        return EXIT_FAILURE;
    }

    if (listen(fd, SOMAXCONN) == -1) {
        perror("listen");
        close(fd);
        return EXIT_FAILURE;
    }

    connections* c = connections_new();

    for (;;) {
        struct sockaddr_in addr;
        socklen_t addr_len = sizeof(addr);
        int new_fd = accept(fd, (struct sockaddr*)&addr, &addr_len);
        if (new_fd == -1) {
            if (errno == EINTR) {
                continue;
            }
            perror("accept");
            break;
        }

        connection conn = {new_fd, addr, addr_len};
        if (!connections_add(c, &conn)) {
            perror("connections_add");
            close(new_fd);
            break;
        }
    }

    connections_free(c);
    close(fd);

    return EXIT_SUCCESS;
}