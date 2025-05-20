//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int sock, port;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP Address> <Port Range>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    strcpy(server.sin_zero, "");
    server.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server.sin_addr);

    for (port = atoi(argv[2]); port <= MAX_PORTS; port++) {
        server.sin_port = htons(port);

        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
            if (errno == ECONNREFUSED) {
                printf("%d - Closed\n", port);
            } else if (errno == ETIMEDOUT) {
                printf("%d - Filtered\n", port);
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