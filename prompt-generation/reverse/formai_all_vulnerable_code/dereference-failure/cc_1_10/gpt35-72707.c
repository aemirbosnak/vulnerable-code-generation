//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <net/if.h>
#include <netinet/ether.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/if_ether.h>

#define ETHERTYPE_IP 0x0800

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s [interface]\n", argv[0]);
        exit(-1);
    }

    char* interface = argv[1];
    int sock_fd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sock_fd < 0) {
        perror("Error creating socket");
        exit(-1);
    }

    struct ifreq ifr;
    strncpy(ifr.ifr_name, interface, IFNAMSIZ);
    if (ioctl(sock_fd, SIOCGIFFLAGS, &ifr) < 0) {
        perror("Error getting interface flags");
        exit(-1);
    }
    ifr.ifr_flags |= IFF_PROMISC;
    if (ioctl(sock_fd, SIOCSIFFLAGS, &ifr) < 0) {
        perror("Error setting interface flags");
        exit(-1);
    }

    while (1) {
        char buffer[2048];
        struct ethhdr *eth_header = (struct ethhdr*)buffer;
        struct iphdr *ip_header = NULL;

        int n = recvfrom(sock_fd, buffer, sizeof(buffer), 0, NULL, NULL);
        if (n < 0) {
            perror("recvfrom");
            continue;
        }

        if (eth_header->h_proto == htons(ETHERTYPE_IP)) {
            ip_header = (struct iphdr *)(buffer + sizeof(struct ethhdr));
            printf("Received packet on interface: %s\n", interface);
            printf("IP Source: %s\n", inet_ntoa(*((struct in_addr*)&ip_header->saddr)));
            printf("IP Destination: %s\n", inet_ntoa(*((struct in_addr*)&ip_header->daddr)));
            printf("\n");
        }
    }

    close(sock_fd);
    return 0;
}