//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: modular
// Module: portscanner.c
// Purpose: This module contains a function to scan a given host for open ports.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define DEFAULT_TIMEOUT 5000 // 5 seconds

// Function to scan a given host for open ports
int scan_ports(const char* hostname, int start_port, int end_port, int timeout) {
    int sock = -1;
    struct addrinfo hints, *result = NULL, *rp = NULL;
    char port_str[6];
    int port_num;
    int num_open_ports = 0;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, NULL, &hints, &result)!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errno));
        return -1;
    }

    for (rp = result; rp!= NULL; rp = rp->ai_next) {
        sock = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);

        if (sock == -1) {
            fprintf(stderr, "socket: %s\n", strerror(errno));
            continue;
        }

        for (port_num = start_port; port_num <= end_port; port_num++) {
            sprintf(port_str, "%d", port_num);
            if (connect(sock, rp->ai_addr, rp->ai_addrlen) == 0) {
                close(sock);
                fprintf(stdout, "Port %s is open.\n", port_str);
                num_open_ports++;
            } else if (errno!= ECONNREFUSED) {
                close(sock);
                fprintf(stdout, "Port %s: %s\n", port_str, strerror(errno));
            }
        }

        close(sock);
    }

    freeaddrinfo(result);

    if (num_open_ports == 0) {
        fprintf(stdout, "No open ports found.\n");
    }

    return 0;
}

// Main function to call the port scanner
int main(int argc, char** argv) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s hostname start_port end_port [timeout]\n", argv[0]);
        return 1;
    }

    const char* hostname = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);
    int timeout = DEFAULT_TIMEOUT;

    if (argc > 4) {
        timeout = atoi(argv[4]);
    }

    scan_ports(hostname, start_port, end_port, timeout);

    return 0;
}