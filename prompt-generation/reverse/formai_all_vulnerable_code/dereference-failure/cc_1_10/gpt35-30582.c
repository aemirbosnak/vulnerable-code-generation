//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: scientific
/**
 * This unique C program is a wireless network scanner that scans for active WiFi access points in range and displays their details.
 * The program uses the Linux Wireless Extension API to query wireless network information like signal strength, SSID, and MAC address.
 *
 * Author: AI Chatbot
 * Date: September 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <linux/wireless.h>
#include <string.h>

int main() {
    int sockfd;
    struct iwreq wrq;
    char *interface_name = "wlan0";
    int i, j;

    // Open a socket for communication with the wireless interface
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        printf("Error opening socket: %s\n", strerror(errno));
        return -1;
    }

    // Set the interface name for the wireless scanner
    memset(&wrq, 0, sizeof(wrq));
    strncpy(wrq.ifr_name, interface_name, IFNAMSIZ);

    // Scan for active access points and print out their details
    for (i = 0; i < 10; i++) {
        if (ioctl(sockfd, SIOCGIWSCAN, &wrq) == -1) {
            printf("Error scanning for wireless networks: %s\n", strerror(errno));
            return -1;
        }

        // Retrieve the scan results
        if (ioctl(sockfd, SIOCGIWSCAN, &wrq) == -1) {
            printf("Error retrieving scan results: %s\n", strerror(errno));
            return -1;
        }

        // Print out the scan results
        struct iw_event iwe;
        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));
        i = 0;
        while (1) {
            memcpy(&iwe, buffer + i, sizeof(iwe));
            if (iwe.cmd == SIOCGIWAP) {
                unsigned char *mac = (unsigned char *) iwe.u.ap_addr.sa_data;

                printf("MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
            } else if (iwe.cmd == SIOCGIWESSID) {
                char ssid[32];
                memcpy(ssid, iwe.u.essid.pointer, iwe.u.essid.length);
                ssid[iwe.u.essid.length] = '\0';

                printf("SSID: %s\n", ssid);
            } else if (iwe.cmd == SIOCGIWRANGE) {
                struct iw_range range;
                memcpy(&range, iwe.u.name, sizeof(struct iw_range));

                printf("Max signal strength: %d dbm\n", range.max_qual);
            }

            i += iwe.len;
            if (i >= sizeof(buffer)) {
                break;
            }
        }

        // Pause for a brief period before scanning again
        sleep(1);
    }

    return 0;
}