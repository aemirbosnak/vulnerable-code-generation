//FormAI DATASET v1.0 Category: Port Scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 65535 // Maximum number of ports to scan
#define TIMEOUT 2 // Timeout in seconds for socket connection

// Function to scan ports on a given host
void scan_ports(const char *host, int start_port, int end_port) {
    int sockfd, i, err, optval;
    struct sockaddr_in addr;
    struct hostent *he;

    printf("Scanning ports %d to %d on %s\n", start_port, end_port, host);

    // Get the IP address of the host
    if ((he = gethostbyname(host)) == NULL) {
        printf("Failed to resolve hostname\n");
        return;
    }

    // Loop through all ports and try to connect
    for (i = start_port; i <= end_port; i++) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            printf("Error creating socket\n");
            return;
        }

        // Set socket options
        optval = 1;
        setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
        setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &optval, sizeof(optval));

        // Set timeout for socket connection
        struct timeval tv;
        tv.tv_sec = TIMEOUT;
        tv.tv_usec = 0;
        setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv));
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));

        // Set up address
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(i);
        addr.sin_addr = *((struct in_addr *) he->h_addr);

        // Connect to the port
        err = connect(sockfd, (struct sockaddr *) &addr, sizeof(addr));
        if (err == 0) {
            printf("Port %d is open\n", i);
        } else {
            printf("Port %d is closed\n", i);
        }

        // Close the socket
        close(sockfd);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 4) {
        printf("Usage: %s <hostname> [<startPort> <endPort>]\n", argv[0]);
        return 0;
    }

    int start_port = 1;
    int end_port = MAX_PORTS;

    if (argc == 4) {
        start_port = atoi(argv[2]);
        end_port = atoi(argv[3]);
    }

    scan_ports(argv[1], start_port, end_port);

    return 0;
}