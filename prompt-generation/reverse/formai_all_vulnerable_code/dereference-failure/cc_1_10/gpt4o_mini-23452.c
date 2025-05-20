//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <string.h>

#define MAX_PACKET_SIZE 65536
#define PROMISCUOUS_MODE 1
#define TIMEOUT 1000

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    static int packet_count = 1;
    const struct ip *ip_header;
    char src_ip[INET_ADDRSTRLEN];
    char dest_ip[INET_ADDRSTRLEN];

    // Extracting the IP header from the packet
    ip_header = (struct ip*)(packet + 14); // Ethernet header is 14 bytes long

    // Convert IP addresses to readable strings
    inet_ntop(AF_INET, &ip_header->ip_src, src_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &ip_header->ip_dst, dest_ip, INET_ADDRSTRLEN);

    // Display packet count and IPs
    printf("Packet #%d: Source: %s, Destination: %s\n", packet_count, src_ip, dest_ip);
    packet_count++;
}

void usage() {
    printf("Syntax: packet_monitor <interface>\n");
    printf("Example: packet_monitor eth0\n");
}

int main(int argc, char *argv[]) {
    pcap_if_t *interfaces, *temp;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    
    if (argc != 2) {
        usage();
        return 1;
    }

    // Find all available network interfaces
    if (pcap_findalldevs(&interfaces, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return 1;
    }

    // Iterate through the list of interfaces to find the one specified
    temp = interfaces;
    while (temp != NULL) {
        if (strcmp(temp->name, argv[1]) == 0) {
            break;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        fprintf(stderr, "No interface found with name %s\n", argv[1]);
        pcap_freealldevs(interfaces);
        return 1;
    }

    // Open the network device in promiscuous mode
    handle = pcap_open_live(temp->name, MAX_PACKET_SIZE, PROMISCUOUS_MODE, TIMEOUT, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", temp->name, errbuf);
        pcap_freealldevs(interfaces);
        return 1;
    }

    // Start packet processing loop
    pcap_loop(handle, 0, packet_handler, NULL);

    // Cleanup
    pcap_freealldevs(interfaces);
    pcap_close(handle);
    return 0;
}