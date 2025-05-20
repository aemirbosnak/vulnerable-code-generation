//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netdb.h>
#include <errno.h>

#define BUF_SIZE 1024

typedef struct {
    char ifname[IF_NAMESIZE];
    char mac[18];
    char ip[16];
} network_info;

void scan_network(int sock) {
    char buf[BUF_SIZE];
    struct ifreq ifr;
    int ret, i = 0;

    memset(&ifr, 0, sizeof(ifr));
    strcpy(ifr.ifr_name, "eth0");

    ret = ioctl(sock, SIOCGIFHWADDR, &ifr);
    if (ret < 0) {
        printf("Error: %s\n", strerror(errno));
    } else {
        sprintf(ifr.ifr_name, "eth%d", i++);
        while (ioctl(sock, SIOCGIFHWADDR, &ifr) == 0) {
            struct sockaddr_in *sin = (struct sockaddr_in *)&ifr.ifr_addr;
            char *ip_str = inet_ntoa(sin->sin_addr);

            if (ip_str!= NULL) {
                printf("Interface: %s\n", ifr.ifr_name);
                printf("MAC Address: %s\n", ifr.ifr_hwaddr.sa_data);
                printf("IP Address: %s\n", ip_str);
            }

            ret = ioctl(sock, SIOCGIFHWADDR, &ifr);
        }
    }
}

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    scan_network(sock);

    close(sock);
    return 0;
}