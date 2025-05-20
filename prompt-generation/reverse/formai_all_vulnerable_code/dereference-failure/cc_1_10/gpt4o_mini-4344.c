//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <string.h>

#define SNAP_LEN 1518
#define SIZE_ETHERNET 14
#define FILTER_EXP "ip"

// Ethernet header
struct ether_header {
    u_char  ether_dhost[6]; /* destination ethernet address */
    u_char  ether_shost[6]; /* source ethernet address */
    u_short ether_type;      /* ethernet type */
};

// Callback function that is called for each captured packet
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ether_header *eth_header;
    struct ip *ip_header;
    struct tcphdr *tcp_header;
    struct udphdr *udp_header;

    eth_header = (struct ether_header *)(packet);
    ip_header = (struct ip *)(packet + SIZE_ETHERNET);
    
    char source_ip[INET_ADDRSTRLEN];
    char dest_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &ip_header->ip_src, source_ip, sizeof(source_ip));
    inet_ntop(AF_INET, &ip_header->ip_dst, dest_ip, sizeof(dest_ip));

    printf("Packet captured: \n");
    printf("Source IP: %s\n", source_ip);
    printf("Destination IP: %s\n", dest_ip);
    
    switch (ip_header->ip_p) {
        case IPPROTO_TCP:
            tcp_header = (struct tcphdr *)(packet + SIZE_ETHERNET + sizeof(struct ip));
            printf("Protocol: TCP\n");
            printf("Source Port: %d\n", ntohs(tcp_header->source));
            printf("Destination Port: %d\n", ntohs(tcp_header->dest));
            break;
        case IPPROTO_UDP:
            udp_header = (struct udphdr *)(packet + SIZE_ETHERNET + sizeof(struct ip));
            printf("Protocol: UDP\n");
            printf("Source Port: %d\n", ntohs(udp_header->source));
            printf("Destination Port: %d\n", ntohs(udp_header->dest));
            break;
        default:
            printf("Protocol: Other\n");
            break;
    }

    printf("Packet Length: %d bytes\n\n", header->len);
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs;
    pcap_if_t *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter_exp[] = FILTER_EXP;
    bpf_u_int32 mask;
    bpf_u_int32 net;

    // Check for enough arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Find all devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Could not find devices: %s\n", errbuf);
        return 1;
    }

    // Find the specified device
    for(device = alldevs; device != NULL; device = device->next) {
        if (strcmp(argv[1], device->name) == 0) break;
    }

    // If the device was not found
    if (device == NULL) {
        fprintf(stderr, "Device %s not found.\n", argv[1]);
        pcap_freealldevs(alldevs);
        return 1;
    }

    // Open the device for live capture
    handle = pcap_open_live(device->name, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device->name, errbuf);
        pcap_freealldevs(alldevs);
        return 1;
    }

    // Compile and set the filter
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Could not parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        pcap_freealldevs(alldevs);
        return 1;
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Could not install filter: %s\n", pcap_geterr(handle));
        pcap_freealldevs(alldevs);
        return 1;
    }

    // Start the packet capture loop
    pcap_loop(handle, 0, packet_handler, NULL);

    // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);
    pcap_freealldevs(alldevs);

    return 0;
}