//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORT_NUM 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if(argc!= 3)
    {
        printf("Usage:./portscanner <IP address> <port range>\n");
        return 1;
    }

    // Convert IP address from string to binary
    char *ip_address = argv[1];
    struct in_addr inet_addr;
    inet_pton(AF_INET, ip_address, &inet_addr);

    // Convert port range from string to integer
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[2]) + MAX_PORT_NUM - 1;

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1)
    {
        printf("Error creating socket\n");
        return 1;
    }

    // Set socket options
    int val = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
    setsockopt(sock, SOL_SOCKET, SO_KEEPALIVE, &val, sizeof(val));

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(start_port);
    server_addr.sin_addr.s_addr = inet_addr.s_addr;

    while(start_port <= end_port)
    {
        // Connect to port
        if(connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0)
        {
            // Port is open, send message and receive response
            char message[] = "Port is open\n";
            send(sock, message, strlen(message), 0);
            char buffer[BUFFER_SIZE];
            memset(buffer, 0, BUFFER_SIZE);
            int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
            if(bytes_received > 0)
            {
                printf("%d is open\n", start_port);
                printf("Received response: %s\n", buffer);
            }
            else
            {
                printf("%d is closed\n", start_port);
            }
        }
        else
        {
            // Port is closed
            printf("%d is closed\n", start_port);
        }

        // Increment port number
        start_port++;

        // Wait for 1 second before checking next port
        usleep(1000000);
    }

    // Close socket
    close(sock);

    return 0;
}