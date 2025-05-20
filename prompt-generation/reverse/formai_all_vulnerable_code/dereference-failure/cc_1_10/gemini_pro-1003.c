//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <linux/if_ether.h>
#include <linux/wireless.h>

#define DEV "wlp3s0"

int main(int argc, char **argv)
{
    int sock, err, rssi;
    struct iwreq wrq;
    struct ifreq ifr;
    char *interface = DEV;

    if (argc > 1) {
        interface = argv[1];
    }

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    strcpy(wrq.ifr_name, interface);
    err = ioctl(sock, SIOCGIWESSID, &wrq);
    if (err == -1) {
        perror("ioctl[SIOCGIWESSID]");
        return 1;
    }

    wrq.u.essid.pointer = malloc(wrq.u.essid.length + 1);
    if (wrq.u.essid.pointer == NULL) {
        perror("malloc");
        return 1;
    }

    err = ioctl(sock, SIOCGIWESSID, &wrq);
    if (err == -1) {
        perror("ioctl[SIOCGIWESSID]");
        return 1;
    }

    printf("ESSID: %s\n", wrq.u.essid.pointer);

    strcpy(ifr.ifr_name, interface);
    err = ioctl(sock, SIOCGIFTXQLEN, &ifr);
    if (err == -1) {
        perror("ioctl[SIOCGIFTXQLEN]");
        return 1;
    }

    printf("TX Queue Length: %d\n", ifr.ifr_ifru.ifru_ivalue);

    strcpy(ifr.ifr_name, interface);
    err = ioctl(sock, SIOCSIWCOMMIT, &ifr);
    if (err == -1) {
        perror("ioctl[SIOCSIWCOMMIT]");
        return 1;
    }

    strcpy(wrq.ifr_name, interface);
    err = ioctl(sock, SIOCGIWSTATS, &wrq);
    if (err == -1) {
        perror("ioctl[SIOCGIWSTATS]");
        return 1;
    }

    rssi = wrq.u.qual.level;

    printf("Signal Strength: %d dBm\n", rssi);

    close(sock);
    return 0;
}