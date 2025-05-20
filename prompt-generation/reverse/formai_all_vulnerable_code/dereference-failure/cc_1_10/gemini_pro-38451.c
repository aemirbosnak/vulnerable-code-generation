//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

// Define the maximum number of hosts to scan
#define MAX_HOSTS 10

// Define the maximum length of a hostname
#define MAX_HOSTNAME_LENGTH 255

// Define the default port to scan
#define DEFAULT_PORT 80

// Define the timeout value for scanning hosts
#define TIMEOUT_VALUE 1000

// Create a socket for scanning hosts
int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    return sockfd;
}

// Resolve a hostname to an IP address
struct hostent *resolve_hostname(char *hostname) {
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("Error resolving hostname");
        exit(1);
    }

    return host;
}

// Scan a host for a specific port
int scan_host(char *hostname, int port) {
    // Create a socket for scanning the host
    int sockfd = create_socket();

    // Resolve the hostname to an IP address
    struct hostent *host = resolve_hostname(hostname);

    // Set the timeout value for the socket
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT_VALUE / 1000;
    timeout.tv_usec = (TIMEOUT_VALUE % 1000) * 1000;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

    // Connect to the host
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *(struct in_addr *)host->h_addr;
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        return -1;
    }

    // Close the socket
    close(sockfd);

    // Return 0 if the host is open on the specified port
    return 0;
}

// Print the results of the scan
void print_results(char *hostname, int port, int status) {
    if (status == 0) {
        printf("%s:%d is open\n", hostname, port);
    } else {
        printf("%s:%d is closed\n", hostname, port);
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has specified a hostname
    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    // Get the hostname from the command line
    char *hostname = argv[1];

    // Scan the host for the default port
    int port = DEFAULT_PORT;
    int status = scan_host(hostname, port);

    // Print the results of the scan
    print_results(hostname, port, status);

    return 0;
}