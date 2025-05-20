//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_PORTS 65535
#define MAX_HOSTS 256

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <host> [<port> ...]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the hostname
    char hostname[MAX_HOSTS];
    strncpy(hostname, argv[1], MAX_HOSTS);

    // Get the list of ports
    int ports[MAX_PORTS];
    int num_ports = 0;
    for (int i = 2; i < argc; i++) {
        int port = atoi(argv[i]);
        if (port < 0 || port > MAX_PORTS) {
            fprintf(stderr, "Invalid port: %s\n", argv[i]);
            return EXIT_FAILURE;
        }
        ports[num_ports++] = port;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Get the host's IP address
    struct hostent *hostent = gethostbyname(hostname);
    if (hostent == NULL) {
        fprintf(stderr, "Could not resolve hostname: %s\n", hostname);
        return EXIT_FAILURE;
    }

    // Loop through the ports and try to connect
    for (int i = 0; i < num_ports; i++) {
        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(ports[i]);
        memcpy(&addr.sin_addr, hostent->h_addr, hostent->h_length);

        int ret = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
        if (ret == 0) {
            printf("Port %d is open\n", ports[i]);
        } else {
            printf("Port %d is closed\n", ports[i]);
        }
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}