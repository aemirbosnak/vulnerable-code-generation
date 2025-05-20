//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 100

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <target> <port1> [port2] ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *target = argv[1];
    int ports[MAX_PORTS];

    for (int i = 2; i < argc; i++) {
        ports[i - 2] = atoi(argv[i]);
    }

    int num_ports = argc - 2;

    struct sockaddr_in sa;
    memset(&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr(target);
    sa.sin_port = htons(0);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if (bind(sock, (struct sockaddr *)&sa, sizeof(sa)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num_ports; i++) {
        sa.sin_port = htons(ports[i]);

        if (connect(sock, (struct sockaddr *)&sa, sizeof(sa)) == 0) {
            printf("Port %d is open\n", ports[i]);
        } else {
            printf("Port %d is closed\n", ports[i]);
        }
    }

    close(sock);

    return EXIT_SUCCESS;
}