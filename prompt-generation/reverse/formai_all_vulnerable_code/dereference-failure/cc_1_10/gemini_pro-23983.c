//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/if.h>
#include <linux/wireless.h>

#define MAX_SSID_LEN 32
#define MAX_BSSID_LEN 18
#define MAX_ESSID_LEN 32

// Wi-Fi signal strength analyzer
int main(int argc, char **argv) {
    // Create a socket for Wi-Fi operations
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Get the interface name from the command line
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }
    char *interface = argv[1];

    // Get the interface index
    struct ifreq ifr;
    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, interface, IFNAMSIZ);
    if (ioctl(sock, SIOCGIFINDEX, &ifr) < 0) {
        perror("ioctl(SIOCGIFINDEX)");
        return EXIT_FAILURE;
    }

    // Get the wireless statistics
    struct iwreq wrq;
    memset(&wrq, 0, sizeof(wrq));
    strncpy(wrq.ifr_name, interface, IFNAMSIZ);
    wrq.u.data.pointer = (char *)malloc(sizeof(struct iw_statistics));
    if (wrq.u.data.pointer == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }
    wrq.u.data.length = sizeof(struct iw_statistics);
    if (ioctl(sock, SIOCGIWSTATS, &wrq) < 0) {
        perror("ioctl(SIOCGIWSTATS)");
        return EXIT_FAILURE;
    }

    // Print the wireless statistics
    struct iw_statistics *stats = (struct iw_statistics *)wrq.u.data.pointer;
    printf("Interface: %s\n", interface);
    printf("Signal level: %d dBm\n", stats->qual.qual);
    printf("Noise level: %d dBm\n", stats->qual.noise);
    printf("Signal-to-noise ratio: %d dB\n", stats->qual.noise - stats->qual.qual);

    // Free the allocated memory
    free(wrq.u.data.pointer);

    // Close the socket
    close(sock);

    return EXIT_SUCCESS;
}