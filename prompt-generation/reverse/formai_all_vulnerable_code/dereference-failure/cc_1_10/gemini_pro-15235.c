//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>

struct if_info {
    char name[IFNAMSIZ];
    unsigned int index;
    unsigned int flags;
    struct sockaddr_in addr;
    struct sockaddr_in netmask;
    struct sockaddr_in broadcast;
};

int get_if_info(struct if_info *info, char *ifname)
{
    int sockfd;
    struct ifreq ifr;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket");
        return -1;
    }

    memset(&ifr, 0, sizeof(ifr));
    strcpy(ifr.ifr_name, ifname);

    if (ioctl(sockfd, SIOCGIFADDR, &ifr) == -1) {
        perror("ioctl (SIOCGIFADDR)");
        close(sockfd);
        return -1;
    }
    memcpy(&info->addr, &ifr.ifr_addr, sizeof(info->addr));

    if (ioctl(sockfd, SIOCGIFNETMASK, &ifr) == -1) {
        perror("ioctl (SIOCGIFNETMASK)");
        close(sockfd);
        return -1;
    }
    memcpy(&info->netmask, &ifr.ifr_netmask, sizeof(info->netmask));

    if (ioctl(sockfd, SIOCGIFBRDADDR, &ifr) == -1) {
        perror("ioctl (SIOCGIFBRDADDR)");
        close(sockfd);
        return -1;
    }
    memcpy(&info->broadcast, &ifr.ifr_broadaddr, sizeof(info->broadcast));

    if (ioctl(sockfd, SIOCGIFFLAGS, &ifr) == -1) {
        perror("ioctl (SIOCGIFFLAGS)");
        close(sockfd);
        return -1;
    }
    info->flags = ifr.ifr_flags;

    if (ioctl(sockfd, SIOCGIFINDEX, &ifr) == -1) {
        perror("ioctl (SIOCGIFINDEX)");
        close(sockfd);
        return -1;
    }
    info->index = ifr.ifr_ifindex;

    close(sockfd);

    return 0;
}

int main(int argc, char **argv)
{
    struct if_info info;
    int i;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (get_if_info(&info, argv[1]) == -1) {
        fprintf(stderr, "Error getting interface information\n");
        return EXIT_FAILURE;
    }

    printf("Interface: %s\n", info.name);
    printf("Index: %u\n", info.index);
    printf("Flags: %u\n", info.flags);
    printf("IP address: %s\n", inet_ntoa(info.addr.sin_addr));
    printf("Netmask: %s\n", inet_ntoa(info.netmask.sin_addr));
    printf("Broadcast address: %s\n", inet_ntoa(info.broadcast.sin_addr));

    return EXIT_SUCCESS;
}