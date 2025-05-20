//MISTRAL-7B DATASET v1.0 Category: Port Scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>

// Name of our lovely program
#define PROGRAM_NAME "relaxed_scanner"

// Function to start the scanning process
void scan_ports(int start_port, int end_port) {
    int sockfd, port, service;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Relaxed introduction to our scanning process
    printf("\n%s v1.0 - A relaxed port scanner\n", PROGRAM_NAME);
    printf("Scanning from port %d to %d...\n", start_port, end_port);

    for (port = start_port; port <= end_port; port++) {
        // Create a socket
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("Error creating socket");
            exit(EXIT_FAILURE);
        }

        // Set up the server address structure
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(port);

        // Translate a dotted domain name to an IP address
        server = gethostbyname("localhost");
        if (server == NULL) {
            fprintf(stderr, "%s: unknown host\n", "localhost");
            exit(EXIT_FAILURE);
        }

        // Copy the server's IP address into our address structure
        bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

        // Connect to the server
        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            perror("Error connecting to server");
            close(sockfd);
            continue;
        }

        // Check if the port is open
        if (recv(sockfd, &service, sizeof(service), 0) > 0) {
            // Display the open port number and service name
            printf("\nPort %d is open with service %s\n", port, getservbyport(htons(service), "tcp")->s_name);
        }

        // Close the socket
        close(sockfd);
    }
}

// Main function
int main(int argc, char *argv[]) {
    int start_port, end_port;

    // Check if the correct number of arguments is provided
    if (argc != 3) {
        printf("%s usage: %s <start_port> <end_port>\n", PROGRAM_NAME, PROGRAM_NAME);
        exit(EXIT_FAILURE);
    }

    // Parse the start and end port arguments
    start_port = atoi(argv[1]);
    end_port = atoi(argv[2]);

    // Start the scanning process
    scan_ports(start_port, end_port);

    return EXIT_SUCCESS;
}