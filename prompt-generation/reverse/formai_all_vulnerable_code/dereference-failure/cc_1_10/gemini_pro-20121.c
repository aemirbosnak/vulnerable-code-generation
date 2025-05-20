//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: Linus Torvalds
/*
 * Linux Network Packet Monitoring with a Torvalds-ian Twist
 *
 * "Look, here's a packet. Now what?" -- Linus Torvalds
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <errno.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

// Linus-approved macros
#define FOR_EACH_PACKET(pkt, hdr, len, ret) \
    do { \
        ret = pcap_next_ex(pcap, &hdr, &len); \
        if (ret == 1) { \
            pkt = hdr; \
        } \
    } while (0)

#define ETHERNET_HDR_LEN 14
#define IP_HDR_LEN      20
#define TCP_HDR_LEN     20
#define UDP_HDR_LEN     8

// Packet sniffing function
void sniff(char *iface) {
    // Open the network interface
    pcap_t *pcap = pcap_open_live(iface, BUFSIZ, 1, 1000, NULL);
    if (!pcap) {
        fprintf(stderr, "Error opening interface: %s\n", pcap_geterr(pcap));
        exit(1);
    }

    // Packet loop
    const int hdr_len = ETHERNET_HDR_LEN + IP_HDR_LEN;
    const int max_len = 1514;
    int ret;
    const u_char *pkt;
    const struct ether_header *eth;
    const struct ip *ip;
    const struct tcphdr *tcp;
    const struct udphdr *udp;
    char src[INET_ADDRSTRLEN];
    char dst[INET_ADDRSTRLEN];

    while (1) {
        FOR_EACH_PACKET(pkt, eth, max_len, ret);
        if (ret != 1) {
            if (ret == 0) continue;
            fprintf(stderr, "Error sniffing packet: %s\n", pcap_geterr(pcap));
            exit(1);
        }

        // Parse the Ethernet header
        ip = (struct ip *) (pkt + ETHERNET_HDR_LEN);

        // Parse the IP header
        inet_ntop(AF_INET, &ip->ip_src, src, sizeof(src));
        inet_ntop(AF_INET, &ip->ip_dst, dst, sizeof(dst));

        // Print the IP packet info
        printf("IP packet from %s to %s\n", src, dst);

        // Parse the transport header
        switch (ip->ip_p) {
            case IPPROTO_TCP:
                tcp = (struct tcphdr *) (pkt + hdr_len);
                printf("  TCP packet from port %d to port %d\n",
                       ntohs(tcp->th_sport), ntohs(tcp->th_dport));
                break;
            case IPPROTO_UDP:
                udp = (struct udphdr *) (pkt + hdr_len);
                printf("  UDP packet from port %d to port %d\n",
                       ntohs(udp->uh_sport), ntohs(udp->uh_dport));
                break;
            default:
                printf("  Unknown transport protocol\n");
                break;
        }

        // Print the packet data payload
        printf("  Payload: ");
        for (int i = hdr_len; i < max_len; i++) {
            printf("%02x ", pkt[i]);
        }
        printf("\n");

        // Ignore the rest of the bytes
        break;
    }

    // Close the network interface
    pcap_close(pcap);
}

// Main function
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        exit(1);
    }

    // "Just do it" - Shia LaBeouf
    sniff(argv[1]);

    return 0;
}