//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>

#define MAX_INTERFACES 16

typedef struct {
    char name[IFNAMSIZ];
    unsigned int index;
    unsigned int flags;
    char mac[6];
} interface_t;

int main(int argc, char *argv[]) {
    int sockfd;
    struct ifreq ifr[MAX_INTERFACES];
    interface_t interfaces[MAX_INTERFACES];
    int num_interfaces = 0;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    for (int i = 0; i < MAX_INTERFACES; i++) {
        memset(&ifr[i], 0, sizeof(struct ifreq));
        snprintf(ifr[i].ifr_name, IFNAMSIZ, "wlan%d", i);
        if (ioctl(sockfd, SIOCGIFFLAGS, &ifr[i]) == -1) {
            if (errno != ENODEV) {
                perror("ioctl");
                close(sockfd);
                return 1;
            }
            continue;
        }

        interfaces[num_interfaces].index = ifr[i].ifr_ifindex;
        interfaces[num_interfaces].flags = ifr[i].ifr_flags;

        if (ioctl(sockfd, SIOCGIFHWADDR, &ifr[i]) == -1) {
            perror("ioctl");
            close(sockfd);
            return 1;
        }

        memcpy(interfaces[num_interfaces].mac, ifr[i].ifr_hwaddr.sa_data, 6);
        num_interfaces++;
    }

    close(sockfd);

    printf("Found %d wireless interfaces:\n", num_interfaces);
    for (int i = 0; i < num_interfaces; i++) {
        printf("  %s (index %u, flags 0x%08x, MAC %02x:%02x:%02x:%02x:%02x:%02x)\n",
                interfaces[i].name, interfaces[i].index, interfaces[i].flags,
                interfaces[i].mac[0], interfaces[i].mac[1], interfaces[i].mac[2],
                interfaces[i].mac[3], interfaces[i].mac[4], interfaces[i].mac[5]);
    }

    return 0;
}