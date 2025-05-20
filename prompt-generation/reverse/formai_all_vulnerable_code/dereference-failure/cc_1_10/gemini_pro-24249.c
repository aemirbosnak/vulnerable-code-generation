//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>

// Function to scan a single port
int scan_port(char *ip, int port)
{
    int sockfd;
    struct sockaddr_in serv_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        return -1;
    }

    // Set the server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(ip);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
    {
        //perror("connect");
        return -1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}

// Function to scan a range of ports
int scan_ports(char *ip, int start_port, int end_port)
{
    int i;

    for (i = start_port; i <= end_port; i++)
    {
        int result = scan_port(ip, i);
        if (result == 0)
        {
            printf("Port %d is open\n", i);
        }
    }

    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <ip> <start_port> <end_port>\n", argv[0]);
        return -1;
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    int result = scan_ports(ip, start_port, end_port);
    if (result == -1)
    {
        return -1;
    }

    return 0;
}