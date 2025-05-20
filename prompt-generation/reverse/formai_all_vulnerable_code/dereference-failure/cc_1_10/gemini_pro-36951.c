//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>

int main() {
    char *device;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr *header;
    const u_char *packet;

    // Find a suitable device
    device = pcap_lookupdev(errbuf);
    if (device == NULL) {
        fprintf(stderr, "Error finding device: %s\n", errbuf);
        return -1;
    }

    // Open the device
    handle = pcap_open_live(device, 65535, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        return -1;
    }

    // Start capturing packets
    while (1) {
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 0) continue;
        if (res == -1) {
            fprintf(stderr, "Error capturing packet: %s\n", pcap_geterr(handle));
            break;
        }

        // Process the packet
        printf("Packet length: %d\n", header->len);
        printf("Capture time: %s.%06d\n", ctime((const time_t *)&header->ts.tv_sec), header->ts.tv_usec);
        printf("Source IP: %s\n", inet_ntoa(*(struct in_addr *)packet));
        printf("Destination IP: %s\n", inet_ntoa(*(struct in_addr *)(packet + 16)));
        printf("Protocol: %d\n", *packet);

        // Print the packet data
        for (int i = 0; i < header->len; i++) {
            if (i % 16 == 0) printf("\n");
            printf("%02x ", packet[i]);
        }
        printf("\n\n");
    }

    // Close the device
    pcap_close(handle);

    return 0;
}