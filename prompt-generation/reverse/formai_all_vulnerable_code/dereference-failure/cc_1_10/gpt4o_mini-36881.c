//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_PORT 65535
#define MIN_PORT 1
#define TIMEOUT 1  // seconds

void signal_handler(int signal) {
    if (signal == SIGINT) {
        printf("\nPort scanning interrupted by user.\n");
        exit(0);
    }
}

int create_socket() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sock;
}

int set_socket_options(int sock) {
    int optval = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        perror("Set socket options failed");
        close(sock);
        exit(EXIT_FAILURE);
    }
    return 0;
}

int scan_port(const char *ip, int port) {
    int sock = create_socket();
    set_socket_options(sock);
    
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    int connection_status = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    
    // Close socket
    close(sock);

    if (connection_status == 0) {
        return 1;  // Port is open
    }

    if (errno == EINPROGRESS) {
        return 0;  // Port is filtered or closed but we didn't establish a connection
    }

    return 0;  // Port is closed
}

void print_banner() {
    printf("===================================\n");
    printf("      Simple C Port Scanner        \n");
    printf("===================================\n");
}

void scan_ports(const char *ip) {
    printf("Scanning open ports on %s...\n", ip);
    for (int port = MIN_PORT; port <= MAX_PORT; port++) {
        int open = scan_port(ip, port);
        if (open) {
            printf("Port %d is open\n", port);
        }
        // Optional: add sleep to reduce the load on the network
        // usleep(100); // Uncomment to slow down the scanning
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    signal(SIGINT, signal_handler);
    
    const char *ip = argv[1];
    print_banner();
    scan_ports(ip);

    printf("Port scan complete.\n");
    return 0;
}