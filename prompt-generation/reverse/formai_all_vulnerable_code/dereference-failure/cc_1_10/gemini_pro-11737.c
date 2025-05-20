//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>

#define MAX_EVENTS 1024

struct client_data {
    int fd;
    char *buffer;
    size_t buffer_len;
};

int set_nonblock(int fd) {
    int flags = fcntl(fd, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl");
        return -1;
    }
    flags |= O_NONBLOCK;
    if (fcntl(fd, F_SETFL, flags) == -1) {
        perror("fcntl");
        return -1;
    }
    return 0;
}

struct client_data *create_client_data(int fd) {
    struct client_data *client = malloc(sizeof(*client));
    if (client == NULL) {
        perror("malloc");
        return NULL;
    }
    client->fd = fd;
    client->buffer = malloc(4096);
    if (client->buffer == NULL) {
        perror("malloc");
        free(client);
        return NULL;
    }
    client->buffer_len = 0;
    return client;
}

void free_client_data(struct client_data *client) {
    close(client->fd);
    free(client->buffer);
    free(client);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int port = atoi(argv[1]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    if (listen(sockfd, SOMAXCONN) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    if (set_nonblock(sockfd) == -1) {
        perror("set_nonblock");
        return EXIT_FAILURE;
    }

    int epollfd = epoll_create1(0);
    if (epollfd == -1) {
        perror("epoll_create1");
        return EXIT_FAILURE;
    }

    struct epoll_event event;
    memset(&event, 0, sizeof(event));
    event.events = EPOLLIN | EPOLLET;
    event.data.fd = sockfd;
    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, sockfd, &event) == -1) {
        perror("epoll_ctl");
        return EXIT_FAILURE;
    }

    struct epoll_event events[MAX_EVENTS];

    while (1) {
        int nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        if (nfds == -1) {
            if (errno == EINTR) {
                continue;
            }
            perror("epoll_wait");
            return EXIT_FAILURE;
        }

        for (int i = 0; i < nfds; i++) {
            if (events[i].data.fd == sockfd) {
                struct sockaddr_in client_addr;
                socklen_t client_addr_len = sizeof(client_addr);
                int clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
                if (clientfd == -1) {
                    perror("accept");
                    continue;
                }

                if (set_nonblock(clientfd) == -1) {
                    perror("set_nonblock");
                    continue;
                }

                struct client_data *client = create_client_data(clientfd);
                if (client == NULL) {
                    continue;
                }

                event.events = EPOLLIN | EPOLLET;
                event.data.ptr = client;
                if (epoll_ctl(epollfd, EPOLL_CTL_ADD, clientfd, &event) == -1) {
                    perror("epoll_ctl");
                    free_client_data(client);
                    continue;
                }
            } else {
                struct client_data *client = events[i].data.ptr;
                if (events[i].events & EPOLLIN) {
                    ssize_t nread = read(client->fd, client->buffer + client->buffer_len, 4096 - client->buffer_len);
                    if (nread == -1) {
                        if (errno == EAGAIN) {
                            continue;
                        }
                        perror("read");
                        free_client_data(client);
                        continue;
                    } else if (nread == 0) {
                        close(client->fd);
                        epoll_ctl(epollfd, EPOLL_CTL_DEL, client->fd, NULL);
                        free_client_data(client);
                        continue;
                    }
                    client->buffer_len += nread;
                    if (strstr(client->buffer, "\n") != NULL) {
                        char *newline = strchr(client->buffer, '\n');
                        *newline = '\0';
                        printf("Received: %s\n", client->buffer);
                        write(client->fd, client->buffer, strlen(client->buffer));
                        client->buffer_len = 0;
                    }
                }
            }
        }
    }

    close(sockfd);
    close(epollfd);

    return EXIT_SUCCESS;
}