//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>

#define MAX_PACKET_SIZE 1536

int main(int argc, char **argv) {
    char *interface = "wlan0";  // change this to your wireless interface name
    char filter_expression[] = "ether proto 0x0800";  // filter only IP packets
    struct bpf_program filter;
    bpf_u_int32 mask, net;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    const u_char *packet;
    struct pcap_pkthdr packet_header;
    int res;

    // retrieve the network mask and network address of the given interface
    if(pcap_lookupnet(interface, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Failed to get network info: %s\n", errbuf);
        exit(1);
    }

    // open the wireless interface in monitor mode
    handle = pcap_open_live(interface, MAX_PACKET_SIZE, 1, 0, errbuf);
    if(handle == NULL) {
        fprintf(stderr, "Failed to open device %s: %s\n", interface, errbuf);
        exit(1);
    }
    if(pcap_set_rfmon(handle, 1) != 0) {  // enable monitor mode
        fprintf(stderr, "Failed to enable monitor mode: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // compile the filter expression
    if(pcap_compile(handle, &filter, filter_expression, 0, net) == -1) {
        fprintf(stderr, "Failed to compile the filter expression: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // apply the filter to the interface
    if(pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Failed to apply the filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // enter the main loop to capture packets
    while((packet = pcap_next(handle, &packet_header)) != NULL) {
        // parse the ethernet header of the packet
        struct ether_header *eth_header = (struct ether_header *) packet;

        // if the packet is an IP packet, print the source and destination MAC address
        if(ntohs(eth_header->ether_type) == ETHERTYPE_IP) {
            char src_mac_str[18], dst_mac_str[18];
            sprintf(src_mac_str, "%02X:%02X:%02X:%02X:%02X:%02X", 
                    eth_header->ether_shost[0], eth_header->ether_shost[1],
                    eth_header->ether_shost[2], eth_header->ether_shost[3],
                    eth_header->ether_shost[4], eth_header->ether_shost[5]);
            sprintf(dst_mac_str, "%02X:%02X:%02X:%02X:%02X:%02X", 
                    eth_header->ether_dhost[0], eth_header->ether_dhost[1],
                    eth_header->ether_dhost[2], eth_header->ether_dhost[3],
                    eth_header->ether_dhost[4], eth_header->ether_dhost[5]);
            printf("Source MAC: %s\n", src_mac_str);
            printf("Destination MAC: %s\n", dst_mac_str);
        }
    }

    // clean up
    pcap_freecode(&filter);
    pcap_close(handle);
    return 0;
}