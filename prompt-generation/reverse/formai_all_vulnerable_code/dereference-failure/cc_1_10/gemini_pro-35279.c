//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <sys/ioctl.h>
#include <linux/if.h>
#include <linux/if_ether.h>
#include <linux/if_packet.h>

#define ETH_P_ALL 0x0003

struct decentralized_firewall {
    int sockfd;
    struct sockaddr_ll saddr;
    struct ifreq ifr;
};

int decentralized_firewall_init(struct decentralized_firewall *firewall, char *iface) {
    firewall->sockfd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (firewall->sockfd < 0) {
        perror("socket");
        return -1;
    }

    memset(&firewall->ifr, 0, sizeof(firewall->ifr));
    strncpy(firewall->ifr.ifr_name, iface, IFNAMSIZ);
    if (ioctl(firewall->sockfd, SIOCGIFINDEX, &firewall->ifr) < 0) {
        perror("ioctl");
        return -1;
    }

    memset(&firewall->saddr, 0, sizeof(firewall->saddr));
    firewall->saddr.sll_family = AF_PACKET;
    firewall->saddr.sll_protocol = htons(ETH_P_ALL);
    firewall->saddr.sll_ifindex = firewall->ifr.ifr_ifindex;

    return 0;
}

void decentralized_firewall_loop(struct decentralized_firewall *firewall) {
    char buf[1500];
    while (1) {
        int len = recvfrom(firewall->sockfd, buf, sizeof(buf), 0, NULL, NULL);
        if (len < 0) {
            perror("recvfrom");
            continue;
        }

        struct ethhdr *eth = (struct ethhdr *)buf;
        if (ntohs(eth->h_proto) != ETH_P_ALL) {
            continue;
        }

        // TODO: Implement firewall rules here

        // Allow all traffic by default
        sendto(firewall->sockfd, buf, len, 0, (struct sockaddr *)&firewall->saddr, sizeof(firewall->saddr));
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct decentralized_firewall firewall;
    if (decentralized_firewall_init(&firewall, argv[1]) < 0) {
        return EXIT_FAILURE;
    }

    decentralized_firewall_loop(&firewall);

    return EXIT_SUCCESS;
}