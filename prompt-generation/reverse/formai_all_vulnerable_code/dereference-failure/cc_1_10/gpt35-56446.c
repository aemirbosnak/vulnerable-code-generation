//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define MAX_INTERFACES 16
#define MAX_INTERFACE_NAME_LEN 16

int main() {
    // variables to store network interface information
    struct ifconf ifc;
    struct ifreq ifr[MAX_INTERFACES];
    int sock = -1;
    int i, numInterfaces;

    memset(ifr, 0, sizeof(ifr));

    // create a socket to perform the ioctl calls
    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);
    if (sock == -1) {
        printf("Failed to create socket: %s\n", strerror(errno));
        return -1;
    }

    // query the kernel interface configuration information
    ifc.ifc_len = sizeof(ifr);
    ifc.ifc_req = ifr;
    if (ioctl(sock, SIOCGIFCONF, &ifc) == -1) {
        printf("Failed to retrieve network interface information: %s\n", strerror(errno));
        return -1;
    }

    // calculate the number of interfaces found
    numInterfaces = ifc.ifc_len / sizeof(ifr[0]);

    // loop through each interface and display its information
    for (i = 0; i < numInterfaces; i++) {
        char ip[INET_ADDRSTRLEN];

        // retrieve the interface name
        printf("Interface name: %s\n", ifr[i].ifr_name);

        // retrieve the IP address of the interface
        if (ioctl(sock, SIOCGIFADDR, &ifr[i]) != -1) {
            struct sockaddr_in* addr = (struct sockaddr_in*)&ifr[i].ifr_addr;
            inet_ntop(AF_INET, &addr->sin_addr, ip, sizeof(ip));
            printf("\tIP address: %s\n", ip);
        }

        // retrieve the netmask of the interface
        if (ioctl(sock, SIOCGIFNETMASK, &ifr[i]) != -1) {
            struct sockaddr_in* mask = (struct sockaddr_in*)&ifr[i].ifr_netmask;
            inet_ntop(AF_INET, &mask->sin_addr, ip, sizeof(ip));
            printf("\tNetmask: %s\n", ip);
        }

        // retrieve the broadcast address of the interface
        if (ioctl(sock, SIOCGIFBRDADDR, &ifr[i]) != -1) {
            struct sockaddr_in* bcast = (struct sockaddr_in*)&ifr[i].ifr_broadaddr;
            inet_ntop(AF_INET, &bcast->sin_addr, ip, sizeof(ip));
            printf("\tBroadcast address: %s\n", ip);
        }

        // retrieve the MAC address of the interface
        if (ioctl(sock, SIOCGIFHWADDR, &ifr[i]) != -1) {
            printf("\tMAC address: ");
            for (int j = 0; j < 6; j++) {
                printf("%02X%s", (unsigned char) ifr[i].ifr_hwaddr.sa_data[j], (j == 5) ? "" : ":");
            }
            printf("\n");
        } else {
            printf("\tFailed to retrieve MAC address: %s\n", strerror(errno));
        }
    }

    // close the socket
    close(sock);

    return 0;
}