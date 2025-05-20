//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_BUF_SIZE 4096

typedef struct {
    int sockfd;
    char *host;
    int port;
    char *path;
} http_client_t;

http_client_t *http_client_init(const char *host, int port, const char *path) {
    http_client_t *client = malloc(sizeof(http_client_t));
    if (client == NULL) {
        return NULL;
    }
    client->sockfd = -1;
    client->host = strdup(host);
    client->port = port;
    client->path = strdup(path);
    return client;
}

void http_client_destroy(http_client_t *client) {
    if (client->sockfd != -1) {
        close(client->sockfd);
    }
    free(client->host);
    free(client->path);
    free(client);
}

int http_client_connect(http_client_t *client) {
    struct sockaddr_in addr;
    struct hostent *host_info;

    host_info = gethostbyname(client->host);
    if (host_info == NULL) {
        return -1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(client->port);
    memcpy(&addr.sin_addr, host_info->h_addr, host_info->h_length);

    client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sockfd == -1) {
        return -1;
    }

    if (connect(client->sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        return -1;
    }

    return 0;
}

int http_client_send_request(http_client_t *client) {
    char buf[MAX_BUF_SIZE];
    int len;

    snprintf(buf, MAX_BUF_SIZE, "GET %s HTTP/1.1\r\n", client->path);
    len = strlen(buf);

    snprintf(buf + len, MAX_BUF_SIZE - len, "Host: %s\r\n", client->host);
    len += strlen(buf + len);

    snprintf(buf + len, MAX_BUF_SIZE - len, "\r\n");
    len += strlen(buf + len);

    if (send(client->sockfd, buf, len, 0) == -1) {
        return -1;
    }

    return 0;
}

int http_client_receive_response(http_client_t *client) {
    char buf[MAX_BUF_SIZE];
    int len;

    memset(buf, 0, MAX_BUF_SIZE);
    len = recv(client->sockfd, buf, MAX_BUF_SIZE - 1, 0);
    if (len == -1) {
        return -1;
    }

    buf[len] = '\0';
    printf("%s", buf);

    return 0;
}

int main(int argc, char **argv) {
    http_client_t *client;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    client = http_client_init(argv[1], atoi(argv[2]), "/");
    if (client == NULL) {
        fprintf(stderr, "Failed to initialize HTTP client\n");
        return EXIT_FAILURE;
    }

    if (http_client_connect(client) == -1) {
        fprintf(stderr, "Failed to connect to server\n");
        http_client_destroy(client);
        return EXIT_FAILURE;
    }

    if (http_client_send_request(client) == -1) {
        fprintf(stderr, "Failed to send request\n");
        http_client_destroy(client);
        return EXIT_FAILURE;
    }

    if (http_client_receive_response(client) == -1) {
        fprintf(stderr, "Failed to receive response\n");
        http_client_destroy(client);
        return EXIT_FAILURE;
    }

    http_client_destroy(client);
    return EXIT_SUCCESS;
}