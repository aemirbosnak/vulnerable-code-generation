//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <unistd.h>
#include <linux/wireless.h>

#define INTERFACE "wlan0"

int main(int argc, char *argv[]) {

    struct iwreq pwrq;

    int sockfd;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    strcpy(pwrq.ifr_ifrn.ifrn_name, INTERFACE);

    if(ioctl(sockfd, SIOCGIWNAME, &pwrq) != -1) {
        printf("Wireless interface %s is present\n", INTERFACE);
    } else {
        printf("Wireless interface %s is not present\n", INTERFACE);
        exit(1);
    }

    printf("\nScanning for wireless networks...\n");

    if(ioctl(sockfd, SIOCSIWSCAN, &pwrq) < 0) {
        printf("Error scanning for wireless networks: %s\n", strerror(errno));
        exit(1);
    }

    char buffer[512];
    memset(buffer, 0, sizeof(buffer));
    pwrq.u.essid.pointer = buffer;
    pwrq.u.essid.length = IW_ESSID_MAX_SIZE + 1;

    while(ioctl(sockfd, SIOCGIWSCAN, &pwrq) != -1) {

        printf("Wireless network name: %s\n", pwrq.u.essid.pointer);
        printf("Signal strength: %d dBm\n", pwrq.u.qual.level);

        memset(buffer, 0, sizeof(buffer));
        pwrq.u.essid.pointer = buffer;
        pwrq.u.essid.length = IW_ESSID_MAX_SIZE + 1;
    }

    close(sockfd);
    return 0;
}