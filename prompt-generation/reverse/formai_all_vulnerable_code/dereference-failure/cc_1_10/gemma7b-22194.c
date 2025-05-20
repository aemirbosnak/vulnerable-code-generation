//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

int main()
{
    // Define the target IP address and port range
    char target_ip[] = "192.168.1.1";
    int target_port_start = 1024;
    int target_port_end = 65535;

    // Allocate memory for the scan results
    char *results = malloc(1024 * sizeof(char));

    // Loop over the port range
    for (int port = target_port_start; port <= target_port_end; port++)
    {
        // Create a socket
        int sockfd = socket(AF_INET, SOCK_STREAM, htons(port));

        // Connect to the target port
        struct sockaddr_in sock_addr;
        sock_addr.sin_port = htons(port);
        if (connect(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) == 0)
        {
            // Print the port number and the result
            results[port] = 'Y';
            printf("Port %d: OPEN\n", port);
        }
        else
        {
            // Print the port number and the result
            results[port] = 'N';
            printf("Port %d: CLOSED\n", port);
        }

        // Close the socket
        close(sockfd);
    }

    // Print the scan results
    printf("Scan results:\n");
    for (int port = target_port_start; port <= target_port_end; port++)
    {
        printf("Port %d: %c\n", port, results[port]);
    }

    // Free the memory
    free(results);

    return 0;
}