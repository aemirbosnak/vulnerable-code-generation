//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void port_scanner(int sock, int target_ip, int start_port, int end_port);

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage:./port_scanner <target_ip> <start_port> <end_port>\n");
        exit(1);
    }

    int target_ip = inet_addr(argv[1]);
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    port_scanner(sock, target_ip, start_port, end_port);

    close(sock);
    return 0;
}

void port_scanner(int sock, int target_ip, int start_port, int end_port) {
    struct sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = target_ip;
    target.sin_port = htons(start_port);

    for (int i = start_port; i <= end_port; i++) {
        if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
            printf("Port %d is open\n", i);
            close(sock);
            sock = socket(AF_INET, SOCK_STREAM, 0);
        } else {
            printf("Port %d is closed\n", i);
        }

        target.sin_port = htons(i);
    }
}