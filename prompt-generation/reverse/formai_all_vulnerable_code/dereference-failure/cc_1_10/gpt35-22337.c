//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netpacket/packet.h>

#define BUFFER_SIZE 4096

unsigned short checksum(unsigned short *ptr, int nbytes);

int main(int argc, char *argv[]) {
    int sockfd, sockfd_raw, sockopt, data_len, i;
    char buffer[BUFFER_SIZE], *interface;
    struct ifreq ifreq;
    struct sockaddr_ll device;
    struct packet_mreq packet_mreq;
    struct ether_header *eth_header;
    struct iphdr *ip_header;
    struct tcphdr *tcp_header;
    struct udphdr *udp_header;

    if(argc != 2) {
        printf("Usage: %s <interface name>\n", argv[0]);
        return 1;
    }

    interface = argv[1];

    sockfd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if(sockfd == -1) {
        perror("socket");
        return 1;
    }

    memset(&ifreq, 0, sizeof(ifreq));
    strncpy(ifreq.ifr_name, interface, sizeof(ifreq.ifr_name)-1);
    if(ioctl(sockfd, SIOCGIFINDEX, &ifreq) == -1) {
        perror("ioctl");
        return 1;
    }

    memset(&device, 0, sizeof(device));
    device.sll_family = AF_PACKET;
    device.sll_ifindex = ifreq.ifr_ifindex;
    device.sll_protocol = htons(ETH_P_IP);
    if(bind(sockfd, (struct sockaddr *)&device, sizeof(device)) == -1) {
        perror("bind");
        return 1;
    }

    /* Enable promiscuous mode */
    packet_mreq.mr_type = PACKET_MR_PROMISC;
    packet_mreq.mr_ifindex = ifreq.ifr_ifindex;
    packet_mreq.mr_alen = 0;
    setsockopt(sockfd, SOL_PACKET, PACKET_ADD_MEMBERSHIP, &packet_mreq, sizeof(packet_mreq));

    printf("Listening on interface: %s\n", interface);

    while(1) {
        data_len = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if(data_len == -1) {
            perror("recv");
            return 1;
        }

        eth_header = (struct ether_header *)buffer;
        if(ntohs(eth_header->ether_type) == ETHERTYPE_IP) {
            ip_header = (struct iphdr *)(buffer + sizeof(struct ether_header));
            printf("%s\n", inet_ntoa(*(struct in_addr *)&ip_header->saddr));
        }
    }

    close(sockfd);
    return 0;
}

/* Compute checksum for array with even and odd number of bytes */
unsigned short checksum(unsigned short *ptr, int nbytes) {
    register long sum;
    unsigned short oddbyte;
    register short answer;

    sum = 0;
    while(nbytes > 1) {
        sum += *ptr++;
        nbytes -= 2;
    }
    if(nbytes == 1) {
        oddbyte = 0;
        *((unsigned char *)&oddbyte) = *(unsigned char *)ptr;
        sum += oddbyte;
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    answer = (short)~sum;
    return answer;
}