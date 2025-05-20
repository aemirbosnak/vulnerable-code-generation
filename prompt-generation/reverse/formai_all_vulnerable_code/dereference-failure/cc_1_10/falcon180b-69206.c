//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_HOSTNAME_LEN 256
#define MAX_DATA_SIZE 1024
#define TIMEOUT_MS 5000

typedef struct {
    char hostname[MAX_HOSTNAME_LEN];
    int port;
} host_info_t;

int ping_host(host_info_t* host) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Failed to create socket: %s\n", strerror(errno));
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(host->port);

    if (inet_pton(AF_INET, host->hostname, &addr.sin_addr) <= 0) {
        printf("Invalid hostname or IP address\n");
        close(sock);
        return -1;
    }

    if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        if (errno == ECONNREFUSED) {
            printf("Host is not reachable\n");
        } else if (errno == ETIMEDOUT) {
            printf("Connection timed out\n");
        } else {
            printf("Failed to connect: %s\n", strerror(errno));
        }
        close(sock);
        return -1;
    }

    close(sock);
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <hostname/IP> <port>\n", argv[0]);
        return 1;
    }

    host_info_t host;
    strncpy(host.hostname, argv[1], MAX_HOSTNAME_LEN);
    host.port = atoi(argv[2]);

    int result = ping_host(&host);
    if (result == 0) {
        printf("Host is reachable\n");
    } else {
        printf("Host is not reachable\n");
    }

    return 0;
}