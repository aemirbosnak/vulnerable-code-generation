//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/if.h>

int main()
{
    int s, i, j;
    struct ifreq ifr;
    struct sockaddr_in *addr;
    char buf[1024];

    s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s < 0)
    {
        perror("socket");
        exit(1);
    }

    for (i = 0; i < 100; i++)
    {
        snprintf(ifr.ifr_name, sizeof(ifr.ifr_name), "wlan%d", i);
        if (ioctl(s, SIOCGIFFLAGS, &ifr) < 0)
        {
            perror("ioctl");
            continue;
        }

        if (!(ifr.ifr_flags & IFF_UP))
        {
            continue;
        }

        if (ioctl(s, SIOCGIFADDR, &ifr) < 0)
        {
            perror("ioctl");
            continue;
        }

        addr = (struct sockaddr_in *)&ifr.ifr_addr;
        printf("Interface %s: %s\n", ifr.ifr_name, inet_ntoa(addr->sin_addr));

        for (j = 0; j < 100; j++)
        {
            snprintf(buf, sizeof(buf), "nmap -sV %s", inet_ntoa(addr->sin_addr));
            system(buf);
        }
    }

    close(s);
    return 0;
}