//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/epoll.h>
#include <errno.h>

#define MAX_EVENTS 10
#define BUFFER_SIZE 1024
#define SERVER_PORT 8888

bool is_attack(char* buffer) {
    // You can add your logic to detect intrusion or attack here
    // I am just checking if the string "attack" is in the buffer
    if (strstr(buffer, "attack") != NULL) {
        return true;
    }
    return false;
}

void setnonblocking(int sockfd) {
    int opts;
    opts = fcntl(sockfd, F_GETFL);
    if (opts < 0) {
        perror("fcntl(F_GETFL)");
        exit(EXIT_FAILURE);
    }
    opts = (opts | O_NONBLOCK);
    if (fcntl(sockfd, F_SETFL, opts) < 0) {
        perror("fcntl(F_SETFL)");
        exit(EXIT_FAILURE);
    }
}

int main() {
    int listen_fd, conn_fd, epoll_fd, ret;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    struct epoll_event event;
    struct epoll_event events[MAX_EVENTS];
    socklen_t cli_len;
    int n;

    // Create a listening socket
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(SERVER_PORT);

    // Bind the listening socket
    if (bind(listen_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Set the listening socket to non-blocking mode
    setnonblocking(listen_fd);

    // Listen for incoming connections
    if (listen(listen_fd, SOMAXCONN) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Create the epoll instance
    epoll_fd = epoll_create1(0);
    if (epoll_fd < 0) {
        perror("epoll_create1");
        exit(EXIT_FAILURE);
    }

    // Add the listening socket to the epoll instance
    event.data.fd = listen_fd;
    event.events = EPOLLIN | EPOLLET;
    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, listen_fd, &event) < 0) {
        perror("epoll_ctl");
        exit(EXIT_FAILURE);
    }

    while (true) {
        n = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
        if (n < 0) {
            if (errno == EINTR) {
                continue;
            } else {
                perror("epoll_wait");
                exit(EXIT_FAILURE);
            }
        }
        for (int i = 0; i < n; i++) {
            if (events[i].events & EPOLLERR) {
                perror("EPOLLERR");
                close(events[i].data.fd);
                continue;
            }
            if (events[i].data.fd == listen_fd) {
                while (true) {
                    conn_fd = accept(listen_fd, (struct sockaddr*)&cli_addr, &cli_len);
                    if (conn_fd < 0) {
                        if (errno == EAGAIN || errno == EWOULDBLOCK) {
                            break;
                        } else {
                            perror("accept");
                            break;
                        }
                    }
                    printf("Connection established with client %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
                    setnonblocking(conn_fd);
                    event.data.fd = conn_fd;
                    event.events = EPOLLIN | EPOLLET;
                    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, conn_fd, &event) < 0) {
                        perror("epoll_ctl");
                        exit(EXIT_FAILURE);
                    }
                }
                continue;
            } else {
                memset(buffer, 0, BUFFER_SIZE);
                ret = recv(events[i].data.fd, buffer, BUFFER_SIZE, 0);
                if (ret < 0) {
                    if (errno == EAGAIN || errno == EWOULDBLOCK) {
                        continue;
                    } else {
                        perror("recv");
                        close(events[i].data.fd);
                        continue;
                    }
                }
                if (ret == 0) {
                    printf("Connection closed by client %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
                    close(events[i].data.fd);
                    continue;
                }
                printf("Received message from client %s:%d: %s\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port), buffer);
                if (is_attack(buffer)) {
                    printf("INTRUSION DETECTED! Closing connection with client %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
                    close(events[i].data.fd);
                    continue;
                }
            }
        }
    }

    return 0;
}