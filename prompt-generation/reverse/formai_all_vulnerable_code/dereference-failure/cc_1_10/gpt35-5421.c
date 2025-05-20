//FormAI DATASET v1.0 Category: Port Scanner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int scan_port(char *host, int port) {
    struct sockaddr_in sin;
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(host);
    sin.sin_port = htons(port);

    if (connect(sock, (struct sockaddr*)&sin, sizeof(sin)) == 0) {
        printf("Port %d open on %s!\n", port, host);
        close(sock);
        return 1;
    } else {
        close(sock);
        return 0;
    }
}

int main(int argc, char *argv[]) {
    char *host;
    int start_port = 1;
    int end_port = 1024;

    if (argc < 2) {
        printf("Usage: %s <host> [<start_port> <end_port>]\n", argv[0]);
        return 1;
    }

    host = argv[1];
    if (argc > 2) {
        start_port = atoi(argv[2]);
    }
    if (argc > 3) {
        end_port = atoi(argv[3]);
    }

    printf("Scanning ports %d-%d on %s...\n", start_port, end_port, host);

    for (int port = start_port; port <= end_port; port++) {
        scan_port(host, port);
    }

    printf("Scan complete!\n");

    return 0;
}