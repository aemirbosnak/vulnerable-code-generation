//FormAI DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define MAX_PORTS 65535

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Error: Invalid arguments. Please enter a single IP address to scan.\n");
        exit(0);
    }
    
    int sock;
    struct sockaddr_in target;
    int port;
    char *ip_address = argv[1];
    int open_ports = 0;

    printf("=== Starting port scan for %s ===\n", ip_address);

    // Create TCP socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) {
        printf("Error: Could not create socket. Errno: %d\n", errno);
        exit(0);
    }

    // Set socket timeout
    struct timeval timeout;
    timeout.tv_sec = 2;
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    // Loop through all possible ports
    for (port = 1; port <= MAX_PORTS; port++) {
        // Prepare sockaddr_in structure
        target.sin_family = AF_INET;
        target.sin_port = htons(port);
        target.sin_addr.s_addr = inet_addr(ip_address);

        // Connect to the target port
        if (connect(sock, (struct sockaddr *)&target, sizeof(target)) < 0) {
            // Port is closed
            continue;
        } else {
            // Port is open
            printf("[+] Port %d is open\n", port);
            open_ports++;
        }
        close(sock);
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) {
            printf("Error: Could not create socket. Errno: %d\n", errno);
            exit(0);
        }
    }

    if (open_ports > 0) {
        printf("\nScan complete. %d open ports found on %s!\n", open_ports, ip_address);
    } else {
        printf("\nScan complete. No open ports found on %s\n", ip_address);
    }

    return 0;
}