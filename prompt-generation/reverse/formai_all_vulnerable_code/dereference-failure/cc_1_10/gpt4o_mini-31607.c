//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <string.h>

// Callback function that will be called by pcap for each captured packet
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct iphdr *ip_header;
    struct tcphdr *tcp_header;
    struct udphdr *udp_header;
    char src_ip[INET_ADDRSTRLEN], dst_ip[INET_ADDRSTRLEN];

    ip_header = (struct iphdr *)(packet + 14); // Ethernet header is 14 bytes
    inet_ntop(AF_INET, &ip_header->saddr, src_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &ip_header->daddr, dst_ip, INET_ADDRSTRLEN);

    printf("Captured a packet:\n");
    printf("Source IP: %s\n", src_ip);
    printf("Destination IP: %s\n", dst_ip);
    printf("Packet Size: %d bytes\n", header->len);
    
    // Check if TCP
    if (ip_header->protocol == IPPROTO_TCP) {
        tcp_header = (struct tcphdr *)(packet + 14 + ip_header->ihl * 4);
        printf("Protocol: TCP\n");
        printf("Source Port: %d\n", ntohs(tcp_header->source));
        printf("Destination Port: %d\n", ntohs(tcp_header->dest));
    }
    // Check if UDP
    else if (ip_header->protocol == IPPROTO_UDP) {
        udp_header = (struct udphdr *)(packet + 14 + ip_header->ihl * 4);
        printf("Protocol: UDP\n");
        printf("Source Port: %d\n", ntohs(udp_header->source));
        printf("Destination Port: %d\n", ntohs(udp_header->dest));
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs;
    pcap_if_t *device;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // Get the list of devices
    if (pcap_findalldevs(&alldevs, errbuf) != 0) {
        fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
        return 1;
    }

    // Print the list and prompt user to select a device
    printf("Available devices:\n");
    for (device = alldevs; device != NULL; device = device->next) {
        printf("%s\n", device->name);
    }

    // For simplicity, let's just use the first device in the list
    if (alldevs == NULL) {
        fprintf(stderr, "No devices found.\n");
        return 1;
    }
    
    // Set the device to capture on
    const char *device_name = alldevs->name;
    printf("Using device: %s\n", device_name);

    // Open the device for capturing
    handle = pcap_open_live(device_name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device_name, errbuf);
        return 1;
    }

    // Start capturing packets
    printf("Starting packet capture...\n");
    pcap_loop(handle, 10, packet_handler, NULL); // Capture 10 packets

    // Cleanup
    pcap_freealldevs(alldevs);
    pcap_close(handle);
    return 0;
}