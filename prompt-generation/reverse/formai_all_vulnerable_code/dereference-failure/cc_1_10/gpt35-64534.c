//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define BUFFER_SIZE 4096

void print_mac_address(unsigned char *mac_addr) {
    for (int i = 0; i < 6; ++i) {
        printf("%02x", mac_addr[i]);
        if (i < 5) {
            printf(":");
        }
    }
}

void scan_network_devices(int sock, struct ifreq *ifr) {
    unsigned char *buffer = malloc(BUFFER_SIZE);
    struct sockaddr_in *sin;
    struct ifconf ifc;
    int i, num_devices;

    ifc.ifc_len = BUFFER_SIZE;
    ifc.ifc_buf = (void*) buffer;

    if (ioctl(sock, SIOCGIFCONF, &ifc) == -1) {
        perror("ioctl failed");
        exit(EXIT_FAILURE);
    }

    num_devices = ifc.ifc_len / sizeof(struct ifreq);

    for (i = 0; i < num_devices; ++i) {
        strncpy(ifr[i].ifr_name, ifc.ifc_req[i].ifr_name, IFNAMSIZ-1);
        if (ioctl(sock, SIOCGIFFLAGS, &ifr[i]) == -1) {
            perror("ioctl failed");
            continue;
        }
        if (ifr[i].ifr_flags & IFF_LOOPBACK) {
            continue;
        }

        printf("Device: %s\n", ifr[i].ifr_name);

        if (ioctl(sock, SIOCGIFHWADDR, &ifr[i]) == -1) {
            perror("ioctl failed");
            continue;
        }

        printf("MAC Address: ");
        print_mac_address((unsigned char*) &ifr[i].ifr_hwaddr.sa_data);
        printf("\n");

        sin = (struct sockaddr_in *) &ifr[i].ifr_addr;
        printf("IP Address: %s\n", inet_ntoa(sin->sin_addr));
    }

    free(buffer);
}

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct ifreq ifr;
    scan_network_devices(sock, &ifr);

    close(sock);
    return 0;
}