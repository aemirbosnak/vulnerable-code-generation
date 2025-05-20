//FormAI DATASET v1.0 Category: Port Scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define MIN_PORT 1
#define MAX_PORT 65535

int main(int argc, char* argv[])
{
    char* target = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Validate inputs
    if (argc < 4 || end_port < start_port || start_port < MIN_PORT || end_port > MAX_PORT)
    {
        printf("Usage: %s <IP address> <starting port> <ending port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(target);

    printf("Scanning ports %d to %d on %s...\n", start_port, end_port, target);

    for (int port = start_port; port <= end_port; port++)
    {
        // Create socket
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0)
        {
            fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        // Set socket options
        int optval = 1;
        if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0)
        {
            fprintf(stderr, "Error setting socket option: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        // Connect to server
        server_addr.sin_port = htons(port);
        if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
        {
            close(sock);
            continue; // Port closed
        }

        // Port open
        printf("Port %d open.\n", port);

        close(sock);
    }

    printf("Port scan complete.\n");

    return EXIT_SUCCESS;
}