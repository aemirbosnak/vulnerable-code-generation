//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SIZE_ETHERNET 14
#define SNAP_LEN 65535

// Enchantment of the Packet
struct ethheader {
    u_char  ether_dhost[6]; 
    u_char  ether_shost[6]; 
    u_short ether_type;     
};

// Dance of the Ethers
void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ethheader *eth = (struct ethheader *)(packet);
    printf("A waltz in the shadows of bytes:\n");

    printf("Ethernet Frame:\n");
    printf("   |- Source Address:  %02x:%02x:%02x:%02x:%02x:%02x\n", 
           eth->ether_shost[0], eth->ether_shost[1], eth->ether_shost[2],
           eth->ether_shost[3], eth->ether_shost[4], eth->ether_shost[5]);
    printf("   |- Destination Address: %02x:%02x:%02x:%02x:%02x:%02x\n",
           eth->ether_dhost[0], eth->ether_dhost[1], eth->ether_dhost[2],
           eth->ether_dhost[3], eth->ether_dhost[4], eth->ether_dhost[5]);
    printf("   |- Ether Type: %04x\n", ntohs(eth->ether_type));
    printf("When the moon spills its silver light upon the data...\n");
}

// The Canvas of Captures
void capture_packets(const char *device) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    handle = pcap_open_live(device, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Failed to open device %s: %s\n", device, errbuf);
        exit(EXIT_FAILURE);
    }

    printf("Awaken, specter of the network, arise from ethereal depths!\n");
    pcap_loop(handle, 10, process_packet, NULL);
    pcap_close(handle);
}

// The Multifarious Devices
void print_devices() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_if_t *alldevsp, *device;

    if (pcap_findalldevs(&alldevsp, errbuf) == -1) {
        fprintf(stderr, "Failed to find devices: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    printf("A carnival of devices unfurls:\n");
    for (device = alldevsp; device != NULL; device = device->next) {
        printf(" - %s\n", device->name);
    }
    pcap_freealldevs(alldevsp);
}

// The Prelude of Input
int main() {
    printf("Welcome to the surrealist realm of packet capture.\n");
    print_devices();

    char device_name[100];
    printf("Whisper the name of your chosen device: ");
    scanf("%99s", device_name);

    capture_packets(device_name);

    return EXIT_SUCCESS; // With the grace of the unseen spirits
}