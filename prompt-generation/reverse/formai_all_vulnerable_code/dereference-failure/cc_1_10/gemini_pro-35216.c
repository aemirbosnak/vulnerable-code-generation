//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>

// A graceful shutdown function to clean up resources
void graceful_shutdown(int sockfd) {
    close(sockfd);
    exit(EXIT_SUCCESS);
}

// A port scanner that scans a range of ports on a given host
int main(int argc, char** argv) {
    // Check if the user provided enough arguments
    if (argc < 3) {
        printf("Usage: %s <IP_ADDRESS> <STARTING_PORT> <ENDING_PORT>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Parse the command-line arguments
    char* ip_address = argv[1];
    int starting_port = atoi(argv[2]);
    int ending_port = atoi(argv[3]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the socket address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_address);

    // Scan the ports
    for (int port = starting_port; port <= ending_port; port++) {
        // Set the port number
        server_addr.sin_port = htons(port);

        // Connect to the port
        int connect_status = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

        // Check if the connection was successful
        if (connect_status == 0) {
            printf("Port %d is open\n", port);
        } else {
            // If the connection failed, check the error code
            if (errno == ECONNREFUSED) {
                printf("Port %d is closed\n", port);
            } else {
                perror("connect");
                graceful_shutdown(sockfd);
            }
        }
    }

    // Clean up resources
    graceful_shutdown(sockfd);
}