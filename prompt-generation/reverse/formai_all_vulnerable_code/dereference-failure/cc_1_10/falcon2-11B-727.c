//Falcon2-11B DATASET v1.0 Category: Wireless Network Scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <net/if.h>
#include <linux/if_packet.h>
#include <net/ethernet.h>
#include <netinet/ether.h>

int main() {
    int sockfd, nbytes, i, j, k;
    char ip[INET_ADDRSTRLEN];
    struct ifreq ifr;
    struct sockaddr_ll ll_addr;
    struct ether_header *eh;

    int port = 9999;

    if (sockfd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL))) {
        printf("Socket Created\n");
    }

    if (ioctl(sockfd, SIOCGIFINDEX, &ifr) < 0) {
        perror("ioctl(SIOCGIFINDEX)");
        exit(1);
    }

    if (ioctl(sockfd, SIOCGIFHWADDR, &ifr) < 0) {
        perror("ioctl(SIOCGIFHWADDR)");
        exit(1);
    }

    memset(&ll_addr, 0, sizeof(struct sockaddr_ll));
    ll_addr.sll_family = AF_PACKET;
    ll_addr.sll_protocol = htons(ETH_P_ALL);
    ll_addr.sll_ifindex = ifr.ifr_ifindex;

    while (1) {
        memset(&ll_addr, 0, sizeof(struct sockaddr_ll));
        if (ioctl(sockfd, SIOCGIFINDEX, &ifr) < 0) {
            perror("ioctl(SIOCGIFINDEX)");
            exit(1);
        }

        if (ioctl(sockfd, SIOCGIFHWADDR, &ifr) < 0) {
            perror("ioctl(SIOCGIFHWADDR)");
            exit(1);
        }

        ll_addr.sll_family = AF_PACKET;
        ll_addr.sll_ifindex = ifr.ifr_ifindex;

        if ((nbytes = recvfrom(sockfd, &ll_addr, sizeof(struct sockaddr_ll), 0, NULL, NULL)) > 0) {
            if (nbytes > 14) {
                eh = (struct ether_header *)&ll_addr;
                printf("Ethernet frame received:\n");
                printf("  Source MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n",
                    eh->ether_dhost[0], eh->ether_dhost[1], eh->ether_dhost[2],
                    eh->ether_dhost[3], eh->ether_dhost[4], eh->ether_dhost[5]);
                printf("  Destination MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n",
                    eh->ether_shost[0], eh->ether_shost[1], eh->ether_shost[2],
                    eh->ether_shost[3], eh->ether_shost[4], eh->ether_shost[5]);
                printf("  Ethernet type: %d\n", ntohs(eh->ether_type));
                printf("  Source IP address: %s\n", inet_ntoa(((struct sockaddr_in *)&ll_addr)->sin_addr));
                printf("  Destination IP address: %s\n", inet_ntoa(((struct sockaddr_in *)&ll_addr)->sin_addr));
            }
        }
    }
    close(sockfd);
    return 0;
}