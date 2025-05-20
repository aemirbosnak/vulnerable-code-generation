//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <poll.h>

#define BUFSIZE 4096

struct proxy_conn {
    int sock;
    char buf[BUFSIZE];
    int buf_len;
    int state;
};

enum proxy_state {
    PROXY_STATE_INIT,
    PROXY_STATE_CONNECTING,
    PROXY_STATE_CONNECTED,
    PROXY_STATE_PROXYING,
    PROXY_STATE_CLOSED,
};

void proxy_init(struct proxy_conn *conn)
{
    conn->sock = -1;
    conn->buf_len = 0;
    conn->state = PROXY_STATE_INIT;
}

void proxy_connect(struct proxy_conn *conn, const char *host, int port)
{
    struct sockaddr_in addr;

    conn->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (conn->sock < 0) {
        perror("socket");
        return;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(host);

    if (connect(conn->sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        close(conn->sock);
        conn->sock = -1;
        return;
    }

    conn->state = PROXY_STATE_CONNECTING;
}

void proxy_proxy(struct proxy_conn *conn)
{
    int ret;

    ret = send(conn->sock, conn->buf, conn->buf_len, 0);
    if (ret < 0) {
        perror("send");
        close(conn->sock);
        conn->sock = -1;
        conn->state = PROXY_STATE_CLOSED;
        return;
    }

    conn->buf_len = 0;
    conn->state = PROXY_STATE_PROXYING;
}

void proxy_close(struct proxy_conn *conn)
{
    if (conn->sock >= 0) {
        close(conn->sock);
        conn->sock = -1;
    }

    conn->state = PROXY_STATE_CLOSED;
}

int main(int argc, char **argv)
{
    int listen_sock, client_sock;
    struct sockaddr_in addr;
    socklen_t addr_len;
    struct pollfd fds[2];
    struct proxy_conn client, server;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listen_sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        close(listen_sock);
        return EXIT_FAILURE;
    }

    if (listen(listen_sock, 5) < 0) {
        perror("listen");
        close(listen_sock);
        return EXIT_FAILURE;
    }

    proxy_init(&client);
    proxy_init(&server);

    fds[0].fd = listen_sock;
    fds[0].events = POLLIN;

    while (1) {
        int ret;

        ret = poll(fds, 2, -1);
        if (ret < 0) {
            perror("poll");
            break;
        }

        if (fds[0].revents & POLLIN) {
            addr_len = sizeof(addr);
            client_sock = accept(listen_sock, (struct sockaddr *)&addr, &addr_len);
            if (client_sock < 0) {
                perror("accept");
                continue;
            }

            proxy_connect(&server, argv[1], 80);
            client.sock = client_sock;
            client.state = PROXY_STATE_CONNECTED;

            fds[1].fd = client_sock;
            fds[1].events = POLLIN;
        }

        if (fds[1].revents & POLLIN) {
            ret = recv(client.sock, client.buf, BUFSIZE, 0);
            if (ret <= 0) {
                proxy_close(&client);
                fds[1].fd = -1;
                fds[1].events = 0;
                continue;
            }

            client.buf_len = ret;
            proxy_proxy(&client);
        }

        if (server.state == PROXY_STATE_PROXYING) {
            ret = recv(server.sock, server.buf, BUFSIZE, 0);
            if (ret <= 0) {
                proxy_close(&server);
                continue;
            }

            server.buf_len = ret;
            proxy_proxy(&server);
        }
    }

    close(listen_sock);
    proxy_close(&client);
    proxy_close(&server);

    return EXIT_SUCCESS;
}