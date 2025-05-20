//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <netinet/in.h>
#include <linux/wireless.h>

#define MAX_INTERFACES 64

int main(void) {
    int sock_fd, interface_count, i;
    struct ifconf ifconf;
    struct ifreq ifreq[MAX_INTERFACES];
    struct iwreq iwreq;

    // Create a socket for the wireless network scanner
    if ((sock_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Use ioctl to get a list of all network interfaces
    ifconf.ifc_buf = (char *)ifreq;
    ifconf.ifc_len = sizeof(ifreq);
    if (ioctl(sock_fd, SIOCGIFCONF, &ifconf) < 0) {
        fprintf(stderr, "Error getting interface list: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Calculate the number of interfaces in the list
    interface_count = ifconf.ifc_len / sizeof(struct ifreq);

    // Print the name and IP address of each wireless interface
    for (i = 0; i < interface_count; i++) {
        if (ifreq[i].ifr_addr.sa_family != AF_INET) {
            continue;
        }

        strncpy(iwreq.ifr_name, ifreq[i].ifr_name, IFNAMSIZ);

        if (ioctl(sock_fd, SIOCGIWNAME, &iwreq) < 0) {
            continue;
        }

        printf("%s:\n", ifreq[i].ifr_name);

        if (ioctl(sock_fd, SIOCGIFADDR, &ifreq[i]) < 0) {
            fprintf(stderr, "Error getting IP address for %s: %s\n",
                    ifreq[i].ifr_name, strerror(errno));
            continue;
        }

        printf("\tIP Address: %s\n", inet_ntoa(((struct sockaddr_in *)&ifreq[i].ifr_addr)->sin_addr));
    }

    close(sock_fd);

    return 0;
}