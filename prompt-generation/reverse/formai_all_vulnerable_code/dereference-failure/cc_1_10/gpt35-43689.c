//FormAI DATASET v1.0 Category: Port Scanner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc != 4)
    {
        printf("\nUsage: %s <ip_addr> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    // Get arguments
    char *ip_addr = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Create TCP socket
    int socket_desc;
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_desc == -1)
    {
        printf("\nFailed to create socket.\n");
        return 1;
    }

    // Create sockaddr_in struct
    struct sockaddr_in server;

    // Clear it out
    memset(&server, 0, sizeof(server));

    // Set addresses and ports
    server.sin_addr.s_addr = inet_addr(ip_addr);
    server.sin_family = AF_INET;

    // Start scanning
    printf("\nStarting port scan of %s\n", ip_addr);
    printf("===================================\n");

    int port;
    for(port=start_port; port<=end_port; port++)
    {
        server.sin_port = htons(port);

        // Try to connect
        if(connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) == 0)
        {
            printf("Port %d - OPEN\n", port);
        }
        else
        {
            printf("Port %d - CLOSED\n", port);
        }

        close(socket_desc);
        socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    }

    printf("\nScan complete.\n");

    return 0;
}