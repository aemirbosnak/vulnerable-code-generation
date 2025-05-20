//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    if (argc!= 3)
    {
        printf("Usage:./scanner <IP Address> <Port Range>\n");
        return 1;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + MAX_PORTS;

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1)
    {
        printf("Error creating socket.\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(start_port);
    if (inet_pton(AF_INET, ip_address, &server_addr.sin_addr) == 0)
    {
        printf("Invalid IP address.\n");
        close(socket_fd);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    while (start_port <= end_port)
    {
        server_addr.sin_port = htons(start_port);
        if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0)
        {
            printf("Port %d is open.\n", start_port);
            close(socket_fd);
            return 0;
        }
        else if (errno!= ECONNREFUSED)
        {
            printf("Error connecting to port %d.\n", start_port);
            close(socket_fd);
            return 1;
        }
        start_port++;
    }

    printf("No open ports found in the specified range.\n");
    close(socket_fd);
    return 0;
}