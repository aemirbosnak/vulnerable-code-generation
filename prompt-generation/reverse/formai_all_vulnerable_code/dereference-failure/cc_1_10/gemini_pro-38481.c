//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: secure
#include <assert.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PORT 65535
#define MAX_HOSTNAME 256
#define MAX_BANNER 1024

// Function to check if a port is open on a given host.
int is_port_open(const char *hostname, uint16_t port) {
    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    // Resolve the hostname to an IP address.
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        close(sockfd);
        return -1;
    }

    // Set up the socket address for the connection.
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    memcpy(&addr.sin_addr, host->h_addr, host->h_length);

    // Connect to the socket.
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        close(sockfd);
        return -1;
    }

    // Check if the connection was successful.
    int err = 0;
    socklen_t len = sizeof(err);
    if (getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &err, &len) == -1) {
        perror("getsockopt");
        close(sockfd);
        return -1;
    }

    // Close the socket.
    close(sockfd);

    // Return the result.
    return err == 0;
}

// Function to scan a range of ports on a given host and print the open ports.
void scan_ports(const char *hostname, uint16_t start_port, uint16_t end_port) {
    // Check if the start and end ports are valid.
    assert(start_port <= end_port);

    // Scan the ports.
    for (uint16_t port = start_port; port <= end_port; port++) {
        if (is_port_open(hostname, port)) {
            printf("%d\n", port);
        }
    }
}

// Function to get the banner of a given port on a given host.
char *get_banner(const char *hostname, uint16_t port) {
    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return NULL;
    }

    // Resolve the hostname to an IP address.
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        close(sockfd);
        return NULL;
    }

    // Set up the socket address for the connection.
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    memcpy(&addr.sin_addr, host->h_addr, host->h_length);

    // Connect to the socket.
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        close(sockfd);
        return NULL;
    }

    // Get the banner.
    char banner[MAX_BANNER];
    memset(banner, 0, sizeof(banner));
    int len = recv(sockfd, banner, sizeof(banner) - 1, 0);
    if (len == -1) {
        perror("recv");
        close(sockfd);
        return NULL;
    }

    // Close the socket.
    close(sockfd);

    // Return the banner.
    return strdup(banner);
}

// Entry point.
int main(int argc, char **argv) {
    // Check the number of arguments.
    if (argc != 4) {
        printf("Usage: %s <hostname> <start_port> <end_port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the hostname.
    char *hostname = argv[1];

    // Get the start and end ports.
    uint16_t start_port = atoi(argv[2]);
    uint16_t end_port = atoi(argv[3]);

    // Scan the ports.
    scan_ports(hostname, start_port, end_port);

    // Get the banner for each open port.
    for (uint16_t port = start_port; port <= end_port; port++) {
        if (is_port_open(hostname, port)) {
            char *banner = get_banner(hostname, port);
            if (banner) {
                printf("Port %d: %s\n", port, banner);
                free(banner);
            } else {
                printf("Port %d: No banner\n", port);
            }
        }
    }

    // Exit.
    return EXIT_SUCCESS;
}