//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <string.h>

#define SNAP_LEN 65535  // Maximum bytes to capture per packet

// Function to capture packets
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ip *ip_header;
    struct udphdr *udp_header;

    // Extract IP header from the packet (the Ethernet header is not included)
    ip_header = (struct ip*)(packet + 14);
    // Check the IP version
    if (ip_header->ip_v == 4) {
        printf("Captured an IPv4 packet:\n");
        printf(" - Source IP: %s\n", inet_ntoa(ip_header->ip_src));
        printf(" - Destination IP: %s\n", inet_ntoa(ip_header->ip_dst));
        printf(" - Packet Length: %d bytes\n\n", ntohs(ip_header->ip_len));

        // Check for UDP (Protocol 17)
        if (ip_header->ip_p == IPPROTO_UDP) {
            udp_header = (struct udphdr*)(packet + 14 + (ip_header->ip_hl * 4));
            printf("   UDP Packet:\n");
            printf("  - Source Port: %d\n", ntohs(udp_header->source));
            printf("  - Destination Port: %d\n", ntohs(udp_header->dest));
        }
    } else {
        printf("Captured a non-IPv4 packet.\n\n");
    }
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevsp, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    int packet_count = 10; // Capture 10 packets

    // Get the list of available devices
    if (pcap_findalldevs(&alldevsp, errbuf) != 0) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Print available devices
    printf("Available Devices:\n");
    for (device = alldevsp; device != NULL; device = device->next) {
        printf(" - %s\n", device->name);
        if (device->description) {
            printf("   (%s)\n", device->description);
        }
    }

    // Prompt user to select a device
    printf("Please enter the name of the device to capture packets from: ");
    char selected_device[100];
    fgets(selected_device, sizeof(selected_device), stdin);
    selected_device[strcspn(selected_device, "\n")] = 0; // Remove the newline character

    // Open the selected device for capturing
    handle = pcap_open_live(selected_device, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device %s: %s\n", selected_device, errbuf);
        pcap_freealldevs(alldevsp);
        return EXIT_FAILURE;
    }

    // Start capturing packets
    printf("Starting packet capture on %s...\n", selected_device);
    pcap_loop(handle, packet_count, packet_handler, NULL);

    // Cleanup
    pcap_close(handle);
    pcap_freealldevs(alldevsp);
    printf("Packet capturing finished.\n");

    return EXIT_SUCCESS;
}