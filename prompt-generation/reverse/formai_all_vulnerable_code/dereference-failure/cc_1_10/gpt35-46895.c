//FormAI DATASET v1.0 Category: Port Scanner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535 // Maximum number of ports to scan

int main(int argc, char *argv[])
{
    // Check if IP address and port range are given
    if (argc < 3)
    {
        printf("Usage: %s <ip_address> <start_port>-<end_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip_address = argv[1];

    // Split the port range into start and end ports
    char *start_port_str = strtok(argv[2], "-");
    char *end_port_str = strtok(NULL, "-");
    int start_port = atoi(start_port_str);
    int end_port = atoi(end_port_str);

    // Create a socket
    int sock;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket() error: ");
        exit(EXIT_FAILURE);
    }

    // Specify the server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_address);

    // Scan each port in the given range
    for (int port = start_port; port <= end_port; port++)
    {
        // Specify the port number
        server_addr.sin_port = htons(port);

        // Connect to the server
        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) >= 0)
        {
            printf("[+] Port %d is open\n", port);
        }

        // Close the socket
        close(sock);

        // Create a new socket for the next port
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
            perror("socket() error: ");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}