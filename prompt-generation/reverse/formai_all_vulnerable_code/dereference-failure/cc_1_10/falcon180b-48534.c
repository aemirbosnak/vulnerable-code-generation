//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void scan_port(int sock, struct sockaddr_in *addr, int port);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <ip address> <port range>\n", argv[0]);
        exit(1);
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3])? atoi(argv[3]) : 65535;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &addr.sin_addr);

    printf("Scanning ports %d to %d on %s...\n", start_port, end_port, ip);

    for (int port = start_port; port <= end_port; port++) {
        scan_port(sock, &addr, port);
    }

    close(sock);
    return 0;
}

void scan_port(int sock, struct sockaddr_in *addr, int port) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("0.0.0.0");

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
        printf("Port %d is open\n", port);
    } else {
        printf("Port %d is closed\n", port);
    }
}