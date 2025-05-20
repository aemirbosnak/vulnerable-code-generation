//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

struct proxy_args {
    int client_fd;
    struct sockaddr_in client_addr;
};

void *proxy(void *arg) {
    struct proxy_args *args = (struct proxy_args *)arg;
    int client_fd = args->client_fd;
    struct sockaddr_in client_addr = args->client_addr;
    char buffer[BUFFER_SIZE];
    int n;

    memset(buffer, 0, BUFFER_SIZE);
    n = recv(client_fd, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        perror("recv");
        close(client_fd);
        return NULL;
    }

    // parse HTTP request
    char method[16];
    char url[256];
    sscanf(buffer, "%s %s", method, url);

    // extract hostname and port number
    char *http = strstr(url, "://");
    if (http == NULL) {
        printf("invalid URL");
        close(client_fd);
        return NULL;;
    }
    char *host_start = http + 3;
    char *host_end = strchr(host_start, ':');
    if (host_end == NULL) {
        host_end = strchr(host_start, '/');
        if (host_end == NULL) {
            printf("invalid URL");
            close(client_fd);
            return NULL;
        }
    }
    char *hostname = strndup(host_start, host_end - host_start);
    int port = 80;
    if (*host_end == ':') {
        port = atoi(host_end + 1);
    }

    // open connection to remote server
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(hostname);
    server_addr.sin_port = htons(port);
    if (connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        close(client_fd);
        close(server_fd);
        return NULL;
    }

    // forward HTTP request to server
    if (send(server_fd, buffer, n, 0) < 0) {
        perror("send");
        close(client_fd);
        close(server_fd);
        return NULL;
    }

    // forward server response to client
    while ((n = recv(server_fd, buffer, BUFFER_SIZE, 0)) > 0) {
        if (send(client_fd, buffer, n, 0) < 0) {
            perror("send");
            close(client_fd);
            close(server_fd);
            return NULL;
        }
        memset(buffer, 0, BUFFER_SIZE);
    }
    if (n < 0) {
        perror("recv");
        close(client_fd);
        close(server_fd);
        return NULL;
    }

    // clean up
    close(client_fd);
    close(server_fd);
    free(args);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("usage: %s <port>\n", argv[0]);
        return 1;
    }
    int port = atoi(argv[1]);

    // create socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        return 1;
    }

    // bind to port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        close(server_fd);
        return 1;
    }

    // listen for incoming connections
    if (listen(server_fd, 10) < 0) {
        perror("listen");
        close(server_fd);
        return 1;
    }
    printf("Proxy server running on port %d...\n", port);

    // accept incoming connections and start proxy thread
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
        if (client_fd < 0) {
            perror("accept");
            continue;
        }

        struct proxy_args *args = malloc(sizeof(struct proxy_args));
        args->client_fd = client_fd;
        args->client_addr = client_addr;

        pthread_t thread;
        pthread_create(&thread, NULL, proxy, args);
        pthread_detach(thread);
    }

    // clean up
    close(server_fd);
    return 0;
}