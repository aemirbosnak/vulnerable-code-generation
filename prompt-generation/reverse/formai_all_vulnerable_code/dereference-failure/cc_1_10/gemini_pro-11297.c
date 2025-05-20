//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// This function scans a single port on a given host.
// It returns 1 if the port is open, 0 otherwise.
int scan_port(char *host, int port) {
    struct sockaddr_in addr;
    int sockfd;

    // Create a socket.
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 0;
    }

    // Set the socket address.
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(host);

    // Connect to the host.
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        close(sockfd);
        return 0;
    }

    // Close the socket.
    close(sockfd);

    // The port is open.
    return 1;
}

// This function scans a range of ports on a given host.
// It prints a list of the open ports.
void scan_ports(char *host, int start_port, int end_port) {
    int i;

    for (i = start_port; i <= end_port; i++) {
        if (scan_port(host, i)) {
            printf("Port %d is open.\n", i);
        }
    }
}

// This is the main function.
int main(int argc, char *argv[]) {
    // Check the command line arguments.
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <start_port> <end_port>\n", argv[0]);
        exit(1);
    }

    // Scan the ports.
    scan_ports(argv[1], atoi(argv[2]), atoi(argv[3]));

    return 0;
}