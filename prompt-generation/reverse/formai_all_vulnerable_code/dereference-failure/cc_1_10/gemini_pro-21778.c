//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_PORTS 100

// Function to print the usage of the program
void usage(char *program_name) {
    printf("Usage: %s <hostname> <port1> <port2> ...\n", program_name);
    printf("Example: %s google.com 80 443 8080\n", program_name);
}

// Function to scan a single port
int scan_port(char *hostname, int port) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    // Resolve the hostname
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        close(sockfd);
        return -1;
    }

    // Set the socket address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *((struct in_addr *)host->h_addr);

    // Connect to the port
    int result = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (result == -1) {
        close(sockfd);
        return 0;
    }

    // Close the socket
    close(sockfd);

    // Return 1 if the port is open, 0 otherwise
    return 1;
}

// Function to scan a range of ports
int scan_ports(char *hostname, int *ports, int num_ports) {
    int i;
    int num_open_ports = 0;

    for (i = 0; i < num_ports; i++) {
        if (scan_port(hostname, ports[i])) {
            printf("Port %d is open\n", ports[i]);
            num_open_ports++;
        }
    }

    return num_open_ports;
}

// Main function
int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc < 3) {
        usage(argv[0]);
        return 1;
    }

    // Get the hostname and port numbers
    char *hostname = argv[1];
    int ports[MAX_PORTS];
    int num_ports = argc - 2;
    for (int i = 0; i < num_ports; i++) {
        ports[i] = atoi(argv[i + 2]);
    }

    // Scan the ports
    int num_open_ports = scan_ports(hostname, ports, num_ports);

    // Print the results
    printf("Scanned %d ports on %s, %d ports are open\n", num_ports, hostname, num_open_ports);

    return 0;
}