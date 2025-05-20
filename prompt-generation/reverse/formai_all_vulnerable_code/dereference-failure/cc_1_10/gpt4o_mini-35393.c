//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Donald Knuth
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <netinet/ether.h>
#include <string.h>

#define SNAP_LEN 65535  // Maximum bytes to capture per packet

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);
void print_ip_header(const struct iphdr *ip_header);
void print_tcp_header(const struct tcphdr *tcp_header);
void print_udp_header(const struct udphdr *udp_header);

int main(int argc, char **argv) {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    int device_index = 0;

    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Could not find devices: %s\n", errbuf);
        return 1;
    }

    printf("Available Devices:\n");
    for (device = alldevs; device != NULL; device = device->next) {
        printf("%d. %s - %s\n", ++device_index, device->name, device->description ? device->description : "No description");
    }
    
    if (device_index == 0) {
        fprintf(stderr, "No devices found.\n");
        return 1;
    }

    printf("Select a device (1-%d): ", device_index);
    int selected_device;
    scanf("%d", &selected_device);

    if (selected_device < 1 || selected_device > device_index) {
        fprintf(stderr, "Invalid device selection.\n");
        return 1;
    }

    for (device = alldevs, selected_device--; selected_device > 0; device = device->next, selected_device--);
    
    handle = pcap_open_live(device->name, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device->name, errbuf);
        return 1;
    }

    printf("Listening on %s...\n", device->name);
    pcap_loop(handle, 0, packet_handler, NULL);

    pcap_freealldevs(alldevs);
    pcap_close(handle);
    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    const struct ether_header *eth_header = (struct ether_header *)packet;
    const struct iphdr *ip_header = (struct iphdr *)(packet + sizeof(struct ether_header));

    printf("Packet Capture:\n");
    printf("----------------------------------------\n");
    printf("Source MAC: %s\n", ether_ntoa((struct ether_addr *)eth_header->ether_shost));
    printf("Destination MAC: %s\n", ether_ntoa((struct ether_addr *)eth_header->ether_dhost));
    
    print_ip_header(ip_header);
    
    // Check for TCP or UDP
    if (ip_header->protocol == IPPROTO_TCP) {
        const struct tcphdr *tcp_header = (struct tcphdr *)(packet + sizeof(struct ether_header) + sizeof(struct iphdr));
        print_tcp_header(tcp_header);
    } else if (ip_header->protocol == IPPROTO_UDP) {
        const struct udphdr *udp_header = (struct udphdr *)(packet + sizeof(struct ether_header) + sizeof(struct iphdr));
        print_udp_header(udp_header);
    } else {
        printf("Other Protocol: %d\n", ip_header->protocol);
    }
    printf("----------------------------------------\n\n");
}

void print_ip_header(const struct iphdr *ip_header) {
    struct in_addr src_addr, dest_addr;
    src_addr.s_addr = ip_header->saddr;
    dest_addr.s_addr = ip_header->daddr;

    printf("Source IP: %s\n", inet_ntoa(src_addr));
    printf("Destination IP: %s\n", inet_ntoa(dest_addr));
}

void print_tcp_header(const struct tcphdr *tcp_header) {
    printf("TCP Header:\n");
    printf("Source Port: %d\n", ntohs(tcp_header->source));
    printf("Destination Port: %d\n", ntohs(tcp_header->dest));
}

void print_udp_header(const struct udphdr *udp_header) {
    printf("UDP Header:\n");
    printf("Source Port: %d\n", ntohs(udp_header->source));
    printf("Destination Port: %d\n", ntohs(udp_header->dest));
}