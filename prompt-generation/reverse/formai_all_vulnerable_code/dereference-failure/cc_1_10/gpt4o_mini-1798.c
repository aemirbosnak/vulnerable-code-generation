//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <netinet/ether.h>
#include <string.h>

#define SNAP_LEN 1518
#define SIZE_ETHERNET 14

void process_packet(const u_char *packet, struct pcap_pkthdr header);
void print_ip(const struct ip *ip_hdr);
void print_tcp(const struct tcphdr *tcp_hdr);
void print_udp(const struct udphdr *udp_hdr);

int main(int argc, char *argv[]) {
    pcap_if_t *interfaces, *temp;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    const char *device; 
    struct bpf_program fp;
    char filter_exp[] = "ip"; // Capture only IP packets

    // Get network devices
    if (pcap_findalldevs(&interfaces, errbuf) == -1) {
        fprintf(stderr, "Could not find devices: %s\n", errbuf);
        return 1;
    }

    // Select the first device as default
    device = interfaces->name;

    // Open the device for packet capture
    handle = pcap_open_live(device, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device, errbuf);
        pcap_freealldevs(interfaces);
        return 1;
    }

    // Compile and set the filter
    if (pcap_compile(handle, &fp, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Could not compile filter: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        pcap_freealldevs(interfaces);
        return 1;
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Could not set filter: %s\n", pcap_geterr(handle));
        pcap_freecode(&fp);
        pcap_close(handle);
        pcap_freealldevs(interfaces);
        return 1;
    }

    pcap_freecode(&fp);

    // Capture packets
    printf("Listening on device %s...\n", device);
    struct pcap_pkthdr header;
    const u_char *packet;

    while (1) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            continue;
        }
        process_packet(packet, header);
    }

    pcap_close(handle);
    pcap_freealldevs(interfaces);
    return 0;
}

void process_packet(const u_char *packet, struct pcap_pkthdr header) {
    const struct ether_header *eth_hdr = (struct ether_header *)packet;
    const struct ip *ip_hdr;
    const struct tcphdr *tcp_hdr;
    const struct udphdr *udp_hdr;
    u_int ether_type;

    ether_type = ntohs(eth_hdr->ether_type);
    if (ether_type == ETHERTYPE_IP) {
        ip_hdr = (struct ip *)(packet + SIZE_ETHERNET);
        printf("Captured an IP packet:\n");
        print_ip(ip_hdr);
        
        if (ip_hdr->ip_p == IPPROTO_TCP) {
            tcp_hdr = (struct tcphdr *)(packet + SIZE_ETHERNET + sizeof(struct ip));
            printf("TCP Packet:\n");
            print_tcp(tcp_hdr);
        } else if (ip_hdr->ip_p == IPPROTO_UDP) {
            udp_hdr = (struct udphdr *)(packet + SIZE_ETHERNET + sizeof(struct ip));
            printf("UDP Packet:\n");
            print_udp(udp_hdr);
        }
    }
}

void print_ip(const struct ip *ip_hdr) {
    char src[INET_ADDRSTRLEN], dest[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &ip_hdr->ip_src, src, sizeof(src));
    inet_ntop(AF_INET, &ip_hdr->ip_dst, dest, sizeof(dest));
    printf("Source IP: %s\n", src);
    printf("Destination IP: %s\n", dest);
    printf("Protocol: %d\n\n", ip_hdr->ip_p);
}

void print_tcp(const struct tcphdr *tcp_hdr) {
    printf("Source Port: %d\n", ntohs(tcp_hdr->source));
    printf("Destination Port: %d\n\n", ntohs(tcp_hdr->dest));
}

void print_udp(const struct udphdr *udp_hdr) {
    printf("Source Port: %d\n", ntohs(udp_hdr->source));
    printf("Destination Port: %d\n\n", ntohs(udp_hdr->dest));
}