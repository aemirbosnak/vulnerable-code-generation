//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>

#define MAX_EVENTS 100

typedef enum {
    EVENT_NONE = 0,
    EVENT_READ = 1,
    EVENT_WRITE = 2,
    EVENT_READ_WRITE = 3,
} event_t;

typedef struct {
    int fd;
    event_t events;
    void *data;
} event_data_t;

typedef struct {
    int epoll_fd;
    event_data_t *events;
    int num_events;
} epoll_state_t;

epoll_state_t *epoll_init(int max_events)
{
    epoll_state_t *state = malloc(sizeof(epoll_state_t));
    if (!state) {
        return NULL;
    }

    state->epoll_fd = epoll_create1(0);
    if (state->epoll_fd == -1) {
        free(state);
        return NULL;
    }

    state->events = malloc(sizeof(event_data_t) * max_events);
    if (!state->events) {
        close(state->epoll_fd);
        free(state);
        return NULL;
    }

    state->num_events = 0;

    return state;
}

int epoll_add_event(epoll_state_t *state, int fd, event_t events, void *data)
{
    struct epoll_event ev;
    memset(&ev, 0, sizeof(ev));

    ev.events = 0;
    if (events & EVENT_READ) {
        ev.events |= EPOLLIN;
    }
    if (events & EVENT_WRITE) {
        ev.events |= EPOLLOUT;
    }

    ev.data.ptr = data;

    if (epoll_ctl(state->epoll_fd, EPOLL_CTL_ADD, fd, &ev) == -1) {
        return -1;
    }

    state->events[state->num_events].fd = fd;
    state->events[state->num_events].events = events;
    state->events[state->num_events].data = data;
    state->num_events++;

    return 0;
}

int epoll_wait_events(epoll_state_t *state, int timeout)
{
    struct epoll_event events[MAX_EVENTS];

    int num_events = epoll_wait(state->epoll_fd, events, MAX_EVENTS, timeout);
    if (num_events == -1) {
        return -1;
    }

    for (int i = 0; i < num_events; i++) {
        event_data_t *event = events[i].data.ptr;
        if (events[i].events & EPOLLIN) {
            event->events |= EVENT_READ;
        }
        if (events[i].events & EPOLLOUT) {
            event->events |= EVENT_WRITE;
        }
    }

    return num_events;
}

void epoll_free(epoll_state_t *state)
{
    close(state->epoll_fd);
    free(state->events);
    free(state);
}

int main()
{
    epoll_state_t *epoll = epoll_init(MAX_EVENTS);
    if (!epoll) {
        perror("epoll_init");
        return EXIT_FAILURE;
    }

    // Create a socket for listening for incoming connections
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1) {
        perror("socket");
        epoll_free(epoll);
        return EXIT_FAILURE;
    }

    int optval = 1;
    if (setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        perror("setsockopt");
        close(listen_sock);
        epoll_free(epoll);
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(12345);

    if (bind(listen_sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        close(listen_sock);
        epoll_free(epoll);
        return EXIT_FAILURE;
    }

    if (listen(listen_sock, 5) == -1) {
        perror("listen");
        close(listen_sock);
        epoll_free(epoll);
        return EXIT_FAILURE;
    }

    // Add the listening socket to the epoll instance
    epoll_add_event(epoll, listen_sock, EVENT_READ, listen_sock);

    while (1) {
        int num_events = epoll_wait_events(epoll, -1);
        if (num_events == -1) {
            perror("epoll_wait_events");
            break;
        }

        // Process the events
        for (int i = 0; i < num_events; i++) {
            int fd = epoll->events[i].fd;
            event_t events = epoll->events[i].events;
            if (fd == listen_sock) {
                // A new connection has arrived
                struct sockaddr_in client_addr;
                socklen_t client_addr_len = sizeof(client_addr);
                int client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &client_addr_len);
                if (client_sock == -1) {
                    perror("accept");
                    continue;
                }

                // Add the client socket to the epoll instance
                epoll_add_event(epoll, client_sock, EVENT_READ_WRITE, client_sock);
            } else {
                // Data has arrived on a client socket
                char buffer[1024];
                int bytes_read = read(fd, buffer, sizeof(buffer));
                if (bytes_read == -1) {
                    perror("read");
                    epoll_add_event(epoll, fd, EVENT_READ_WRITE, NULL);
                    continue;
                }

                if (bytes_read == 0) {
                    // The client has closed the connection
                    epoll_add_event(epoll, fd, EVENT_NONE, NULL);
                    continue;
                }

                // Echo the data back to the client
                write(fd, buffer, bytes_read);
            }
        }
    }

    epoll_free(epoll);

    return EXIT_SUCCESS;
}