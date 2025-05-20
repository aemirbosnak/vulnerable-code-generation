//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: Claude Shannon
/* Claude Shannon's Packet Monitoring Symphony */

#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
    char *device, errbuf[PCAP_ERRBUF_SIZE];

    if (argc != 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    device = argv[1];

    pcap_t *handle = pcap_open_live(device, 65535, 1, 0, errbuf);
    if (handle == NULL) {
        printf("Error opening %s: %s\n", device, errbuf);
        return 1;
    }

    struct pcap_pkthdr *header;
    const u_char *packet;

    while (1) {
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 0) continue;
        if (res == -1) break;
        if (res == -2) {
            printf("pcap_next_ex() error: %s\n", pcap_geterr(handle));
            break;
        }

        printf("Packet length: %d bytes\n", header->len);

        int i;
        for (i = 0; i < header->len; i++) {
            printf("%02X ", packet[i]);
            if ((i + 1) % 16 == 0) printf("\n");
        }

        printf("\n");

        // Parse the packet here...

        printf("=============================================\n");
    }

    pcap_close(handle);
    return 0;
}