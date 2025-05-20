//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define HTTP_PORT 80
#define HTTP_MAX_BUFFER 1024

struct http_request {
    char *method;
    char *host;
    char *path;
    char *body;
    unsigned int body_length;
};

struct http_response {
    unsigned int status_code;
    char *status_message;
    char *headers;
    char *body;
    unsigned int body_length;
};

int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

struct addrinfo *resolve_hostname(const char *hostname) {
    struct addrinfo hints;
    struct addrinfo *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    int err = getaddrinfo(hostname, NULL, &hints, &res);
    if (err != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
        exit(EXIT_FAILURE);
    }
    return res;
}

int connect_to_server(int sockfd, struct addrinfo *res) {
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }
    freeaddrinfo(res);
    return 0;
}

void send_http_request(int sockfd, struct http_request *req) {
    char buffer[HTTP_MAX_BUFFER];
    int len = snprintf(buffer, sizeof(buffer), "%s %s HTTP/1.1\r\nHost: %s\r\n", req->method, req->path, req->host);
    if (len < 0) {
        perror("snprintf");
        exit(EXIT_FAILURE);
    }
    if (write(sockfd, buffer, len) < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }
    if (req->body_length > 0) {
        len = snprintf(buffer, sizeof(buffer), "Content-Length: %u\r\n", req->body_length);
        if (len < 0) {
            perror("snprintf");
            exit(EXIT_FAILURE);
        }
        if (write(sockfd, buffer, len) < 0) {
            perror("write");
            exit(EXIT_FAILURE);
        }
        if (write(sockfd, req->body, req->body_length) < 0) {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }
    if (write(sockfd, "\r\n", 2) < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }
}

struct http_response *receive_http_response(int sockfd) {
    char buffer[HTTP_MAX_BUFFER];
    struct http_response *resp = malloc(sizeof(struct http_response));
    if (resp == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    int len = read(sockfd, buffer, sizeof(buffer));
    if (len < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    buffer[len] = '\0';
    char *status_line = strtok(buffer, "\r\n");
    if (status_line == NULL) {
        fprintf(stderr, "Invalid HTTP response\n");
        exit(EXIT_FAILURE);
    }
    char *status_code = strtok(status_line, " ");
    if (status_code == NULL) {
        fprintf(stderr, "Invalid HTTP response\n");
        exit(EXIT_FAILURE);
    }
    resp->status_code = atoi(status_code);
    char *status_message = strtok(NULL, "\r\n");
    if (status_message == NULL) {
        fprintf(stderr, "Invalid HTTP response\n");
        exit(EXIT_FAILURE);
    }
    resp->status_message = strdup(status_message);
    char *headers = strtok(NULL, "\r\n\r\n");
    if (headers == NULL) {
        fprintf(stderr, "Invalid HTTP response\n");
        exit(EXIT_FAILURE);
    }
    resp->headers = strdup(headers);
    char *body = strtok(NULL, "\0");
    if (body == NULL) {
        resp->body = NULL;
        resp->body_length = 0;
    } else {
        resp->body = strdup(body);
        resp->body_length = strlen(body);
    }
    return resp;
}

void free_http_response(struct http_response *resp) {
    free(resp->status_message);
    free(resp->headers);
    free(resp->body);
    free(resp);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    struct http_request req;
    req.method = "GET";
    req.host = argv[1];
    req.path = argv[2];
    req.body = NULL;
    req.body_length = 0;
    int sockfd = create_socket();
    struct addrinfo *res = resolve_hostname(req.host);
    connect_to_server(sockfd, res);
    send_http_request(sockfd, &req);
    struct http_response *resp = receive_http_response(sockfd);
    printf("HTTP/1.1 %u %s\n", resp->status_code, resp->status_message);
    printf("%s\n", resp->headers);
    if (resp->body_length > 0) {
        printf("%s", resp->body);
    }
    free_http_response(resp);
    close(sockfd);
    return 0;
}