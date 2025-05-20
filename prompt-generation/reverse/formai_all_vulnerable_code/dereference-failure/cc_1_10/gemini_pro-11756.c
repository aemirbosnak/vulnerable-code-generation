//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFERSIZE 1024
#define PORTLIMIT 65535

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Resolve the hostname to an IP address
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Could not resolve hostname: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Create a socket for making connections
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set up the socket address structure
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = ((struct in_addr *) host->h_addr)->s_addr;

    // Start scanning from port 0 to PORTLIMIT
    for (unsigned short port = 0; port <= PORTLIMIT; port++) {
        sin.sin_port = htons(port);

        // Try to connect to the port
        if (connect(sockfd, (struct sockaddr *) &sin, sizeof(sin)) == -1) {
            // If the connection failed, the port is closed
            printf("Port %u: Closed\n", port);
        } else {
            // If the connection succeeded, the port is open
            printf("Port %u: Open\n", port);

            // Close the connection
            close(sockfd);

            // Create a new socket for the next iteration
            sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if (sockfd == -1) {
                perror("socket");
                return EXIT_FAILURE;
            }
        }
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}