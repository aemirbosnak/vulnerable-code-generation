//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_INTERFACES 16

int main()
{
    struct ifreq ifr[MAX_INTERFACES];
    struct ifconf ifc;
    int sock, i;

    // Create a socket to get network interface information
    if ((sock = socket(AF_PACKET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Initialize the ifconf structure
    ifc.ifc_len = sizeof(ifr);
    ifc.ifc_req = ifr;

    // Get network interface information
    if (ioctl(sock, SIOCGIFCONF, &ifc) < 0) {
        perror("ioctl");
        exit(EXIT_FAILURE);
    }

    // Close the socket
    close(sock);

    // Print network interface information
    for (i = 0; i < ifc.ifc_len / sizeof(struct ifreq); i++) {
        printf("Interface %d: %s\n", i, ifr[i].ifr_name);
        printf("  IP address: %s\n", inet_ntoa(((struct sockaddr_in *)&ifr[i].ifr_addr)->sin_addr));
        printf("  Netmask: %s\n", inet_ntoa(((struct sockaddr_in *)&ifr[i].ifr_netmask)->sin_addr));
        printf("  Broadcast address: %s\n", inet_ntoa(((struct sockaddr_in *)&ifr[i].ifr_broadaddr)->sin_addr));
        printf("  MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n",
            (unsigned char)ifr[i].ifr_hwaddr.sa_data[0],
            (unsigned char)ifr[i].ifr_hwaddr.sa_data[1],
            (unsigned char)ifr[i].ifr_hwaddr.sa_data[2],
            (unsigned char)ifr[i].ifr_hwaddr.sa_data[3],
            (unsigned char)ifr[i].ifr_hwaddr.sa_data[4],
            (unsigned char)ifr[i].ifr_hwaddr.sa_data[5]);
        printf("\n");
    }

    return 0;
}