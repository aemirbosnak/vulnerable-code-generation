//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <linux/wireless.h>

#define MAX_INTERFACE_NAME_LEN 8
#define MAX_BUF 2048

/* Function to get Wi-Fi signal strength */
int getWifiSignalStrength(char *iface)
{
    int sock;
    struct iwreq iw;
    memset(&iw, 0, sizeof(iw));
    strncpy(iw.ifr_name, iface, IFNAMSIZ - 1);
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket");
        return 0;
    }
    if (ioctl(sock, SIOCGIWNAME, &iw) < 0)
    {
        perror("ioctl");
        close(sock);
        return 0;
    }
    if (ioctl(sock, SIOCGIWSTATS, &iw) < 0)
    {
        perror("ioctl");
        close(sock);
        return 0;
    }
    close(sock);
    return iw.u.qual.level;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <interface_name>\n", argv[0]);
        return 1;
    }
    /* Get Wi-Fi signal strength */
    int signal_strength = getWifiSignalStrength(argv[1]);
    if (signal_strength > 0)
    {
        printf("Wi-Fi signal strength: %d dBm\n", signal_strength);
    }
    else
    {
        printf("Error getting Wi-Fi signal strength: %s\n", strerror(errno));
    }
    return 0;
}