//FormAI DATASET v1.0 Category: Port Scanner ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to scan the port
void scanPort(char *ip, int port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0); // Create a TCP socket

    // Check if socket creation was successful
    if (sock == -1)
    {
        printf("Could not create the socket");
        exit(1);
    }

    // Create a sockaddr_in structure for the target
    struct sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ip);
    target.sin_port = htons(port);

    // Connect to the target
    int status = connect(sock, (struct sockaddr *)&target, sizeof(target));

    // Check if connection was successful
    if (status == -1)
    {
        printf("Port %d is closed on %s\n", port, ip);
    }
    else
    {
        printf("Port %d is open on %s\n", port, ip);
    }

    close(sock); // Close the socket
}

// Main function
int main(int argc, char *argv[])
{
    // Check if all the required arguments are provided
    if (argc != 3)
    {
        printf("Usage: %s <ip_address> <port_range>\n", argv[0]);
        exit(1);
    }

    // Get the IP address and port range from the arguments
    char *ip = argv[1];
    char *port_range = argv[2];

    // Tokenize the port range
    char *token = strtok(port_range, "-");
    int start_port = atoi(token);
    token = strtok(NULL, "-");
    int end_port = atoi(token);

    // Scan the ports in the given range
    for (int port = start_port; port <= end_port; port++)
    {
        scanPort(ip, port);
    }

    return 0;
}