//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_REQUEST_SIZE 1024
#define MAX_RESPONSE_SIZE 4096

typedef struct 
{
    int fd;
    struct sockaddr_in addr;
} connection_t;

typedef struct 
{
    char *request;
    size_t request_len;
    char *response;
    size_t response_len;
} http_request_t;

connection_t *accept_connection(int listen_fd) 
{
    connection_t *conn = malloc(sizeof(connection_t));
    if (conn == NULL) 
    {
        perror("malloc");
        exit(1);
    }

    conn->fd = accept(listen_fd, (struct sockaddr *)&conn->addr, NULL);
    if (conn->fd == -1) 
    {
        perror("accept");
        exit(1);
    }

    return conn;
}

void close_connection(connection_t *conn) 
{
    close(conn->fd);
    free(conn);
}

http_request_t *read_http_request(connection_t *conn) 
{
    http_request_t *req = malloc(sizeof(http_request_t));
    if (req == NULL) 
    {
        perror("malloc");
        exit(1);
    }

    req->request = malloc(MAX_REQUEST_SIZE);
    if (req->request == NULL) 
    {
        perror("malloc");
        exit(1);
    }

    req->request_len = read(conn->fd, req->request, MAX_REQUEST_SIZE);
    if (req->request_len == -1) 
    {
        perror("read");
        exit(1);
    }

    return req;
}

void write_http_response(connection_t *conn, http_request_t *req) 
{
    write(conn->fd, req->response, req->response_len);
}

void free_http_request(http_request_t *req) 
{
    free(req->request);
    free(req->response);
    free(req);
}

int main(int argc, char *argv[]) 
{
    if (argc != 3) 
    {
        fprintf(stderr, "Usage: %s <listen-port> <upstream-host:port>\n", argv[0]);
        exit(1);
    }

    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) 
    {
        perror("socket");
        exit(1);
    }

    int reuse_addr = 1;
    if (setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &reuse_addr, sizeof(reuse_addr)) == -1) 
    {
        perror("setsockopt");
        exit(1);
    }

    struct sockaddr_in listen_addr;
    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    listen_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listen_fd, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) 
    {
        perror("bind");
        exit(1);
    }

    if (listen(listen_fd, 10) == -1) 
    {
        perror("listen");
        exit(1);
    }

    char *upstream_host = strtok(argv[2], ":");
    char *upstream_port = strtok(NULL, ":");

    struct sockaddr_in upstream_addr;
    memset(&upstream_addr, 0, sizeof(upstream_addr));
    upstream_addr.sin_family = AF_INET;
    upstream_addr.sin_addr.s_addr = inet_addr(upstream_host);
    upstream_addr.sin_port = htons(atoi(upstream_port));

    while (1) 
    {
        connection_t *conn = accept_connection(listen_fd);

        http_request_t *req = read_http_request(conn);

        int upstream_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (upstream_fd == -1) 
        {
            perror("socket");
            exit(1);
        }

        if (connect(upstream_fd, (struct sockaddr *)&upstream_addr, sizeof(upstream_addr)) == -1) 
        {
            perror("connect");
            exit(1);
        }

        write(upstream_fd, req->request, req->request_len);

        char *buffer = malloc(MAX_RESPONSE_SIZE);
        if (buffer == NULL) 
        {
            perror("malloc");
            exit(1);
        }

        size_t response_len = read(upstream_fd, buffer, MAX_RESPONSE_SIZE);
        if (response_len == -1) 
        {
            perror("read");
            exit(1);
        }

        req->response = malloc(response_len);
        if (req->response == NULL) 
        {
            perror("malloc");
            exit(1);
        }

        memcpy(req->response, buffer, response_len);
        req->response_len = response_len;

        free(buffer);
        close(upstream_fd);

        write_http_response(conn, req);

        free_http_request(req);
        close_connection(conn);
    }

    close(listen_fd);
    return 0;
}