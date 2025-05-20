//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_PORTS 65535

// Function to check if a port is open on a given host
int is_port_open(char *host, int port)
{
    int sockfd;
    struct sockaddr_in addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket");
        return -1;
    }

    // Set the address of the host
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &addr.sin_addr) <= 0)
    {
        perror("inet_pton");
        close(sockfd);
        return -1;
    }

    // Connect to the host
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        close(sockfd);
        return 0;
    }

    // The port is open
    close(sockfd);
    return 1;
}

// Main function
int main(int argc, char **argv)
{
    char *host;
    int port;

    // Check the arguments
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    host = argv[1];
    port = atoi(argv[2]);

    // Check if the port is open
    if (is_port_open(host, port))
    {
        printf("Port %d is open on host %s\n", port, host);
    }
    else
    {
        printf("Port %d is closed on host %s\n", port, host);
    }

    return EXIT_SUCCESS;
}