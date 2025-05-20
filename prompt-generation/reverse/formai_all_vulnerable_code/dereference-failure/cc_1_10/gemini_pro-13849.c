//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pcap.h>
#include <time.h>

#define BUFSIZE 65536

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        return -1;
    }

    // Open the network interface
    char *dev = argv[1];
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(dev, BUFSIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live: %s\n", errbuf);
        return -1;
    }

    // Start the capture loop
    struct pcap_pkthdr *header;
    const u_char *packet;
    while (1) {
        // Get the next packet
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == -1) {
            fprintf(stderr, "pcap_next_ex: %s\n", pcap_geterr(handle));
            break;
        } else if (res == 0) {
            continue;
        }

        // Print the packet header
        printf("Packet length: %d\n", header->len);
        printf("Packet timestamp: %s\n", ctime((const time_t *)&header->ts.tv_sec));

        // Print the packet data
        for (int i = 0; i < header->len; i++) {
            if (i % 16 == 0) {
                printf("\n");
            }
            printf("%02x ", packet[i]);
        }
        printf("\n\n");
    }

    // Close the network interface
    pcap_close(handle);

    return 0;
}