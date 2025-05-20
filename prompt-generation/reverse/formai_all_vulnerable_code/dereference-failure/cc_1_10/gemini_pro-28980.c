//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define ERR(...) { fprintf(stderr, __VA_ARGS__); exit(1); }
#define SAFE_FREE(ptr) { if (ptr) free(ptr); ptr = NULL; }
#define SAFE_CLOSE(fd) { if (fd >= 0) close(fd); fd = -1; }

typedef struct {
    int sockfd;
    struct sockaddr_in servaddr;
} http_client_t;

http_client_t* http_client_create(const char* hostname, const char* port) {
    int sockfd;
    struct sockaddr_in servaddr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        ERR("socket() failed");
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(port));

    if (inet_pton(AF_INET, hostname, &servaddr.sin_addr) <= 0) {
        ERR("inet_pton() failed");
    }

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        ERR("connect() failed");
    }

    http_client_t* client = malloc(sizeof(http_client_t));
    client->sockfd = sockfd;
    client->servaddr = servaddr;

    return client;
}

void http_client_destroy(http_client_t* client) {
    SAFE_CLOSE(client->sockfd);
    SAFE_FREE(client);
}

int http_client_send_request(http_client_t* client, const char* request) {
    return send(client->sockfd, request, strlen(request), 0);
}

int http_client_recv_response(http_client_t* client, char* response, size_t max_len) {
    return recv(client->sockfd, response, max_len, 0);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        ERR("Usage: %s <hostname> <port>\n", argv[0]);
    }

    const char* hostname = argv[1];
    const char* port = argv[2];

    http_client_t* client = http_client_create(hostname, port);

    char request[1024];
    snprintf(request, sizeof(request), "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", hostname);

    if (http_client_send_request(client, request) < 0) {
        ERR("http_client_send_request() failed");
    }

    char response[4096];
    if (http_client_recv_response(client, response, sizeof(response)) < 0) {
        ERR("http_client_recv_response() failed");
    }

    printf("%s", response);

    http_client_destroy(client);

    return 0;
}