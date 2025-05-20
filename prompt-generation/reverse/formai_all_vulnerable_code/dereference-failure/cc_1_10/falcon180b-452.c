//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#define MAX_PORTS 65535
#define TIMEOUT 5000 // milliseconds
#define BUFFER_SIZE 1024

int is_valid_port(int port) {
    return port >= 1 && port <= 65535;
}

int is_port_open(int sock, int port) {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        close(sock);
        return 1; // port is open
    } else if (errno == ECONNREFUSED) {
        close(sock);
        return 0; // port is closed
    } else {
        close(sock);
        return -1; // error
    }
}

void handle_signal(int signum) {
    if (signum == SIGALRM) {
        printf("Timeout reached.\n");
        exit(1);
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <ip address> <port range>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + MAX_PORTS - 1;

    if (!is_valid_port(start_port) ||!is_valid_port(end_port)) {
        printf("Invalid port range.\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket.\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(start_port);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to %s.\n", ip_address);
        close(sock);
        return 1;
    }

    signal(SIGALRM, handle_signal);
    alarm(TIMEOUT);

    for (int port = start_port; port <= end_port; port++) {
        if (is_port_open(sock, port)) {
            printf("Port %d is open.\n", port);
        }
    }

    close(sock);
    return 0;
}