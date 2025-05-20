//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/epoll.h>

#define MAX_EVENTS 5
#define MAX_MESSAGE_LENGTH 1024

typedef struct {
    int fd;
    struct sockaddr_in addr;
    socklen_t addr_len;
    char message[MAX_MESSAGE_LENGTH];
    size_t message_len;
} connection_t;

int create_server_socket(int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, 10) == -1) {
        perror("listen");
        exit(1);
    }

    return sockfd;
}

void handle_connection(connection_t *conn) {
    char *message = conn->message;
    size_t message_len = conn->message_len;

    // Process the message here...

    // Send a response back to the client
    if (send(conn->fd, message, message_len, 0) == -1) {
        perror("send");
        close(conn->fd);
    }

    close(conn->fd);
}

int main(int argc, char **argv) {
    int server_sockfd = create_server_socket(atoi(argv[1]));

    int epoll_fd = epoll_create1(0);
    if (epoll_fd == -1) {
        perror("epoll_create1");
        exit(1);
    }

    struct epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = server_sockfd;
    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, server_sockfd, &event) == -1) {
        perror("epoll_ctl");
        exit(1);
    }

    connection_t connections[MAX_EVENTS];
    int num_connections = 0;

    while (1) {
        int num_events = epoll_wait(epoll_fd, connections, MAX_EVENTS, -1);
        if (num_events == -1) {
            perror("epoll_wait");
            exit(1);
        }

        for (int i = 0; i < num_events; i++) {
            if (connections[i].fd == server_sockfd) {
                // New connection
                struct sockaddr_in addr;
                socklen_t addr_len = sizeof(addr);
                int client_sockfd = accept(server_sockfd, (struct sockaddr*)&addr, &addr_len);
                if (client_sockfd == -1) {
                    perror("accept");
                    continue;
                }

                connections[num_connections].fd = client_sockfd;
                connections[num_connections].addr = addr;
                connections[num_connections].addr_len = addr_len;
                connections[num_connections].message_len = 0;

                event.events = EPOLLIN;
                event.data.fd = client_sockfd;
                if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_sockfd, &event) == -1) {
                    perror("epoll_ctl");
                    close(client_sockfd);
                    continue;
                }

                num_connections++;
            } else {
                // Existing connection
                int client_sockfd = connections[i].fd;

                // Read message from client
                ssize_t bytes_read = recv(client_sockfd, connections[i].message + connections[i].message_len, MAX_MESSAGE_LENGTH - connections[i].message_len, 0);
                if (bytes_read == -1) {
                    perror("recv");
                    close(client_sockfd);
                    continue;
                } else if (bytes_read == 0) {
                    // Client closed connection
                    close(client_sockfd);
                    continue;
                }

                connections[i].message_len += bytes_read;

                // Process the message in a separate thread
                handle_connection(&connections[i]);
            }
        }
    }

    // Close server socket and epoll file descriptor
    close(server_sockfd);
    close(epoll_fd);

    return 0;
}