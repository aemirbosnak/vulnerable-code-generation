//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>

#define MAX_LEN 1518

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ip *ip_header;
    struct tcphdr *tcp_header;
    struct udphdr *udp_header;

    // Skip non-IP packets
    ip_header = (struct ip *)(packet + 14); // 14 bytes for Ethernet header

    if (ip_header->ip_v != 4) {
        printf("Not an IPv4 packet\n");
        return;
    }

    // Get protocol type
    switch (ip_header->ip_p) {
        case IPPROTO_TCP:
            tcp_header = (struct tcphdr *)(packet + 14 + ip_header->ip_hl*4);
            printf("TCP Packet: Source IP: %s, Source Port: %d, Dest Port: %d, Length: %d\n",
                   inet_ntoa(ip_header->ip_src), ntohs(tcp_header->source),
                   ntohs(tcp_header->dest), ntohs(ip_header->ip_len));
            break;

        case IPPROTO_UDP:
            udp_header = (struct udphdr *)(packet + 14 + ip_header->ip_hl*4);
            printf("UDP Packet: Source IP: %s, Source Port: %d, Dest Port: %d, Length: %d\n",
                   inet_ntoa(ip_header->ip_src), ntohs(udp_header->source),
                   ntohs(udp_header->dest), ntohs(ip_header->ip_len));
            break;

        default:
            printf("Other Protocol: %d\n", ip_header->ip_p);
            break;
    }
}

void start_packet_capture(char *device) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // Open the device for packet capture
    handle = pcap_open_live(device, MAX_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", device, errbuf);
        return;
    }

    // Start capturing packets
    pcap_loop(handle, 0, packet_handler, NULL);

    // Close the pcap handle
    pcap_close(handle);
}

void list_network_devices() {
    pcap_if_t *alldevs;
    pcap_if_t *device;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Get the list of devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
        return;
    }

    printf("Available devices:\n");
    for (device = alldevs; device != NULL; device = device->next) {
        printf("%s\n", device->name);
    }
    pcap_freealldevs(alldevs);
}

int main() {
    char device[100];

    // List available network devices
    list_network_devices();

    // Ask user for a device to sniff on
    printf("Enter the device name to capture packets: ");
    scanf("%s", device);

    // Start capturing packets
    start_packet_capture(device);

    return 0;
}