//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc!= 3)
    {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + MAX_PORTS - 1;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        printf("Error: Could not create socket\n");
        return 1;
    }

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    struct addrinfo *addr_info = NULL;
    if (getaddrinfo(ip_address, NULL, &hints, &addr_info)!= 0)
    {
        printf("Error: Could not resolve IP address\n");
        close(sock);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    for (int port = start_port; port <= end_port; port++)
    {
        sprintf(buffer, "Port %d is %s\n", port, (connect(sock, addr_info->ai_addr, addr_info->ai_addrlen) == 0)? "open" : "closed");
        printf("%s", buffer);
    }

    close(sock);
    freeaddrinfo(addr_info);
    return 0;
}