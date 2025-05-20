//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <errno.h>

// Function to print usage instructions
void usage(char *prog) {
    fprintf(stderr, "Usage: %s <host> <port>\n", prog);
    exit(1);
}

// Function to handle errors
void error(const char *msg) {
    perror(msg);
    exit(1);
}

// Function to scan a single port
int scan_port(const char *host, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error("socket");
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(host);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        if (errno == ECONNREFUSED) {
            // Port is closed
            return 0;
        } else {
            error("connect");
        }
    } else {
        // Port is open
        close(sock);
        return 1;
    }
}

// Function to scan a range of ports
void scan_range(const char *host, int start_port, int end_port) {
    for (int port = start_port; port <= end_port; port++) {
        if (scan_port(host, port)) {
            printf("Port %d is open\n", port);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        usage(argv[0]);
    }

    const char *host = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port > end_port) {
        fprintf(stderr, "Invalid port range\n");
        exit(1);
    }

    time_t start_time = time(NULL);

    scan_range(host, start_port, end_port);

    time_t end_time = time(NULL);
    double elapsed_time = difftime(end_time, start_time);

    printf("Scan completed in %.2f seconds\n", elapsed_time);

    return 0;
}