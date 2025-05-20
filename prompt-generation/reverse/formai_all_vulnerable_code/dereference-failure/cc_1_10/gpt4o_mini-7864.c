//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <string.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ip *ip_header;
    struct tcphdr *tcp_header;
    struct udphdr *udp_header;

    int size_ip;
    int size_tcp;
    int size_udp;

    /* Process the IP header */
    ip_header = (struct ip *)(packet + 14); // Ethernet header is 14 bytes
    size_ip = ip_header->ip_hl * 4;
    
    if (size_ip < 20) {
        fprintf(stderr, "Invalid IP header size\n");
        return;
    }

    printf("Packet captured: Source IP: %s\n", inet_ntoa(ip_header->ip_src));
    printf("Destination IP: %s\n", inet_ntoa(ip_header->ip_dst));
    printf("Protocol: %d\n", ip_header->ip_p);

    /* Processing TCP packets */
    if (ip_header->ip_p == IPPROTO_TCP) {
        tcp_header = (struct tcphdr*)(packet + 14 + size_ip);
        size_tcp = tcp_header->doff * 4;
        
        printf("TCP Packet:\n");
        printf("Source Port: %d\n", ntohs(tcp_header->source));
        printf("Destination Port: %d\n", ntohs(tcp_header->dest));
        printf("Sequence Number: %u\n", ntohl(tcp_header->seq));
        printf("Acknowledgment Number: %u\n", ntohl(tcp_header->ack_seq));
        printf("====================\n");
    }
    
    /* Processing UDP packets */
    else if (ip_header->ip_p == IPPROTO_UDP) {
        udp_header = (struct udphdr*)(packet + 14 + size_ip);
        size_udp = sizeof(struct udphdr);
        
        printf("UDP Packet:\n");
        printf("Source Port: %d\n", ntohs(udp_header->source));
        printf("Destination Port: %d\n", ntohs(udp_header->dest));
        printf("====================\n");
    }
    
    else {
        printf("Non-TCP/UDP Packet detected, Protocol: %d\n", ip_header->ip_p);
        printf("====================\n");
    }
}

int main(int argc, char **argv) {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    /* Find all interfaces */
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
        return 1;
    }

    /* Find the device specified in command line */
    for (device = alldevs; device != NULL; device = device->next) {
        if (strcmp(device->name, argv[1]) == 0) {
            break;
        }
    }

    if (device == NULL) {
        fprintf(stderr, "Device %s not found\n", argv[1]);
        return 1;
    }

    /* Open the device for packet capture */
    handle = pcap_open_live(device->name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        return 1;
    }

    /* Start packet capture */
    printf("Listening on %s...\n", device->name);
    pcap_loop(handle, 0, packet_handler, NULL);

    pcap_close(handle);
    pcap_freealldevs(alldevs);
    return 0;
}