//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: multiplayer
#include <stdio.h>
#include <pcap.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <string.h>

#define MAX_PACKET_SIZE 2048
#define GAME_PORT 27015 // Example port for multiplayer games (like Steam)

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ip *ip_hdr = (struct ip *)(packet + 14); // Skip Ethernet header
    struct tcphdr *tcp_hdr = (struct tcphdr *)(packet + 14 + (ip_hdr->ip_hl * 4));

    // Check if the packet is TCP and destined for the game port
    if (ntohs(tcp_hdr->th_dport) == GAME_PORT || ntohs(tcp_hdr->th_sport) == GAME_PORT) {
        char source_ip[INET_ADDRSTRLEN];
        char dest_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(ip_hdr->ip_src), source_ip, INET_ADDRSTRLEN);
        inet_ntop(AF_INET, &(ip_hdr->ip_dst), dest_ip, INET_ADDRSTRLEN);
        
        printf("Captured a packet:\n");
        printf("  Source IP: %s:%d\n", source_ip, ntohs(tcp_hdr->th_sport));
        printf("  Destination IP: %s:%d\n", dest_ip, ntohs(tcp_hdr->th_dport));
        printf("  Packet Length: %d bytes\n", header->len);
        printf("--------------------------------------------\n");
    }
}

int main() {
    pcap_if_t *alldevs;
    pcap_if_t *device;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Retrieve the list of network devices
    if (pcap_findalldevs(&alldevs, errbuf) < 0) {
        fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
        return 1;
    }

    // Loop through the found devices and display them
    printf("Available network devices:\n");
    for (device = alldevs; device != NULL; device = device->next) {
        printf("  - %s\n", device->name);
    }

    // Choose the first device for simplicity
    if (alldevs == NULL) {
        fprintf(stderr, "No devices found! Exiting...\n");
        return 1;
    }

    pcap_t *handle = pcap_open_live(alldevs->name, MAX_PACKET_SIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Unable to open the device %s: %s\n", alldevs->name, errbuf);
        return 1;
    }

    printf("Listening on %s for multiplayer game packets...\n", alldevs->name);

    // Start the packet capture loop
    pcap_loop(handle, 0, packet_handler, NULL);

    // Cleanup
    pcap_close(handle);
    pcap_freealldevs(alldevs);

    return 0;
}