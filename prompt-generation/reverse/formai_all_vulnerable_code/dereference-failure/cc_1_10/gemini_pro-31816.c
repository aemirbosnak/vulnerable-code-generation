//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: post-apocalyptic
// The Ruined City Port Scanner - A Relic of the Old World

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

// Macros for the dusty remnants of our once-great civilization
#define MAX_PORTS 1024
#define TIMEOUT_SECS 2

// The echoes of the past, now just ghostly whispers
struct port_scan_result {
    int port;
    char* service;
    int status;
};

// The foundation of our ancient knowledge
int main(int argc, char* argv[]) {
    // Parse the wreckage of our arguments
    if (argc < 3) {
        printf("Usage: %s <ip address> <start port> <end port>\n", argv[0]);
        return 1;
    }

    // Gather the remnants of our intelligence
    char* ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Prepare our socket, the gateway to the ethereal void
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Establish a connection to the ruins of our past
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_address);

    // Scan the desolate ports, one by one
    struct port_scan_result results[MAX_PORTS];
    for (int i = start_port; i <= end_port; i++) {
        addr.sin_port = htons(i);

        // Send a feeble probe into the darkness
        if (connect(sockfd, (struct sockaddr*) &addr, sizeof(addr)) < 0) {
            results[i].status = -1;
            continue;
        }

        // A glimmer of hope! We found something!
        results[i].status = 0;

        // Identify the service, a forgotten relic of the past
        struct servent* service = getservbyport(htons(i), NULL);
        if (service) {
            results[i].service = strdup(service->s_name);
        } else {
            results[i].service = strdup("unknown");
        }
    }

    // Close our portal to the unknown
    close(sockfd);

    // Report our findings, a beacon of knowledge in the wasteland
    printf("Port Scan Results:\n");
    for (int i = start_port; i <= end_port; i++) {
        if (results[i].status == 0) {
            printf("Port %d: %s\n", results[i].port, results[i].service);
        }
    }

    // Mark the end of our journey, a testament to our resilience
    return 0;
}