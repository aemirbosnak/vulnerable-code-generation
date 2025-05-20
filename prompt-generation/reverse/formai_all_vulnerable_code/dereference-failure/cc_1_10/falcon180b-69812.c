//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/wireless.h>

int main() {
    int sock;
    struct ifreq ifr;
    char *dev = "wlan0";
    const char *ifname = dev;
    char *ssid;
    int i, len, ret;
    struct iwreq iwr;
    struct sockaddr_in addr;
    int opt = 1;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(1);
    }

    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, ifname, IFNAMSIZ - 1);

    if (ioctl(sock, SIOCGIFHWADDR, &ifr) < 0) {
        perror("ioctl");
        exit(1);
    }

    ssid = malloc(100);
    if (!ssid) {
        perror("malloc");
        exit(1);
    }

    memset(&iwr, 0, sizeof(iwr));
    iwr.u.data.pointer = ssid;
    iwr.u.data.length = 100;

    if (ioctl(sock, SIOCGIWSCAN, &iwr) < 0) {
        perror("ioctl");
        exit(1);
    }

    printf("SSID: %s\n", ssid);

    close(sock);
    free(ssid);
    return 0;
}