//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <linux/if_ether.h>
#include <linux/ip.h>
#include <linux/udp.h>
#include <linux/tcp.h>
#include <sys/ioctl.h>
#include <time.h>

#define BUFFER_SIZE 65536

void print_packet_info(const u_char *buf, int size) {
    struct ethhdr *eth = (struct ethhdr *)buf;
    printf("Ethernet Header\n");
    printf("   Source MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
           eth->h_source[0], eth->h_source[1], eth->h_source[2],
           eth->h_source[3], eth->h_source[4], eth->h_source[5]);
    printf("   Destination MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
           eth->h_dest[0], eth->h_dest[1], eth->h_dest[2],
           eth->h_dest[3], eth->h_dest[4], eth->h_dest[5]);
    
    if (ntohs(eth->h_proto) == ETH_P_IP) {
        struct iphdr *ip = (struct iphdr *)(buf + sizeof(struct ethhdr));
        printf("IP Header\n");
        printf("   Source IP: %s\n", inet_ntoa(*(struct in_addr *)&ip->saddr));
        printf("   Destination IP: %s\n", inet_ntoa(*(struct in_addr *)&ip->daddr));

        if (ip->protocol == IPPROTO_UDP) {
            struct udphdr *udp = (struct udphdr *)(buf + sizeof(struct ethhdr) + sizeof(struct iphdr));
            printf("UDP Header\n");
            printf("   Source Port: %d\n", ntohs(udp->source));
            printf("   Destination Port: %d\n", ntohs(udp->dest));
        } else if (ip->protocol == IPPROTO_TCP) {
            struct tcphdr *tcp = (struct tcphdr *)(buf + sizeof(struct ethhdr) + sizeof(struct iphdr));
            printf("TCP Header\n");
            printf("   Source Port: %d\n", ntohs(tcp->source));
            printf("   Destination Port: %d\n", ntohs(tcp->dest));
        }
    }

    printf("\n");
}

void packet_capture(const char *interface) {
    int sock;
    struct sockaddr saddr;
    int saddr_len = sizeof(saddr);
    u_char *buffer = (u_char *)malloc(BUFFER_SIZE);

    // Create a raw socket to capture packets
    if ((sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL))) < 0) {
        perror("Socket error");
        exit(EXIT_FAILURE);
    }

    // Bind to the interface
    struct ifreq ifr;
    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, interface, IFNAMSIZ - 1);
    if (ioctl(sock, SIOCGIFINDEX, &ifr) < 0) {
        perror("IOCTL error");
        close(sock);
        exit(EXIT_FAILURE);
    }

    printf("Listening on interface: %s\n", interface);
    printf("Press Ctrl+C to stop the capture...\n");

    while (1) {
        int packet_size = recvfrom(sock, buffer, BUFFER_SIZE, 0, &saddr, (socklen_t *)&saddr_len);
        if (packet_size < 0) {
            perror("Recvfrom error");
            continue;
        }
        print_packet_info(buffer, packet_size);
    }

    close(sock);
    free(buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    packet_capture(argv[1]);
    return EXIT_SUCCESS;
}