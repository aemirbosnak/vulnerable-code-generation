//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define PORT 80
#define IP_ADDR "192.168.1."

void print_open_ports(int sock)
{
    struct sockaddr_in addr;
    socklen_t addr_size = sizeof(addr);
    int open_ports[100] = {0}, count = 0;

    // Scan the network for open ports
    for (int i = 1; i <= 255; i++)
    {
        char ip[20];
        sprintf(ip, "%s%d", IP_ADDR, i);

        addr.sin_addr.s_addr = inet_addr(ip);
        addr.sin_family = AF_INET;
        addr.sin_port = htons(PORT);

        // Set timeout for the connection
        struct timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        // Create socket and connect to the IP
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
        int connect_status = connect(sock, (struct sockaddr *)&addr, sizeof(addr));

        // Check if connection was successful
        if (connect_status < 0)
        {
            if (errno == ECONNREFUSED)
            {
                // Port is closed
                continue;
            }
        }
        else
        {
            // Port is open
            open_ports[count] = i;
            count++;
            printf("%s:%d - Open\n", ip, PORT);
            close(sock);
        }
    }

    // Print out the list of open ports
    printf("List of open ports:\n");
    for (int i = 0; i < count; i++)
    {
        printf("%s:%d\n", IP_ADDR, open_ports[i]);
    }
}

int main()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    print_open_ports(sock);

    return 0;
}