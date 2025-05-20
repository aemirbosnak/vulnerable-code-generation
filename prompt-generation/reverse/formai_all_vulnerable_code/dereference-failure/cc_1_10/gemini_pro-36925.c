//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: modular
/* HTTP client implementation in C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_RESPONSE_SIZE 1024

struct http_request {
    char *method;
    char *url;
    char *body;
};

struct http_response {
    int status_code;
    char *content_type;
    char *body;
};

struct http_client {
    int sockfd;
};

struct http_client *http_client_create() {
    struct http_client *client = malloc(sizeof(struct http_client));
    if (!client) {
        perror("malloc");
        return NULL;
    }
    client->sockfd = -1;
    return client;
}

void http_client_destroy(struct http_client *client) {
    if (client->sockfd != -1) {
        close(client->sockfd);
    }
    free(client);
}

int http_client_connect(struct http_client *client, const char *host, const char *port) {
    struct addrinfo hints, *res;
    int err;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if ((err = getaddrinfo(host, port, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
        return -1;
    }

    client->sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (client->sockfd == -1) {
        perror("socket");
        freeaddrinfo(res);
        return -1;
    }

    if (connect(client->sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        perror("connect");
        freeaddrinfo(res);
        return -1;
    }

    freeaddrinfo(res);
    return 0;
}

struct http_request *http_request_create(const char *method, const char *url, const char *body) {
    struct http_request *request = malloc(sizeof(struct http_request));
    if (!request) {
        perror("malloc");
        return NULL;
    }

    request->method = strdup(method);
    request->url = strdup(url);
    request->body = strdup(body);
    return request;
}

void http_request_destroy(struct http_request *request) {
    free(request->method);
    free(request->url);
    free(request->body);
    free(request);
}

int http_request_send(struct http_client *client, struct http_request *request) {
    char buffer[MAX_RESPONSE_SIZE];
    int bytes_sent;

    snprintf(buffer, MAX_RESPONSE_SIZE, "%s %s HTTP/1.1\r\n", request->method, request->url);
    if ((bytes_sent = send(client->sockfd, buffer, strlen(buffer), 0)) == -1) {
        perror("send");
        return -1;
    }

    snprintf(buffer, MAX_RESPONSE_SIZE, "Host: %s\r\n", request->url);
    if ((bytes_sent = send(client->sockfd, buffer, strlen(buffer), 0)) == -1) {
        perror("send");
        return -1;
    }

    snprintf(buffer, MAX_RESPONSE_SIZE, "Content-Length: %zu\r\n", strlen(request->body));
    if ((bytes_sent = send(client->sockfd, buffer, strlen(buffer), 0)) == -1) {
        perror("send");
        return -1;
    }

    snprintf(buffer, MAX_RESPONSE_SIZE, "\r\n");
    if ((bytes_sent = send(client->sockfd, buffer, strlen(buffer), 0)) == -1) {
        perror("send");
        return -1;
    }

    if ((bytes_sent = send(client->sockfd, request->body, strlen(request->body), 0)) == -1) {
        perror("send");
        return -1;
    }

    return 0;
}

struct http_response *http_response_receive(struct http_client *client) {
    char buffer[MAX_RESPONSE_SIZE];
    int bytes_received;
    char *status_code;
    char *content_type;

    if ((bytes_received = recv(client->sockfd, buffer, MAX_RESPONSE_SIZE - 1, 0)) == -1) {
        perror("recv");
        return NULL;
    }
    buffer[bytes_received] = '\0';

    status_code = strtok(buffer, " ");
    content_type = strtok(NULL, "\r\n");

    struct http_response *response = malloc(sizeof(struct http_response));
    if (!response) {
        perror("malloc");
        return NULL;
    }

    response->status_code = atoi(status_code);
    response->content_type = strdup(content_type);
    response->body = strdup(buffer + strlen(status_code) + strlen(content_type) + 4);
    return response;
}

void http_response_destroy(struct http_response *response) {
    free(response->content_type);
    free(response->body);
    free(response);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <port> <url>\n", argv[0]);
        return 1;
    }

    struct http_client *client = http_client_create();
    if (!client) {
        return 1;
    }

    if (http_client_connect(client, argv[1], argv[2]) == -1) {
        http_client_destroy(client);
        return 1;
    }

    struct http_request *request = http_request_create("GET", argv[3], NULL);
    if (!request) {
        http_client_destroy(client);
        return 1;
    }

    if (http_request_send(client, request) == -1) {
        http_request_destroy(request);
        http_client_destroy(client);
        return 1;
    }

    struct http_response *response = http_response_receive(client);
    if (!response) {
        http_request_destroy(request);
        http_client_destroy(client);
        return 1;
    }

    printf("HTTP/1.1 %d %s\n", response->status_code, response->content_type);
    printf("%s", response->body);

    http_response_destroy(response);
    http_request_destroy(request);
    http_client_destroy(client);
    return 0;
}