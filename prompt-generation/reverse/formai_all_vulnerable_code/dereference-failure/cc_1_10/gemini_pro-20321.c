//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define TIMEOUT_MS 1000

// Function to print the usage of the program
void print_usage(char *progname) {
    printf("Usage: %s <hostname> <port> <port> ...\n", progname);
    printf("Example: %s example.com 80 443 3306\n", progname);
}

// Function to scan a single port on a host
int scan_port(char *hostname, int port) {
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket() failed");
        return -1;
    }

    // Set a timeout for the connect() call
    struct timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = TIMEOUT_MS * 1000;
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        perror("setsockopt() failed");
        close(sock);
        return -1;
    }

    // Resolve the hostname to an IP address
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    struct addrinfo *result;
    if (getaddrinfo(hostname, NULL, &hints, &result) != 0) {
        perror("getaddrinfo() failed");
        close(sock);
        return -1;
    }

    // Connect to the port on the host
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    memcpy(&addr.sin_addr, &((struct sockaddr_in *)result->ai_addr)->sin_addr, sizeof(addr.sin_addr));
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        close(sock);
        freeaddrinfo(result);
        return 0;
    }

    freeaddrinfo(result); 
    close(sock);
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        print_usage(argv[0]);
        return 1;
    }

    // Get the hostname and ports from the command line arguments
    char *hostname = argv[1];
    int ports[argc - 2];
    for (int i = 2; i < argc; i++) {
        ports[i - 2] = atoi(argv[i]);
    }

    // Scan each port on the host
    for (int i = 0; i < argc - 2; i++) {
        int port = ports[i];
        printf("Scanning port %d on %s...\n", port, hostname);
        int result = scan_port(hostname, port);
        if (result == 1) {
            printf("Port %d is open\n", port);
        } else if (result == 0) {
            printf("Port %d is closed\n", port);
        } else {
            perror("scan_port() failed");
            return 1; 
        }
    }

    return 0;
}