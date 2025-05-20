//FormAI DATASET v1.0 Category: Port Scanner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {

    // Check if enough arguments have been passed
    if (argc != 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        exit(1);
    }

    // Extract IP address and port range from command line arguments
    char *ipAddress = argv[1];
    char *portRange = argv[2];
    char *portRangeCopy = strdup(portRange);  // Make a copy of port range to keep original data intact

    // Parse port range and extract minPort and maxPort
    char *minPortStr = strtok(portRangeCopy, "-");
    char *maxPortStr = strtok(NULL, "-");
    int minPort = atoi(minPortStr);
    int maxPort = atoi(maxPortStr);

    // Create a socket for the connection
    int socketFD = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFD < 0) {
        printf("Error creating socket.\n");
        exit(1);
    }

    // Initialize socket address structure
    struct sockaddr_in servAddr;
    bzero((char *) &servAddr, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = inet_addr(ipAddress);

    // Loop through all the ports in the range and try to connect to them
    for (int port = minPort; port <= maxPort; port++) {
        // Update port number in socket address structure
        servAddr.sin_port = htons(port);

        // Try to open a connection with the remote server
        if (connect(socketFD, (struct sockaddr *) &servAddr, sizeof(servAddr)) >= 0) {
            printf("Port %d is open\n", port);
            close(socketFD);  // Close connection if open
            socketFD = socket(AF_INET, SOCK_STREAM, 0);  // Create a new socket for the next port
        }
    }

    // Close the socket that was opened
    close(socketFD);

    return 0;
}