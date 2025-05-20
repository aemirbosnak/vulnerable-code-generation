//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_INTERFACE_NAME_LEN 16
#define MAC_ADDR_LEN 6

int main() {
    int fd;
    struct ifreq ifr;
    unsigned char mac_address[MAC_ADDR_LEN];
    
    // Create a socket
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd < 0) {
        perror("Failed to create socket");
        exit(1);
    }
    
    // Get the list of interfaces
    struct if_nameindex *if_nidxs, *intf;
    if_nidxs = if_nameindex();
    if (if_nidxs == NULL) {
        perror("Failed to get interface list");
        exit(1);
    }
    
    // Iterate through each interface and print its name and MAC address
    for (intf = if_nidxs; intf && intf->if_name; ++intf) {
        // Clean up old memory
        memset(&ifr, 0, sizeof(ifr));
        memset(mac_address, 0, sizeof(mac_address));
        
        // Set the interface name
        strncpy(ifr.ifr_name, intf->if_name, MAX_INTERFACE_NAME_LEN-1);
        ifr.ifr_name[MAX_INTERFACE_NAME_LEN-1] = 0;

        // Get the MAC address for this interface
        if (ioctl(fd, SIOCGIFHWADDR, &ifr) == 0) {
            memcpy(mac_address, ifr.ifr_hwaddr.sa_data, MAC_ADDR_LEN);
            printf("Interface %s has MAC address ", ifr.ifr_name);
            for (int i = 0; i < MAC_ADDR_LEN; ++i) {
                printf("%02x", mac_address[i]);
                if (i < MAC_ADDR_LEN-1) {
                    printf(":");
                }
            }
            printf("\n");
        } else {
            perror("Failed to get MAC address");
        }
    }
    
    // Clean up
    if_freenameindex(if_nidxs);
    close(fd);
    
    return 0;
}