//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <net/if.h>
#include <linux/wireless.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
    // Get the interface name
    char *interface = "wlan0";
    if (argc > 1) {
        interface = argv[1];
    }

    // Create a socket
    int sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    // Get the interface index
    struct ifreq ifr;
    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, interface, IFNAMSIZ);
    if (ioctl(sock, SIOCGIFINDEX, &ifr) < 0) {
        perror("ioctl");
        exit(1);
    }

    // Get the wireless statistics
    struct iwreq wrq;
    memset(&wrq, 0, sizeof(wrq));
    strncpy(wrq.ifr_name, interface, IFNAMSIZ);
    wrq.u.data.length = sizeof(struct iw_quality);
    wrq.u.data.pointer = (caddr_t)&wrq.u.qual;
    if (ioctl(sock, SIOCGIWPRIV, &wrq) < 0) {
        perror("ioctl");
        exit(1);
    }

    // Print the signal strength
    printf("Signal strength: %d dBm\n", wrq.u.qual.level);

    // Close the socket
    close(sock);

    return 0;
}