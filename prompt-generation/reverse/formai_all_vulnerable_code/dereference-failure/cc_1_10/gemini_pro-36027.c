//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: innovative
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <string.h>

#define MAX_BYTES 2048

struct packet_header {
    struct timeval ts;
    uint32_t caplen;
    uint32_t len;
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(argv[1], MAX_BYTES, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live(): %s\n", errbuf);
        return EXIT_FAILURE;
    }

    struct packet_header header;
    const u_char *packet;

    while (1) {
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 1) {
            struct ip *ip_header = (struct ip *)(packet + sizeof(struct packet_header));
            if (ip_header->ip_p == IPPROTO_TCP) {
                struct tcphdr *tcp_header = (struct tcphdr *)(packet + sizeof(struct packet_header) + sizeof(struct ip));
                printf("TCP packet from %s:%d to %s:%d\n", inet_ntoa(ip_header->ip_src), ntohs(tcp_header->th_sport), inet_ntoa(ip_header->ip_dst), ntohs(tcp_header->th_dport));
            } else if (ip_header->ip_p == IPPROTO_UDP) {
                struct udphdr *udp_header = (struct udphdr *)(packet + sizeof(struct packet_header) + sizeof(struct ip));
                printf("UDP packet from %s:%d to %s:%d\n", inet_ntoa(ip_header->ip_src), ntohs(udp_header->uh_sport), inet_ntoa(ip_header->ip_dst), ntohs(udp_header->uh_dport));
            } else {
                printf("Unknown packet type\n");
            }
        } else if (res == -1) {
            fprintf(stderr, "pcap_next_ex(): %s\n", pcap_geterr(handle));
            break;
        } else if (res == 0) {
            // Timeout
        }
    }

    pcap_close(handle);
    return EXIT_SUCCESS;
}