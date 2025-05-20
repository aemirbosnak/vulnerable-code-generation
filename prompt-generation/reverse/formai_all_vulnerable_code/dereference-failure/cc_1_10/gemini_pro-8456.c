//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define MAX_PORTS 100
#define MAX_HOST_NAME 256

int main(int argc, char **argv) {
    // Check input arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port-range>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get host name
    char host_name[MAX_HOST_NAME];
    strcpy(host_name, argv[1]);

    // Get port range
    int port_range[2];
    if (sscanf(argv[2], "%d-%d", &port_range[0], &port_range[1]) != 2) {
        fprintf(stderr, "Invalid port range: %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Get host IP address
    struct hostent *hostent = gethostbyname(host_name);
    if (hostent == NULL) {
        perror("Error getting host IP address");
        exit(EXIT_FAILURE);
    }
    struct in_addr **addr_list = (struct in_addr **)hostent->h_addr_list;

    // Loop through ports
    for (int port = port_range[0]; port <= port_range[1]; port++) {
        // Create a socket address
        struct sockaddr_in sockaddr;
        sockaddr.sin_family = AF_INET;
        sockaddr.sin_port = htons(port);
        sockaddr.sin_addr = *addr_list[0];

        // Connect to the port
        int connfd = connect(sockfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr));
        if (connfd == -1) {
            if (errno == ECONNREFUSED) {
                printf("Port %d is closed\n", port);
            } else {
                perror("Error connecting to port");
            }
        } else {
            printf("Port %d is open\n", port);
            close(connfd);
        }
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}