//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAXLINE 1024

// Function to print error message and exit program
void error(char *message) {
    perror(message);
    exit(1);
}

// Function to scan a single port
int scan_port(int sock, char *ip, int port) {
    struct sockaddr_in server_addr;
    int opt = 1;
    int result = 0;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
            result = 1;
        } else {
            printf("Error connecting to %s:%d - %s\n", ip, port, strerror(errno));
        }
    } else {
        printf("Port %d is open\n", port);
        result = 1;
        close(sock);
    }

    return result;
}

// Function to scan multiple ports
int scan_ports(char *ip, int start_port, int end_port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error("socket");
    }

    int result = 0;

    for (int i = start_port; i <= end_port; i++) {
        if (scan_port(sock, ip, i) == 1) {
            result = 1;
        }
    }

    close(sock);
    return result;
}

int main(int argc, char **argv) {
    if (argc!= 4) {
        printf("Usage: %s <IP address> <start port> <end port>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (scan_ports(ip, start_port, end_port) == 1) {
        printf("At least one port is open\n");
    } else {
        printf("All ports are closed\n");
    }

    return 0;
}