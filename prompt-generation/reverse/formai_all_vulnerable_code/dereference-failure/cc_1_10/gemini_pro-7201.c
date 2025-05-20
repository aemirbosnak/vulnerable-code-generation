//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <net/if_arp.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

int main(int argc, char **argv)
{
    int sock, ret;
    struct ifreq *ifr;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    ifr = (struct ifreq *)calloc(1, sizeof(struct ifreq));
    if (ifr == NULL) {
        perror("calloc");
        exit(1);
    }

    strcpy(ifr->ifr_name, "wlp3s0");
    ret = ioctl(sock, SIOCGIFFLAGS, ifr);
    if (ret < 0) {
        perror("ioctl");
        exit(1);
    }

    printf("Wireless Network Scanner!\n\n");
    printf("Scanning for wireless networks...\n");

    if (ifr->ifr_flags & IFF_UP) {
        printf("Interface is up!\n");
    } else {
        printf("Interface is down!\n");
    }

    if (ifr->ifr_flags & IFF_RUNNING) {
        printf("Interface is running!\n");
    } else {
        printf("Interface is not running!\n");
    }

    close(sock);
    free(ifr);

    return 0;
}