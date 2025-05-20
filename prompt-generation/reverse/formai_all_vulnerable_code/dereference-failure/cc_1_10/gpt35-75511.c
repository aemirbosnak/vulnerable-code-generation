//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/if_ether.h>
#include <linux/if_packet.h>
#include <net/ethernet.h>

#define MAXIP 256
#define DEBUG 1

struct ipmac {
    uint32_t ip;
    uint8_t mac[6];
    int found;
};

struct ifmac {
    char name[IFNAMSIZ];
    uint8_t mac[6];
};

void getifmac(struct ifmac *ifm) {
    int sfd;
    struct ifreq ifr;

    memset(&ifr, 0, sizeof(struct ifreq));
    strncpy(ifr.ifr_name, ifm->name, IFNAMSIZ-1);

    sfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);
    if (sfd < 0) {
        perror("No socket");
        return;
    }

    if (ioctl(sfd, SIOCGIFHWADDR, &ifr) < 0) {
        perror("Failed to get MAC address");
        close(sfd);
        return;
    }

    ifm->mac[0] = ifr.ifr_hwaddr.sa_data[0];
    ifm->mac[1] = ifr.ifr_hwaddr.sa_data[1];
    ifm->mac[2] = ifr.ifr_hwaddr.sa_data[2];
    ifm->mac[3] = ifr.ifr_hwaddr.sa_data[3];
    ifm->mac[4] = ifr.ifr_hwaddr.sa_data[4];
    ifm->mac[5] = ifr.ifr_hwaddr.sa_data[5];

    close(sfd);
}

int sendarp(int sfd, struct ifmac *ifm, uint32_t ip, uint8_t *replymac) {
    struct sockaddr_ll sa;
    struct ifreq ifr;
    struct ether_header eth_hdr;
    struct ether_arp arp_pkt;
    char buf[1024];

    memset(buf, 0, sizeof(buf));
    memset(&eth_hdr, 0, sizeof(eth_hdr));
    memset(&arp_pkt, 0, sizeof(arp_pkt));
    memset(&ifr, 0, sizeof(ifr));
    memset(&sa, 0, sizeof(sa));

    /* Get the MAC of the interface */
    getifmac(ifm);

    /* Construct the ARP packet */
    memcpy(&eth_hdr.ether_dhost, &replymac, 6);
    memcpy(&eth_hdr.ether_shost, ifm->mac, 6);
    eth_hdr.ether_type = htons(ETHERTYPE_ARP);

    arp_pkt.arp_hrd = htons(ARPHRD_ETHER);
    arp_pkt.arp_pro = htons(ETHERTYPE_IP);
    arp_pkt.arp_hln = 6;
    arp_pkt.arp_pln = 4;
    arp_pkt.arp_op = htons(ARPOP_REQUEST);

    memcpy(&arp_pkt.arp_sha, ifm->mac, 6);
    memcpy(&arp_pkt.arp_spa, &ip, 4);
    memset(&arp_pkt.arp_tha, 0, 6);
    memset(&arp_pkt.arp_tpa, 0, 4);

    memcpy(buf, &eth_hdr, sizeof(eth_hdr));
    memcpy(buf+sizeof(eth_hdr), &arp_pkt, sizeof(arp_pkt));

    /* Get the index of the network interface */
    strncpy(ifr.ifr_name, ifm->name, IFNAMSIZ-1);
    if (ioctl(sfd, SIOCGIFINDEX, &ifr) == -1) {
        perror("ioctl SIOCGIFINDEX");
        return 1;
    }

    sa.sll_family = AF_PACKET;
    sa.sll_ifindex = ifr.ifr_ifindex;
    sa.sll_protocol = htons(ETH_P_ARP);
    sa.sll_hatype = 0;
    sa.sll_pkttype = 0;
    sa.sll_halen = 0;

    if (sendto(sfd, buf, sizeof(eth_hdr)+sizeof(arp_pkt), 0, (struct sockaddr *)&sa, sizeof(sa)) < 0) {
        perror("sendto");
        return 1;
    }

    return 0;
}

void usage(char *progname) {
    printf("Usage: %s <IP>\n", progname);
}

