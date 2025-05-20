//FormAI DATASET v1.0 Category: Port Scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

// Function to scan ports
void scanport(char *ip, int start_port, int end_port)
{
    struct sockaddr_in server;
    int sock;

    // Loop through all the ports
    for(int port = start_port; port <= end_port; port++)
    {
        // Create the socket
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if(sock == -1)
        {
            printf("Error creating socket: %s\n", strerror(errno));
            return;
        }

        // Set up the server information
        server.sin_addr.s_addr = inet_addr(ip);
        server.sin_family = AF_INET;
        server.sin_port = htons(port);

        // Attempt to connect to the server
        int connect_status = connect(sock, (struct sockaddr *)&server, sizeof(server));
        if(connect_status < 0)
        {
            // Port is closed
            printf("Port %d is closed.\n", port);
        }
        else
        {
            // Port is open
            printf("Port %d is open.\n", port);

            // Close the socket
            close(sock);
        }
    }
}

int main()
{
    // Get the IP address to scan
    char ip[16];
    printf("Enter the IP address to scan: ");
    scanf("%15s", ip);

    // Get the range of ports to scan
    int start_port, end_port;
    printf("Enter the start port: ");
    scanf("%d", &start_port);
    printf("Enter the end port: ");
    scanf("%d", &end_port);

    // Scan the ports
    scanport(ip, start_port, end_port);

    return 0;
}