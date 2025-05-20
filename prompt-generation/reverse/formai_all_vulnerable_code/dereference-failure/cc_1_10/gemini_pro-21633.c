//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10

struct client {
    int fd;
    char *buf;
    int buflen;
};

struct server {
    int sockfd;
    struct client clients[MAX_CLIENTS];
    int num_clients;
};

int server_init(struct server *server, int port) {
    int fd;

    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return -1;
    }

    if (listen(fd, MAX_CLIENTS) < 0) {
        perror("listen");
        return -1;
    }

    server->sockfd = fd;
    server->num_clients = 0;

    return 0;
}

void server_accept(struct server *server) {
    int fd;
    struct sockaddr_in addr;
    socklen_t addrlen;

    addrlen = sizeof(addr);
    fd = accept(server->sockfd, (struct sockaddr *)&addr, &addrlen);
    if (fd < 0) {
        perror("accept");
        return;
    }

    printf("New client connected from %s:%d\n", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));

    struct client *client = &server->clients[server->num_clients++];
    client->fd = fd;
    client->buf = NULL;
    client->buflen = 0;
}

void server_recv(struct server *server, struct client *client) {
    char buf[1024];
    int n;

    n = read(client->fd, buf, sizeof(buf));
    if (n < 0) {
        perror("read");
        return;
    }

    if (n == 0) {
        printf("Client disconnected\n");
        close(client->fd);
        client->fd = -1;
        return;
    }

    char *newbuf = realloc(client->buf, client->buflen + n + 1);
    if (newbuf == NULL) {
        perror("realloc");
        return;
    }

    client->buf = newbuf;
    memcpy(client->buf + client->buflen, buf, n);
    client->buflen += n;
    client->buf[client->buflen] = '\0';

    printf("Received %d bytes from client:\n%s\n", n, client->buf);
}

void server_send(struct server *server, struct client *client, const char *buf, int len) {
    int n;

    n = write(client->fd, buf, len);
    if (n < 0) {
        perror("write");
        return;
    }

    printf("Sent %d bytes to client:\n%s\n", n, buf);
}

void server_close(struct server *server) {
    for (int i = 0; i < server->num_clients; i++) {
        if (server->clients[i].fd != -1) {
            close(server->clients[i].fd);
        }
    }

    close(server->sockfd);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    struct server server;
    if (server_init(&server, port) < 0) {
        return 1;
    }

    while (1) {
        fd_set rfds;
        FD_ZERO(&rfds);
        FD_SET(server.sockfd, &rfds);

        for (int i = 0; i < server.num_clients; i++) {
            if (server.clients[i].fd != -1) {
                FD_SET(server.clients[i].fd, &rfds);
            }
        }

        int nfds = select(server.sockfd + 1, &rfds, NULL, NULL, NULL);
        if (nfds < 0) {
            perror("select");
            break;
        }

        if (FD_ISSET(server.sockfd, &rfds)) {
            server_accept(&server);
        }

        for (int i = 0; i < server.num_clients; i++) {
            if (server.clients[i].fd != -1 && FD_ISSET(server.clients[i].fd, &rfds)) {
                server_recv(&server, &server.clients[i]);
            }
        }
    }

    server_close(&server);

    return 0;
}