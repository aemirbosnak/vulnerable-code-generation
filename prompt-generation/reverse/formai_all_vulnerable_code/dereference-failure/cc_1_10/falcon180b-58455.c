//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_PORTS 1024

int scan_ports(char *hostname, int start_port, int end_port);

int main(int argc, char *argv[])
{
    if (argc!= 4)
    {
        printf("Usage: %s <hostname> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    scan_ports(hostname, start_port, end_port);

    return 0;
}

int scan_ports(char *hostname, int start_port, int end_port)
{
    int sock;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    int num_open_ports = 0;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(hostname, NULL, &hints, &servinfo))!= 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next)
    {
        sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol);

        if (sock == -1)
        {
            perror("socket");
            continue;
        }

        for (int port = start_port; port <= end_port; port++)
        {
            if (connect(sock, p->ai_addr, p->ai_addrlen) == 0)
            {
                printf("Port %d is open\n", port);
                num_open_ports++;
            }
            else if (errno!= ECONNREFUSED)
            {
                perror("connect");
                close(sock);
                return 1;
            }
        }

        close(sock);
    }

    if (num_open_ports == 0)
        printf("No open ports found\n");

    return 0;
}