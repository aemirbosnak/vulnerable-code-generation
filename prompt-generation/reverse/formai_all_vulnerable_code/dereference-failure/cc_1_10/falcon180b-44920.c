//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX 65535
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sock, port, ret, val;
    struct sockaddr_in server;
    char buffer[BUFSIZE];
    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (argc!= 4) {
        printf("Usage: %s <IP Address> <Start Port> <End Port>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Socket creation failed: %s\n", strerror(errno));
        exit(1);
    }

    printf("Scanning ports from %d to %d on %s...\n", start_port, end_port, ip);

    for (port = start_port; port <= end_port; port++) {
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = inet_addr(ip);
        server.sin_port = htons(port);

        ret = connect(sock, (struct sockaddr *)&server, sizeof(server));
        if (ret == -1) {
            if (errno == ECONNREFUSED) {
                printf("%d - Closed\n", port);
            } else if (errno == ECONNRESET) {
                printf("%d - Reset\n", port);
            } else {
                printf("%d - Unknown\n", port);
            }
        } else {
            close(sock);
            printf("%d - Open\n", port);
        }
    }

    close(sock);
    return 0;
}