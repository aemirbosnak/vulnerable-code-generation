//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_PORTS 65535

char* banner;

void print_banner() {
    printf("%s\n", banner);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <target> <port1> <port2> ... <portN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    banner = "C Port Scanner";

    printf("%s\n", banner);

    printf("Target: %s\n", argv[1]);

    int target_fd;
    struct sockaddr_in target_addr;

    if ((target_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(argv[1]);
    target_addr.sin_port = 0;

    if (connect(target_fd, (struct sockaddr *) &target_addr, sizeof(target_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    for (int i = 2; i < argc; i++) {
        uint16_t port = atoi(argv[i]);

        if (port < 1 || port > MAX_PORTS) {
            printf("Invalid port: %d\n", port);
            continue;
        }

        target_addr.sin_port = htons(port);

        if (connect(target_fd, (struct sockaddr *) &target_addr, sizeof(target_addr)) == -1) {
            printf("Port %d is closed\n", port);
        } else {
            printf("Port %d is open\n", port);
        }
    }

    close(target_fd);

    return EXIT_SUCCESS;
}