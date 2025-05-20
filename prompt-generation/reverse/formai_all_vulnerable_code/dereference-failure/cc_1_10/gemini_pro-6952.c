//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_INTERFACES 10

void print_interface_info(int sock, struct ifreq *ifr)
{
    if (ioctl(sock, SIOCGIFFLAGS, ifr) == -1) {
        perror("ioctl(SIOCGIFFLAGS)");
        return;
    }

    printf("Interface: %s\n", ifr->ifr_name);
    printf("  Flags: ");
    if (ifr->ifr_flags & IFF_UP) {
        printf("UP ");
    }
    if (ifr->ifr_flags & IFF_BROADCAST) {
        printf("BROADCAST ");
    }
    if (ifr->ifr_flags & IFF_MULTICAST) {
        printf("MULTICAST ");
    }
    if (ifr->ifr_flags & IFF_LOOPBACK) {
        printf("LOOPBACK ");
    }
    if (ifr->ifr_flags & IFF_POINTOPOINT) {
        printf("POINTOPOINT ");
    }
    if (ifr->ifr_flags & IFF_NOARP) {
        printf("NOARP ");
    }
    printf("\n");

    if (ioctl(sock, SIOCGIFADDR, ifr) == -1) {
        perror("ioctl(SIOCGIFADDR)");
        return;
    }

    printf("  IP Address: %s\n", inet_ntoa(((struct sockaddr_in *)&ifr->ifr_addr)->sin_addr));

    if (ioctl(sock, SIOCGIFNETMASK, ifr) == -1) {
        perror("ioctl(SIOCGIFNETMASK)");
        return;
    }

    printf("  Netmask: %s\n", inet_ntoa(((struct sockaddr_in *)&ifr->ifr_netmask)->sin_addr));

    if (ioctl(sock, SIOCGIFHWADDR, ifr) == -1) {
        perror("ioctl(SIOCGIFHWADDR)");
        return;
    }

    printf("  MAC Address: ");
    for (int i = 0; i < 6; i++) {
        printf("%02X", (unsigned char)ifr->ifr_hwaddr.sa_data[i]);
        if (i < 5) {
            printf(":");
        }
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int sock;
    struct ifreq ifr;
    char *interface;

    if (argc > 1) {
        interface = argv[1];
    } else {
        interface = "wlan0";
    }

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        perror("socket()");
        return EXIT_FAILURE;
    }

    strncpy(ifr.ifr_name, interface, sizeof(ifr.ifr_name));

    print_interface_info(sock, &ifr);

    close(sock);

    return EXIT_SUCCESS;
}