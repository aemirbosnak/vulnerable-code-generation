//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_PORT 65535

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    if (port < 1 || port > MAX_PORT) {
        printf("Invalid port number\n");
        exit(1);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);

    if (inet_pton(AF_INET, host, &addr.sin_addr) <= 0) {
        printf("Invalid host address\n");
        close(sock);
        exit(1);
    }

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        } else {
            printf("Error connecting to host\n");
        }
        close(sock);
        exit(1);
    }

    close(sock);
    printf("Port %d is open\n", port);
    exit(0);
}