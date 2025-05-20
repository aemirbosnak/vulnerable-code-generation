//FormAI DATASET v1.0 Category: Port Scanner ; Style: Machiavellien
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void banner() {
    printf("##############################################\n");
    printf("##                                          ##\n");
    printf("##         MACHIAVELLIAN PORT SCANNER        ##\n");
    printf("##                                          ##\n");
    printf("##############################################\n\n");
}

void usage(char *prog_name) {
    printf("Usage: %s <target IP> <start port> <end port>\n", prog_name);
    printf("Example: %s 192.168.0.1 1 65535\n", prog_name);
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in target_addr;
    int start_port, end_port, current_port;
    char *ip_address;
    int timeout = 10; // timeout in seconds
    char banner_buffer[1024];

    if (argc < 4) {
        usage(argv[0]);
        exit(1);
    }

    banner();

    ip_address = argv[1];
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    printf("Scanning ports %d to %d on %s\n", start_port, end_port, ip_address);

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error: Could not create socket.\n");
        exit(1);
    }

    // Set target address structure
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(ip_address);

    // Scan for open ports
    for (current_port = start_port; current_port <= end_port; current_port++) {
        // Set target address port
        target_addr.sin_port = htons(current_port);

        // Connect to target
        if (connect(sock, (struct sockaddr*)&target_addr, sizeof(target_addr)) == 0) {
            printf("Port %d: Open\n", current_port);

            // Receive banner
            if (recv(sock, banner_buffer, sizeof(banner_buffer), 0) > 0) {
                printf("Banner: %s\n", banner_buffer);
            }

            // Close connection
            close(sock);
        }
        else {
            printf("Port %d: Closed\n", current_port);
        }

        // Reset socket
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            printf("Error: Could not create socket.\n");
            exit(1);
        }

        // Set timeout
        struct timeval tv;
        tv.tv_sec = timeout;
        tv.tv_usec = 0;
        if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv)) < 0) {
            printf("Error: Could not set timeout.\n");
            exit(1);
        }
    }

    // Close socket
    close(sock);

    printf("\nScan complete.\n");

    return 0;
}