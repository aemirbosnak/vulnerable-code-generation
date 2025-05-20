//FormAI DATASET v1.0 Category: Port Scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <netinet/ip_icmp.h>

#define MAX_PORT 65535
typedef unsigned char   BYTE;
typedef unsigned short   WORD;
typedef unsigned long   DWORD;

DWORD timer = 0;

int test_port(char *host, int port) {
    struct addrinfo hints, *res;
    int sockfd, status;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    char port_str[6];
    snprintf(port_str, 6, "%d", port);

    if ((status = getaddrinfo(host, port_str, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return 0;
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    if (sockfd == -1) {
        fprintf(stderr, "Could not open socket for %s:%d\n", host, port);
        return 0;
    }

    fcntl(sockfd, F_SETFL, O_NONBLOCK);

    connect(sockfd, res->ai_addr, res->ai_addrlen);

    fd_set write_fds;
    FD_ZERO(&write_fds);
    FD_SET(sockfd, &write_fds);

    int sel = select(sockfd+1, NULL, &write_fds, NULL, NULL);

    if (sel > 0) {
        int err;
        socklen_t len = sizeof err;
        getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &err, &len);
        if (err == 0) {
            close(sockfd);
            return 1;
        } else {
            close(sockfd);
            return 0;
        }
    } else {
        close(sockfd);
        return 0;
    }
}

void print_usage(char *prog) {
    printf("Usage: %s <host>\n", prog);
}

void scan_ports(char *host) {
    int i, open = 0;
    for (i = 1; i <= MAX_PORT; i++) {
        if (test_port(host, i)) {
            printf("Port %d is open!\n", i);
            open++;
        }
        if (timer % 1000 == 0) {
            printf("Scanning... %d ports scanned\n", i);
        }
        usleep(1000);
    }
    if (open == 0) {
        printf("No open ports found on %s\n", host);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return 0;
    }

    char *host = argv[1];
    printf("Scanning ports on %s...\n", host);

    scan_ports(host);

    printf("Scan complete!\n");

    return 0;
}