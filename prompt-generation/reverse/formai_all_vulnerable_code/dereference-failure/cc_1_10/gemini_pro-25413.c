//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_EVENTS 1024

struct client {
    int fd;
    char *buf;
    size_t buf_len;
    size_t buf_used;
    int subscribed;
};

struct mailing_list {
    int fd;
    int epfd;
    struct epoll_event *events;
    struct client *clients;
    size_t num_clients;
};

int mailing_list_init(struct mailing_list *ml, int port) {
    int fd, epfd;

    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr = {
            .s_addr = htonl(INADDR_ANY),
        },
    };

    if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        close(fd);
        return -1;
    }

    if (listen(fd, 10) == -1) {
        perror("listen");
        close(fd);
        return -1;
    }

    epfd = epoll_create1(0);
    if (epfd == -1) {
        perror("epoll_create1");
        close(fd);
        return -1;
    }

    struct epoll_event event = {
        .events = EPOLLIN,
        .data = {
            .fd = fd,
        },
    };

    if (epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &event) == -1) {
        perror("epoll_ctl");
        close(fd);
        close(epfd);
        return -1;
    }

    ml->fd = fd;
    ml->epfd = epfd;
    ml->events = malloc(sizeof(struct epoll_event) * MAX_EVENTS);
    ml->clients = malloc(sizeof(struct client) * MAX_EVENTS);
    ml->num_clients = 0;

    return 0;
}

void mailing_list_free(struct mailing_list *ml) {
    close(ml->fd);
    close(ml->epfd);
    free(ml->events);
    free(ml->clients);
}

int mailing_list_accept(struct mailing_list *ml) {
    int fd;
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);

    fd = accept(ml->fd, (struct sockaddr *)&addr, &addr_len);
    if (fd == -1) {
        perror("accept");
        return -1;
    }

    if (ml->num_clients >= MAX_EVENTS) {
        close(fd);
        return -1;
    }

    struct client *client = &ml->clients[ml->num_clients++];

    client->fd = fd;
    client->buf = malloc(1024);
    client->buf_len = 1024;
    client->buf_used = 0;
    client->subscribed = 0;

    struct epoll_event event = {
        .events = EPOLLIN,
        .data = {
            .ptr = client,
        },
    };

    if (epoll_ctl(ml->epfd, EPOLL_CTL_ADD, fd, &event) == -1) {
        perror("epoll_ctl");
        close(fd);
        return -1;
    }

    return 0;
}

int mailing_list_handle_client(struct mailing_list *ml, struct client *client) {
    int n;

    n = read(client->fd, client->buf + client->buf_used, client->buf_len - client->buf_used);
    if (n == -1) {
        perror("read");
        return -1;
    }

    client->buf_used += n;

    if (client->buf_used >= client->buf_len) {
        client->buf_len *= 2;
        client->buf = realloc(client->buf, client->buf_len);
    }

    if (client->buf_used > 0 && client->buf[client->buf_used - 1] == '\n') {
        client->buf[client->buf_used - 1] = '\0';
        client->buf_used--;

        if (strcmp(client->buf, "SUBSCRIBE") == 0) {
            client->subscribed = 1;
            write(client->fd, "OK\n", 3);
        } else if (strcmp(client->buf, "UNSUBSCRIBE") == 0) {
            client->subscribed = 0;
            write(client->fd, "OK\n", 3);
        } else {
            write(client->fd, "ERR\n", 4);
        }

        client->buf_used = 0;
    }

    return 0;
}

int mailing_list_broadcast(struct mailing_list *ml, const char *msg, size_t len) {
    int i;

    for (i = 0; i < ml->num_clients; i++) {
        struct client *client = &ml->clients[i];

        if (client->subscribed) {
            if (write(client->fd, msg, len) == -1) {
                perror("write");
                return -1;
            }
        }
    }

    return 0;
}

int mailing_list_run(struct mailing_list *ml) {
    int nfds;

    while (1) {
        nfds = epoll_wait(ml->epfd, ml->events, MAX_EVENTS, -1);
        if (nfds == -1) {
            perror("epoll_wait");
            return -1;
        }

        int i;

        for (i = 0; i < nfds; i++) {
            if (ml->events[i].data.fd == ml->fd) {
                mailing_list_accept(ml);
            } else {
                struct client *client = ml->events[i].data.ptr;
                mailing_list_handle_client(ml, client);
            }
        }
    }

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    struct mailing_list ml;
    if (mailing_list_init(&ml, port) == -1) {
        return 1;
    }

    mailing_list_run(&ml);

    mailing_list_free(&ml);

    return 0;
}