//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    int port;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    printf("Scanning ports from 1 to %d...\n", MAX_PORTS);

    for (port = 1; port <= MAX_PORTS; port++) {
        if (port!= atoi(argv[2])) {
            memset(buffer, 0, BUFFER_SIZE);

            if (send(sock, "HELO\r\n", strlen("HELO\r\n"), 0) == -1) {
                printf("Error: %s\n", strerror(errno));
                exit(1);
            }

            if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
                printf("Error: %s\n", strerror(errno));
                exit(1);
            }

            if (strstr(buffer, "220")!= NULL) {
                printf("Port %d is open\n", port);
            } else {
                printf("Port %d is closed\n", port);
            }
        }
    }

    close(sock);

    return 0;
}