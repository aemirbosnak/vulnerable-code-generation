//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <linux/wireless.h>

#define MAX_STR_LEN 100

// Function to get signal strength from a wireless device
int get_signal_strength(const char* device_name) {
    int sock = -1;
    struct ifreq ifr;
    int ret = -1;

    // Open a socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        perror("socket");
        return -1;
    }

    // Set the interface name
    strncpy(ifr.ifr_name, device_name, IFNAMSIZ-1);

    // Get the signal strength
    ret = ioctl(sock, SIOCGIWSTATS, &ifr);
    if (ret == -1) {
        perror("ioctl");
        close(sock);
        return -1;
    }

    // Close the socket
    close(sock);

    return 0;
}

// Function to print signal strength in a human-readable format
void print_signal_strength(int quality, int level) {
    int quality_percent = quality * 100 / 70;
    int level_percent = level * 100 / 255;

    if (quality < 0) {
        printf("Signal quality: unknown (quality: %d)\n", quality);
    } else if (quality == 0) {
        printf("Signal quality: none\n");
    } else {
        printf("Signal quality: %d (%d%%)\n", quality, quality_percent);
    }

    if (level < 0) {
        printf("Signal level: unknown (level: %d)\n", level);
    } else {
        printf("Signal level: %d (%d%%)\n", level, level_percent);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <wireless_device_name>\n", argv[0]);
        return -1;
    }

    int ret = get_signal_strength(argv[1]);
    if (ret == -1) {
        return -1;
    }

    print_signal_strength(0, 0);

    return 0;
}