//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <string.h>

#define MAXBYTES2CAPTURE 2048

// Function to analyze and print packet information
void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ip *ip_header;
    struct tcphdr *tcp_header;
    struct udphdr *udp_header;

    // Point to the start of the IP header
    ip_header = (struct ip *)(packet + 14); // 14 is the size of the Ethernet header

    // Print some details of the packet
    printf("Packet captured:\n");
    printf("Source IP: %s\n", inet_ntoa(ip_header->ip_src));
    printf("Destination IP: %s\n", inet_ntoa(ip_header->ip_dst));

    switch (ip_header->ip_p) {
        case IPPROTO_TCP:
            tcp_header = (struct tcphdr *)(packet + 14 + (ip_header->ip_hl << 2));
            printf("Protocol: TCP\n");
            printf("Source Port: %d\n", ntohs(tcp_header->source));
            printf("Destination Port: %d\n", ntohs(tcp_header->dest));
            break;
        case IPPROTO_UDP:
            udp_header = (struct udphdr *)(packet + 14 + (ip_header->ip_hl << 2));
            printf("Protocol: UDP\n");
            printf("Source Port: %d\n", ntohs(udp_header->source));
            printf("Destination Port: %d\n", ntohs(udp_header->dest));
            break;
        default:
            printf("Protocol: Other\n");
            break;
    }
    printf("------\n");
}

// Callback function for pcap_loop()
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    process_packet(args, header, packet);
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    int device_number = 0;

    // List available devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return 1;
    }

    // Display available devices
    printf("Available devices:\n");
    for (device = alldevs; device != NULL; device = device->next) {
        printf("%d. %s\n", ++device_number, device->name);
    }

    // Check if there are no devices
    if (device_number == 0) {
        printf("No devices found! Exiting...\n");
        return 1;
    }

    // Prompt user to select device
    int selected_device = 0;
    printf("Select a device (1-%d): ", device_number);
    scanf("%d", &selected_device);
    if (selected_device < 1 || selected_device > device_number) {
        printf("Invalid device selected! Exiting...\n");
        return 1;
    }

    // Get the selected device
    device = alldevs;
    for (int i = 1; i < selected_device; i++) {
        device = device->next;
    }

    // Open selected device in promiscuous mode
    handle = pcap_open_live(device->name, MAXBYTES2CAPTURE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device->name, errbuf);
        return 1;
    }

    // Start capturing packets
    printf("Starting packet capture on %s...\n", device->name);
    pcap_loop(handle, 0, packet_handler, NULL);

    // Clean up
    pcap_freealldevs(alldevs);
    pcap_close(handle);
    return 0;
}