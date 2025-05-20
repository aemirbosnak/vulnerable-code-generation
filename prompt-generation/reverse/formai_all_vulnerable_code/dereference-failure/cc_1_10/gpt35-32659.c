//FormAI DATASET v1.0 Category: Port Scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAX_PORT_NUM 65535
#define TIMEOUT_SEC 2

typedef struct {
    char *ip;
    int port;
} target_t;

void scan_target(target_t *target) {
    int sock_fd, ret;
    struct sockaddr_in addr;
    struct timeval timeout;
    fd_set fds;

    /* create socket */
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("socket");
        return;
    }

    /* set timeout */
    timeout.tv_sec = TIMEOUT_SEC;
    timeout.tv_usec = 0;
    FD_ZERO(&fds);
    FD_SET(sock_fd, &fds);

    /* set socket options */
    addr.sin_family = AF_INET;
    addr.sin_port = htons(target->port);
    addr.sin_addr.s_addr = inet_addr(target->ip);

    /* connect to target */
    ret = connect(sock_fd, (struct sockaddr *)&addr, sizeof(addr));
    if (ret < 0) {
        if (errno == ECONNREFUSED) {
            printf("%s:%d is closed.\n", target->ip, target->port);
        }
        close(sock_fd);
        return;
    }

    printf("%s:%d is open.\n", target->ip, target->port);

    close(sock_fd);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <ip_address>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    target_t target;

    target.ip = ip;

    /* scan all ports */
    for (int port = 1; port <= MAX_PORT_NUM; port++) {
        target.port = port;
        scan_target(&target);
    }

    return 0;
}