int main(int argc, char **argv) {
    int sfd, maxfd, i, ret, found = 0;
    uint32_t network, ip;
    fd_set fds;
    char ipstr[MAXIP];
    struct ifmac ifm;
    struct ipmac ipm;
    struct timeval tv;
    uint8_t broadcast[] = {0xff,0xff,0xff,0xff,0xff,0xff};
    uint8_t buffer[sizeof(struct ether_header)+sizeof(struct ether_arp)];
    struct ether_header *eth_hdr = (struct ether_header*)buffer;
    struct ether_arp *arp_pkt = (struct ether_arp*)(buffer+sizeof(struct ether_header));

    if (argc < 2) {
        usage(argv[0]);
        return -1;
    }

    /* Initialize structures */
    memset(&ifm, 0, sizeof(ifm));
    memset(&ipm, 0, sizeof(ipm));

    /* Parse IP address */
    memset(ipstr, 0, MAXIP);
    strncpy(ipstr, argv[1], MAXIP-1);
    if (inet_pton(AF_INET, ipstr, &network) < 0) {
        printf("%s is an invalid IP address\n", ipstr);
        usage(argv[0]);
        return -1;
    }
    network = ntohl(network);

    /* Create socket */
    if ((sfd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ARP))) < 0) {
        perror("socket");
        return -1;
    }

    /* Get interface name */
    if (ioctl(sfd, SIOCGIFNAME, &ifm) < 0) {
        perror("ioctl SIOCGIFNAME");
        return -1;
    }

    /* Get MAC address of the interface */
    getifmac(&ifm);

    /* Add socket to FD set */
    FD_ZERO(&fds);
    FD_SET(sfd, &fds);
    maxfd = sfd+1;

    /* Send ARP request */
    for (i = 1; i <= 254; i++) {
        ip = (network & 0xffffff00) | i;
        if (sendarp(sfd, &ifm, ip, broadcast) < 0) {
            fprintf(stderr, "Failed to send ARP request for IP %d.%d.%d.%d\n",
                (ip >> 24),
                (ip >> 16) & 0xff,
                (ip >> 8) & 0xff,
                ip & 0xff);
        }
    }

    /* Wait for responses */
    tv.tv_sec = 2;
    tv.tv_usec = 0;
    while (found < 254) {
        ret = select(maxfd, &fds, NULL, NULL, &tv);
        if (ret < 0 && errno != EINTR) {
            perror("select");
            break;
        } else if (ret > 0 && FD_ISSET(sfd, &fds)) {
            memset(buffer, 0, sizeof(buffer));
            if (recv(sfd, buffer, sizeof(buffer), 0) < 0) {
                perror("recv");
                continue;
            }

            if (ntohs(eth_hdr->ether_type) != ETHERTYPE_ARP ||
                ntohs(arp_pkt->ea_hdr.ar_op) != ARPOP_REPLY ||
                memcmp(&arp_pkt->arp_spa, &network, 3) != 0 ||
                arp_pkt->arp_spa[3] >= 255 ||
                arp_pkt->arp_spa[3] == 0 ||
                memcmp(&arp_pkt->arp_tpa, &network, 3) != 0) {
                continue;
            }

            ipm.ip = *((uint32_t*)&arp_pkt->arp_spa);
            memcpy(ipm.mac, arp_pkt->arp_sha, 6);
            ipm.found = 1;

            if (DEBUG) {
                printf("Found IP address %d.%d.%d.%d with MAC address %02x:%02x:%02x:%02x:%02x:%02x\n",
                    (ipm.ip >> 24),
                    (ipm.ip >> 16) & 0xff,
                    (ipm.ip >> 8) & 0xff,
                    ipm.ip & 0xff,
                    ipm.mac[0],
                    ipm.mac[1],
                    ipm.mac[2],
                    ipm.mac[3],
                    ipm.mac[4],
                    ipm.mac[5]);
            }

            found++;
        }
    }

    /* Print out results */
    printf("Results:\n");
    for (i = 1; i <= 254; i++) {
        ip = (network & 0xffffff00) | i;
        if (memcmp(&ifm.mac, &ipm.mac, 6) == 0) {
            printf("%d.%d.%d.%d: This machine\n",
                (ip >> 24),
                (ip >> 16) & 0xff,
                (ip >> 8) & 0xff,
                ip & 0xff);
        } else {
            if (ipm.found) {
                printf("%d.%d.%d.%d: %02x:%02x:%02x:%02x:%02x:%02x\n",
                    (ip >> 24),
                    (ip >> 16) & 0xff,
                    (ip >> 8) & 0xff,
                    ip & 0xff,
                    ipm.mac[0],
                    ipm.mac[1],
                    ipm.mac[2],
                    ipm.mac[3],
                    ipm.mac[4],
                    ipm.mac[5]);
            } else {
                printf("%d.%d.%d.%d: No response\n",
                    (ip >> 24),
                    (ip >> 16) & 0xff,
                    (ip >> 8) & 0xff,
                    ip & 0xff);
            }
        }
    }

    close(sfd);

    return 0;
}