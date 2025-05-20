//FormAI DATASET v1.0 Category: Port Scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_PORT 65535

// Scan single port
void scan_port(const char *ip, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        return;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);

    int result = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    if (result == 0) {
        printf("[+] Port %d is open\n", port);
    }
    else {
        printf("[-] Port %d is closed\n", port);
    }

    close(sock);
}

// Scan range of ports
void scan_range(const char *ip, int from_port, int to_port) {
    for (int port = from_port; port <= to_port; port++) {
        scan_port(ip, port);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        printf("       %s <ip> <from_port> <to_port>\n", argv[0]);
        return 1;
    }

    const char *ip = argv[1];

    if (atoi(argv[2]) > 0 && argc == 3) {
        int port = atoi(argv[2]);
        scan_port(ip, port);
    }
    else if (atoi(argv[2]) > 0 && atoi(argv[3]) > 0 && argc == 4) {
        int from_port = atoi(argv[2]);
        int to_port = atoi(argv[3]);
        scan_range(ip, from_port, to_port);
    }
    else {
        printf("Invalid arguments\n");
        return 1;
    }

    return 0;
}