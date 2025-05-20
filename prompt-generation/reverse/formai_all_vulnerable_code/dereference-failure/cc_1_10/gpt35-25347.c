//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <string.h>

#define PORT 80

int main()
{
    struct sockaddr_in addr;
    struct hostent *host;
    int fd, addr_len, ret, i;
    char *host_name = "www.google.com";
    char buf[1024];

    if ((host = gethostbyname(host_name)) == NULL)
    {
        printf("\nError: Could not resolve hostname.\n");
        return(EXIT_FAILURE);
    }

    fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (fd < 0)
    {
        printf("\nError: Could not create socket.\n");
        return(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);

    for(i=0; i < 255; i++)
    {
        char ip_address[20];
        sprintf(ip_address, "%d.%d.%d.%d", 192, 168, 1, i);
        addr.sin_addr.s_addr = inet_addr(ip_address);
        addr_len = sizeof(addr);
        ret = sendto(fd, "PING", 4, 0, (const struct sockaddr *)&addr, addr_len);
        if (ret < 0)
        {
            printf("\nError: Could not send packet to %s\n", ip_address);
        }
        else
        {
            struct timeval tv = {1, 0};
            fd_set read_fds;
            FD_ZERO(&read_fds);
            FD_SET(fd, &read_fds);
            ret = select(fd+1, &read_fds, NULL, NULL, &tv);
            if (ret <= 0)
            {
                printf("\nNo response from %s\n", ip_address);
            }
            else
            {
                ret = recvfrom(fd, buf, sizeof(buf), 0, (struct sockaddr *)&addr, &addr_len);
                if (ret < 0)
                {
                    printf("\nError: Could not receive response from %s\n", ip_address);
                }
                else if (strcmp(buf, "PONG") == 0)
                {
                    printf("\n%s is responsive on port %d\n", ip_address, PORT);
                }
                else
                {
                    printf("\n%s responded, but not with expected response (PONG)\n", ip_address);
                }
            }
        }
    }

    close(fd);
    return 0;
}