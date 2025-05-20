//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <linux/wireless.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct iwreq iw;

    if (argc != 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    memset(&iw, 0, sizeof(iw));
    strncpy(iw.ifr_name, argv[1], IFNAMSIZ - 1);

    if (ioctl(sockfd, SIOCGIWNAME, &iw) == -1) {
        perror("ioctl");
        printf("%s is not a wireless interface\n", argv[1]);
        return 1;
    }

    printf("Analyzing Wi-Fi signal strength on %s...\n", argv[1]);

    while (1) {
        if (ioctl(sockfd, SIOCGIWSCAN, &iw) == -1) {
            perror("ioctl");
            return 1;
        }

        struct iw_scan_req *req = (struct iw_scan_req *) iw.u.data.pointer;
        struct iw_event *event = (struct iw_event *) (req + 1);
        int idx = 0;
        int len = iw.u.data.length;

        while (idx < len) {
            event = (struct iw_event *) ((char *) req + idx);

            if (event->cmd == SIOCGIWAP) {
                char mac[18];
                sprintf(mac, "%.2X:%.2X:%.2X:%.2X:%.2X:%.2X",
                        ((unsigned char *) event->u.ap_addr.sa_data)[0],
                        ((unsigned char *) event->u.ap_addr.sa_data)[1],
                        ((unsigned char *) event->u.ap_addr.sa_data)[2],
                        ((unsigned char *) event->u.ap_addr.sa_data)[3],
                        ((unsigned char *) event->u.ap_addr.sa_data)[4],
                        ((unsigned char *) event->u.ap_addr.sa_data)[5]);

                int signal_dbm = event->u.qual.level - 256;
                float signal_percent = (float) (signal_dbm + 100) / 100.0;

                printf("%s: %ddBm (%.0f%%)\n", mac, signal_dbm, signal_percent * 100.0);
            }

            idx += event->len;
        }

        printf("\n");
        sleep(1);
    }

    return 0;
}