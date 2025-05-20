//FormAI DATASET v1.0 Category: Port Scanner ; Style: visionary
/* 
Unique C Port Scanner Program 
By: Your Name 
*/

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

// Define the number of ports to scan
#define NUM_PORTS 65535

int main(int argc, char *argv[])
{
    // Check if IP and port were provided
    if (argc < 3)
    {
        printf("Usage: %s <IP address> <Starting Port>\n", argv[0]);
        return 1;
    }

    // Parse IP and starting port from arguments
    char *ip = argv[1];
    int start_port = atoi(argv[2]);

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        perror("socket() failed");
        return 1;
    }

    // Set up address structure
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);

    // Loop through ports and try to connect
    int i;
    for (i = start_port; i <= NUM_PORTS; i++)
    {
        addr.sin_port = htons(i);

        // Connect to port
        if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0)
        {
            printf("Port %d is open\n", i);
            close(sock);
            sock = socket(AF_INET, SOCK_STREAM, 0);
            if (sock == -1)
            {
                perror("socket() failed");
                return 1;
            }
        }
    }

    printf("Scan complete.\n");

    return 0;
}