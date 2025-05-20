//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: creative
#include <pcap/pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// A structure to store the packet data
typedef struct {
    uint32_t ts_sec;
    uint32_t ts_usec;
    uint32_t len;
    uint8_t *data;
} packet_t;

// A function to print the packet data
void print_packet(packet_t *pkt) {
    printf("Timestamp: %u.%06u\n", pkt->ts_sec, pkt->ts_usec);
    printf("Length: %u\n", pkt->len);
    printf("Data: ");
    for (int i = 0; i < pkt->len; i++) {
        printf("%02x", pkt->data[i]);
    }
    printf("\n\n");
}

// A function to capture packets
void packet_capture(char *device) {
    // Open the device
    pcap_t *handle = pcap_open_live(device, 65535, 1, 1000, NULL);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", pcap_geterr(handle));
        return;
    }

    // Capture packets
    while (1) {
        struct pcap_pkthdr *header;
        const u_char *data;
        int res = pcap_next_ex(handle, &header, &data);
        if (res == 0) {
            continue;
        } else if (res == -1) {
            fprintf(stderr, "Error capturing packets: %s\n", pcap_geterr(handle));
            break;
        } else if (res == -2) {
            break;
        }

        // Store the packet data
        packet_t pkt;
        pkt.ts_sec = header->ts.tv_sec;
        pkt.ts_usec = header->ts.tv_usec;
        pkt.len = header->len;
        pkt.data = malloc(pkt.len);
        memcpy(pkt.data, data, pkt.len);

        // Print the packet data
        print_packet(&pkt);

        // Free the packet data
        free(pkt.data);
    }

    // Close the device
    pcap_close(handle);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <device>\n", argv[0]);
        return 1;
    }

    packet_capture(argv[1]);

    return 0;
}