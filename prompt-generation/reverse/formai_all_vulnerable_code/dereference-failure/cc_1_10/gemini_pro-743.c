//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/wireless.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    struct iwreq wrq;
    memset(&wrq, 0, sizeof(struct iwreq));

    strncpy(wrq.ifr_name, argv[1], IFNAMSIZ);
    if (ioctl(socket(PF_INET, SOCK_DGRAM, 0), SIOCGIWESSID, &wrq) < 0) {
        perror("ioctl(SIOCGIWESSID)");
        return 1;
    }

    double max_signal_strength = -128;
    double min_signal_strength = 0;
    double average_signal_strength = 0;
    int count = 0;
    char *start = (char *)wrq.u.essid.pointer;
    char *end = start + wrq.u.essid.length;
    while (start != end) {
        double signal_strength = 0;
        for (int i = 0; i < 4; i++) {
            signal_strength += ((unsigned char)*start++) << (8*i);
        }
        signal_strength /= 100;
        max_signal_strength = fmax(max_signal_strength, signal_strength);
        min_signal_strength = fmin(min_signal_strength, signal_strength);
        average_signal_strength += signal_strength;
        count++;
    }

    average_signal_strength /= count;

    printf("Interface: %s\n", argv[1]);
    printf("Maximum signal strength: %.1f dBm\n", max_signal_strength);
    printf("Minimum signal strength: %.1f dBm\n", min_signal_strength);
    printf("Average signal strength: %.1f dBm\n", average_signal_strength);

    return 0;
}