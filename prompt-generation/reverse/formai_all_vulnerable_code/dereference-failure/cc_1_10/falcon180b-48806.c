//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX 65535

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void scan_port(int sock, int port) {
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        printf("Port %d is open\n", port);
    } else if (errno == ECONNREFUSED) {
        printf("Port %d is closed\n", port);
    } else {
        printf("Error connecting to port %d\n", port);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage:./portscanner <IP address> <port range>\n");
        return 1;
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + MAX - 1;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error("socket");
    }

    printf("Scanning ports %d - %d on %s...\n", start_port, end_port, ip);

    for (int i = start_port; i <= end_port; i++) {
        scan_port(sock, i);
    }

    close(sock);
    return 0;
}