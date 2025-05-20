//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <string.h>

#define SNAP_LEN 65535

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ip *ip_header;
    struct udphdr *udp_header;
    struct tcphdr *tcp_header;

    // Skip the Ethernet header to get to the IP header
    ip_header = (struct ip*)(packet + 14);

    // Get source and destination IP addresses
    char src_ip[INET_ADDRSTRLEN];
    char dst_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(ip_header->ip_src), src_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(ip_header->ip_dst), dst_ip, INET_ADDRSTRLEN);

    printf("Source IP: %s --> Destination IP: %s\n", src_ip, dst_ip);

    // Check protocol type to differentiate between TCP and UDP
    switch (ip_header->ip_p) {
        case IPPROTO_TCP:
            tcp_header = (struct tcphdr*)(packet + 14 + (ip_header->ip_hl * 4));
            printf("Protocol: TCP | Source Port: %d | Destination Port: %d\n",
                   ntohs(tcp_header->source),
                   ntohs(tcp_header->dest));
            break;
        case IPPROTO_UDP:
            udp_header = (struct udphdr*)(packet + 14 + (ip_header->ip_hl * 4));
            printf("Protocol: UDP | Source Port: %d | Destination Port: %d\n",
                   ntohs(udp_header->source),
                   ntohs(udp_header->dest));
            break;
        default:
            printf("Protocol: Unknown\n");
            break;
    }
    printf("----------------------------------------------------\n");
}

void handle_error(const char *error_buffer) {
    fprintf(stderr, "Error: %s\n", error_buffer);
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs;
    pcap_if_t *device;
    char errbuf[PCAP_ERRBUF_SIZE];
  
    // Retrieve the device list
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        handle_error(errbuf);
        return 1;
    }

    // Displaying the devices found
    printf("Available devices:\n");
    for (device = alldevs; device != NULL; device = device->next) {
        printf("%s\n", device->name);
    }

    // Choose the first device for monitoring
    device = alldevs;
    if (device == NULL) {
        printf("No devices found! Exiting...\n");
        return 1;
    }

    // Open the device for capturing packets
    pcap_t *handle = pcap_open_live(device->name, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        handle_error(errbuf);
        return 1;
    }

    // Start capturing packets
    printf("Starting packet capture on %s...\n", device->name);
    
    pcap_loop(handle, 0, packet_handler, NULL);

    // Clean up and close the session
    pcap_close(handle);
    pcap_freealldevs(alldevs);
  
    return 0;
}