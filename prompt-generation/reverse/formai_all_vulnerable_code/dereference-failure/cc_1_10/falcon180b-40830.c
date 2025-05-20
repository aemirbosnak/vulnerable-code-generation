//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX 65535
#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int sock, port, addrlen, ret;
    struct sockaddr_in server;
    char buffer[BUF_SIZE];

    if (argc!= 3)
    {
        printf("Usage: %s <IP address> <port range>\n", argv[0]);
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        printf("Error creating socket.\n");
        return 1;
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server.sin_addr);

    for (port = 1; port <= MAX; port++)
    {
        if (port == atoi(argv[2]))
            continue;

        addrlen = sizeof(server);
        ret = connect(sock, (struct sockaddr *)&server, addrlen);

        if (ret == 0)
        {
            printf("Port %d is open.\n", port);
            close(sock);
            return 0;
        }
        else if (errno!= ECONNREFUSED)
        {
            printf("Error connecting to port %d.\n", port);
            close(sock);
            return 1;
        }
    }

    printf("All ports between 1 and %d are closed.\n", MAX);
    close(sock);
    return 0;
}