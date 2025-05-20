//FormAI DATASET v1.0 Category: Port Scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>

#define BUF_SIZE 1024

// Define a struct to hold the scan results
typedef struct Port {
    int portNumber;
    int isOpen;
} Port;

// Define a function to set the file descriptor as non-blocking
void setNonBlock(int fd) {
    int flags = fcntl(fd, F_GETFL, 0);
    fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}

// Define a function to handle SIGINT and terminate the scanner
void sigint_handler(int sig) {
    printf("\nTerminating port scanner...\n");
    exit(0);
}

// Define an asynchronous function to scan a single port on a given host
void scanPort(char* host, int port, Port* result) {
    // Create the socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket: ");
        exit(1);
    }

    // Set the socket as non-blocking
    setNonBlock(sockfd);

    // Set up the address struct
    struct sockaddr_in addr;
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &(addr.sin_addr));

    // Attempt to connect to the port
    int res = connect(sockfd, (struct sockaddr*) &addr, sizeof(addr));
    if (res < 0 && errno == EINPROGRESS) {
        // Connection is in progress, wait for it to complete
        fd_set writefds;
        FD_ZERO(&writefds);
        FD_SET(sockfd, &writefds);
        res = select(sockfd + 1, NULL, &writefds, NULL, NULL);
        if (res == -1) {
            perror("Error during select: ");
            exit(1);
        } else if (res > 0) {
            int so_error = 0;
            socklen_t len = sizeof(so_error);
            getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &so_error, &len);
            if (so_error == 0) {
                // Connection was successful
                result->portNumber = port;
                result->isOpen = 1;
                close(sockfd);
                return;
            }
        }
    } else if (res == 0) {
        // Connection was successful
        result->portNumber = port;
        result->isOpen = 1;
        close(sockfd);
        return;
    }

    // Connection was unsuccessful or timed out
    result->portNumber = port;
    result->isOpen = 0;
    close(sockfd);
}

int main(int argc, char** argv) {
    // Check command line arguments
    if (argc != 3) {
        printf("Usage: %s <hostname> <num_ports>\n", argv[0]);
        exit(1);
    }

    // Register the SIGINT handler
    signal(SIGINT, sigint_handler);

    // Parse the command line arguments
    char* hostname = argv[1];
    int num_ports = atoi(argv[2]);

    // Allocate memory for the scan results
    Port* results = malloc(num_ports * sizeof(Port));
    if (results == NULL) {
        perror("Failed to allocate memory: ");
        exit(1);
    }

    // Call the scanPort function asynchronously for each port
    int i;
    for (i = 0; i < num_ports; i++) {
        scanPort(hostname, i, &results[i]);
    }

    // Wait for all scans to complete
    int num_scans_remaining = num_ports;
    while (num_scans_remaining > 0) {
        for (i = 0; i < num_ports; i++) {
            if (results[i].portNumber != -1) {
                if (results[i].isOpen) {
                    printf("Port %d is open\n", results[i].portNumber);
                } else {
                    printf("Port %d is closed\n", results[i].portNumber);
                }
                results[i].portNumber = -1;
                num_scans_remaining--;
            }
        }
    }

    // Free the memory used by the port scan results
    free(results);

    return 0;
}