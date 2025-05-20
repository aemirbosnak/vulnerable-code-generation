//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>

#define TIMEOUT 1
#define MAX_PORTS 65535

int set_socket_non_blocking(int sockfd) {
    int flags = fcntl(sockfd, F_GETFL, 0);
    if (flags < 0) {
        perror("fcntl F_GETFL");
        return -1;
    }
    if (fcntl(sockfd, F_SETFL, flags | O_NONBLOCK) < 0) {
        perror("fcntl F_SETFL");
        return -1;
    }
    return 0;
}

int scan_port(const char *ip, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return -1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &server_addr.sin_addr) <= 0) {
        perror("Invalid address");
        close(sockfd);
        return -1;
    }

    if (set_socket_non_blocking(sockfd) < 0) {
        close(sockfd);
        return -1;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        if (errno != EINPROGRESS) {
            perror("Connect failed");
            close(sockfd);
            return -1;
        }
    }

    fd_set fdset;
    struct timeval tv;
    int max_fd = sockfd;

    FD_ZERO(&fdset);
    FD_SET(sockfd, &fdset);
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    int select_result = select(max_fd + 1, NULL, &fdset, NULL, &tv);
    if (select_result > 0) {
        int so_error;
        socklen_t len = sizeof(so_error);
        if (getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &so_error, &len) < 0) {
            perror("getsockopt failed");
            close(sockfd);
            return -1;
        }
        close(sockfd);
        return (so_error == 0) ? 1 : 0; // Port is open (1) or closed (0)
    } else if (select_result == 0) {
        close(sockfd);
        return 0; // Timeout, considering port as closed
    } else {
        perror("Select failed");
        close(sockfd);
        return -1;
    }
}

void scan_ports(const char *ip, int start_port, int end_port) {
    printf("Scanning IP: %s\n", ip);
    for (int port = start_port; port <= end_port; port++) {
        int result = scan_port(ip, port);
        if (result == 1) {
            printf("Port %d is open\n", port);
        } else if (result == 0) {
            // Port is closed, do nothing
        } else {
            printf("Error scanning port %d\n", port);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP> <start-port> <end-port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > MAX_PORTS || start_port > end_port) {
        fprintf(stderr, "Invalid port range. Ports must be between 1 and %d\n", MAX_PORTS);
        return EXIT_FAILURE;
    }

    scan_ports(ip, start_port, end_port);

    return EXIT_SUCCESS;
}