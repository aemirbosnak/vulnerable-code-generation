//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <string.h>

#define SNAP_LEN 65535   // Maximum bytes to capture
#define PROMISCUOUS 1    // Set promiscuous mode
#define TIMEOUT 1000     // Milliseconds before timeout

void packet_analysis(const struct pcap_pkthdr *header, const u_char *packet);
void print_ip_header(const u_char *packet, int size);
void print_tcp_header(const u_char *packet, int size);
void print_udp_header(const u_char *packet, int size);

int main(int argc, char *argv[]) {
    pcap_if_t *interfaces, *temp;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Check for correct usage
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    // Fetch the list of network interfaces
    if (pcap_findalldevs(&interfaces, errbuf) == -1) {
        fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
        return 1;
    }

    // Find the requested interface
    for (temp = interfaces; temp != NULL; temp = temp->next) {
        if (strcmp(temp->name, argv[1]) == 0) {
            break;
        }
    }

    if (temp == NULL) {
        fprintf(stderr, "Unable to find interface %s\n", argv[1]);
        pcap_freealldevs(interfaces);
        return 1;
    }

    // Open the interface for capturing
    handle = pcap_open_live(temp->name, SNAP_LEN, PROMISCUOUS, TIMEOUT, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device %s: %s\n", temp->name, errbuf);
        pcap_freealldevs(interfaces);
        return 1;
    }

    printf("Listening on %s...\n", temp->name);

    // Start capturing packets
    pcap_loop(handle, 0, packet_analysis, NULL);

    // Cleanup
    pcap_freealldevs(interfaces);
    pcap_close(handle);
    return 0;
}

void packet_analysis(const struct pcap_pkthdr *header, const u_char *packet) {
    struct ip *ip_header;

    // Get IP header from the packet
    ip_header = (struct ip *)(packet + 14); // Skip Ethernet header

    printf("Packet captured: Length = %d bytes\n", header->len);
    printf("Source IP: %s\n", inet_ntoa(ip_header->ip_src));
    printf("Destination IP: %s\n", inet_ntoa(ip_header->ip_dst));

    // Analyze protocols
    switch (ip_header->ip_p) {
        case IPPROTO_TCP:
            print_tcp_header(packet, header->len);
            break;
        case IPPROTO_UDP:
            print_udp_header(packet, header->len);
            break;
        default:
            printf("Other Protocol: %d\n", ip_header->ip_p);
            break;
    }
    printf("\n");
}

void print_tcp_header(const u_char *packet, int size) {
    struct tcphdr *tcp_header = (struct tcphdr *)(packet + 14 + sizeof(struct ip));

    printf("TCP Packet:\n");
    printf("Source Port: %d\n", ntohs(tcp_header->source));
    printf("Destination Port: %d\n", ntohs(tcp_header->dest));
    printf("Sequence Number: %u\n", ntohl(tcp_header->seq));
    printf("Acknowledgment Number: %u\n", ntohl(tcp_header->ack_seq));
    printf("Flags: %d\n", tcp_header->fin + (tcp_header->syn << 1) + (tcp_header->rst << 2) +
                             (tcp_header->psh << 3) + (tcp_header->ack << 4) + (tcp_header->urg << 5));
}

void print_udp_header(const u_char *packet, int size) {
    struct udphdr *udp_header = (struct udphdr *)(packet + 14 + sizeof(struct ip));

    printf("UDP Packet:\n");
    printf("Source Port: %d\n", ntohs(udp_header->source));
    printf("Destination Port: %d\n", ntohs(udp_header->dest));
    printf("Length: %d\n", ntohs(udp_header->len));
}