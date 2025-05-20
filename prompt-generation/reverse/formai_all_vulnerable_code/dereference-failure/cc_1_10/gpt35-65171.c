//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <net/if_arp.h>

#define MAX_RECV_BUF 2048

int main(int argc, char **argv) {
    int sockfd, num_bytes;
    char recv_buf[MAX_RECV_BUF], *pointer, dev_buf[256], addr_buf[256], mac_buf[32], vendor_buf[256];
    struct ifreq ifr;
    struct sockaddr_in *sin;
    struct arpreq arpreq;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s INTERFACENAME\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, argv[1], IFNAMSIZ - 1);

    if (ioctl(sockfd, SIOCGIFADDR, &ifr) == -1) {
        perror("ioctl");
        exit(1);
    }

    sin = (struct sockaddr_in *)&ifr.ifr_addr;
    strcpy(addr_buf, inet_ntoa(sin->sin_addr));
    printf("IP address of interface %s: %s\n", argv[1], addr_buf);

    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, argv[1], IFNAMSIZ - 1);

    if (ioctl(sockfd, SIOCGIFHWADDR, &ifr) == -1) {
        perror("ioctl");
        exit(1);
    }

    sprintf(mac_buf, "%02X:%02X:%02X:%02X:%02X:%02X", (unsigned char)ifr.ifr_hwaddr.sa_data[0], (unsigned char)ifr.ifr_hwaddr.sa_data[1], (unsigned char)ifr.ifr_hwaddr.sa_data[2], (unsigned char)ifr.ifr_hwaddr.sa_data[3], (unsigned char)ifr.ifr_hwaddr.sa_data[4], (unsigned char)ifr.ifr_hwaddr.sa_data[5]);
    printf("MAC address of interface %s: %s\n", argv[1], mac_buf);

    for (int i = 1; i <= 255; i++) {
        sprintf(dev_buf, "%s.%d", addr_buf, i);

        memset(&arpreq, 0, sizeof(arpreq));
        ((struct sockaddr_in *)&arpreq.arp_pa)->sin_family = AF_INET;
        ((struct sockaddr_in *)&arpreq.arp_pa)->sin_addr.s_addr = inet_addr(dev_buf);
        memcpy(arpreq.arp_ha.sa_data, "\0\0\0\0\0\0", 6);
        arpreq.arp_ha.sa_family = ARPHRD_ETHER;
        strcpy(arpreq.arp_dev, argv[1]);

        if (ioctl(sockfd, SIOCGARP, &arpreq) == -1) {
            continue;
        }

        sprintf(mac_buf, "%02X:%02X:%02X:%02X:%02X:%02X", (unsigned char)arpreq.arp_ha.sa_data[0], (unsigned char)arpreq.arp_ha.sa_data[1], (unsigned char)arpreq.arp_ha.sa_data[2], (unsigned char)arpreq.arp_ha.sa_data[3], (unsigned char)arpreq.arp_ha.sa_data[4], (unsigned char)arpreq.arp_ha.sa_data[5]);

        pointer = strtok(mac_buf, ":");

        if (pointer != NULL) {
            sprintf(vendor_buf, "http://www.macvendorlookup.com/search/%s", pointer);
            printf("%-15s%-20s%-40s\n", dev_buf, mac_buf, vendor_buf);
        }
    }

    close(sockfd);
    return 0;
}