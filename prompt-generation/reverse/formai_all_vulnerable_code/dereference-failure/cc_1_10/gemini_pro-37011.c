//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

struct proxy_request {
    char *method;
    char *path;
    char *version;
    char *host;
    int port;
};

struct proxy_response {
    int status_code;
    char *status_message;
    char *headers;
    char *body;
};

struct proxy {
    int listen_socket;
    struct sockaddr_in listen_address;
    int backlog;
};

struct client {
    int socket;
    struct sockaddr_in address;
};

struct server {
    int socket;
    struct sockaddr_in address;
};

void error(char *message) {
    perror(message);
    exit(1);
}

void parse_request(char *request, struct proxy_request *request_struct) {
    char *line = strtok(request, "\r\n");
    char *method = strtok(line, " ");
    char *path = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");

    request_struct->method = malloc(strlen(method) + 1);
    strcpy(request_struct->method, method);

    request_struct->path = malloc(strlen(path) + 1);
    strcpy(request_struct->path, path);

    request_struct->version = malloc(strlen(version) + 1);
    strcpy(request_struct->version, version);

    char *host = NULL;
    char *port = NULL;

    line = strtok(NULL, "\r\n");
    while (line != NULL) {
        if (strncmp(line, "Host: ", 6) == 0) {
            host = strtok(line + 6, ":");
            port = strtok(NULL, "\r\n");
        }

        line = strtok(NULL, "\r\n");
    }

    request_struct->host = malloc(strlen(host) + 1);
    strcpy(request_struct->host, host);

    request_struct->port = atoi(port);
}

void send_request(struct proxy_request *request_struct, struct server *server) {
    char request[MAX_BUFFER_SIZE];
    sprintf(request, "%s %s %s\r\n", request_struct->method, request_struct->path, request_struct->version);
    sprintf(request, "%sHost: %s:%d\r\n", request, request_struct->host, request_struct->port);
    sprintf(request, "%sConnection: close\r\n", request);
    sprintf(request, "%s\r\n", request);

    send(server->socket, request, strlen(request), 0);
}

void receive_response(struct server *server, struct proxy_response *response_struct) {
    char response[MAX_BUFFER_SIZE];
    int bytes_received = recv(server->socket, response, MAX_BUFFER_SIZE, 0);

    if (bytes_received == -1) {
        error("recv");
    }

    char *status_line = strtok(response, "\r\n");
    char *status_code = strtok(status_line, " ");
    char *status_message = strtok(NULL, "\r\n");

    response_struct->status_code = atoi(status_code);
    response_struct->status_message = malloc(strlen(status_message) + 1);
    strcpy(response_struct->status_message, status_message);

    char *headers = strtok(NULL, "\r\n\r\n");
    response_struct->headers = malloc(strlen(headers) + 1);
    strcpy(response_struct->headers, headers);

    char *body = strtok(NULL, "");
    response_struct->body = malloc(strlen(body) + 1);
    strcpy(response_struct->body, body);
}

void send_response(struct proxy_response *response_struct, struct client *client) {
    char response[MAX_BUFFER_SIZE];
    sprintf(response, "HTTP/1.1 %d %s\r\n", response_struct->status_code, response_struct->status_message);
    sprintf(response, "%s%s", response, response_struct->headers);
    sprintf(response, "%s\r\n", response);
    sprintf(response, "%s%s", response, response_struct->body);

    send(client->socket, response, strlen(response), 0);
}

void handle_client(struct client *client, struct proxy *proxy) {
    char request[MAX_BUFFER_SIZE];
    int bytes_received = recv(client->socket, request, MAX_BUFFER_SIZE, 0);

    if (bytes_received == -1) {
        error("recv");
    }

    struct proxy_request request_struct;
    parse_request(request, &request_struct);

    struct server server;
    server.socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server.socket == -1) {
        error("socket");
    }

    server.address.sin_family = AF_INET;
    server.address.sin_addr.s_addr = inet_addr(request_struct.host);
    server.address.sin_port = htons(request_struct.port);

    if (connect(server.socket, (struct sockaddr *)&server.address, sizeof(server.address)) == -1) {
        error("connect");
    }

    send_request(&request_struct, &server);

    struct proxy_response response_struct;
    receive_response(&server, &response_struct);

    send_response(&response_struct, client);

    close(server.socket);
}

void listen_for_clients(struct proxy *proxy) {
    int client_socket;
    struct sockaddr_in client_address;
    socklen_t client_address_length = sizeof(client_address);

    while (1) {
        client_socket = accept(proxy->listen_socket, (struct sockaddr *)&client_address, &client_address_length);

        if (client_socket == -1) {
            error("accept");
        }

        struct client client;
        client.socket = client_socket;
        client.address = client_address;

        handle_client(&client, proxy);

        close(client_socket);
    }
}

void start_proxy(struct proxy *proxy) {
    proxy->listen_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (proxy->listen_socket == -1) {
        error("socket");
    }

    proxy->listen_address.sin_family = AF_INET;
    proxy->listen_address.sin_addr.s_addr = INADDR_ANY;
    proxy->listen_address.sin_port = htons(8080);

    if (bind(proxy->listen_socket, (struct sockaddr *)&proxy->listen_address, sizeof(proxy->listen_address)) == -1) {
        error("bind");
    }

    if (listen(proxy->listen_socket, proxy->backlog) == -1) {
        error("listen");
    }

    listen_for_clients(proxy);
}

int main() {
    struct proxy proxy;
    proxy.backlog = 10;

    start_proxy(&proxy);

    return 0;
}