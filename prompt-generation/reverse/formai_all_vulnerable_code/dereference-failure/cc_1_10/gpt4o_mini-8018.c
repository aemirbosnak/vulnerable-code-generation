//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

// Function to print packet details
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    const struct ip *ip;
    const struct tcphdr *tcp;
    const struct udphdr *udp;
    char src_ip[INET_ADDRSTRLEN], dst_ip[INET_ADDRSTRLEN];
    
    ip = (struct ip *)(packet + 14); // Skip Ethernet header
    inet_ntop(AF_INET, &(ip->ip_src), src_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(ip->ip_dst), dst_ip, INET_ADDRSTRLEN);

    printf("Packet captured: \n");
    printf("   Source IP: %s\n", src_ip);
    printf("   Destination IP: %s\n", dst_ip);
    printf("   Protocol: %d\n", ip->ip_p);
    
    if (ip->ip_p == IPPROTO_TCP) {
        tcp = (struct tcphdr *)(packet + 14 + (ip->ip_hl * 4));
        printf("   TCP - Source Port: %d, Destination Port: %d\n", ntohs(tcp->th_sport), ntohs(tcp->th_dport));
    } else if (ip->ip_p == IPPROTO_UDP) {
        udp = (struct udphdr *)(packet + 14 + (ip->ip_hl * 4));
        printf("   UDP - Source Port: %d, Destination Port: %d\n", ntohs(udp->uh_sport), ntohs(udp->uh_dport));
    }
    printf("\n");
}

// Main function
int main(int argc, char *argv[]) {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return 1;
    }

    printf("Available devices:\n");
    for (device = alldevs; device != NULL; device = device->next) {
        printf("   %s\n", device->name);
    }
    
    // Select the first device
    device = alldevs;
    printf("Using device: %s\n", device->name);

    // Open the device for sniffing
    handle = pcap_open_live(device->name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device %s: %s\n", device->name, errbuf);
        return 1;
    }

    printf("Starting packet capture...\n");
    
    // Start capturing packets
    pcap_loop(handle, 0, packet_handler, NULL);

    // Cleanup
    pcap_close(handle);
    pcap_freealldevs(alldevs);
    
    return 0;
}