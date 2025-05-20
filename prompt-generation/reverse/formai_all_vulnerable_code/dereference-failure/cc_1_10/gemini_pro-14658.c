//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

// Recursive function to scan ports
void scan_ports(char *host, int start, int end) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Get the host address
    struct hostent *host_entry = gethostbyname(host);
    if (host_entry == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    // Set the socket address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(start);
    memcpy(&addr.sin_addr, host_entry->h_addr, host_entry->h_length);

    // Connect to the port
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        // Port is closed
        if (start != end) {
            // Recursively scan the next port
            scan_ports(host, start + 1, end);
        }
        return;
    }

    // Port is open
    printf("Port %d is open on %s\n", start, host);

    // Close the socket
    close(sockfd);

    // Recursively scan the next port
    scan_ports(host, start + 1, end);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <host> <start port> <end port>\n", argv[0]);
        return 1;
    }

    // Get the host, start port, and end port
    char *host = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Scan the ports
    scan_ports(host, start_port, end_port);

    return 0;
}