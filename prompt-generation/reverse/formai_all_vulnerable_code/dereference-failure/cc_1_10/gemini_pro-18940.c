//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_PORTS 1024

typedef struct port_scan_result {
    int port;
    int is_open;
} port_scan_result;

// Create a socket and connect to the specified host and port
int connect_to_host(char *host, int port) {
    int sockfd;
    struct sockaddr_in servaddr;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return -1;
    }

    // Resolve the hostname
    struct hostent *hostent = gethostbyname(host);
    if (hostent == NULL) {
        perror("gethostbyname");
        close(sockfd);
        return -1;
    }

    // Set up the servaddr struct
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    memcpy(&servaddr.sin_addr, hostent->h_addr, hostent->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        close(sockfd);
        return -1;
    }

    return sockfd;
}

// Scan a range of ports on the specified host
int scan_ports(char *host, int start_port, int end_port) {
    int num_open_ports = 0;

    // Create an array of port scan results
    port_scan_result results[MAX_PORTS];

    // Iterate over the range of ports
    for (int i = start_port; i <= end_port; i++) {
        int sockfd = connect_to_host(host, i);

        // If the connection was successful, the port is open
        if (sockfd >= 0) {
            results[i].port = i;
            results[i].is_open = 1;
            num_open_ports++;
            close(sockfd);
        }
    }

    // Print the results
    for (int i = start_port; i <= end_port; i++) {
        if (results[i].is_open) {
            printf("Port %d is open\n", results[i].port);
        }
    }

    return num_open_ports;
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <host> <start_port> <end_port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *host = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    int num_open_ports = scan_ports(host, start_port, end_port);

    printf("Found %d open ports\n", num_open_ports);

    return EXIT_SUCCESS;
}