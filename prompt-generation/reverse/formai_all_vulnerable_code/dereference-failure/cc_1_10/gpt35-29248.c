//FormAI DATASET v1.0 Category: Port Scanner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MIN_PORT 0
#define MAX_PORT 65535

// Function to scan ports
void scan_ports(char* ip_addr) {
    int sockfd;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt_val = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt_val, sizeof(opt_val)) < 0) {
        perror("setsockopt() failed");
        exit(EXIT_FAILURE);
    }

    // Define a sockaddr_in structure and assign values
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(0);
    server_addr.sin_addr.s_addr = inet_addr(ip_addr);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind() failed");
        exit(EXIT_FAILURE);
    }

    // Define a range of ports to scan
    int start_port = MIN_PORT;
    int end_port = MAX_PORT;

    // Scan ports
    int i;
    for (i = start_port; i <= end_port; i++) {
        struct sockaddr_in dest_addr;
        dest_addr.sin_family = AF_INET;
        dest_addr.sin_addr.s_addr = inet_addr(ip_addr);
        dest_addr.sin_port = htons(i);

        // Connect to the destination address and port
        int conn = connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr));

        if (conn == 0) {
            printf("Port %d is open\n", i);
        } else {
            printf("Port %d is closed (error: %s)\n", i, strerror(errno));
        }
    }

    // Close the socket
    close(sockfd);
}

int main(int argc, char** argv) {
    // Check for command line arguments
    if (argc != 2) {
        printf("Usage: %s <ip_address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Scan ports
    scan_ports(argv[1]);

    return 0;
}