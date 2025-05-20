//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: modular
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_ETHERNET 14
#define ETHER_TYPE_IP 0x0800

// Function prototypes
void packet_handler(u_char *, const struct pcap_pkthdr *, const u_char *);
void print_ip_header(const u_char *);
void print_payload(const u_char *, int);

// Network interface selection
void select_interface(char *dev) {
    char errbuf[PCAP_ERRBUF_SIZE];

    // Get a list of available devices
    pcap_if_t *alldevs, *d;
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Cannot find devices: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // Print available devices
    printf("Available network interfaces:\n");
    int i = 0;
    for (d = alldevs; d != NULL; d = d->next) {
        printf("%d. %s\n", ++i, d->name);
    }

    printf("Select an interface by number: ");
    int choice;
    scanf("%d", &choice);

    if (choice < 1 || choice > i) {
        fprintf(stderr, "Invalid choice.\n");
        pcap_freealldevs(alldevs);
        exit(EXIT_FAILURE);
    }

    // Set the device name
    d = alldevs;
    for (int j = 1; j < choice; j++) {
        d = d->next;
    }
    strcpy(dev, d->name);

    pcap_freealldevs(alldevs);
}

// Packet capturing function
void capture_packets(pcap_t *handle) {
    struct pcap_pkthdr header;
    const u_char *packet;

    while (1) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) continue; // No packet captured

        packet_handler(NULL, &header, packet);
    }
}

// Packet handler function
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // Get the IP header from the packet
    struct sniff_ethernet {
        u_char ether_dhost[6]; /* Destination host address */
        u_char ether_shost[6]; /* Source host address */
        u_short ether_type;     /* IP? ARP? RARP? etc */
    };

    const struct sniff_ethernet *ethernet = (struct sniff_ethernet *)(packet);
    
    // Filter for IP packets
    if (ntohs(ethernet->ether_type) == ETHER_TYPE_IP) {
        printf("Captured an IP packet:\n");
        print_ip_header(packet + SIZE_ETHERNET);
    }
}

// Function to print IP header information
void print_ip_header(const u_char *ip_header) {
    printf("IP Header:\n");
    unsigned char ip_ihl = (ip_header[0] & 0x0F) * 4; // Get IP header length
    printf("IP Header Length: %d bytes\n", ip_ihl);
    printf("Source IP: %d.%d.%d.%d\n", ip_header[12], ip_header[13], ip_header[14], ip_header[15]);
    printf("Destination IP: %d.%d.%d.%d\n", ip_header[16], ip_header[17], ip_header[18], ip_header[19]);
    print_payload(ip_header + ip_ihl, ntohs(*(u_short *)(ip_header + 2)) - ip_ihl); // Print payload
}

// Print payload function
void print_payload(const u_char *payload, int len) {
    printf("Payload (%d bytes):\n", len);
    for (int i = 0; i < len; i++) {
        printf("%02x ", payload[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }
    printf("\n");
}

// Main function
int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    char dev[100];

    // Select a network interface
    select_interface(dev);

    // Open the selected device for packet capturing
    pcap_t *handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", dev, errbuf);
        return EXIT_FAILURE;
    }

    printf("Capturing packets on %s...\n", dev);
    // Start capturing packets
    capture_packets(handle);

    // Close the pcap handle
    pcap_close(handle);
    return 0;
}