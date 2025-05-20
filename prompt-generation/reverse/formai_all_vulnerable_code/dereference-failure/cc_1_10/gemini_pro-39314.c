//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

static int running;

static void signal_handler(int signal) {
    running = 0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *ip = argv[1];
    int port = atoi(argv[2]);
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &address.sin_addr) != 1) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    signal(SIGINT, signal_handler);
    running = 1;
    while (running) {
        if (connect(sock, (struct sockaddr *)&address, sizeof(address)) == 0) {
            printf("Port %d is open on %s.\n", port, ip);
        } else {
            if (errno == ECONNREFUSED) {
                printf("Port %d is closed on %s.\n", port, ip);
            } else {
                perror("connect");
                return EXIT_FAILURE;
            }
        }

        sleep(1);
    }

    close(sock);
    return EXIT_SUCCESS;
}