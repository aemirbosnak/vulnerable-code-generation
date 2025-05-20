//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

// Global variables
int sockfd;
struct sockaddr_in servaddr;

// Function to handle Ctrl+C
void sigint_handler(int sig) {
    // Close the socket and exit
    close(sockfd);
    exit(0);
}

// Function to scan a range of ports
int scan_ports(char *host, int start_port, int end_port) {
    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        return -1;
    }

    // Set up the server address
    struct hostent *he;
    if ((he = gethostbyname(host)) == NULL) {
        perror("Error resolving hostname");
        return -1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(start_port);
    servaddr.sin_addr = *((struct in_addr *)he->h_addr);

    // Scan the ports
    int i, res;
    for (i = start_port; i <= end_port; i++) {
        // Set the server port
        servaddr.sin_port = htons(i);

        // Connect to the server
        res = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

        // Check if the port is open
        if (res == 0) {
            printf("Port %d is open on host %s\n", i, host);
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}

// Main function
int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <start_port> <end_port>\n", argv[0]);
        return -1;
    }

    // Handle Ctrl+C
    signal(SIGINT, sigint_handler);

    // Scan the ports
    char *host = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);
    scan_ports(host, start_port, end_port);

    return 0;
}