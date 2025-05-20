//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define BUFFSIZE 1024
#define PORT 8080

typedef struct proxy_request_t {
    char *method;
    char *url;
    char *version;
    char *host;
    int port;
    char *path;
    char *query_string;
    char *headers;
    char *body;
} proxy_request_t;

typedef struct proxy_response_t {
    int status_code;
    char *status_message;
    char *headers;
    char *body;
} proxy_response_t;

char *parse_request_line(char *request) {
    char *line = strtok(request, "\r\n");
    char *method = strtok(line, " ");
    char *url = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");
    return line;
}

proxy_request_t parse_request(char *request) {
    proxy_request_t req;
    req.method = strtok(request, " ");
    req.url = strtok(NULL, " ");
    req.version = strtok(NULL, "\r\n");
    req.host = strtok(req.url, "/");
    req.port = 80;
    req.path = strtok(NULL, "?");
    req.query_string = strtok(NULL, "\r\n");
    req.headers = strtok(NULL, "\r\n");
    req.body = strtok(NULL, "\r\n");
    return req;
}

char *build_request(proxy_request_t req) {
    char *request = malloc(BUFFSIZE);
    sprintf(request, "%s %s %s\r\n", req.method, req.url, req.version);
    sprintf(request, "%sHost: %s\r\n", request, req.host);
    sprintf(request, "%sConnection: close\r\n", request);
    sprintf(request, "%s%s", request, req.headers);
    sprintf(request, "%s\r\n", request, req.body);
    return request;
}

proxy_response_t send_request(char *request, char *host, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(host);
    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    send(sockfd, request, strlen(request), 0);
    char *response = malloc(BUFFSIZE);
    recv(sockfd, response, BUFFSIZE, 0);
    close(sockfd);
    proxy_response_t res;
    res.status_code = strtok(response, " ");
    res.status_message = strtok(NULL, "\r\n");
    res.headers = strtok(NULL, "\r\n");
    res.body = strtok(NULL, "\r\n");
    return res;
}

int main() {
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    bind(listenfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    listen(listenfd, 5);
    while (1) {
        int connfd = accept(listenfd, (struct sockaddr *)NULL, NULL);
        char *request = malloc(BUFFSIZE);
        recv(connfd, request, BUFFSIZE, 0);
        proxy_request_t req = parse_request(request);
        char *host = req.host;
        int port = req.port;
        char *request_to_send = build_request(req);
        proxy_response_t response = send_request(request_to_send, host, port);
        char *response_to_send = malloc(BUFFSIZE);
        sprintf(response_to_send, "%s %s\r\n", response.status_code, response.status_message);
        sprintf(response_to_send, "%s%s", response_to_send, response.headers);
        sprintf(response_to_send, "%s\r\n", response_to_send, response.body);
        send(connfd, response_to_send, strlen(response_to_send), 0);
        close(connfd);
    }
    close(listenfd);
    return 0;
}