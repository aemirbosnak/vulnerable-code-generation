//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

// Define the maximum number of ports to scan
#define MAX_PORTS 100

// Define the timeout in seconds for each port scan
#define TIMEOUT 1

// Define the port range to scan
#define START_PORT 1
#define END_PORT 65535

// Define the banner for the program
#define BANNER "\n================================================================================================================================================\n" \
                " _                               _       _                                 _     _       _         _          _    _                                \n" \
                "| |                             | |     (_)                               | |   (_)     | |       | |        (_)  | |                              \n" \
                "| |__   __ _ _ __   ___ _ __   | |_ _ __ _  _ __   _____      ___ __ _  ___| |__   _ ___  | | ___    _ _ __   _ ___  __ _ _ __   ___ _ __   \n" \
                "| '_ \\ / _` | '_ \\ / _ \\ '_ \\  | __| '__| | | '_ \\ / _ \\ \\ /\ / / '_ ` _ \\ / _ \\ '_ \\ | / __| | |/ _ \\  | | '_ \\ | / __|/ _` | '_ \\ / _ \\ '__|  \n" \
                "| |_) | (_| | | | |  __/ | | | | |_| |  | | | | | |  __/\\ V  V /| | | | |  __/ | | || \\__ \\ | | (_) | | | | | || \\__ \\ (_| | |_) |  __/ |   \n" \
                "|_.__/ \\__,_|_| |_|\\___|_| |_|  \\__|_|  |_|_|_| |_|\\___| \\_/\\_/ |_| |_| |\\___|_| |_| |_|___/ |_|\\___/  |_|_| |_| |_|___/\\__,_| .__/ \\___|_|    \n" \
                "                                                                                                                            |_|                       \n" \
                "================================================================================================================================================\n\n"

// Define the usage message for the program
#define USAGE "Usage: %s <hostname> <port range>\n" \
                "\n" \
                "Example:\n" \
                " %s example.com 80-443\n\n"

// Function to scan a single port
int scan_port(const char *hostname, int port) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    // Set the timeout for the socket
    struct timeval timeout = {TIMEOUT, 0};
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        perror("setsockopt");
        close(sockfd);
        return -1;
    }

    // Resolve the hostname
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "gethostbyname: %s\n", hostname);
        close(sockfd);
        return -1;
    }

    // Create the socket address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    memcpy(&addr.sin_addr, host->h_addr, host->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
        close(sockfd);
        return 0;
    }

    // Close the socket
    close(sockfd);

    return 1;
}

// Function to scan a range of ports
void scan_ports(const char *hostname, const char *port_range) {
    // Parse the port range
    int start_port, end_port;
    if (sscanf(port_range, "%d-%d", &start_port, &end_port) != 2) {
        fprintf(stderr, "Invalid port range: %s\n", port_range);
        return;
    }

    // Check if the port range is valid
    if (start_port < START_PORT || start_port > END_PORT || end_port < START_PORT || end_port > END_PORT) {
        fprintf(stderr, "Invalid port range: %d-%d\n", start_port, end_port);
        return;
    }

    // Print the banner
    printf("%s", BANNER);

    // Scan the ports
    for (int port = start_port; port <= end_port; port++) {
        int result = scan_port(hostname, port);

        // Print the port and the result
        if (result == 1) {
            printf("Port %d: open\n", port);
        } else if (result == 0) {
            printf("Port %d: closed\n", port);
        } else {
            perror("scan_port");
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 3) {
        fprintf(stderr, USAGE, argv[0]);
        return EXIT_FAILURE;
    }

    // Get the hostname and port range
    const char *hostname = argv[1];
    const char *port_range = argv[2];

    // Scan the ports
    scan_ports(hostname, port_range);

    return EXIT_SUCCESS;
}