//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535

int main(int argc, char **argv) {
    int sock, ret;
    struct sockaddr_in server;
    int port;
    char ip[16];
    char *target_ip;

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return 1;
    }

    target_ip = argv[1];
    port = atoi(argv[2]);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    if (inet_pton(AF_INET, target_ip, &server.sin_addr) <= 0) {
        printf("Invalid IP Address\n");
        close(sock);
        return 1;
    }

    for (port = 1; port <= MAX_PORTS; port++) {
        ret = connect(sock, (struct sockaddr *)&server, sizeof(server));

        if (ret == -1) {
            if (errno == ECONNREFUSED) {
                printf("Port %d is closed\n", port);
            } else if (errno == ETIMEDOUT) {
                printf("Port %d is filtered\n", port);
            } else {
                printf("Error connecting to port %d: %s\n", port, strerror(errno));
            }
        } else {
            close(sock);
            printf("Port %d is open\n", port);
            break;
        }
    }

    close(sock);

    return 0;
}