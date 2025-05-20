//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <pthread.h>

typedef struct {
    int fd;
    char *request;
    char *path;
    char *query_string;
    char *method;
    char *protocol;
    char *host;
    char *user_agent;
    char *accept;
    char *accept_language;
    char *content_type;
    char *content_length;
    char *content;
} http_request;

typedef struct {
    int fd;
    char *response;
    int content_length;
    char *content_type;
} http_response;

typedef struct {
    int fd;
    http_request *request;
    http_response *response;
} client_data;

void *client_handler(void *arg) {
    client_data *data = (client_data *)arg;
    int fd = data->fd;
    http_request *request = data->request;
    http_response *response = data->response;

    char *content = "Hello, World!";
    response->content_length = strlen(content);
    response->content_type = "text/plain";
    response->response = malloc(sizeof(char) * 1024);
    sprintf(response->response, "HTTP/1.1 200 OK\r\nContent-Type: %s\r\nContent-Length: %d\r\n\r\n%s", response->content_type, response->content_length, content);
    write(fd, response->response, strlen(response->response));
    close(fd);
    free(data);
    return NULL;
}

int main(int argc, char *argv[]) {
    int sockfd, clientfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addrlen;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        close(sockfd);
        return 1;
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        close(sockfd);
        return 1;
    }

    while (1) {
        addrlen = sizeof(client_addr);
        clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &addrlen);
        if (clientfd < 0) {
            perror("accept");
            continue;
        }

        client_data *data = malloc(sizeof(client_data));
        data->fd = clientfd;
        data->request = malloc(sizeof(http_request));
        data->response = malloc(sizeof(http_response));

        pthread_t thread;
        pthread_create(&thread, NULL, client_handler, data);
    }

    close(sockfd);
    return 0;
}