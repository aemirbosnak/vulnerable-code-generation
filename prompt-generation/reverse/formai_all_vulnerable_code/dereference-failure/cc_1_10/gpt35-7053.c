//FormAI DATASET v1.0 Category: Port Scanner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAX_PORT 65535

int main(int argc, char *argv[]) {
    char *target_host;
    int target_port;
    int sock;
    int scan_port;
    int optval;

    if (argc < 2) {
        printf("Please provide a target host to scan.\n");
        return 1;
    }

    target_host = argv[1];

    printf("Scanning target: %s\n", target_host);

    for (scan_port = 1; scan_port <= MAX_PORT; scan_port++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            printf("Failed to create socket: %s\n", strerror(errno));
            return 1;
        }

        optval = 1;
        setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval , sizeof(int));

        struct hostent *target_ent;
        struct sockaddr_in target_addr;
        target_ent = gethostbyname(target_host);
        if (target_ent == NULL) {
            printf("Failed to resolve target host: %s\n", target_host);
            return 1;
        }

        memset(&target_addr, 0, sizeof(target_addr));
        target_addr.sin_family = AF_INET;
        target_addr.sin_addr.s_addr = *((unsigned long *)target_ent->h_addr_list[0]);
        target_addr.sin_port = htons(scan_port);

        int connect_result;
        connect_result = connect(sock, (struct sockaddr *)&target_addr, sizeof(target_addr));
        if (connect_result == 0) {
            printf("Port %d open\n", scan_port);
        }

        close(sock);
    }

    printf("Scan complete.\n");

    return 0;
}