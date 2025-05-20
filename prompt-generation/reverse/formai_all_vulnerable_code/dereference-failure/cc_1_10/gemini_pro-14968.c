//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

typedef struct {
    char *host;
    char *port;
    char *path;
    char *query;
} HTTP_Request;

typedef struct {
    int code;
    char *message;
    char *headers;
    char *body;
} HTTP_Response;

HTTP_Request *HTTP_Request_new(char *host, char *port, char *path, char *query) {
    HTTP_Request *request = malloc(sizeof(HTTP_Request));
    request->host = malloc(strlen(host) + 1);
    request->port = malloc(strlen(port) + 1);
    request->path = malloc(strlen(path) + 1);
    request->query = malloc(strlen(query) + 1);
    strcpy(request->host, host);
    strcpy(request->port, port);
    strcpy(request->path, path);
    strcpy(request->query, query);
    return request;
}

void HTTP_Request_free(HTTP_Request *request) {
    free(request->host);
    free(request->port);
    free(request->path);
    free(request->query);
    free(request);
}

HTTP_Response *HTTP_Request_send(HTTP_Request *request) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return NULL;
    }

    server = gethostbyname(request->host);
    if (server == NULL) {
        perror("Error getting host by name");
        return NULL;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(request->port));
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        return NULL;
    }

    char *request_string = malloc(strlen("GET ") + strlen(request->path) + strlen(" HTTP/1.1\r\nHost: ") + strlen(request->host) + strlen("\r\n\r\n") + 1);
    sprintf(request_string, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", request->path, request->host);

    n = write(sockfd, request_string, strlen(request_string));
    if (n < 0) {
        perror("Error writing to socket");
        return NULL;
    }

    char *response = malloc(4096);
    n = read(sockfd, response, 4096);
    if (n < 0) {
        perror("Error reading from socket");
        return NULL;
    }

    HTTP_Response *response_struct = malloc(sizeof(HTTP_Response));
    response_struct->code = atoi(strtok(response, " "));
    response_struct->message = strtok(NULL, "\r\n");
    response_struct->headers = strtok(NULL, "\r\n\r\n");
    response_struct->body = strtok(NULL, "\0");

    free(request_string);
    free(response);
    close(sockfd);
    return response_struct;
}

void HTTP_Response_free(HTTP_Response *response) {
    free(response->message);
    free(response->headers);
    free(response->body);
    free(response);
}

int main() {
    HTTP_Request *request = HTTP_Request_new("example.com", "80", "/", "foo=bar");
    HTTP_Response *response = HTTP_Request_send(request);
    printf("Code: %d\n", response->code);
    printf("Message: %s\n", response->message);
    printf("Headers: %s\n", response->headers);
    printf("Body: %s\n", response->body);
    HTTP_Response_free(response);
    HTTP_Request_free(request);
    return 0;
}