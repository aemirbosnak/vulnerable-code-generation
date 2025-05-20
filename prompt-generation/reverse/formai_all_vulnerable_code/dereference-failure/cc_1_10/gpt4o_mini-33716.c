//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: multivariable
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <netinet/ether.h>
#include <string.h>
#include <time.h>

#define SIZE_ETHERNET 14

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    const struct ether_header *eth_header;
    const struct ip *ip_header;
    const struct udphdr *udp_header;
    const struct tcphdr *tcp_header;

    char src_ip[INET_ADDRSTRLEN], dst_ip[INET_ADDRSTRLEN];
    int ip_header_length;

    eth_header = (struct ether_header *)packet;
    ip_header = (struct ip *)(packet + SIZE_ETHERNET);
    ip_header_length = ip_header->ip_hl * 4;
  
    // Convert source and destination IP addresses to string
    inet_ntop(AF_INET, &(ip_header->ip_src), src_ip, sizeof(src_ip));
    inet_ntop(AF_INET, &(ip_header->ip_dst), dst_ip, sizeof(dst_ip));

    printf("Packet captured:\n");
    printf("Source MAC: %s\n", ether_ntoa((struct ether_addr *)eth_header->ether_shost));
    printf("Destination MAC: %s\n", ether_ntoa((struct ether_addr *)eth_header->ether_dhost));
    printf("Source IP: %s\n", src_ip);
    printf("Destination IP: %s\n", dst_ip);

    if (ip_header->ip_p == IPPROTO_TCP) {
        tcp_header = (struct tcphdr *)(packet + SIZE_ETHERNET + ip_header_length);
        printf("Protocol: TCP\n");
        printf("Source Port: %d\n", ntohs(tcp_header->source));
        printf("Destination Port: %d\n", ntohs(tcp_header->dest));
    } else if (ip_header->ip_p == IPPROTO_UDP) {
        udp_header = (struct udphdr *)(packet + SIZE_ETHERNET + ip_header_length);
        printf("Protocol: UDP\n");
        printf("Source Port: %d\n", ntohs(udp_header->source));
        printf("Destination Port: %d\n", ntohs(udp_header->dest));
    } else {
        printf("Protocol: Other\n");
    }
    printf("-----------------------------------------------------\n");
}

void list_devices() {
    pcap_if_t *alldevices;
    pcap_if_t *device;

    char error_buffer[PCAP_ERRBUF_SIZE];

    if (pcap_findalldevs(&alldevices, error_buffer) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", error_buffer);
        exit(1);
    }

    printf("Available Network Devices:\n");
    for (device = alldevices; device != NULL; device = device->next) {
        printf("%s\n", device->name);
    }
    pcap_freealldevs(alldevices);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        list_devices();
        return 1;
    }

    char *dev = argv[1];
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", dev, errbuf);
        return 2;
    }

    printf("Listening on %s...\n", dev);

    pcap_loop(handle, 0, packet_handler, NULL);

    pcap_close(handle);
    return 0;
}