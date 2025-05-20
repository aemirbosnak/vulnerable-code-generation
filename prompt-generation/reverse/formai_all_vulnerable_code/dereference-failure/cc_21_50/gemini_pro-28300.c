//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_EVENTS 10

struct client_data {
    int fd;
    char *buf;
    size_t buf_len;
};

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int port = atoi(argv[1]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    int ret = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (ret == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    ret = listen(sockfd, SOMAXCONN);
    if (ret == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    int epollfd = epoll_create1(0);
    if (epollfd == -1) {
        perror("epoll_create1");
        return EXIT_FAILURE;
    }

    struct epoll_event event;
    event.events = EPOLLIN | EPOLLET;
    event.data.fd = sockfd;

    ret = epoll_ctl(epollfd, EPOLL_CTL_ADD, sockfd, &event);
    if (ret == -1) {
        perror("epoll_ctl");
        return EXIT_FAILURE;
    }

    struct epoll_event events[MAX_EVENTS];

    while (1) {
        int nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        if (nfds == -1) {
            perror("epoll_wait");
            return EXIT_FAILURE;
        }

        for (int i = 0; i < nfds; i++) {
            if (events[i].data.fd == sockfd) {
                int clientfd = accept(sockfd, NULL, NULL);
                if (clientfd == -1) {
                    perror("accept");
                    continue;
                }

                struct client_data *client_data = malloc(sizeof(struct client_data));
                if (client_data == NULL) {
                    perror("malloc");
                    close(clientfd);
                    continue;
                }

                client_data->fd = clientfd;
                client_data->buf = malloc(BUFSIZ);
                if (client_data->buf == NULL) {
                    perror("malloc");
                    free(client_data);
                    close(clientfd);
                    continue;
                }

                client_data->buf_len = 0;

                event.events = EPOLLIN | EPOLLET;
                event.data.ptr = client_data;

                ret = epoll_ctl(epollfd, EPOLL_CTL_ADD, clientfd, &event);
                if (ret == -1) {
                    perror("epoll_ctl");
                    free(client_data->buf);
                    free(client_data);
                    close(clientfd);
                    continue;
                }
            } else {
                struct client_data *client_data = (struct client_data *)events[i].data.ptr;

                ret = read(client_data->fd, client_data->buf + client_data->buf_len, BUFSIZ - client_data->buf_len);
                if (ret == -1) {
                    perror("read");
                    close(client_data->fd);
                    free(client_data->buf);
                    free(client_data);
                    continue;
                } else if (ret == 0) {
                    close(client_data->fd);
                    free(client_data->buf);
                    free(client_data);
                    continue;
                }

                client_data->buf_len += ret;

                int is_palindrome = 1;
                for (int j = 0; j < client_data->buf_len / 2; j++) {
                    if (client_data->buf[j] != client_data->buf[client_data->buf_len - 1 - j]) {
                        is_palindrome = 0;
                        break;
                    }
                }

                char *msg;
                if (is_palindrome) {
                    msg = "yes\n";
                } else {
                    msg = "no\n";
                }

                ret = write(client_data->fd, msg, strlen(msg));
                if (ret == -1) {
                    perror("write");
                    close(client_data->fd);
                    free(client_data->buf);
                    free(client_data);
                    continue;
                }

                close(client_data->fd);
                free(client_data->buf);
                free(client_data);
            }
        }
    }

    close(sockfd);
    close(epollfd);

    return EXIT_SUCCESS;
}