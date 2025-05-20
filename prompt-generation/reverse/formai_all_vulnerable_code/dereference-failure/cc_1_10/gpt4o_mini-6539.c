//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>

#define MAX_PACKET_SIZE 65536

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured: Length: %d\n", header->len);
    for (int i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

void display_error(const char *error_message) {
    fprintf(stderr, "Error: %s\n", error_message);
}

void get_interface(char *dev) {
    char errbuf[PCAP_ERRBUF_SIZE];
    if (pcap_findalldevs(&dev, errbuf) == -1) {
        display_error(errbuf);
        exit(EXIT_FAILURE);
    }
}

int main(void) {
    char *dev; // Device to capture packets from
    char errbuf[PCAP_ERRBUF_SIZE]; // Buffer for error messages
    pcap_t *handle; // Packet capture handle

    get_interface(dev);

    printf("Using device: %s\n", dev);
    
    handle = pcap_open_live(dev, MAX_PACKET_SIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        display_error(errbuf);
        exit(EXIT_FAILURE);
    }

    printf("Starting capture... (Press CTRL+C to stop)\n");

    pcap_loop(handle, 0, packet_handler, NULL);

    pcap_close(handle);
    free(dev);

    printf("Capture finished!\n");
    return 0;
}