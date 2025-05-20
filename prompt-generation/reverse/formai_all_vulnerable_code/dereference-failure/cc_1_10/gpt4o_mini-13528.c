//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: beginner-friendly
#include <stdio.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>

// Callback function that gets called for each captured packet
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ip *ip_header = (struct ip *)(packet + 14); // Ethernet header is 14 bytes

    // Get the source and destination IP addresses
    char source_ip[INET_ADDRSTRLEN];
    char dest_ip[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &(ip_header->ip_src), source_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(ip_header->ip_dst), dest_ip, INET_ADDRSTRLEN);

    printf("Captured packet: %s -> %s\n", source_ip, dest_ip);
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Check for proper usage
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    // Find all available devices
    if (pcap_findalldevs(&alldevs, errbuf) != 0) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return 1;
    }

    // Looking for the specified device
    for (device = alldevs; device; device = device->next) {
        if (strcmp(device->name, argv[1]) == 0) break;
    }

    if (device == NULL) {
        fprintf(stderr, "Device %s not found\n", argv[1]);
        return 1;
    }

    // Open the device for packet capturing
    handle = pcap_open_live(device->name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device %s: %s\n", device->name, errbuf);
        return 1;
    }

    // Capture packets indefinitely and call packet_handler for each captured packet
    printf("Listening on %s...\n", device->name);
    pcap_loop(handle, 0, packet_handler, NULL);

    // Cleanup
    pcap_close(handle);
    pcap_freealldevs(alldevs);

    return 0;
}