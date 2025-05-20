//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: future-proof
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <errno.h> 
#include <sys/ioctl.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <net/if.h> 
#include <arpa/inet.h> 
#include <unistd.h> 

#define MAXINTERFACES 16 
#define MAXDATASIZE 8192 

int main()
{
    char buffer[MAXDATASIZE];
    struct ifconf ifc;
    struct ifreq ifr[MAXINTERFACES];
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) 
    {
        perror("socket failed");
        return 1;
    }

    ifc.ifc_len = sizeof(ifr);
    ifc.ifc_ifcu.ifcu_buf = (caddr_t)ifr;
    if (ioctl(sock, SIOCGIFCONF, &ifc) < 0) 
    {
        perror("ioctl(SIOCGIFCONF) failed");
        return 1;
    }

    int interfaces = ifc.ifc_len / sizeof(ifr[0]);

    for (int i = 0; i < interfaces; i++)
    {
        struct ifreq *r = &ifr[i];
        if (ioctl(sock, SIOCGIFFLAGS, r) < 0) 
        {
            perror("ioctl(SIOCGIFFLAGS) failed");
            return 1;
        }

        if (r->ifr_flags & IFF_LOOPBACK) continue;

        if (ioctl(sock, SIOCGIFBRDADDR, r) < 0) 
        {
            perror("ioctl(SIOCGIFBRDADDR) failed");
            return 1;
        }

        struct sockaddr_in *ip = (struct sockaddr_in *)&r->ifr_addr;
        struct sockaddr_in *broadcast = (struct sockaddr_in *)&r->ifr_broadaddr;

        sprintf(buffer, "Interface %s:\n  IP address: %s\n  Broadcast address: %s\n", r->ifr_name, inet_ntoa(ip->sin_addr), inet_ntoa(broadcast->sin_addr));
        printf("%s", buffer);
    }

    return 0;
}