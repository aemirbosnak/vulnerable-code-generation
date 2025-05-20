//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: detailed
// C Network Topology Mapper Example

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <err.h>

// Define the maximum number of hosts to scan
#define MAX_HOSTS 100

// Define the port to scan
#define PORT 80

// Define the timeout for each scan
#define TIMEOUT 1000000

// Define the structure to store the scan results
typedef struct {
    char *hostname;
    int port;
    int status;
} scan_result;

// Function to scan a single host
int scan_host(char *hostname, int port, int timeout) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        err(1, "socket");
    }

    // Set the timeout
    struct timeval tv;
    tv.tv_sec = timeout / 1000000;
    tv.tv_usec = timeout % 1000000;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        err(1, "setsockopt");
    }

    // Resolve the hostname
    struct hostent *hostent = gethostbyname(hostname);
    if (hostent == NULL) {
        err(1, "gethostbyname");
    }

    // Connect to the host
    struct sockaddr_in sockaddr_in;
    sockaddr_in.sin_family = AF_INET;
    sockaddr_in.sin_port = htons(port);
    sockaddr_in.sin_addr = *(struct in_addr *)hostent->h_addr;
    if (connect(sockfd, (struct sockaddr *)&sockaddr_in, sizeof(sockaddr_in)) < 0) {
        return -1;
    }

    // Close the socket
    close(sockfd);

    // Return the status
    return 0;
}

// Function to scan a list of hosts
int scan_hosts(char *hostnames[], int num_hosts, int port, int timeout) {
    // Create an array to store the scan results
    scan_result scan_results[MAX_HOSTS];

    // Scan each host
    for (int i = 0; i < num_hosts; i++) {
        // Scan the host
        scan_results[i].hostname = hostnames[i];
        scan_results[i].port = port;
        scan_results[i].status = scan_host(hostnames[i], port, timeout);
    }

    // Print the scan results
    printf("Scan Results\n");
    printf("--------------------------\n");
    printf("Hostname\tPort\tStatus\n");
    printf("--------------------------\n");
    for (int i = 0; i < num_hosts; i++) {
        printf("%s\t%d\t%s\n", scan_results[i].hostname, scan_results[i].port, scan_results[i].status == 0 ? "Open" : "Closed");
    }

    // Return the number of open ports
    int num_open_ports = 0;
    for (int i = 0; i < num_hosts; i++) {
        if (scan_results[i].status == 0) {
            num_open_ports++;
        }
    }

    return num_open_ports;
}

// Main function
int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname> [<hostname> ...]\n", argv[0]);
        return 1;
    }

    // Get the list of hosts to scan
    char *hostnames[MAX_HOSTS];
    int num_hosts = 0;
    for (int i = 1; i < argc; i++) {
        hostnames[num_hosts++] = argv[i];
    }

    // Scan the hosts
    int num_open_ports = scan_hosts(hostnames, num_hosts, PORT, TIMEOUT);

    // Print the number of open ports
    printf("Number of open ports: %d\n", num_open_ports);

    return 0;
}