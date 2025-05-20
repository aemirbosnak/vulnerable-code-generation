//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <string.h>

#define CAPTURE_COUNT 10

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ip *ip_header;
    struct tcphdr *tcp_header;
    
    // Get the IP header
    ip_header = (struct ip *)(packet + 14); // Ethernet header is 14 bytes
    tcp_header = (struct tcphdr *)(packet + 14 + (ip_header->ip_hl * 4)); // TCP header follows IP header

    char src_ip[INET_ADDRSTRLEN];
    char dst_ip[INET_ADDRSTRLEN];

    // Convert IP addresses from binary to text
    inet_ntop(AF_INET, &(ip_header->ip_src), src_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(ip_header->ip_dst), dst_ip, INET_ADDRSTRLEN);

    // Print the details of the packet
    printf("Packet captured:\n"
           "Source IP: %s\n"
           "Destination IP: %s\n"
           "Source Port: %u\n"
           "Destination Port: %u\n"
           "Sequence Number: %u\n"
           "TCP Header Length: %u\n"
           "Flags: %u\n\n",
           src_ip, dst_ip,
           ntohs(tcp_header->source), ntohs(tcp_header->dest),
           ntohl(tcp_header->seq), (unsigned int)tcp_header->doff,
           (unsigned int)tcp_header->fin |
           (unsigned int)tcp_header->syn << 1 |
           (unsigned int)tcp_header->rst << 2 |
           (unsigned int)tcp_header->psh << 3 |
           (unsigned int)tcp_header->ack << 4 |
           (unsigned int)tcp_header->urg << 5);
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs, *dev;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    int device_count = 0;
    
    // Get the list of devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
        return -1;
    }

    printf("Available interfaces:\n");
    for (dev = alldevs; dev; dev = dev->next) {
        printf("%d. %s\n", ++device_count, dev->name);
    }

    if (device_count == 0) {
        fprintf(stderr, "No devices found! Exiting.\n");
        return -1;
    }

    // Selecting the first device available for capturing
    dev = alldevs; 
    printf("Using interface: %s\n", dev->name);

    // Open the device for capturing
    handle = pcap_open_live(dev->name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        return -1;
    }

    // Set a TCP filter
    struct bpf_program filter;
    char filter_exp[] = "tcp";
    if (pcap_compile(handle, &filter, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        return -1;
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        return -1;
    }

    printf("Capturing packets... Press CTRL+C to stop.\n");
    // Capture packets
    pcap_loop(handle, CAPTURE_COUNT, packet_handler, NULL);

    // Cleanup
    pcap_freecode(&filter);
    pcap_close(handle);
    pcap_freealldevs(alldevs);

    return 0;
}