//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define SNAP_LEN 1518   // max number of bytes to capture
#define ETHER_ADDR_LEN 6

// An example of a "denied" IP address and port
const char *DENIED_IP = "192.168.1.100"; // Denied IP address
const int DENIED_PORT = 8080;             // Denied port

// A utility function to print packet details
void print_packet_info(const struct ip *ip_header, const struct tcphdr *tcp_header) {
    char src_ip[INET_ADDRSTRLEN];
    char dst_ip[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &ip_header->ip_src, src_ip, sizeof(src_ip));
    inet_ntop(AF_INET, &ip_header->ip_dst, dst_ip, sizeof(dst_ip));

    printf("Packet information:\n");
    printf("Source IP: %s\n", src_ip);
    printf("Destination IP: %s\n", dst_ip);
    printf("Source port: %d\n", ntohs(tcp_header->source));
    printf("Destination port: %d\n", ntohs(tcp_header->dest));
}

// Packet capture callback function
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    const struct ip *ip_header;
    const struct tcphdr *tcp_header;

    // Pointer arithmetic to locate IP header
    ip_header = (struct ip *)(packet + 14); // skip Ethernet header

    // skip non-TCP packets
    if (ip_header->ip_p != IPPROTO_TCP) {
        return;
    }

    // Pointer arithmetic to locate TCP header
    tcp_header = (struct tcphdr *)(packet + 14 + (ip_header->ip_hl * 4));

    // Convert IP address strings for comparison
    char src_ip[INET_ADDRSTRLEN];
    char dst_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &ip_header->ip_src, src_ip, sizeof(src_ip));
    inet_ntop(AF_INET, &ip_header->ip_dst, dst_ip, sizeof(dst_ip));

    // Check for denied conditions
    if ((strcmp(src_ip, DENIED_IP) == 0 && ntohs(tcp_header->dest) == DENIED_PORT) ||
        (strcmp(dst_ip, DENIED_IP) == 0 && ntohs(tcp_header->source) == DENIED_PORT)) {
        printf("Blocked packet:\n");
        print_packet_info(ip_header, tcp_header);
        printf("Packet blocked due to firewall rules.\n\n");
    } else {
        // Print allowed packet information
        printf("Allowed packet:\n");
        print_packet_info(ip_header, tcp_header);
        printf("Packet allowed.\n\n");
    }
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs, *device;
    char errbuf[PCAP_ERRBUF_SIZE];
    
    // Get the list of available devices
    if (pcap_findalldevs(&alldevs, errbuf) != 0) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return 1;
    }

    // Print list of devices
    printf("Available devices:\n");
    for (device = alldevs; device != NULL; device = device->next) {
        printf("%s\n", device->name);
    }

    // Select the first network device
    if (alldevs == NULL) {
        fprintf(stderr, "No network devices found!\n");
        return 1;
    }

    // Open the device for packet capture
    pcap_t *handle = pcap_open_live(alldevs->name, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        return 1;
    }

    printf("Starting packet capture on %s...\n", alldevs->name);

    // Start packet capture loop
    pcap_loop(handle, 0, packet_handler, NULL);

    // Cleanup
    pcap_close(handle);
    pcap_freealldevs(alldevs);
    return 0;
}