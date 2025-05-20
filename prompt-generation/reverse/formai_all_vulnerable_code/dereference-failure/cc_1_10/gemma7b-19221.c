//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: accurate
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

#define PORT_RANGE 1-65535

int main()
{
    int sockfd, port, n, err, host_len;
    struct sockaddr_in host_addr;

    printf("Enter host IP address: ");
    char host[256];
    scanf("%s", host);

    printf("Enter port range (e.g. 1-65535): ");
    char port_range[256];
    scanf("%s", port_range);

    char **ports = (char**)malloc(sizeof(char*) * PORT_RANGE);
    for (int i = 0; i < PORT_RANGE; i++)
    {
        ports[i] = (char*)malloc(sizeof(char) * 6);
    }

    for (port = atoi(port_range[0]); port <= atoi(port_range[1]); port++)
    {
        host_addr.sin_port = htons(port);
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        err = connect(sockfd, (struct sockaddr*)&host_addr, sizeof(host_addr));

        if (err == 0)
        {
            printf("Port %d is open.\n", port);
            ports[port - atoi(port_range[0])] = "open";
        }
        else
        {
            perror("Error connecting to port");
        }

        close(sockfd);
    }

    printf("Port scan complete.\n");
    for (int i = 0; i < PORT_RANGE; i++)
    {
        printf("Port %d: %s\n", i + atoi(port_range[0]), ports[i]);
    }

    free(ports);

    return 0;
}