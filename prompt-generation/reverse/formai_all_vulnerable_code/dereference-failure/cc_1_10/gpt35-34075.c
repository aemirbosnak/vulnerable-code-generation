//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <net/if.h>
#include <linux/wireless.h>
#include <errno.h>

int scanWirelessNetworks(char* interfaceName) {
    int sockFd = socket(AF_INET, SOCK_DGRAM, 0);
    int numNetworks = 0;
    
    if (sockFd != -1) {
        // Prepare a request to list all available wireless networks
        struct iwreq iwReq;
        strncpy(iwReq.ifr_name, interfaceName, IFNAMSIZ);
        iwReq.u.data.pointer = NULL;
        iwReq.u.data.length = 0;
        iwReq.u.data.flags = 0;
        
        // Issue the request to the kernel
        if (ioctl(sockFd, SIOCSIWSCAN, &iwReq) != -1) {
            sleep(5); // Wait for the scanning to finish
            
            // Prepare a request to get the results of the scan
            iwReq.u.data.pointer = malloc (1024 * sizeof(char));
            iwReq.u.data.length = 1024;
            iwReq.u.data.flags = 0;
            
            // Issue the request to the kernel
            if (ioctl(sockFd, SIOCGIWSCAN, &iwReq) != -1) {
                // Iterate through the wireless networks and print their details
                struct iw_event* event = (struct iw_event*)iwReq.u.data.pointer;
                while (event->cmd != SIOCGIWSCAN) {
                    if (event->cmd == SIOCGIWAP) {
                        struct sockaddr* address = (struct sockaddr*)&(event->u.ap_addr);
                        char macAddr[20];
                        sprintf(macAddr, "%02X:%02X:%02X:%02X:%02X:%02X",
                                       (unsigned char)address->sa_data[0],
                                       (unsigned char)address->sa_data[1],
                                       (unsigned char)address->sa_data[2],
                                       (unsigned char)address->sa_data[3],
                                       (unsigned char)address->sa_data[4],
                                       (unsigned char)address->sa_data[5]);
                        printf("Network %d: MAC Address: %s, Signal Strength: %d dBm\n",
                               numNetworks+1, macAddr, (event+2)->u.qual.level);
                        numNetworks++;
                    }
                    event = (struct iw_event*)((char*)event + event->len);
                }
            } else {
                printf("Failed to get wireless networks scan results: %s\n", strerror(errno));
            }
            free(iwReq.u.data.pointer);
        } else {
            printf("Failed to scan wireless networks: %s\n", strerror(errno));
        }
        close(sockFd);
    } else {
        printf("Failed to open socket: %s\n", strerror(errno));
    }
    
    return numNetworks;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <wireless interface name>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    char* interfaceName = argv[1];
    printf("Scanning for wireless networks on interface %s...\n", interfaceName);
    
    int numNetworks = scanWirelessNetworks(interfaceName);
    
    printf("Found %d wireless networks.\n", numNetworks);
    return EXIT_SUCCESS;
}