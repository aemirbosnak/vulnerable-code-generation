//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <linux/if_ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <pcap.h>

#define MAXBYTES2CAPTURE 2048
#define DEVICE "eth0"

void process_packet(const struct pcap_pkthdr *header, const u_char *packet) {
    struct ethhdr *eth = (struct ethhdr *)packet;
    
    // Print Ethernet Source and Destination
    printf("Ethernet Source: %02X:%02X:%02X:%02X:%02X:%02X\n",
           eth->h_source[0], eth->h_source[1], eth->h_source[2],
           eth->h_source[3], eth->h_source[4], eth->h_source[5]);
           
    printf("Ethernet Destination: %02X:%02X:%02X:%02X:%02X:%02X\n",
           eth->h_dest[0], eth->h_dest[1], eth->h_dest[2],
           eth->h_dest[3], eth->h_dest[4], eth->h_dest[5]);

    if (ntohs(eth->h_proto) == ETH_P_IP) {
        const struct iphdr *ip = (struct iphdr *)(packet + sizeof(struct ethhdr));
        struct in_addr src_ip, dest_ip;

        src_ip.s_addr = ip->saddr;
        dest_ip.s_addr = ip->daddr;

        printf("IP Source: %s\n", inet_ntoa(src_ip));
        printf("IP Destination: %s\n", inet_ntoa(dest_ip));

        if (ip->protocol == IPPROTO_TCP) {
            const struct tcphdr *tcp = (struct tcphdr *)(packet + sizeof(struct ethhdr) + sizeof(struct iphdr));
            printf("TCP Source Port: %u\n", ntohs(tcp->source));
            printf("TCP Destination Port: %u\n", ntohs(tcp->dest));
        }
    }

    printf("--------------------------------------\n");
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    process_packet(header, packet);
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_if_t *alldevsp, *device;
    
    // Find all network devices
    if (pcap_findalldevs(&alldevsp, errbuf) == -1) {
        fprintf(stderr, "Could not find devices: %s\n", errbuf);
        return 1;
    }

    // Print available devices
    printf("Available devices:\n");
    for (device = alldevsp; device; device = device->next) {
        printf(" - %s\n", device->name);
    }

    // Open the specified device
    pcap_t *handle = pcap_open_live(DEVICE, MAXBYTES2CAPTURE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", DEVICE, errbuf);
        return 2;
    }

    // Set filter for IP protocol only
    struct bpf_program fp;
    char filter_exp[] = "ip";
    if (pcap_compile(handle, &fp, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Could not compile filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 2;
    }
    
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Could not set filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 2;
    }
    
    // Start processing packets
    printf("Starting packet capture on %s...\n", DEVICE);
    pcap_loop(handle, 0, packet_handler, NULL);

    // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);
    pcap_freealldevs(alldevsp);
    
    return 0;
}