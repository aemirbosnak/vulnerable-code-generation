//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <net/ethernet.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    int sockfd, num_interfaces, i;
    struct ifreq *ifreq;
    struct ifconf ifc;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    ifc.ifc_len = sizeof(struct ifreq) * 10;
    ifc.ifc_buf = malloc(ifc.ifc_len);
    if (ifc.ifc_buf == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    if (ioctl(sockfd, SIOCGIFCONF, &ifc) == -1) {
        perror("ioctl");
        return EXIT_FAILURE;
    }

    num_interfaces = ifc.ifc_len / sizeof(struct ifreq);

    printf("Interface  IP Address  MAC Address\n");
    for (i = 0; i < num_interfaces; i++) {
        ifreq = &ifc.ifc_req[i];
        if (ifreq->ifr_addr.sa_family == AF_INET) {
            printf("%-10s  %15s  %17s\n", ifreq->ifr_name,
                   inet_ntoa(((struct sockaddr_in *)&ifreq->ifr_addr)->sin_addr),
                   ether_ntoa((struct ether_addr *)ifreq->ifr_hwaddr.sa_data));
        }
    }

    free(ifc.ifc_buf);
    close(sockfd);
    return EXIT_SUCCESS;
}