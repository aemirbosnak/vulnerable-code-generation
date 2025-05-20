//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <linux/wireless.h>

#define MAX_SSID_LEN 32
#define DEFAULT_IFACE "wlan0"

int main(int argc, char *argv[]) {
    char ifname[IFNAMSIZ] = DEFAULT_IFACE;
    if (argc > 1) {
        strncpy(ifname, argv[1], IFNAMSIZ);
        ifname[IFNAMSIZ-1] = '\0';
    }

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return 1;
    }

    struct iwreq req;
    strncpy(req.ifr_name, ifname, IFNAMSIZ);

    if (ioctl(sock, SIOCGIWSCAN, &req) == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    struct iw_event iwe;
    char buf[4096];
    int len;

    while ((len = recv(sock, buf, sizeof(buf), 0)) > 0) {
        char *ptr = buf;
        while (ptr < buf + len) {
            memcpy(&iwe, ptr, IW_EV_LCP_LEN);
            ptr += iwe.len;

            if (iwe.cmd == SIOCGIWAP) {
                struct sockaddr *sap = (struct sockaddr *)&iwe.u.ap_addr;
                char mac[18];
                snprintf(mac, sizeof(mac), "%02x:%02x:%02x:%02x:%02x:%02x",
                         sap->sa_data[0], sap->sa_data[1], sap->sa_data[2],
                         sap->sa_data[3], sap->sa_data[4], sap->sa_data[5]);

                fprintf(stdout, "Access point MAC address: %s\n", mac);
            } else if (iwe.cmd == SIOCGIWESSID) {
                char ssid[MAX_SSID_LEN+1];
                memcpy(ssid, iwe.u.essid.pointer, iwe.u.essid.length);
                ssid[iwe.u.essid.length] = '\0';

                fprintf(stdout, "SSID: %s\n", ssid);
            }
        }
    }

    close(sock);
    return 0;
}