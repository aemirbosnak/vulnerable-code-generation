//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <netinet/if_ether.h>
#include <netpacket/packet.h>

#define MAX_PACKET_SIZE 65536

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd, n;
    char buffer[MAX_PACKET_SIZE];
    struct sockaddr_ll addr;
    socklen_t addr_len = sizeof(addr);
    struct ifreq ifr;
    struct hostent *h;
    char *interface = argv[1];

    sockfd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, interface, IFNAMSIZ - 1);
    if (ioctl(sockfd, SIOCGIFINDEX, &ifr) < 0) {
        perror("ioctl");
        exit(EXIT_FAILURE);
    }

    addr.sll_family = AF_PACKET;
    addr.sll_ifindex = ifr.ifr_ifindex;
    addr_len = sizeof(addr);

    if (bind(sockfd, (struct sockaddr *)&addr, addr_len) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    printf("Netowrk Scanner Initialized.\n");

    while (1) {
        n = recvfrom(sockfd, buffer, MAX_PACKET_SIZE, 0, (struct sockaddr *)&addr, &addr_len);
        if (n < 0) {
            perror("recvfrom");
            exit(EXIT_FAILURE);
        }

        printf("Packet received from %s\n", inet_ntoa(*(struct in_addr *)&addr.sll_addr[0]));

        h = gethostbyaddr((char *)&addr.sll_addr, sizeof(addr.sll_addr), AF_PACKET);
        if (h) {
            printf("Hostname: %s\n", h->h_name);
        }
    }

    return 0;
}