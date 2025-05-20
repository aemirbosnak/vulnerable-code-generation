//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 65535
#define BUF_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(1);
}

void scan_ports(const char *hostname, int start_port, int end_port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        die("socket");
    }

    struct hostent *he = gethostbyname(hostname);
    if (he == NULL) {
        die("gethostbyname");
    }

    struct in_addr *addr = (struct in_addr *)he->h_addr;

    for (int port = start_port; port <= end_port; ++port) {
        int result = connect(sock, (struct sockaddr *)addr, sizeof(*addr));
        if (result == -1) {
            if (errno == ECONNREFUSED) {
                printf("%d - Closed\n", port);
            } else if (errno == ETIMEDOUT) {
                printf("%d - Filtered\n", port);
            } else {
                printf("%d - Error: %s\n", port, strerror(errno));
            }
        } else {
            close(sock);
            printf("%d - Open\n", port);
        }
    }

    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s hostname start_port end_port\n", argv[0]);
        return 1;
    }

    const char *hostname = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port > end_port || start_port < 1 || end_port > MAX_PORTS) {
        fprintf(stderr, "Invalid port range\n");
        return 1;
    }

    scan_ports(hostname, start_port, end_port);

    return 0;
}