//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

int main() {
    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr *header;
    const u_char *packet;
    int i;
    char* mac_string;
    char* ssid_string;

    /* Find a device */
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find a device: %s\n", errbuf);
        return -1;
    }

    /* Open the device */
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device: %s\n", errbuf);
        return -1;
    }

    /* Start sniffing */
    while (1) {
        /* Grab a packet */
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == -1) {
            fprintf(stderr, "Error reading packet: %s\n", pcap_geterr(handle));
            return -1;
        } else if (res == 0) {
            /* Timeout elapsed */
            continue;
        }

        /* Parse the packet */
        if (header->len >= 30) {
            mac_string = malloc(18);
            snprintf(mac_string, 18, "%02X:%02X:%02X:%02X:%02X:%02X", packet[10], packet[11], packet[12], packet[13], packet[14], packet[15]);
            ssid_string = malloc(header->len - 30);
            memcpy(ssid_string, packet + 30, header->len - 30);
            // Do something with the packet
            printf("Packet length: %d\n", header->len);
            printf("Destination MAC: %s\n", mac_string);
            printf("Source MAC: %02X:%02X:%02X:%02X:%02X:%02X\n", packet[4], packet[5], packet[6], packet[7], packet[8], packet[9]);
            printf("SSID: %s\n", ssid_string);

            free(mac_string);
            free(ssid_string);
        }
    }

    /* Close the device */
    pcap_close(handle);

    return 0;
}