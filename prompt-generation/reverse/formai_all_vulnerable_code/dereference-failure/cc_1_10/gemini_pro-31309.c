//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: distributed
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 1024

typedef struct proxy {
    int fd;
    struct sockaddr_in addr;
} proxy_t;

int proxy_init(proxy_t *proxy, char *host, char *port) {
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        perror("socket");
        return -1;
    }

    memset(&proxy->addr, 0, sizeof(proxy->addr));
    proxy->addr.sin_family = AF_INET;
    proxy->addr.sin_port = htons(atoi(port));
    if (inet_aton(host, &proxy->addr.sin_addr) == 0) {
        perror("inet_aton");
        close(fd);
        return -1;
    }

    if (connect(fd, (struct sockaddr *)&proxy->addr, sizeof(proxy->addr)) < 0) {
        perror("connect");
        close(fd);
        return -1;
    }

    proxy->fd = fd;
    return 0;
}

void proxy_close(proxy_t *proxy) {
    close(proxy->fd);
}

int proxy_send(proxy_t *proxy, char *buf, int len) {
    int ret = send(proxy->fd, buf, len, 0);
    if (ret < 0) {
        perror("send");
        return -1;
    }
    return ret;
}

int proxy_recv(proxy_t *proxy, char *buf, int len) {
    int ret = recv(proxy->fd, buf, len, 0);
    if (ret < 0) {
        perror("recv");
        return -1;
    }
    return ret;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <port> <url>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    char *port = argv[2];
    char *url = argv[3];

    proxy_t proxy;
    if (proxy_init(&proxy, host, port) < 0) {
        return 1;
    }

    char buf[BUFSIZE];
    snprintf(buf, BUFSIZE, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", url, host);
    if (proxy_send(&proxy, buf, strlen(buf)) < 0) {
        proxy_close(&proxy);
        return 1;
    }

    while (1) {
        int ret = proxy_recv(&proxy, buf, BUFSIZE);
        if (ret == 0) {
            break;
        } else if (ret < 0) {
            proxy_close(&proxy);
            return 1;
        }
        write(STDOUT_FILENO, buf, ret);
    }

    proxy_close(&proxy);
    return 0;
}