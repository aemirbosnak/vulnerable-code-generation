//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <net/if.h>
#include <ifaddrs.h>

#define MAX_IFACE_NAME_LEN 16
#define MAX_IFACE_ADDR_LEN 46
#define MAX_SSID_LEN 32

typedef struct {
    char iface_name[MAX_IFACE_NAME_LEN];
    char iface_addr[MAX_IFACE_ADDR_LEN];
    char ssid[MAX_SSID_LEN];
} iface_info_t;

int get_iface_info(iface_info_t *iface_info) {
    struct ifaddrs *ifaddr, *ifa;
    int sockfd, ret;
    char host[NI_MAXHOST];
    char service[NI_MAXSERV];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        printf("Error: %s\n", strerror(errno));
        return -1;
    }

    ret = getifaddrs(&ifaddr);
    if (ret < 0) {
        printf("Error: %s\n", strerror(errno));
        close(sockfd);
        return -1;
    }

    for (ifa = ifaddr; ifa!= NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL)
            continue;

        if (ifa->ifa_addr->sa_family!= AF_INET)
            continue;

        if (getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), host, NI_MAXHOST, service, NI_MAXSERV, 0)) {
            printf("Error: %s\n", gai_strerror(ret));
            freeifaddrs(ifaddr);
            close(sockfd);
            return -1;
        }

        strncpy(iface_info->iface_name, ifa->ifa_name, MAX_IFACE_NAME_LEN - 1);
        strncpy(iface_info->iface_addr, host, MAX_IFACE_ADDR_LEN - 1);
        strncpy(iface_info->ssid, "", MAX_SSID_LEN - 1);

        printf("Interface: %s\nIP Address: %s\nSSID: %s\n", iface_info->iface_name, iface_info->iface_addr, iface_info->ssid);
    }

    freeifaddrs(ifaddr);
    close(sockfd);

    return 0;
}

int main(int argc, char *argv[]) {
    iface_info_t iface_info;

    if (get_iface_info(&iface_info) < 0) {
        return 1;
    }

    return 0;
}