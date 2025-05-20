//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void scan_port(int sock, int port);

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <ip address> <port range>\n", argv[0]);
        exit(1);
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + MAX_PORTS - 1;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(start_port);
    inet_pton(AF_INET, ip, &server.sin_addr);

    for (int i = start_port; i <= end_port; i++) {
        scan_port(sock, i);
    }

    close(sock);
    return 0;
}

void scan_port(int sock, int port) {
    struct sockaddr_in target;
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    inet_pton(AF_INET, "0.0.0.0", &target.sin_addr);

    if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == -1) {
        printf("Port %d is closed\n", port);
    } else {
        printf("Port %d is open\n", port);
        close(sock);
    }
}