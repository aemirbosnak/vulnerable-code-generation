//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: single-threaded
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 4096

typedef struct {
    int sockfd;
    char *host;
    char *port;
} proxy_connection;

proxy_connection *proxy_connection_new(char *host, char *port) {
    proxy_connection *conn = malloc(sizeof(proxy_connection));
    if (!conn) {
        perror("malloc");
        return NULL;
    }

    conn->sockfd = -1;
    conn->host = strdup(host);
    conn->port = strdup(port);
    return conn;
}

int proxy_connection_connect(proxy_connection *conn) {
    struct addrinfo hints, *res;

    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    int err = getaddrinfo(conn->host, conn->port, &hints, &res);
    if (err != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
        return -1;
    }

    conn->sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (conn->sockfd == -1) {
        perror("socket");
        freeaddrinfo(res);
        return -1;
    }

    if (connect(conn->sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        perror("connect");
        freeaddrinfo(res);
        close(conn->sockfd);
        return -1;
    }

    freeaddrinfo(res);
    return 0;
}

void proxy_connection_free(proxy_connection *conn) {
    if (conn->sockfd != -1) {
        close(conn->sockfd);
    }
    free(conn->host);
    free(conn->port);
    free(conn);
}

int proxy_forward(int client_sockfd, proxy_connection *conn) {
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = read(client_sockfd, buffer, sizeof(buffer))) > 0) {
        if (write(conn->sockfd, buffer, n) != n) {
            perror("write");
            return -1;
        }
    }

    if (n == -1) {
        perror("read");
        return -1;
    }

    return 0;
}

int proxy_reverse(int client_sockfd, proxy_connection *conn) {
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = read(conn->sockfd, buffer, sizeof(buffer))) > 0) {
        if (write(client_sockfd, buffer, n) != n) {
            perror("write");
            return -1;
        }
    }

    if (n == -1) {
        perror("read");
        return -1;
    }

    return 0;
}

int proxy_handle_client(int client_sockfd) {
    char buffer[BUFFER_SIZE];
    int n;

    if ((n = read(client_sockfd, buffer, sizeof(buffer))) <= 0) {
        if (n == -1) {
            perror("read");
        }
        return -1;
    }

    char *host = NULL;
    char *port = NULL;
    char *path = NULL;

    char *line = strtok(buffer, "\r\n");
    while (line) {
        if (strncmp(line, "GET ", 4) == 0) {
            path = strchr(line, ' ');
            if (path) {
                path++;
            }
        } else if (strncmp(line, "Host: ", 6) == 0) {
            host = line + 6;
        } else if (strncmp(line, "Port: ", 6) == 0) {
            port = line + 6;
        }

        line = strtok(NULL, "\r\n");
    }

    if (!host || !port || !path) {
        fprintf(stderr, "Invalid request\n");
        return -1;
    }

    proxy_connection *conn = proxy_connection_new(host, port);
    if (!conn) {
        return -1;
    }

    if (proxy_connection_connect(conn) == -1) {
        proxy_connection_free(conn);
        return -1;
    }

    if (proxy_forward(client_sockfd, conn) == -1) {
        proxy_connection_free(conn);
        return -1;
    }

    if (proxy_reverse(client_sockfd, conn) == -1) {
        proxy_connection_free(conn);
        return -1;
    }

    proxy_connection_free(conn);
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        close(sockfd);
        return 1;
    }

    if (listen(sockfd, 5) == -1) {
        perror("listen");
        close(sockfd);
        return 1;
    }

    while (1) {
        int client_sockfd = accept(sockfd, NULL, NULL);
        if (client_sockfd == -1) {
            perror("accept");
            continue;
        }

        proxy_handle_client(client_sockfd);
        close(client_sockfd);
    }

    close(sockfd);
    return 0;
}