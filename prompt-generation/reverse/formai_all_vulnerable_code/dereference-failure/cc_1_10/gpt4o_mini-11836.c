//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pcap.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define MAX_DEVICES 10

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ip *ip_header = (struct ip *)(packet + 14); // IP header follows Ethernet header
    struct tcphdr *tcp_header = (struct tcphdr *)(packet + 14 + (ip_header->ip_hl * 4)); // TCP header follows IP header

    printf("Captured a TCP packet:\n");
    printf("Source IP: %s\n", inet_ntoa(ip_header->ip_src));
    printf("Destination IP: %s\n", inet_ntoa(ip_header->ip_dst));
    printf("Source Port: %d\n", ntohs(tcp_header->source));
    printf("Destination Port: %d\n", ntohs(tcp_header->dest));
    printf("Packet Length: %d bytes\n", header->len);
    printf("-------------------------------\n");
}

void list_devices() {
    pcap_if_t *alldevs, *device;
    char errbuf[PCAP_ERRBUF_SIZE];

    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    printf("Available Network Devices:\n");
    int i = 0;
    for (device = alldevs; device != NULL; device = device->next, i++) {
        printf("%d. %s\n", i + 1, device->name);
    }
    
    pcap_freealldevs(alldevs);
}

int main() {
    pcap_if_t *alldevs, *device;
    char errbuf[PCAP_ERRBUF_SIZE];
    int device_index;

    // List available devices
    list_devices();
    
    printf("Select a device (1 to N): ");
    scanf("%d", &device_index);
    
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    device = alldevs;
    for (int i = 1; i < device_index; i++) {
        device = device->next;
    }
    
    if (device == NULL) {
        fprintf(stderr, "Device not found.\n");
        return EXIT_FAILURE;
    }

    printf("Capturing packets on device: %s\n", device->name);
    
    pcap_t *handle = pcap_open_live(device->name, BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Error opening the device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    pcap_loop(handle, 10, process_packet, NULL); // Limit to 10 packets for demonstration

    pcap_close(handle);
    pcap_freealldevs(alldevs);
    
    return EXIT_SUCCESS;
}