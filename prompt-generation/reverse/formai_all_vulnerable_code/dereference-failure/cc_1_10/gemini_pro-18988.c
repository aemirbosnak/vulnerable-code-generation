//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

void usage() {
    printf("Usage: wireless-network-scanner <interface>\n");
    printf("Example: wireless-network-scanner wlan0\n");
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        usage();
    }

    char *interface = argv[1];
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(interface, 65535, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live(): %s\n", errbuf);
        exit(1);
    }

    struct pcap_pkthdr *header;
    const u_char *packet;
    int ret;
    while ((ret = pcap_next_ex(handle, &header, &packet)) >= 0) {
        if (ret == 0) {
            continue;
        }

        // Parse the 802.11 header
        const u_char *llc = packet + 14;
        if (llc[0] == 0xaa && llc[1] == 0xaa && llc[2] == 0x03) {
            // This is an 802.11 management frame
            // Parse the management frame header
            const u_char *subtype = llc + 3;
            const u_char *to_ds = llc + 11;
            const u_char *from_ds = llc + 12;
            const u_char *ssid_length = llc + 32;
            const u_char *ssid = llc + 34;

            // Check if this is a beacon management frame
            if (*subtype == 0x80 || *subtype == 0x00) {
                // This is a beacon management frame
                // Get the SSID
                char ssid_str[33];
                memcpy(ssid_str, ssid, *ssid_length);
                ssid_str[*ssid_length] = '\0';

                // Print the SSID and the BSSID
                printf("%s (%02x:%02x:%02x:%02x:%02x:%02x)\n", ssid_str, packet[16], packet[17], packet[18], packet[19], packet[20], packet[21]);
            }
        }
    }

    if (ret == -1) {
        fprintf(stderr, "pcap_next_ex(): %s\n", pcap_geterr(handle));
    }

    pcap_close(handle);

    return 0;
}