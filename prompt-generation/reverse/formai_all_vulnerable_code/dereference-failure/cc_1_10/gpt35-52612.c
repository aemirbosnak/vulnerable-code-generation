//FormAI DATASET v1.0 Category: Port Scanner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT_RANGE_MIN 1
#define PORT_RANGE_MAX 65535
#define MAX_WAIT_MILLISEC 250

int socket_valid(int sockfd);
int set_socket_nonblocking(int sockfd);
void close_socket(int sockfd);

int main(int argc, char *argv[])
{
    int sockfd, rc, on = 1;
    struct sockaddr_in sa;
    struct timeval tv;
    fd_set fds;
    char *target;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <target>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (!socket_valid(sockfd)) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    rc = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *) &on, sizeof(on));
    if (rc < 0) {
        perror("setsockopt() failed");
        close_socket(sockfd);
        exit(EXIT_FAILURE);
    }

    rc = set_socket_nonblocking(sockfd);
    if (rc < 0) {
        perror("set_socket_nonblocking() failed");
        close_socket(sockfd);
        exit(EXIT_FAILURE);
    }

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr(argv[1]);
    if (sa.sin_addr.s_addr == INADDR_NONE) {
        printf("Invalid IP address: %s\n", argv[1]);
        close_socket(sockfd);
        exit(EXIT_FAILURE);
    }

    target = strdup(argv[1]);
    if (!target) {
        perror("strdup() failed");
        close_socket(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Scanning ports on %s...\n", target);

    for (int i = PORT_RANGE_MIN; i <= PORT_RANGE_MAX; i++) {
        sa.sin_port = htons(i);

        rc = connect(sockfd, (struct sockaddr *) &sa, sizeof(sa));
        if (rc < 0) {
            if (errno != EINPROGRESS) {
                continue;
            }

            FD_ZERO(&fds);
            FD_SET(sockfd, &fds);

            tv.tv_sec = 0;
            tv.tv_usec = MAX_WAIT_MILLISEC * 1000;

            rc = select(sockfd + 1, NULL, &fds, NULL, &tv);
            if (rc <= 0) {
                continue;
            }

            if (!FD_ISSET(sockfd, &fds)) {
                continue;
            }
        }

        printf("Port %d open!\n", i);
    }

    printf("Scan completed!\n");

    close_socket(sockfd);

    return 0;
}

int socket_valid(int sockfd)
{
    return sockfd >= 0;
}

int set_socket_nonblocking(int sockfd)
{
    int flags;

    flags = fcntl(sockfd, F_GETFL, 0);
    if (flags < 0) {
        perror("fcntl(F_GETFL) failed");
        return -1;
    }

    flags |= O_NONBLOCK;
    if (fcntl(sockfd, F_SETFL, flags) < 0) {
        perror("fcntl(F_SETFL) failed");
        return -1;
    }

    return 0;
}

void close_socket(int sockfd)
{
    close(sockfd);
}