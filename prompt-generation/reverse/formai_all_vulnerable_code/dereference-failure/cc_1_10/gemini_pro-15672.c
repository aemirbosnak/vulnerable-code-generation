//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAX_PORTS 100

struct port_range {
    int start;
    int end;
};

struct port_scanner {
    struct port_range range;
    const char *target;
    int socket_fd;
};

int create_socket(const char *target) {
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(target);
    addr.sin_port = 0;

    if (connect(socket_fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    return socket_fd;
}

int scan_port(struct port_scanner *scanner, int port) {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(scanner->target);
    addr.sin_port = htons(port);

    if (connect(scanner->socket_fd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        printf("Port %d is open\n", port);
        return 1;
    } else {
        return 0;
    }
}

void scan_ports(struct port_scanner *scanner) {
    for (int port = scanner->range.start; port <= scanner->range.end; port++) {
        scan_port(scanner, port);
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <target> <start_port> <end_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct port_scanner scanner;
    scanner.target = argv[1];
    scanner.range.start = atoi(argv[2]);
    scanner.range.end = atoi(argv[3]);
    scanner.socket_fd = create_socket(scanner.target);

    scan_ports(&scanner);

    close(scanner.socket_fd);

    return EXIT_SUCCESS;
}