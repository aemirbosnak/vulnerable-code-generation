//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: single-threaded
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SNAPLEN 1024
#define PCAP_ERRBUF_SIZE 256
#define PROMISCUOUS 1
#define TIMEOUT 1000

/* Function to print the contents of a packet */
void print_packet(const u_char *packet, size_t len) {
    int i;

    printf("Packet length: %d bytes\n", len);

    for (i = 0; i < len; i++) {
        printf("%02x ", packet[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }

    printf("\n\n");
}

/* Main function */
int main(int argc, char **argv) {
    char *device;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr *header;
    const u_char *packet;

    /* Get the device to capture packets from */
    if (argc < 2) {
        device = pcap_lookupdev(errbuf);
        if (device == NULL) {
            fprintf(stderr, "Error finding a device: %s\n", errbuf);
            return 1;
        }
    } else {
        device = argv[1];
    }

    /* Open the device for capturing packets */
    handle = pcap_open_live(device, SNAPLEN, PROMISCUOUS, TIMEOUT, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        return 1;
    }

    /* Start capturing packets */
    while (1) {
        /* Wait for a packet to arrive */
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 0) {
            continue;
        } else if (res == -1) {
            fprintf(stderr, "Error capturing packet: %s\n", pcap_geterr(handle));
            break;
        } else if (res == -2) {
            break;
        }

        /* Print the contents of the packet */
        print_packet(packet, header->len);
    }

    /* Close the device */
    pcap_close(handle);

    return 0;
}