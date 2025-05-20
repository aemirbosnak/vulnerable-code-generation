//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: decentralized
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>

void print_packet_info(const u_char *packet, struct pcap_pkthdr packet_header);

int main(int argc, char **argv)
{
    char *dev = NULL; // Name of the device to sniff
    char errbuf[PCAP_ERRBUF_SIZE]; // Error buffer
    pcap_t *handle; // Session handle
    struct bpf_program fp; // The compiled filter expression
    char filter_exp[] = "ip"; // The filter expression
    bpf_u_int32 mask; // The netmask of our sniffing device
    bpf_u_int32 net; // The IP of our sniffing device
    struct pcap_pkthdr packet_header; // The header that pcap gives us
    const u_char *packet; // The actual packet

    // Get device that we intend to sniff
    dev = pcap_lookupdev(errbuf);
    
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    printf("Sniffing on device: %s\n", dev);

    // Get the network address and mask of the device
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        return EXIT_FAILURE;
    }

    // Open device for capture
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return EXIT_FAILURE;
    }

    // Compile and apply the filter
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Capture packets
    while (1) {
        packet = pcap_next(handle, &packet_header);
        print_packet_info(packet, packet_header);
    }

    // Close session
    pcap_close(handle);

    return EXIT_SUCCESS;
}

void print_packet_info(const u_char *packet, struct pcap_pkthdr packet_header)
{
    struct ether_header *eth_header;
    u_int16_t ethertype;

    // Get the Ethernet header
    eth_header = (struct ether_header *) packet;

    // Get the type of the packet
    ethertype = ntohs(eth_header->ether_type);

    printf("Packet length: %d\n", packet_header.len);
    printf("Destination MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n", eth_header->ether_dhost[0], eth_header->ether_dhost[1], eth_header->ether_dhost[2], eth_header->ether_dhost[3], eth_header->ether_dhost[4], eth_header->ether_dhost[5]);
    printf("Source MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n", eth_header->ether_shost[0], eth_header->ether_shost[1], eth_header->ether_shost[2], eth_header->ether_shost[3], eth_header->ether_shost[4], eth_header->ether_shost[5]);

    if (ethertype == ETHERTYPE_IP) { // IP Packet
        const u_char *ip_packet;
        struct sockaddr_in source_address, dest_address;
        char source_address_string[INET_ADDRSTRLEN], dest_address_string[INET_ADDRSTRLEN];

        // Get the IP packet
        ip_packet = packet + sizeof(struct ether_header);

        // Get the source and destination IP addresses
        memcpy(&source_address.sin_addr, ip_packet + 12, 4);
        memcpy(&dest_address.sin_addr, ip_packet + 16, 4);
        inet_ntop(AF_INET, &(source_address.sin_addr), source_address_string, INET_ADDRSTRLEN);
        inet_ntop(AF_INET, &(dest_address.sin_addr), dest_address_string, INET_ADDRSTRLEN);

        printf("Source IP address: %s\n", source_address_string);
        printf("Destination IP address: %s\n", dest_address_string);
    }
}