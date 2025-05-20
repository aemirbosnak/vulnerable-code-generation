//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/time.h>

#define MAX_DATA_LEN 1024
#define TIMEOUT 5

int sock_fd;
struct addrinfo hints, *res;

void signal_handler(int signum)
{
    if (signum == SIGINT || signum == SIGTERM) {
        close(sock_fd);
        printf("Exiting.\n");
        exit(0);
    }
}

void connect_callback(int status)
{
    if (status != 0) {
        fprintf(stderr, "ERROR: Could not connect, error code: %s\n", gai_strerror(status));
        exit(1);
    }

    printf("Connected to server.\n");

    char data[MAX_DATA_LEN];
    int len;
    fd_set read_fds;
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    while (1) {
        FD_ZERO(&read_fds);
        FD_SET(sock_fd, &read_fds);
        int ready = select(sock_fd + 1, &read_fds, NULL, NULL, &tv);

        if (ready == -1) {
            perror("ERROR: select() failed");
            break;
        } else if (ready == 0) {
            printf("Timeout occurred - no data received after %d seconds.\n", TIMEOUT);
            break;
        }

        len = recv(sock_fd, data, MAX_DATA_LEN - 1, 0);

        if (len == -1) {
            perror("ERROR: recv() failed");
            break;
        } else if (len == 0) {
            printf("Connection closed by server.\n");
            break;
        }

        data[len] = '\0';
        printf("Received data: %s\n", data);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr,"Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    int status = getaddrinfo(argv[1], argv[2], &hints, &res);

    if (status != 0) {
        fprintf(stderr, "ERROR: Could not get address info, error code: %s\n", gai_strerror(status));
        exit(1);
    }

    sock_fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    if (sock_fd == -1) {
        perror("ERROR: Could not create socket");
        exit(1);
    }

    if (fcntl(sock_fd, F_SETFL, O_NONBLOCK) == -1) {
        perror("ERROR: Could not set socket to non-blocking mode");
        close(sock_fd);
        exit(1);
    }

    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    if (connect(sock_fd, res->ai_addr, res->ai_addrlen) == -1) {
        if (errno != EINPROGRESS) {
            perror("ERROR: Could not connect");
            close(sock_fd);
            exit(1);
        }

        fd_set write_fds;
        FD_ZERO(&write_fds);
        FD_SET(sock_fd, &write_fds);
        struct timeval tv;
        tv.tv_sec = TIMEOUT;
        tv.tv_usec = 0;

        if (select(sock_fd + 1, NULL, &write_fds, NULL, &tv) == -1) {
            perror("ERROR: select() failed");
            close(sock_fd);
            exit(1);
        }

        int err = 0;
        socklen_t err_len = sizeof(err);

        if (getsockopt(sock_fd, SOL_SOCKET, SO_ERROR, &err, &err_len) == -1) {
            perror("ERROR: getsockopt() failed");
            close(sock_fd);
            exit(1);
        }

        if (err != 0) {
            fprintf(stderr, "ERROR: Could not connect, error code: %s\n", strerror(err));
            close(sock_fd);
            exit(1);
        }
    }

    connect_callback(0);

    return 0;
}