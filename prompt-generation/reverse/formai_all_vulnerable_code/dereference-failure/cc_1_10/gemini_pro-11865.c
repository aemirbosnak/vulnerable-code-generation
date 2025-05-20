//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <fcntl.h>

#define MAX_PORTS 65535
#define MAX_HOST_LEN 256

void print_usage(char *progname) {
    printf("Usage: %s <hostname> <port1> <port2> ... <portN>\n", progname);
    printf("Scans the specified ports on the given hostname.\n");
    printf("Example: %s scanme.com 80 443 22\n", progname);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    // Get the hostname from the first argument.
    char *hostname = argv[1];

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Get the IP address of the hostname.
    struct hostent *hostent = gethostbyname(hostname);
    if (hostent == NULL) {
        perror("gethostbyname");
        close(sockfd);
        return EXIT_FAILURE;
    }

    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_addr = *(struct in_addr *)hostent->h_addr;

    // Set the non-blocking flag on the socket.
    int flags = fcntl(sockfd, F_GETFL, 0);
    if (flags < 0) {
        perror("fcntl");
        close(sockfd);
        return EXIT_FAILURE;
    }
    if (fcntl(sockfd, F_SETFL, flags | O_NONBLOCK) < 0) {
        perror("fcntl");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Scan the specified ports.
    for (int i = 2; i < argc; i++) {
        // Get the port number from the argument.
        int port = atoi(argv[i]);

        // Set the port number in the sockaddr_in structure.
        sin.sin_port = htons(port);

        // Connect to the port.
        int ret = connect(sockfd, (struct sockaddr *)&sin, sizeof(sin));

        // Check if the connection was successful.
        if (ret == 0) {
            printf("Port %d is open.\n", port);
        } else if (errno == EINPROGRESS) {
            // The connection is in progress.
            fd_set writefds;
            FD_ZERO(&writefds);
            FD_SET(sockfd, &writefds);

            // Wait for the connection to complete.
            struct timeval timeout;
            timeout.tv_sec = 1;
            timeout.tv_usec = 0;
            ret = select(sockfd + 1, NULL, &writefds, NULL, &timeout);
            if (ret < 0) {
                perror("select");
                close(sockfd);
                return EXIT_FAILURE;
            } else if (ret == 0) {
                // The connection timed out.
                printf("Port %d is not open.\n", port);
            } else {
                // The connection completed.
                int error;
                socklen_t len = sizeof(error);
                if (getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &error, &len) < 0) {
                    perror("getsockopt");
                    close(sockfd);
                    return EXIT_FAILURE;
                }
                if (error == 0) {
                    printf("Port %d is open.\n", port);
                } else {
                    printf("Port %d is not open.\n", port);
                }
            }
        } else {
            // The connection failed.
            printf("Port %d is not open.\n", port);
        }
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}