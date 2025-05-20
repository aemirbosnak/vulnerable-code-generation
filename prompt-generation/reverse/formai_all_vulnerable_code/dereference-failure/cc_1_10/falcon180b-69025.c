//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <signal.h>
#include <fcntl.h>
#include <poll.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024
#define TIMEOUT 5000

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    int sock;
    struct sockaddr_in addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid host or IP address.\n");
        exit(1);
    }

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    fd_set master, read;
    FD_ZERO(&master);
    FD_ZERO(&read);
    FD_SET(sock, &master);

    struct pollfd poll_fds[1];
    poll_fds[0].fd = sock;
    poll_fds[0].events = POLLIN;

    int ret;

    for (int i = 1; i <= MAX_PORTS; i++) {
        if (poll(poll_fds, 1, TIMEOUT) > 0) {
            if (poll_fds[0].revents & POLLIN) {
                ret = recv(sock, buffer, BUFFER_SIZE, 0);
                if (ret <= 0) {
                    break;
                }
                buffer[ret] = '\0';
                printf("Port %d: %s\n", i, buffer);
            }
        } else {
            break;
        }
    }

    close(sock);

    return 0;
}