//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <linux/wireless.h>

void scan_wireless_networks(int sock_fd, struct iwreq *wrq, char *interface, int max_scan_attempts, int current_attempt) {
    if (current_attempt >= max_scan_attempts) {
        printf("Wireless network scan failed.\n");
        return;
    }

    memset(wrq, 0, sizeof(struct iwreq));
    strncpy(wrq->ifr_name, interface, IFNAMSIZ);

    wrq->u.data.length = IW_SCAN_MAX_DATA;
    if (ioctl(sock_fd, SIOCSIWSCAN, wrq) < 0) {
        printf("Wireless network scan failed: %s\n", strerror(errno));
        return;
    }

    sleep(5);

    char buffer[8192];
    wrq->u.data.pointer = buffer;
    if (ioctl(sock_fd, SIOCGIWSCAN, wrq) < 0) {
        printf("Wireless network scan failed: %s\n", strerror(errno));
        return;
    }

    int results_len = wrq->u.data.length;
    struct iw_event *event = (struct iw_event *) buffer;
    while (event < (struct iw_event *)(buffer + results_len)) {
        if (event->cmd == SIOCGIWAP) {
            char address[6];
            memcpy(address, &(event->u.ap_addr), sizeof(address));
            printf("Found wireless network with BSSID: %02x:%02x:%02x:%02x:%02x:%02x\n",
                   address[0], address[1], address[2], address[3], address[4], address[5]);
        }
        event = (struct iw_event *)((char *)event + event->len);
    }

    current_attempt += 1;
    scan_wireless_networks(sock_fd, wrq, interface, max_scan_attempts, current_attempt);
}

int main(int argc, char **argv) {
    char *interface = argv[1];

    int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock_fd < 0) {
        printf("Error opening socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    struct iwreq wrq;
    int max_scan_attempts = 5;
    int current_attempt = 0;
    scan_wireless_networks(sock_fd, &wrq, interface, max_scan_attempts, current_attempt);

    close(sock_fd);

    return 0;
}