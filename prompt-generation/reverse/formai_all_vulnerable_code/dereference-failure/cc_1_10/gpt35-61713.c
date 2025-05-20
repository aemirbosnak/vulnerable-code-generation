//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define MAX_INTERFACES 64
#define MAX_BUFFER 1024

int main(void) {
    int i, sockfd, num_of_interfaces;
    struct ifconf ifconf;
    struct ifreq ifreq[MAX_INTERFACES];
    char buffer[MAX_BUFFER];

    // Create socket descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Fill in ifconf structure
    ifconf.ifc_buf = buffer;
    ifconf.ifc_len = MAX_BUFFER;
    if (ioctl(sockfd, SIOCGIFCONF, &ifconf) < 0) {
        perror("Error getting interface list");
        exit(1);
    }

    // Loop through the list of interfaces
    num_of_interfaces = ifconf.ifc_len / sizeof(struct ifreq);
    for (i = 0; i < num_of_interfaces; i++) {
        // Get the name of the interface
        printf("Interface Name: %s\n", ifreq[i].ifr_name);
        
        // Get the IP address of the interface
        if (ioctl(sockfd, SIOCGIFADDR, &ifreq[i]) < 0) {
            perror("Error getting interface address");
            exit(1);
        }
        struct sockaddr_in* addr = (struct sockaddr_in*)&ifreq[i].ifr_addr;
        printf("IP Address: %s\n", inet_ntoa(addr->sin_addr));
        
        // Get the MAC address of the interface
        if (ioctl(sockfd, SIOCGIFHWADDR, &ifreq[i]) < 0) {
            perror("Error getting interface MAC address");
            exit(1);
        }
        unsigned char mac[6];
        memcpy(mac, ifreq[i].ifr_hwaddr.sa_data, 6);
        printf("MAC Address: %02x:%02x:%02x:%02x:%02x:%02x\n", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

        printf("\n");
    }

    // Close socket descriptor
    close(sockfd);

    return 0;
}