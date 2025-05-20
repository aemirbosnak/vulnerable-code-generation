//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: portable
#include <pcap.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define MAX_BYTES 2048
#define PROMISCUOUS 1

void print_usage(char *argv[]) {
    printf("Usage: %s <interface> <filter>\n", argv[0]);
    printf("Example: %s eth0 \"tcp port 80\"\n", argv[0]);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv);
        return 1;
    }

    char *interface = argv[1];
    char *filter = argv[2];

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(interface, MAX_BYTES, PROMISCUOUS, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening interface: %s\n", errbuf);
        return 2;
    }

    struct bpf_program fp;
    if (pcap_compile(handle, &fp, filter, 0, 0) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        return 3;
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        return 4;
    }

    int packet_count = 0;
    while (1) {
        struct pcap_pkthdr *header;
        const u_char *data;
        int res = pcap_next_ex(handle, &header, &data);
        if (res == -1) {
            fprintf(stderr, "Error reading packet: %s\n", pcap_geterr(handle));
            break;
        } else if (res == 0) {
            continue;
        } else if (res == 1) {
            packet_count++;

            struct ether_header *eth = (struct ether_header *)data;
            printf("Packet %d:\n", packet_count);
            printf("Source MAC: %.2X:%.2X:%.2X:%.2X:%.2X:%.2X\n",
                eth->ether_shost[0], eth->ether_shost[1], eth->ether_shost[2],
                eth->ether_shost[3], eth->ether_shost[4], eth->ether_shost[5]);
            printf("Destination MAC: %.2X:%.2X:%.2X:%.2X:%.2X:%.2X\n",
                eth->ether_dhost[0], eth->ether_dhost[1], eth->ether_dhost[2],
                eth->ether_dhost[3], eth->ether_dhost[4], eth->ether_dhost[5]);
            printf("Type: 0x%.4X\n", ntohs(eth->ether_type));

            if (ntohs(eth->ether_type) == ETHERTYPE_IP) {
                struct ip *ip = (struct ip *)(data + sizeof(struct ether_header));
                printf("Source IP: %s\n", inet_ntoa(ip->ip_src));
                printf("Destination IP: %s\n", inet_ntoa(ip->ip_dst));
                printf("Protocol: %d\n", ip->ip_p);

                if (ip->ip_p == IPPROTO_TCP) {
                    struct tcphdr *tcp = (struct tcphdr *)(data + sizeof(struct ether_header) + sizeof(struct ip));
                    printf("Source port: %d\n", ntohs(tcp->th_sport));
                    printf("Destination port: %d\n", ntohs(tcp->th_dport));
                }
            }
        }
    }

    pcap_close(handle);
    return 0;
}