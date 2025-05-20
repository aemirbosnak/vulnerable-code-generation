//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX_PORTS 65535 // Max number of ports to scan

// Function to convert a string IP address to a binary IP address
unsigned int get_ip_address(char *str_ip) {
    struct sockaddr_in sa;
    inet_pton(AF_INET, str_ip, &(sa.sin_addr));
    return sa.sin_addr.s_addr;
}

// Function to scan a single port on a target IP address
bool scan_port(unsigned int ip_address, unsigned short port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return false;
    }

    struct sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    target.sin_addr.s_addr = ip_address;

    int conn_status = connect(sockfd, (struct sockaddr *)&target, sizeof(target));
    if (conn_status == 0) {
        return true;
    } else {
        if (errno == ECONNREFUSED) {
            return false;
        } else {
            perror("Error connecting to port");
            return false;
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <target IP address> <start port> <end port>\n", argv[0]);
        return -1;
    }

    unsigned int ip_address = get_ip_address(argv[1]);
    unsigned short start_port = atoi(argv[2]);
    unsigned short end_port = atoi(argv[3]);

    if (start_port > end_port) {
        printf("Invalid port range: start port must be less than end port.\n");
        return -1;
    }

    printf("Scanning ports on %s...\n", argv[1]);

    for (unsigned short port = start_port; port <= end_port; port++) {
        bool port_open = scan_port(ip_address, port);
        if (port_open) {
            printf("Port %d is open!\n", port);
        }
    }

    printf("Scan complete.\n");

    return 0;
}