//FormAI DATASET v1.0 Category: Port Scanner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define START_PORT 1
#define END_PORT 65536

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <host>\n", argv[0]);
        exit(1);
    }

    char *target_ip = argv[1];
    int sock, err, port;
    struct sockaddr_in addr;

    for (port = START_PORT; port < END_PORT; port++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            printf("Could not create socket: %s\n", strerror(errno));
            exit(1);
        }

        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        err = inet_pton(AF_INET, target_ip, &addr.sin_addr);
        if (err <= 0) {
            if (err == 0) {
                printf("Invalid IP address: %s\n", target_ip);
            } else {
                printf("Could not convert IP address: %s\n", strerror(errno));
            }
            exit(1);
        }

        err = connect(sock, (struct sockaddr *) &addr, sizeof(addr));
        if (err >= 0) {
            printf("Port %d is open.\n", port);
            close(sock);
        }
    }

    printf("Port scan complete.\n");
    exit(EXIT_SUCCESS);
}