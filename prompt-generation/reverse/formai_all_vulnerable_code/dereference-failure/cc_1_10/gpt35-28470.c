//FormAI DATASET v1.0 Category: Chat server ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>

#define MAX_EVENTS 10
#define MAX_BUFFER_SIZE 1024

/* Function to set a socket to non-blocking mode */
int set_nonblocking(int fd)
{
    int flags = fcntl(fd, F_GETFL, 0);
    if (flags == -1)
    {
        return -1;
    }
    flags |= O_NONBLOCK;
    return fcntl(fd, F_SETFL, flags);
}

/* Function to handle incoming connections */
void handle_connection(int fd, int epoll_fd)
{
    struct epoll_event event;
    event.events = EPOLLIN | EPOLLET;
    event.data.fd = fd;
    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &event) == -1)
    {
        perror("Error adding socket to epoll");
        exit(EXIT_FAILURE);
    }
    printf("New connection on fd %d\n", fd);
}

/* Function to handle incoming data */
void handle_data(int fd, int epoll_fd, char *buffer)
{
    int bytes_read = read(fd, buffer, MAX_BUFFER_SIZE);
    if (bytes_read == -1)
    {
        if (errno == EAGAIN || errno == EWOULDBLOCK)
        {
            return;
        }
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }
    if (bytes_read == 0)
    {
        printf("Connection closed on fd %d\n", fd);
        if (epoll_ctl(epoll_fd, EPOLL_CTL_DEL, fd, NULL) == -1)
        {
            perror("Error removing socket from epoll");
            exit(EXIT_FAILURE);
        }
        close(fd);
        return;
    }
    buffer[bytes_read] = '\0';
    printf("Received data on fd %d: %s\n", fd, buffer);
}

/* Main function */
int main(int argc, char *argv[])
{
    int server_fd, client_fd, epoll_fd, nfds, i;
    struct sockaddr_in server_addr, client_addr;
    struct epoll_event events[MAX_EVENTS];
    char buffer[MAX_BUFFER_SIZE];

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Initialize server address */
    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    /* Create server socket */
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    /* Bind server socket to address */
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in)) == -1)
    {
        perror("Error binding server socket to address");
        exit(EXIT_FAILURE);
    }

    /* Set server socket to listen mode */
    if (listen(server_fd, SOMAXCONN) == -1)
    {
        perror("Error setting server socket to listen mode");
        exit(EXIT_FAILURE);
    }

    /* Set server socket to non-blocking mode */
    if (set_nonblocking(server_fd) == -1)
    {
        perror("Error setting server socket to non-blocking mode");
        exit(EXIT_FAILURE);
    }

    /* Create epoll instance */
    epoll_fd = epoll_create1(0);
    if (epoll_fd == -1)
    {
        perror("Error creating epoll instance");
        exit(EXIT_FAILURE);
    }

    /* Add server socket to epoll */
    struct epoll_event event;
    event.events = EPOLLIN | EPOLLET;
    event.data.fd = server_fd;
    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, server_fd, &event) == -1)
    {
        perror("Error adding server socket to epoll");
        exit(EXIT_FAILURE);
    }

    /* Main event loop */
    while (1)
    {
        nfds = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
        if (nfds == -1)
        {
            perror("Error waiting for events");
            exit(EXIT_FAILURE);
        }
        for (i = 0; i < nfds; i++)
        {
            if (events[i].data.fd == server_fd)
            {
                /* New connection */
                socklen_t client_addr_len = sizeof(struct sockaddr_in);
                client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
                if (client_fd == -1)
                {
                    perror("Error accepting new connection");
                    continue;
                }
                if (set_nonblocking(client_fd) == -1)
                {
                    perror("Error setting client socket to non-blocking mode");
                    continue;
                }
                handle_connection(client_fd, epoll_fd);
            }
            else
            {
                /* Incoming data */
                handle_data(events[i].data.fd, epoll_fd, buffer);
            }
        }
    }

    return 0;
}