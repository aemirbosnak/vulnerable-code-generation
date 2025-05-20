//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: mind-bending
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Colors for mind-bending output
#define RESET       "\x1b[0m"
#define RED         "\x1b[31m"
#define GREEN       "\x1b[32m"
#define YELLOW      "\x1b[33m"
#define BLUE        "\x1b[34m"
#define MAGENTA     "\x1b[35m"
#define CYAN        "\x1b[36m"
#define WHITE       "\x1b[37m"
#define BLINK       "\x1b[5m"

// Twinkling star effect for each packet
#define TWINKLE     "\x1b[5;3;33m*\x1b[0m"

// Function to print packet information
void print_packet(const struct pcap_pkthdr *header, const unsigned char *data) {
    printf("----------------------------------------------------------\n");

    // Mind-bending packet header
    printf(YELLOW "[%s %03d ms", "Packet", header->ts.tv_sec % 1000);
    printf(CYAN " | %03d bytes", header->len);
    printf(MAGENTA " | %02x:%02x:%02x:%02x:%02x:%02x]\n", data[6], data[7], data[8], data[9], data[10], data[11]);

    // Twinkling star effect
    printf(TWINKLE);

    // EtherType identification
    uint16_t ether_type = ((uint16_t)data[12] << 8) | data[13];
    switch (ether_type) {
        case 0x0800: printf(GREEN " IPv4"); break;
        case 0x0806: printf(BLUE " ARP"); break;
        default: printf(RED " Unknown"); break;
    }

    // Blink for IPv4 packets
    if (ether_type == 0x0800) printf(BLINK);

    printf(RESET " - ");

    // IPv4 source and destination addresses
    if (ether_type == 0x0800) {
        printf(GREEN "%d.%d.%d.%d -> %d.%d.%d.%d\n",
            data[26], data[27], data[28], data[29],
            data[30], data[31], data[32], data[33]);
    }

    // IPv4 protocol identification
    if (ether_type == 0x0800) {
        switch (data[23]) {
            case 1: printf(RED " ICMP"); break;
            case 6: printf(CYAN " TCP"); break;
            case 17: printf(MAGENTA " UDP"); break;
            default: printf(YELLOW " Unknown"); break;
        }
    }

    // Twinkling star effect
    printf(TWINKLE);
}

// Function to capture packets
void capture_packets(char *device) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        return;
    }

    // Loop forever, capturing packets
    while (1) {
        struct pcap_pkthdr *header;
        const unsigned char *data;
        int res = pcap_next_ex(handle, &header, &data);
        if (res == 0) continue;
        if (res == -1) {
            fprintf(stderr, "Error capturing packet: %s\n", pcap_geterr(handle));
            break;
        }
        print_packet(header, data);
    }

    pcap_close(handle);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <device>\n", argv[0]);
        return EXIT_FAILURE;
    }

    capture_packets(argv[1]);
    return EXIT_SUCCESS;
}