//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void scan_ports(int sock, int start_port, int end_port) {
    int port;
    for (port = start_port; port <= end_port; port++) {
        int addrlen = sizeof(struct sockaddr_in);
        struct sockaddr_in target;
        memset(&target, 0, sizeof(target));
        target.sin_family = AF_INET;
        target.sin_port = htons(port);
        inet_pton(AF_INET, "127.0.0.1", &target.sin_addr);

        if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
            char buffer[BUFFER_SIZE];
            memset(buffer, 0, BUFFER_SIZE);
            send(sock, "GET / HTTP/1.0\r\n\r\n", strlen("GET / HTTP/1.0\r\n\r\n"), 0);
            int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
            if (bytes_received > 0) {
                buffer[bytes_received] = '\0';
                printf("Port %d is open. Received response:\n%s\n", port, buffer);
            } else {
                printf("Port %d is closed.\n", port);
            }
        } else {
            printf("Port %d is closed.\n", port);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);

    if (start_port > end_port) {
        printf("Invalid port range.\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket.\n");
        return 1;
    }

    scan_ports(sock, start_port, end_port);

    close(sock);
    return 0;
}