//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_REQUEST_SIZE 4096
#define MAX_RESPONSE_SIZE 8192

typedef struct {
    int sockfd;
    char *host;
    char *port;
    char *path;
} http_client_context;

void *http_client_thread(void *arg) {
    http_client_context *ctx = (http_client_context *)arg;
    int sockfd = ctx->sockfd;
    char *host = ctx->host;
    char *port = ctx->port;
    char *path = ctx->path;

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    struct hostent *host_ent = gethostbyname(host);
    if (host_ent == NULL) {
        fprintf(stderr, "Error: Could not resolve hostname '%s'\n", host);
        exit(1);
    }
    memcpy(&server_addr.sin_addr, host_ent->h_addr, host_ent->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error: Could not connect to server '%s'\n", host);
        exit(1);
    }

    char request[MAX_REQUEST_SIZE];
    snprintf(request, MAX_REQUEST_SIZE, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);
    if (send(sockfd, request, strlen(request), 0) == -1) {
        fprintf(stderr, "Error: Could not send request to server '%s'\n", host);
        exit(1);
    }

    char response[MAX_RESPONSE_SIZE];
    int response_len = 0;
    while ((response_len = recv(sockfd, response, MAX_RESPONSE_SIZE, 0)) > 0) {
        printf("%s", response);
    }
    if (response_len == -1) {
        fprintf(stderr, "Error: Could not receive response from server '%s'\n", host);
        exit(1);
    }

    close(sockfd);
    free(ctx);

    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <port> <path>\n", argv[0]);
        exit(1);
    }

    char *host = argv[1];
    char *port = argv[2];
    char *path = argv[3];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Error: Could not create socket\n");
        exit(1);
    }

    http_client_context *ctx = (http_client_context *)malloc(sizeof(http_client_context));
    ctx->sockfd = sockfd;
    ctx->host = host;
    ctx->port = port;
    ctx->path = path;

    pthread_t thread;
    if (pthread_create(&thread, NULL, http_client_thread, (void *)ctx) != 0) {
        fprintf(stderr, "Error: Could not create thread\n");
        exit(1);
    }

    if (pthread_join(thread, NULL) != 0) {
        fprintf(stderr, "Error: Could not join thread\n");
        exit(1);
    }

    return 0;
}