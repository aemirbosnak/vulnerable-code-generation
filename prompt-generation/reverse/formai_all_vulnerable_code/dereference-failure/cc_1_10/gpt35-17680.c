//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080

void process_request(int client_fd, char *client_request);
int create_server_socket(int server_port);

int main(int argc, char **argv) {
    int server_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // create server socket
    server_fd = create_server_socket(SERVER_PORT);

    while (true) {
        // wait for client connection
        int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_fd == -1) {
            perror("accept error");
            exit(EXIT_FAILURE);
        }

        // receive client request
        char client_request[1024] = {0};
        recv(client_fd, client_request, sizeof(client_request), 0);
        
        // process client request and send response
        process_request(client_fd, client_request);

        // close client connection
        close(client_fd);
    }

    // close server socket
    close(server_fd);
    return 0;
}

void process_request(int client_fd, char *client_request) {
    char *method = strtok(client_request, " ");
    char *url = strtok(NULL, " ");
    char *protocol_version = strtok(NULL, " \r\n");

    // check if request is GET method
    if (strcmp(method, "GET") != 0) {
        char *error_response = "HTTP/1.1 405 Method Not Allowed\r\n\r\n";
        send(client_fd, error_response, strlen(error_response), 0);
        return;
    }

    // extract host and port from url
    char *host = strstr(url, "://") ? strstr(url, "://") + 3 : url;
    char *path = strchr(host, '/') ? strchr(host, '/') : "";
    char *port = strstr(host, ":") ? strstr(host, ":") + 1 : "80";
    host = strtok(host, ":/");

    // create proxy request
    char proxy_request[1024];
    sprintf(proxy_request, "GET %s HTTP/1.1\r\nHost: %s:%s\r\nConnection: close\r\n\r\n", path, host, port);

    // create proxy socket
    int proxy_fd;
    if ((proxy_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("proxy socket error");
        exit(EXIT_FAILURE);
    }

    // connect to proxy server
    struct sockaddr_in proxy_addr;
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_port = htons(atoi(port));
    proxy_addr.sin_addr.s_addr = inet_addr(host);
    if (connect(proxy_fd, (struct sockaddr*)&proxy_addr, sizeof(proxy_addr)) == -1) {
        perror("proxy connect error");
        exit(EXIT_FAILURE);
    }

    // send proxy request to server
    send(proxy_fd, proxy_request, strlen(proxy_request), 0);

    // receive proxy response from server and send to client
    char proxy_response[4096];
    int bytes_received;
    while ((bytes_received = recv(proxy_fd, proxy_response, sizeof(proxy_response), 0)) > 0) {
        send(client_fd, proxy_response, bytes_received, 0);
    }

    // close proxy socket
    close(proxy_fd);
}

int create_server_socket(int server_port) {
    int server_fd;
    struct sockaddr_in server_addr;

    // create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("server socket error");
        exit(EXIT_FAILURE);
    }

    // set socket options to reuse address
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        perror("setsockopt error");
        exit(EXIT_FAILURE);
    }

    // bind socket to server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind error");
        exit(EXIT_FAILURE);
    }

    // set socket to listen
    if (listen(server_fd, 10) == -1) {
        perror("listen error");
        exit(EXIT_FAILURE);
    }

    return server_fd;
}