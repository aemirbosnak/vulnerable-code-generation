//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <string.h>
#include <time.h>

#define MAX_PACKETS 100

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);
void print_ip_header(const struct ip *ip_hdr);
void print_tcp_header(const struct tcphdr *tcp_hdr);
void print_udp_header(const struct udphdr *udp_hdr);
void print_packet_info(const u_char *packet, struct pcap_pkthdr *header);

int main(int argc, char *argv[]) {
    char *dev;  
    char errbuf[PCAP_ERRBUF_SIZE]; 
    pcap_if_t *alldevs, *device;
    pcap_t *handle;  
    int packet_count = 0;

    // Check for device availability
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Couldn't find devices: %s\n", errbuf);
        return 1;
    }

    // Print available devices
    printf("Available devices:\n");
    for (device = alldevs; device != NULL; device = device->next) {
        printf("%s\n", device->name);
    }

    // Choose a device
    dev = alldevs->name;

    // Open the device for capturing
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 2;
    }

    // Start capturing packets
    printf("Capturing packets on %s...\n", dev);
    pcap_loop(handle, MAX_PACKETS, packet_handler, (u_char *)&packet_count);

    // Clean up
    pcap_close(handle);
    pcap_freealldevs(alldevs);
    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    int *packet_count = (int *)args;
    (*packet_count)++;
    
    printf("\nPacket Number: %d\n", *packet_count);
    print_packet_info(packet, (struct pcap_pkthdr *)header);
}

void print_packet_info(const u_char *packet, struct pcap_pkthdr *header) {
    struct ip *ip_hdr = (struct ip *)(packet + 14); // IP header starts after Ethernet header
    unsigned short ip_header_length = ip_hdr->ip_hl * 4;

    printf("Timestamp: %s", ctime((const time_t *)&header->ts.tv_sec));
    printf("Protocol: %d\n", ip_hdr->ip_p);
    print_ip_header(ip_hdr);

    if (ip_hdr->ip_p == IPPROTO_TCP) { 
        struct tcphdr *tcp_hdr = (struct tcphdr *)(packet + 14 + ip_header_length);
        print_tcp_header(tcp_hdr);
    } else if (ip_hdr->ip_p == IPPROTO_UDP) {
        struct udphdr *udp_hdr = (struct udphdr *)(packet + 14 + ip_header_length);
        print_udp_header(udp_hdr);
    }
}

void print_ip_header(const struct ip *ip_hdr) {
    char src_ip[INET_ADDRSTRLEN];
    char dst_ip[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &(ip_hdr->ip_src), src_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(ip_hdr->ip_dst), dst_ip, INET_ADDRSTRLEN);

    printf("Source IP: %s\n", src_ip);
    printf("Destination IP: %s\n", dst_ip);
}

void print_tcp_header(const struct tcphdr *tcp_hdr) {
    printf("TCP Source Port: %d\n", ntohs(tcp_hdr->source));
    printf("TCP Destination Port: %d\n", ntohs(tcp_hdr->dest));
    printf("TCP Sequence Number: %u\n", ntohl(tcp_hdr->seq));
    printf("TCP Acknowledgment Number: %u\n", ntohl(tcp_hdr->ack_seq));
}

void print_udp_header(const struct udphdr *udp_hdr) {
    printf("UDP Source Port: %d\n", ntohs(udp_hdr->source));
    printf("UDP Destination Port: %d\n", ntohs(udp_hdr->dest));
}