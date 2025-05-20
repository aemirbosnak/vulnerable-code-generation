//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <linux/if_packet.h>

#define PACKET_LENGTH 1024
#define ETHER_TYPE 0x0800
#define TIMEOUT 1

int main(int argc, char *argv[]) {
    int sockfd;
    struct ifreq ifr;
    struct sockaddr_ll sll;
    unsigned char packet[PACKET_LENGTH];
    unsigned char dest_mac_addr[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
    struct ethhdr *eth_header;
    struct iphdr *ip_header;
    int packet_length, recv_length, i;
    char interface_name[IFNAMSIZ];

    if (argc != 2) {
        printf("Usage: %s <interface_name>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(PF_PACKET, SOCK_RAW, htons(ETHER_TYPE));
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, argv[1], IFNAMSIZ - 1);

    if (ioctl(sockfd, SIOCGIFINDEX, &ifr) == -1) {
        perror("ioctl");
        exit(1);
    }

    memset(&sll, 0, sizeof(sll));
    sll.sll_family = PF_PACKET;
    sll.sll_ifindex = ifr.ifr_ifindex;
    sll.sll_halen = 6;
    memcpy(sll.sll_addr, dest_mac_addr, sll.sll_halen);

    eth_header = (struct ethhdr *) packet;
    memcpy(eth_header->h_dest, dest_mac_addr, sizeof(dest_mac_addr));
    memcpy(eth_header->h_source, sll.sll_addr, sizeof(sll.sll_addr));
    eth_header->h_proto = htons(ETHER_TYPE);
    packet_length = sizeof(struct ethhdr);

    if (bind(sockfd, (struct sockaddr *) &sll, sizeof(sll)) == -1) {
        perror("bind");
        exit(1);
    }

    printf("Scanning wireless network...\n");

    for (i = 0; i < 255; i++) {
        struct in_addr inaddr;
        char *ip_address;
        char command[50];
        int status;

        sprintf(command, "ping -c 1 -w %d 192.168.1.%d", TIMEOUT, i);
        status = system(command);

        if (status == 0) {
            printf("Device found at 192.168.1.%d\n", i);
            inaddr.s_addr = inet_addr("192.168.1.1");
            ip_address = inet_ntoa(inaddr);

            ip_header = (struct iphdr *) &packet[packet_length];
            ip_header->version = 4;
            ip_header->ihl = 5;
            ip_header->tos = 0;
            ip_header->tot_len = htons(PACKET_LENGTH - packet_length);
            ip_header->id = htons(0);
            ip_header->frag_off = htons(0);
            ip_header->ttl = 255;
            ip_header->protocol = IPPROTO_ICMP;
            ip_header->check = 0;
            ip_header->saddr = inet_addr(ip_address);
            ip_header->daddr = inet_addr("192.168.1.255");

            packet_length += sizeof(struct iphdr);
            memset(&packet[packet_length], 0, PACKET_LENGTH - packet_length);

            if (sendto(sockfd, packet, packet_length, 0, (struct sockaddr *) &sll, sizeof(sll)) == -1) {
                perror("sendto");
            }
        } else {
            printf("No device found at 192.168.1.%d\n", i);
        }
    }

    close(sockfd);

    return 0;
}