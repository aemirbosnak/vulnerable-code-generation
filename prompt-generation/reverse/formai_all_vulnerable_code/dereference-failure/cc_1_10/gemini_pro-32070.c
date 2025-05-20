//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_EVENTS 10

struct client_data {
    int fd;
    int state;
    char buffer[1024];
    int buffer_len;
};

void handle_client(struct epoll_event *event, struct client_data *client) {
    int fd = client->fd;
    int state = client->state;

    if (state == 0) {
        // Read request
        int n = read(fd, client->buffer, sizeof(client->buffer) - 1);
        if (n <= 0) {
            // Client closed connection
            close(fd);
            free(client);
            return;
        }
        client->buffer_len = n;
        client->state = 1;
    } else if (state == 1) {
        // Parse request
        char *path = strtok(client->buffer, " ");
        if (!path) {
            // Invalid request
            close(fd);
            free(client);
            return;
        }

        // Generate response
        char *response = "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nHello, world!\n";
        int response_len = strlen(response);

        // Send response
        int n = write(fd, response, response_len);
        if (n <= 0) {
            // Client closed connection
            close(fd);
            free(client);
            return;
        }

        // Close connection
        close(fd);
        free(client);
    }
}

int main(int argc, char *argv[]) {
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8080);

    if (bind(listen_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(listen_fd, 10) < 0) {
        perror("listen");
        return 1;
    }

    int epoll_fd = epoll_create1(0);
    if (epoll_fd < 0) {
        perror("epoll_create1");
        return 1;
    }

    struct epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = listen_fd;

    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, listen_fd, &event) < 0) {
        perror("epoll_ctl");
        return 1;
    }

    while (1) {
        struct epoll_event events[MAX_EVENTS];
        int n = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
        if (n < 0) {
            perror("epoll_wait");
            break;
        }

        for (int i = 0; i < n; i++) {
            if (events[i].data.fd == listen_fd) {
                // New connection
                struct sockaddr_in client_addr;
                socklen_t client_addr_len = sizeof(client_addr);
                int client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_addr_len);
                if (client_fd < 0) {
                    perror("accept");
                    continue;
                }

                struct client_data *client = malloc(sizeof(struct client_data));
                client->fd = client_fd;
                client->state = 0;
                client->buffer_len = 0;

                event.events = EPOLLIN;
                event.data.fd = client_fd;

                if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_fd, &event) < 0) {
                    perror("epoll_ctl");
                    free(client);
                    close(client_fd);
                    continue;
                }
            } else {
                // Existing connection
                struct client_data *client = (struct client_data *)events[i].data.ptr;
                handle_client(&events[i], client);
            }
        }
    }

    close(listen_fd);
    close(epoll_fd);
    return 0;
}