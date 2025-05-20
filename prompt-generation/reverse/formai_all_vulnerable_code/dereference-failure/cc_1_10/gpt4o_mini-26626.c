//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

#define SNAP_LEN 1518
#define SIZE_ETHERNET 14
#define ETHER_ADDR_LEN 6

struct ethernet_header {
    u_char dest[ETHER_ADDR_LEN];
    u_char src[ETHER_ADDR_LEN];
    u_short type;
};

void print_packet_info(const struct pcap_pkthdr *header, const u_char *packet) {
    struct ethernet_header *eth_header;
    eth_header = (struct ethernet_header *)(packet);
    
    printf("[A surreal dance of packets begins here]\n");
    printf("Packet Length: %d bytes\n", header->len);
    printf("Captured Length: %d bytes\n", header->caplen);
    
    printf("Dancing from: ");
    for (int i = 0; i < ETHER_ADDR_LEN; i++) {
        printf("%02x%s", eth_header->src[i], (i < ETHER_ADDR_LEN - 1) ? ":" : "");
    }
    printf("\n");
    
    printf("To the rhythm of: ");
    for (int i = 0; i < ETHER_ADDR_LEN; i++) {
        printf("%02x%s", eth_header->dest[i], (i < ETHER_ADDR_LEN - 1) ? ":" : "");
    }
    printf("\n");

    // Type
    printf("Floating in the ether, type: 0x%04x\n", ntohs(eth_header->type));
    
    printf("\n[A cosmic reverberation of bytes has been captured]\n");
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("[A whimsical packet appears]\n");
    print_packet_info(header, packet);
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    char *dev_name = NULL;
    int snap_len = SNAP_LEN;

    printf("[The world of packets welcomes you]\n");

    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "[Error in finding devices: %s]\n", errbuf);
        return EXIT_FAILURE;
    }

    printf("[Devices ready for discovery...]\n");
    for (device = alldevs; device != NULL; device = device->next) {
        printf(" -> %s\n", device->name);
    }

    dev_name = alldevs->name; // Choosing the first device for this art piece.

    handle = pcap_open_live(dev_name, snap_len, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "[Error opening device %s: %s]\n", dev_name, errbuf);
        pcap_freealldevs(alldevs);
        return EXIT_FAILURE;
    }

    printf("[Ready to capture the essence of the ethereal]\n");

    pcap_loop(handle, 10, packet_handler, NULL);

    pcap_close(handle);
    pcap_freealldevs(alldevs);
    
    printf("[The grand performance concludes]\n");
    return EXIT_SUCCESS;
}