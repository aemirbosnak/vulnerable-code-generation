//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

#define TIMEOUT 1

// Function to check if a port is open
int is_port_open(const char *hostname, int port) {
    int sock;
    struct sockaddr_in server;

    // Create a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        return 0;
    }

    // Setup the timeout for the socket
    struct timeval tv;
    tv.tv_sec = TIMEOUT;  // Timeout of 1 second
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

    // Setup the server address structure
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    struct hostent *host = gethostbyname(hostname);
    
    if (host == NULL) {
        close(sock);
        return 0; // Host could not be resolved
    }

    memcpy(&server.sin_addr, host->h_addr_list[0], host->h_length);

    // Try to connect to the server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        close(sock);
        return 0; // Port is closed
    }

    close(sock);
    return 1; // Port is open
}

// Main function to execute the port scanner
int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <start_port> <end_port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    printf("Scanning ports from %d to %d on host: %s\n", start_port, end_port, hostname);

    clock_t start_time = clock();

    // Loop through the range of ports specified
    for (int port = start_port; port <= end_port; port++) {
        if (is_port_open(hostname, port)) {
            printf("Port %d is open.\n", port);
        } else {
            printf("Port %d is closed.\n", port);
        }
    }

    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Scanning completed in %.2f seconds.\n", time_taken);

    return EXIT_SUCCESS;
}