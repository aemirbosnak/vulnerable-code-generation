//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <pcap.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_PACKET_SIZE 65536

struct ip_header {
    unsigned char ip_version:4;
    unsigned char ip_header_length:4;
    unsigned char ip_tos;
    unsigned short ip_total_length;
    unsigned short ip_id;
    unsigned short ip_flags:3;
    unsigned short ip_fragment_offset:13;
    unsigned char ip_ttl;
    unsigned char ip_protocol;
    unsigned short ip_checksum;
    struct in_addr ip_source_address;
    struct in_addr ip_destination_address;
};

struct tcp_header {
    unsigned short tcp_source_port;
    unsigned short tcp_destination_port;
    unsigned int tcp_sequence_number;
    unsigned int tcp_acknowledgment_number;
    unsigned char tcp_data_offset:4;
    unsigned char tcp_reserved:3;
    unsigned char tcp_flags:8;
    unsigned short tcp_window_size;
    unsigned short tcp_checksum;
    unsigned short tcp_urgent_pointer;
};

void print_ip_header(struct ip_header *ip) {
    printf("IP Header:\n");
    printf("  Version: %d\n", ip->ip_version);
    printf("  Header Length: %d bytes\n", ip->ip_header_length * 4);
    printf("  Type of Service: %d\n", ip->ip_tos);
    printf("  Total Length: %d bytes\n", ntohs(ip->ip_total_length));
    printf("  Identification: %d\n", ntohs(ip->ip_id));
    printf("  Flags: %d\n", ip->ip_flags);
    printf("  Fragment Offset: %d\n", ntohs(ip->ip_fragment_offset));
    printf("  Time to Live: %d\n", ip->ip_ttl);
    printf("  Protocol: %d\n", ip->ip_protocol);
    printf("  Checksum: %d\n", ntohs(ip->ip_checksum));
    printf("  Source Address: %s\n", inet_ntoa(ip->ip_source_address));
    printf("  Destination Address: %s\n", inet_ntoa(ip->ip_destination_address));
}

void print_tcp_header(struct tcp_header *tcp) {
    printf("TCP Header:\n");
    printf("  Source Port: %d\n", ntohs(tcp->tcp_source_port));
    printf("  Destination Port: %d\n", ntohs(tcp->tcp_destination_port));
    printf("  Sequence Number: %u\n", ntohl(tcp->tcp_sequence_number));
    printf("  Acknowledgment Number: %u\n", ntohl(tcp->tcp_acknowledgment_number));
    printf("  Data Offset: %d bytes\n", tcp->tcp_data_offset * 4);
    printf("  Flags: %d\n", tcp->tcp_flags);
    printf("  Window Size: %d\n", ntohs(tcp->tcp_window_size));
    printf("  Checksum: %d\n", ntohs(tcp->tcp_checksum));
    printf("  Urgent Pointer: %d\n", ntohs(tcp->tcp_urgent_pointer));
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *interface = argv[1];
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(interface, MAX_PACKET_SIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening interface: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    while (1) {
        struct pcap_pkthdr *header;
        const unsigned char *packet;
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == -1) {
            fprintf(stderr, "Error reading packet: %s\n", pcap_geterr(handle));
            break;
        } else if (res == 0) {
            continue;
        }

        struct ip_header *ip = (struct ip_header *)packet;
        if (ip->ip_protocol != IPPROTO_TCP) {
            continue;
        }

        struct tcp_header *tcp = (struct tcp_header *)(packet + ip->ip_header_length * 4);
        print_ip_header(ip);
        print_tcp_header(tcp);
        printf("\n");
    }

    pcap_close(handle);
    return EXIT_SUCCESS;
}