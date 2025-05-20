//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/tcp.h>

#define MAX_CONNECTIONS 100
#define MAX_URLS 1000

struct connection {
    int sockfd;
    struct sockaddr_in addr;
    char *url;
    size_t url_len;
    char *response;
    size_t response_len;
    int status_code;
    int is_done;
};

struct monitor {
    struct connection connections[MAX_CONNECTIONS];
    int num_connections;
    char *urls[MAX_URLS];
    int num_urls;
};

struct monitor *monitor_create() {
    struct monitor *monitor = malloc(sizeof(*monitor));
    if (!monitor) {
        return NULL;
    }

    monitor->num_connections = 0;
    monitor->num_urls = 0;

    return monitor;
}

void monitor_destroy(struct monitor *monitor) {
    for (int i = 0; i < monitor->num_connections; i++) {
        close(monitor->connections[i].sockfd);
    }

    free(monitor);
}

int monitor_add_url(struct monitor *monitor, char *url) {
    if (monitor->num_urls >= MAX_URLS) {
        return -1;
    }

    monitor->urls[monitor->num_urls++] = strdup(url);

    return 0;
}

int monitor_connect(struct monitor *monitor, int index) {
    struct connection *connection = &monitor->connections[index];
    struct sockaddr_in *addr = &connection->addr;
    struct hostent *host;

    host = gethostbyname(addr->sin_addr.s_addr);
    if (!host) {
        return -1;
    }

    connection->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (connection->sockfd < 0) {
        return -1;
    }

    connection->addr.sin_family = AF_INET;
    connection->addr.sin_port = htons(80);
    memcpy(&connection->addr.sin_addr, host->h_addr, host->h_length);

    return connect(connection->sockfd, (struct sockaddr *)&connection->addr, sizeof(connection->addr));
}

int monitor_send(struct monitor *monitor, int index) {
    struct connection *connection = &monitor->connections[index];
    ssize_t n;

    n = send(connection->sockfd, connection->url, connection->url_len, MSG_NOSIGNAL);
    if (n < 0) {
        return -1;
    }

    return n;
}

int monitor_recv(struct monitor *monitor, int index) {
    struct connection *connection = &monitor->connections[index];
    ssize_t n;
    char buf[1024];

    while (1) {
        n = recv(connection->sockfd, buf, sizeof(buf), 0);
        if (n == 0) {
            break;
        } else if (n < 0) {
            return -1;
        }

        connection->response = realloc(connection->response, connection->response_len + n);
        if (!connection->response) {
            return -1;
        }

        memcpy(connection->response + connection->response_len, buf, n);
        connection->response_len += n;
    }

    return n;
}

int monitor_parse_status_code(struct monitor *monitor, int index) {
    struct connection *connection = &monitor->connections[index];
    char *p;

    p = strstr(connection->response, "HTTP");
    if (!p) {
        return -1;
    }

    p = strstr(p, " ");
    if (!p) {
        return -1;
    }

    p++;

    connection->status_code = atoi(p);

    return 0;
}

int monitor_is_done(struct monitor *monitor, int index) {
    struct connection *connection = &monitor->connections[index];

    return connection->is_done;
}

void monitor_set_done(struct monitor *monitor, int index) {
    struct connection *connection = &monitor->connections[index];

    connection->is_done = 1;
}

int monitor_run(struct monitor *monitor) {
    fd_set rfds;
    struct timeval tv;
    int maxfd;
    int i;
    int n;

    while (1) {
        FD_ZERO(&rfds);
        maxfd = -1;

        for (i = 0; i < monitor->num_connections; i++) {
            if (!monitor_is_done(monitor, i)) {
                FD_SET(monitor->connections[i].sockfd, &rfds);
                if (monitor->connections[i].sockfd > maxfd) {
                    maxfd = monitor->connections[i].sockfd;
                }
            }
        }

        tv.tv_sec = 1;
        tv.tv_usec = 0;

        n = select(maxfd + 1, &rfds, NULL, NULL, &tv);
        if (n < 0) {
            return -1;
        }

        for (i = 0; i < monitor->num_connections; i++) {
            if (FD_ISSET(monitor->connections[i].sockfd, &rfds)) {
                if (monitor->connections[i].is_done) {
                    monitor_recv(monitor, i);
                } else {
                    if (monitor_connect(monitor, i) < 0) {
                        monitor_set_done(monitor, i);
                    } else if (monitor_send(monitor, i) < 0) {
                        monitor_set_done(monitor, i);
                    } else {
                        monitor_recv(monitor, i);
                        if (monitor_parse_status_code(monitor, i) < 0) {
                            monitor_set_done(monitor, i);
                        } else {
                            monitor_set_done(monitor, i);
                        }
                    }
                }
            }
        }
    }

    return 0;
}

int main(int argc, char **argv) {
    struct monitor *monitor;
    int i;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <urls>\n", argv[0]);
        return 1;
    }

    monitor = monitor_create();
    if (!monitor) {
        fprintf(stderr, "Failed to create monitor\n");
        return 1;
    }

    for (i = 1; i < argc; i++) {
        if (monitor_add_url(monitor, argv[i]) < 0) {
            fprintf(stderr, "Failed to add URL: %s\n", argv[i]);
            monitor_destroy(monitor);
            return 1;
        }
    }

    if (monitor_run(monitor) < 0) {
        fprintf(stderr, "Failed to run monitor\n");
        monitor_destroy(monitor);
        return 1;
    }

    monitor_destroy(monitor);

    return 0;
}