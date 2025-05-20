//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <net/if.h>
#include <linux/wireless.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <interface name>\n", argv[0]);
        return 1;
    }

    char *ifname = argv[1];
    int sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_IP);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    struct iwreq wrq;
    memset(&wrq, 0, sizeof(wrq));
    strncpy(wrq.ifr_name, ifname, IFNAMSIZ);

    int res = ioctl(sock, SIOCGIWSCAN, &wrq);
    if (res < 0) {
        perror("ioctl");
        return 1;
    }

    struct iw_event iwe;
    char *ptr = wrq.u.data.pointer;
    char *end = ptr + wrq.u.data.length;
    while (ptr < end) {
        memcpy(&iwe, ptr, sizeof(iwe));

        if (iwe.cmd == SIOCGIWAP) {
            struct sockaddr_in addr;
            memset(&addr, 0, sizeof(addr));
            addr.sin_family = AF_INET;
            memcpy(&addr.sin_addr, iwe.u.ap_addr.sa_data+2, sizeof(struct in_addr));
            printf("%s %02X:%02X:%02X:%02X:%02X:%02X\n", inet_ntoa(addr.sin_addr),
                   iwe.u.ap_addr.sa_data[0], iwe.u.ap_addr.sa_data[1], iwe.u.ap_addr.sa_data[2],
                   iwe.u.ap_addr.sa_data[3], iwe.u.ap_addr.sa_data[4], iwe.u.ap_addr.sa_data[5]);
        }

        ptr += iwe.len;
    }

    return 0;
}