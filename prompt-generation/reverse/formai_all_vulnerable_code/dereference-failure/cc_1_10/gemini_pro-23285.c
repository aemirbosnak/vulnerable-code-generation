//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <net/if.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>

// Get the network interface information
struct if_info {
    char name[IFNAMSIZ];
    unsigned int index;
    unsigned int flags;
    unsigned int mtu;
    unsigned int addr_len;
    struct sockaddr_in addr;
    struct sockaddr_in mask;
    struct sockaddr_in bcast;
};

int get_interface_info(struct if_info *info, char *interface) {
    int fd;
    struct ifreq ifr;

    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        return -1;
    }

    strncpy(ifr.ifr_name, interface, IFNAMSIZ);

    if (ioctl(fd, SIOCGIFFLAGS, &ifr) < 0) {
        perror("ioctl[SIOCGIFFLAGS]");
        close(fd);
        return -1;
    }
    info->flags = ifr.ifr_flags;

    if (ioctl(fd, SIOCGIFMTU, &ifr) < 0) {
        perror("ioctl[SIOCGIFMTU]");
        close(fd);
        return -1;
    }
    info->mtu = ifr.ifr_mtu;

    if (ioctl(fd, SIOCGIFADDR, &ifr) < 0) {
        perror("ioctl[SIOCGIFADDR]");
        close(fd);
        return -1;
    }
    memcpy(&info->addr, &ifr.ifr_addr, sizeof(struct sockaddr_in));

    if (ioctl(fd, SIOCGIFNETMASK, &ifr) < 0) {
        perror("ioctl[SIOCGIFNETMASK]");
        close(fd);
        return -1;
    }
    memcpy(&info->mask, &ifr.ifr_addr, sizeof(struct sockaddr_in));

    if (ioctl(fd, SIOCGIFBRDADDR, &ifr) < 0) {
        perror("ioctl[SIOCGIFBRDADDR]");
        close(fd);
        return -1;
    }
    memcpy(&info->bcast, &ifr.ifr_addr, sizeof(struct sockaddr_in));

    close(fd);

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    struct if_info info;
    if (get_interface_info(&info, argv[1]) < 0) {
        perror("get_interface_info");
        return 1;
    }

    printf("Interface: %s\n", info.name);
    printf("Index: %u\n", info.index);
    printf("Flags: 0x%x\n", info.flags);
    printf("MTU: %u\n", info.mtu);
    printf("Address: %s\n", inet_ntoa(info.addr.sin_addr));
    printf("Mask: %s\n", inet_ntoa(info.mask.sin_addr));
    printf("Broadcast: %s\n", inet_ntoa(info.bcast.sin_addr));

    return 0;
}