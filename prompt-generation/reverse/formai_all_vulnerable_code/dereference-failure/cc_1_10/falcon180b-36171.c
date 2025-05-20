//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535

void print_usage(char *argv[]) {
    printf("Usage: %s <host> <port_range>\n", argv[0]);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage(argv);
        return 1;
    }

    char *host = argv[1];
    char *port_range = argv[3];

    int start_port, end_port;
    if (sscanf(port_range, "%d-%d", &start_port, &end_port)!= 2) {
        printf("Invalid port range\n");
        return 1;
    }

    if (start_port > end_port) {
        printf("Invalid port range\n");
        return 1;
    }

    int max_fd = 0;
    int *fds = calloc(end_port - start_port + 1, sizeof(int));
    if (fds == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    for (int i = start_port; i <= end_port; i++) {
        int fd = socket(AF_INET, SOCK_STREAM, 0);
        if (fd == -1) {
            printf("Error creating socket\n");
            free(fds);
            return 1;
        }

        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(i);
        addr.sin_addr.s_addr = inet_addr(host);

        if (connect(fd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
            printf("Port %d is open\n", i);
            close(fd);
        } else {
            if (errno == ECONNREFUSED) {
                printf("Port %d is closed\n", i);
            } else {
                printf("Error connecting to port %d: %s\n", i, strerror(errno));
            }
            close(fd);
        }

        fds[i - start_port] = fd;
        if (fd > max_fd) {
            max_fd = fd;
        }
    }

    select(max_fd + 1, NULL, NULL, NULL, NULL);

    free(fds);

    return 0;
}