//FormAI DATASET v1.0 Category: Port Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define DELIMITER ":"

// Function declarations
void port_scan(char *host, int start_port, int end_port);
int is_port_open(const char *host, const int port);

int main(int argc, char *argv[]) 
{
    // Check for correct command-line arguments
    if (argc != 4) 
    {
        printf("Usage: %s <host> <start_port> <end_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *host = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || start_port > 65535 || end_port < 1 || end_port > 65535 || start_port > end_port)
    {
        printf("Invalid port range\n");
        exit(EXIT_FAILURE);
    }

    // Call the port scanning function
    port_scan(host, start_port, end_port);

    return 0;
}

// Function to scan the given port range for the host
void port_scan(char *host, int start_port, int end_port) 
{
    printf("Scanning ports %d to %d on host %s\n", start_port, end_port, host);

    for (int port = start_port; port <= end_port; port++) 
    {
        if (is_port_open(host, port)) 
        {
            printf("Port %d is open\n", port);
        }
    }
}

// Function to check if the given port is open on the host
int is_port_open(const char *host, const int port) 
{
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(host);
    addr.sin_port = htons(port);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Connect to the specified host on the specified port
    int result = connect(sockfd, (struct sockaddr *)&addr, sizeof(struct sockaddr));
    if (result < 0) 
    {
        // Port is closed
        close(sockfd);
        return 0;
    }
    else 
    {
        // Port is open
        close(sockfd);
        return 1;
    }
}