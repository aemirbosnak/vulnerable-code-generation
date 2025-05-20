//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void port_scanner(char* ip, int start_port, int end_port);

int main(int argc, char** argv) {
    if (argc!= 4) {
        printf("Usage: %s <ip> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    char* ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    port_scanner(ip, start_port, end_port);

    return 0;
}

void port_scanner(char* ip, int start_port, int end_port) {
    int sock;
    struct sockaddr_in server;
    int port;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error: Could not create socket\n");
        exit(1);
    }

    printf("Scanning ports from %d to %d on %s...\n", start_port, end_port, ip);

    for (port = start_port; port <= end_port; port++) {
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = inet_addr(ip);
        server.sin_port = htons(port);

        if (connect(sock, (struct sockaddr*)&server, sizeof(server)) == 0) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }
    }

    close(sock);
}