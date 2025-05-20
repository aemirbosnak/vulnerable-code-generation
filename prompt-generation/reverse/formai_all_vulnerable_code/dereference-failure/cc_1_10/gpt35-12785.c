//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

#define MAX_PORT 65535
#define MIN_PORT 1
#define MAX_IP_LENGTH 16

void scan_port(char* ip, int port)
{
    struct sockaddr_in server;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1)
    {
        printf("Error: could not create socket.\n");
        exit(EXIT_FAILURE);
    }

    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // attempt to connect
    if(connect(sock, (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        // failed to connect
        printf("Port %d is closed\n", port);
    }
    else
    {
        // success
        printf("Port %d is open\n", port);
    }

    close(sock);
}

void scan_range(char* ip, int start_port, int end_port)
{
    for(int port=start_port; port<=end_port; port++)
    {
        scan_port(ip, port);
    }
}

int main(int argc , char *argv[])
{   
    char ip[MAX_IP_LENGTH];
    int start_port = MIN_PORT;
    int end_port = MAX_PORT;

    // check user arguments
    if(argc < 2 || argc > 4)
    {
        printf("Usage:\n\t%s IP_ADDRESS [START_PORT] [END_PORT]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strncpy(ip, argv[1], MAX_IP_LENGTH);

    if(argc >= 3)
    {
        start_port = atoi(argv[2]);
        if(start_port < MIN_PORT || start_port > MAX_PORT)
        {
            printf("Error: invalid start port.\n");
            exit(EXIT_FAILURE);
        }
    }

    if(argc == 4)
    {
        end_port = atoi(argv[3]);
        if(end_port < MIN_PORT || end_port > MAX_PORT)
        {
            printf("Error: invalid end port.\n");
            exit(EXIT_FAILURE);
        }
    }

    scan_range(ip, start_port, end_port);

    return 0;
}