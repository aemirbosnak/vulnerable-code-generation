//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535

void print_usage(char *prog_name) {
    printf("Usage: %s <hostname/IP> <start_port> <end_port>\n", prog_name);
    exit(1);
}

int main(int argc, char *argv[]) {
    char *hostname;
    int start_port, end_port;

    if (argc!= 4) {
        print_usage(argv[0]);
    }

    hostname = argv[1];
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    if (start_port > end_port) {
        printf("Error: start_port (%d) cannot be greater than end_port (%d)\n", start_port, end_port);
        exit(1);
    }

    printf("Scanning host %s for ports %d to %d...\n", hostname, start_port, end_port);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(start_port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    int opt = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    for (int i = start_port; i <= end_port; i++) {
        server_addr.sin_port = htons(i);

        int res = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (res == -1) {
            if (errno == ECONNREFUSED) {
                printf("Port %d is closed\n", i);
            } else if (errno == ECONNRESET) {
                printf("Port %d is open\n", i);
            } else {
                printf("Error connecting to port %d: %s\n", i, strerror(errno));
            }
        } else {
            close(sock);
            printf("Port %d is open\n", i);
        }
    }

    close(sock);
    return 0;
}