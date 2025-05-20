//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <linux/wireless.h>

/* Function to scan for wireless networks */
void scan_wireless_networks(int sock_interface)
{
    struct iwreq iw_request;
    char buffer[1024];

    memset(&iw_request, 0, sizeof(iw_request));
    strncpy(iw_request.ifr_name, "wlan0", IFNAMSIZ);

    iw_request.u.data.pointer = buffer;
    iw_request.u.data.length = sizeof(buffer);
    iw_request.u.data.flags = 0;

    if (ioctl(sock_interface, SIOCGIWSCAN, &iw_request) < 0) {
        perror("ioctl[SIOCSIWSCAN]");
        exit(EXIT_FAILURE);
    }

    struct iw_event *event = (struct iw_event*)buffer;
    while (event->cmd != SIOCGIWSCAN) {
        if (event->cmd == SIOCGIWAP) {
            struct sockaddr *ap_addr = (struct sockaddr*)&event->u.ap_addr;
            char ap_addr_str[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &(((struct sockaddr_in*)ap_addr)->sin_addr), ap_addr_str, sizeof(ap_addr_str));

            printf("Found BSSID: %s\n", ap_addr_str);
        }

        event = (struct iw_event*)((char*)event + IW_EV_LCP_LEN + event->len);
    }
}

int main()
{
    /* Create a socket for wireless interface */
    int sock_interface;
    if ((sock_interface = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    /* Scan the wireless networks */
    scan_wireless_networks(sock_interface);

    /* Close the socket */
    close(sock_interface);

    return 0;
}