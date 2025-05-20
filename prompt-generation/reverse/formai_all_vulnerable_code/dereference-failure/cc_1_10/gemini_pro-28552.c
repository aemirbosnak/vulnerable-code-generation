//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

#define MAX_LINE 8192

typedef struct {
    char *host;
    int port;
    char *path;
    char *method;
    char *body;
    char *headers;
} request_t;

typedef struct {
    int fd;
    char *buf;
    int len;
} response_t;

request_t *request_new(char *host, int port, char *path, char *method, char *body, char *headers) {
    request_t *req = malloc(sizeof(request_t));
    req->host = strdup(host);
    req->port = port;
    req->path = strdup(path);
    req->method = strdup(method);
    req->body = strdup(body);
    req->headers = strdup(headers);
    return req;
}

void request_free(request_t *req) {
    free(req->host);
    free(req->path);
    free(req->method);
    free(req->body);
    free(req->headers);
    free(req);
}

response_t *response_new() {
    response_t *res = malloc(sizeof(response_t));
    res->fd = -1;
    res->buf = NULL;
    res->len = 0;
    return res;
}

void response_free(response_t *res) {
    if (res->fd != -1) {
        close(res->fd);
    }
    if (res->buf != NULL) {
        free(res->buf);
    }
    free(res);
}

int socket_connect(char *host, int port) {
    struct hostent *he;
    struct sockaddr_in addr;
    int fd;

    if ((he = gethostbyname(host)) == NULL) {
        return -1;
    }
    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        return -1;
    }
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *((struct in_addr *)he->h_addr);
    if (connect(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        close(fd);
        return -1;
    }
    return fd;
}

response_t *request_send(request_t *req) {
    char buf[MAX_LINE];
    char *line;
    int fd;

    if ((fd = socket_connect(req->host, req->port)) == -1) {
        return NULL;
    }
    snprintf(buf, sizeof(buf), "%s %s HTTP/1.1\r\n", req->method, req->path);
    if (send(fd, buf, strlen(buf), 0) == -1) {
        close(fd);
        return NULL;
    }
    snprintf(buf, sizeof(buf), "Host: %s\r\n", req->host);
    if (send(fd, buf, strlen(buf), 0) == -1) {
        close(fd);
        return NULL;
    }
    if (req->headers != NULL) {
        if (send(fd, req->headers, strlen(req->headers), 0) == -1) {
            close(fd);
            return NULL;
        }
    }
    if (req->body != NULL) {
        if (send(fd, req->body, strlen(req->body), 0) == -1) {
            close(fd);
            return NULL;
        }
    }
    if (send(fd, "\r\n", 2, 0) == -1) {
        close(fd);
        return NULL;
    }
    response_t *res = response_new();
    res->fd = fd;
    while ((line = fgets(buf, sizeof(buf), fd)) != NULL) {
        res->buf = realloc(res->buf, res->len + strlen(line) + 1);
        memcpy(res->buf + res->len, line, strlen(line));
        res->len += strlen(line);
    }
    return res;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s host port [path] [method] [body] [headers]\n", argv[0]);
        return 1;
    }
    char *host = argv[1];
    int port = atoi(argv[2]);
    char *path = argc >= 4 ? argv[3] : "/";
    char *method = argc >= 5 ? argv[4] : "GET";
    char *body = argc >= 6 ? argv[5] : NULL;
    char *headers = argc >= 7 ? argv[6] : NULL;
    request_t *req = request_new(host, port, path, method, body, headers);
    response_t *res = request_send(req);
    if (res == NULL) {
        fprintf(stderr, "Error sending request\n");
        return 1;
    }
    printf("%s\n", res->buf);
    response_free(res);
    request_free(req);
    return 0;
}