//GEMINI-pro DATASET v1.0 Category: Educational ; Style: asynchronous
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define MAX_EVENTS 10
#define BUFFER_SIZE 1024

typedef enum {
    READ,
    WRITE
} event_type_t;

typedef struct {
    int fd;
    event_type_t type;
    char *buffer;
    size_t buffer_size;
    size_t buffer_used;
    struct epoll_event event;
} event_t;

static int create_and_bind_socket(const char *address, int port)
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = inet_addr(address),
        .sin_port = htons(port)
    };

    if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    return fd;
}

static void set_nonblocking(int fd)
{
    int flags = fcntl(fd, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }

    if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) == -1) {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }
}

static event_t *create_event(int fd, event_type_t type, char *buffer, size_t buffer_size)
{
    event_t *event = malloc(sizeof(event_t));
    if (event == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    event->fd = fd;
    event->type = type;
    event->buffer = buffer;
    event->buffer_size = buffer_size;
    event->buffer_used = 0;
    event->event.data.ptr = event;

    return event;
}

static void free_event(event_t *event)
{
    if (event->buffer != NULL) {
        free(event->buffer);
        event->buffer = NULL;
    }

    free(event);
}

static void add_event_to_epoll(int epoll_fd, event_t *event)
{
    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, event->fd, &event->event) == -1) {
        perror("epoll_ctl");
        exit(EXIT_FAILURE);
    }
}

static void remove_event_from_epoll(int epoll_fd, event_t *event)
{
    if (epoll_ctl(epoll_fd, EPOLL_CTL_DEL, event->fd, &event->event) == -1) {
        perror("epoll_ctl");
        exit(EXIT_FAILURE);
    }
}

static void handle_read_event(event_t *event)
{
    ssize_t bytes_read = read(event->fd, event->buffer + event->buffer_used, event->buffer_size - event->buffer_used);
    if (bytes_read == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    } else if (bytes_read == 0) {
        close(event->fd);
        remove_event_from_epoll(event->event.data.fd, event);
        free_event(event);
    } else {
        event->buffer_used += bytes_read;
        event->event.events = EPOLLIN | EPOLLOUT;
        add_event_to_epoll(event->event.data.fd, event);
    }
}

static void handle_write_event(event_t *event)
{
    ssize_t bytes_written = write(event->fd, event->buffer, event->buffer_used);
    if (bytes_written == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    } else {
        event->buffer_used -= bytes_written;
        if (event->buffer_used == 0) {
            event->event.events = EPOLLIN;
            remove_event_from_epoll(event->event.data.fd, event);
            add_event_to_epoll(event->event.data.fd, event);
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int epoll_fd = epoll_create1(0);
    if (epoll_fd == -1) {
        perror("epoll_create1");
        exit(EXIT_FAILURE);
    }

    int server_fd = create_and_bind_socket(argv[1], atoi(argv[2]));
    if (server_fd == -1) {
        perror("create_and_bind_socket");
        exit(EXIT_FAILURE);
    }

    set_nonblocking(server_fd);

    event_t *server_event = create_event(server_fd, READ, NULL, 0);
    if (server_event == NULL) {
        perror("create_event");
        exit(EXIT_FAILURE);
    }

    server_event->event.events = EPOLLIN;
    add_event_to_epoll(epoll_fd, server_event);

    struct epoll_event events[MAX_EVENTS];
    while (1) {
        int num_events = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
        if (num_events == -1) {
            perror("epoll_wait");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < num_events; i++) {
            event_t *event = events[i].data.ptr;

            if (event->fd == server_fd) {
                struct sockaddr_in client_addr;
                socklen_t client_addr_len = sizeof(client_addr);
                int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
                if (client_fd == -1) {
                    perror("accept");
                    exit(EXIT_FAILURE);
                }

                set_nonblocking(client_fd);

                char *client_address = inet_ntoa(client_addr.sin_addr);
                if (client_address == NULL) {
                    perror("inet_ntoa");
                    exit(EXIT_FAILURE);
                }

                printf("New connection from %s:%d\n", client_address, ntohs(client_addr.sin_port));

                event_t *client_event = create_event(client_fd, READ, malloc(BUFFER_SIZE), BUFFER_SIZE);
                if (client_event == NULL) {
                    perror("create_event");
                    exit(EXIT_FAILURE);
                }

                client_event->event.events = EPOLLIN;
                add_event_to_epoll(epoll_fd, client_event);
            } else if (events[i].events & EPOLLIN) {
                handle_read_event(event);
            } else if (events[i].events & EPOLLOUT) {
                handle_write_event(event);
            }
        }
    }

    close(server_fd);
    close(epoll_fd);

    return EXIT_SUCCESS;
}