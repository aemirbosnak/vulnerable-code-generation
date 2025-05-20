//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: Ada Lovelace
#include <stdlib.h>
#include <stdio.h>
#include <pcap.h>
#include <string.h>
#include <netinet/in.h>

struct packet_header {
    uint16_t source_port;
    uint16_t destination_port;
    uint32_t sequence_number;
    uint32_t acknowledgment_number;
    uint8_t flags;
    uint8_t window_size;
    uint16_t checksum;
    uint16_t urgent_pointer;
};

struct ip_header {
    uint8_t version;
    uint8_t header_length;
    uint8_t type_of_service;
    uint16_t total_length;
    uint16_t identification;
    uint16_t flags;
    uint8_t time_to_live;
    uint8_t protocol;
    uint16_t header_checksum;
    uint32_t source_ip;
    uint32_t destination_ip;
};

struct ether_header {
    uint8_t destination_mac[6];
    uint8_t source_mac[6];
    uint16_t ether_type;
};

void print_packet(const uint8_t *packet, int length) {
    struct ether_header *ether_header = (struct ether_header *)packet;
    struct ip_header *ip_header = (struct ip_header *)(packet + sizeof(struct ether_header));
    struct packet_header *packet_header = (struct packet_header *)(packet + sizeof(struct ether_header) + sizeof(struct ip_header));

    printf("Ethernet header:\n");
    printf("  Destination MAC: %02x:%02x:%02x:%02x:%02x:%02x\n", ether_header->destination_mac[0], ether_header->destination_mac[1], ether_header->destination_mac[2], ether_header->destination_mac[3], ether_header->destination_mac[4], ether_header->destination_mac[5]);
    printf("  Source MAC: %02x:%02x:%02x:%02x:%02x:%02x\n", ether_header->source_mac[0], ether_header->source_mac[1], ether_header->source_mac[2], ether_header->source_mac[3], ether_header->source_mac[4], ether_header->source_mac[5]);
    printf("  Ether type: %04x\n", ntohs(ether_header->ether_type));

    printf("IP header:\n");
    printf("  Version: %d\n", ip_header->version);
    printf("  Header length: %d bytes\n", ip_header->header_length * 4);
    printf("  Type of service: %d\n", ip_header->type_of_service);
    printf("  Total length: %d bytes\n", ntohs(ip_header->total_length));
    printf("  Identification: %d\n", ntohs(ip_header->identification));
    printf("  Flags: %02x\n", ip_header->flags);
    printf("  Time to live: %d\n", ip_header->time_to_live);
    printf("  Protocol: %d\n", ip_header->protocol);
    printf("  Header checksum: %04x\n", ntohs(ip_header->header_checksum));
    printf("  Source IP: %d.%d.%d.%d\n", (ip_header->source_ip >> 24) & 0xff, (ip_header->source_ip >> 16) & 0xff, (ip_header->source_ip >> 8) & 0xff, ip_header->source_ip & 0xff);
    printf("  Destination IP: %d.%d.%d.%d\n", (ip_header->destination_ip >> 24) & 0xff, (ip_header->destination_ip >> 16) & 0xff, (ip_header->destination_ip >> 8) & 0xff, ip_header->destination_ip & 0xff);

    printf("Packet header:\n");
    printf("  Source port: %d\n", ntohs(packet_header->source_port));
    printf("  Destination port: %d\n", ntohs(packet_header->destination_port));
    printf("  Sequence number: %d\n", ntohl(packet_header->sequence_number));
    printf("  Acknowledgment number: %d\n", ntohl(packet_header->acknowledgment_number));
    printf("  Flags: %02x\n", packet_header->flags);
    printf("  Window size: %d\n", ntohs(packet_header->window_size));
    printf("  Checksum: %04x\n", ntohs(packet_header->checksum));
    printf("  Urgent pointer: %d\n", ntohs(packet_header->urgent_pointer));
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    char *interface = argv[1];

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(interface, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Error opening interface: %s\n", errbuf);
        return 1;
    }

    while (1) {
        struct pcap_pkthdr *header;
        const uint8_t *packet;
        int res = pcap_next_ex(handle, &header, &packet);

        if (res == 1) {
            print_packet(packet, header->len);
        } else if (res == 0) {
            printf("No packets received\n");
        } else if (res == -1) {
            printf("Error reading packet: %s\n", pcap_geterr(handle));
        } else if (res == -2) {
            printf("Error reading packet: %s\n", pcap_geterr(handle));
        }
    }

    pcap_close(handle);
    return 0;
}