//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>

#define SIZE_ETHERNET 14

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);
void print_ip(const struct ip* ip_header);

int main(int argc, char *argv[]) {
    pcap_if_t *interfaces, *temp;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the list of network interfaces
    if (pcap_findalldevs(&interfaces, errbuf) == -1) {
        fprintf(stderr, "Could not find devices: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Iterate through the interfaces to find the specified one
    temp = interfaces;
    while (temp) {
        if (strcmp(temp->name, argv[1]) == 0) {
            break;
        }
        temp = temp->next;
    }

    // Check if the specified interface was found
    if (!temp) {
        fprintf(stderr, "No such interface found: %s\n", argv[1]);
        pcap_freealldevs(interfaces);
        return EXIT_FAILURE;
    }

    // Opening the interface for packet capture
    handle = pcap_open_live(temp->name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", temp->name, errbuf);
        pcap_freealldevs(interfaces);
        return EXIT_FAILURE;
    }

    printf("Listening on %s...\n", temp->name);
    
    // Start capturing packets
    pcap_loop(handle, 10, process_packet, NULL);

    // Cleanup
    pcap_freealldevs(interfaces);
    pcap_close(handle);
    return EXIT_SUCCESS;
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    const struct ip *ip_header;
    int size_ip;

    // Get the IP header using the offset of Ethernet header
    ip_header = (struct ip *)(packet + SIZE_ETHERNET);
    size_ip = ip_header->ip_hl * 4;

    // Ensure the IP header is valid
    if (size_ip < 20) {
        fprintf(stderr, "Invalid IP header length\n");
        return;
    }

    // Print IP source and destination
    printf("Captured Packet:\n");
    printf("From: %s\n", inet_ntoa(ip_header->ip_src));
    printf("To: %s\n", inet_ntoa(ip_header->ip_dst));
    printf("Packet Length: %d\n", header->len);
    printf("Timestamp: %s", ctime((const time_t *)&header->ts.tv_sec));
    printf("-----------------------------------------\n");
}

// Compile with: gcc -o packet_monitor packet_monitor.c -lpcap