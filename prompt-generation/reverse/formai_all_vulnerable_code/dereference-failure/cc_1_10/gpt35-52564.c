//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define MAX_INTERFACE_NAME_SIZE 16

int main()
{
    int sock;
    struct ifreq ifr;

    // Create a socket for the wireless interface
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        printf("Cannot create socket\n");
        return 1;
    }

    // Scan through all network interfaces
    for (int i = 1; i <= 64; i++) {
        char if_name[MAX_INTERFACE_NAME_SIZE];
        snprintf(if_name, MAX_INTERFACE_NAME_SIZE, "wlan%d", i);

        strcpy(ifr.ifr_name, if_name);

        if (ioctl(sock, SIOCGIFFLAGS, &ifr) == 0) {
            if (ifr.ifr_flags & IFF_UP) {
                printf("%s is up\n", if_name);
            } else {
                printf("%s is down\n", if_name);
            }

            if (ifr.ifr_flags & IFF_RUNNING) {
                printf("%s is running\n", if_name);
            } else {
                printf("%s is not running\n", if_name);
            }

            if (ifr.ifr_flags & IFF_PROMISC) {
                printf("%s is in promiscuous mode\n", if_name);
            } else {
                printf("%s is not in promiscuous mode\n", if_name);
            }

            if (ifr.ifr_flags & IFF_LOOPBACK) {
                printf("%s is a loopback device\n", if_name);
            } else {
                printf("%s is not a loopback device\n", if_name);
            }

            printf("\n");
        }
    }

    close(sock);

    return 0;
}