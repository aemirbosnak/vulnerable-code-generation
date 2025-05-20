//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: modular
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_PACKET_SIZE 65536

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);
void print_packet_info(const u_char *packet, struct pcap_pkthdr header);

int main(int argc, char *argv[]) {
    pcap_if_t *all_devs;
    pcap_if_t *device;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    if (pcap_findalldevs(&all_devs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    printf("Available devices:\n");
    for (device = all_devs; device != NULL; device = device->next) {
        printf("%s\n", device->name);
    }

    // Choosing the first device for monitoring
    device = all_devs;
    if (device == NULL) {
        fprintf(stderr, "No devices found!\n");
        return EXIT_FAILURE;
    }

    handle = pcap_open_live(device->name, MAX_PACKET_SIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Unable to open device %s: %s\n", device->name, errbuf);
        return EXIT_FAILURE;
    }

    printf("Listening on %s...\n", device->name);
    pcap_loop(handle, 0, packet_handler, NULL);

    pcap_freealldevs(all_devs);
    pcap_close(handle);
    return EXIT_SUCCESS;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured! Length: %d bytes\n", header->len);
    print_packet_info(packet, *header);
}

void print_packet_info(const u_char *packet, struct pcap_pkthdr header) {
    struct ether_header {
        u_char  ether_dst[6];  /* destination eth addr */
        u_char  ether_src[6];  /* source ether addr    */
        u_short ether_type;     /* packet type ID field */
    };
    
    const struct ether_header *eth_header = (struct ether_header *)packet;

    printf("Source MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
           eth_header->ether_src[0],
           eth_header->ether_src[1],
           eth_header->ether_src[2],
           eth_header->ether_src[3],
           eth_header->ether_src[4],
           eth_header->ether_src[5]);

    printf("Destination MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
           eth_header->ether_dst[0],
           eth_header->ether_dst[1],
           eth_header->ether_dst[2],
           eth_header->ether_dst[3],
           eth_header->ether_dst[4],
           eth_header->ether_dst[5]);

    printf("Ether Type: %04x\n", ntohs(eth_header->ether_type));
    
    // Just printing a snippet of the packet data
    printf("Packet Data (first 16 bytes): ");
    for (int i = 0; i < 16 && i < header.len; i++) {
        printf("%02x ", packet[i]);
    }
    printf("\n\n");
}