//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: excited
// Prepare for an exhilarating packet-capturing adventure!

#include <stdio.h>
#include <pcap.h>

// Let's set up our packet-sniffing parameters
int main() {
    char *device, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr *header;
    const u_char *packet;

    // Discover the available network devices
    printf("Unveiling the secret realms of your network...\n");
    device = pcap_lookupdev(errbuf);
    if (device == NULL) {
        fprintf(stderr, "Oops, our device detector failed: %s\n", errbuf);
        return 1;
    }
    printf("Aha! We've found your secret agent: %s\n", device);

    // Open a gateway to the packet dimension
    printf("Opening the ethereal gateway...\n");
    handle = pcap_open_live(device, 65535, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Gateway malfunction! %s\n", errbuf);
        return 1;
    }

    // Prepare for the packet avalanche!
    printf("Ready your nets, the packet storm is coming!\n");
    while (1) {
        // Intercept a packet from the data deluge
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 0) continue;
        if (res == -1) {
            fprintf(stderr, "Whoa there! Our packet hunter hit a snag: %s\n", pcap_geterr(handle));
            break;
        }

        // Analyze the captured packet
        printf("\nPacket Alert! We've netted a new one!\n");
        printf("Timestamp: %ld.%06ld\n", header->ts.tv_sec, header->ts.tv_usec);
        printf("Packet length: %d bytes\n", header->len);
        printf("Source MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
               packet[6], packet[7], packet[8], packet[9], packet[10], packet[11]);
        printf("Destination MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
               packet[0], packet[1], packet[2], packet[3], packet[4], packet[5]);

        // Decipher the packet's contents
        if (packet[12] == 0x08 && packet[13] == 0x00) {
            printf("We've intercepted an IPv4 packet!\n");
            printf("Source IP: %d.%d.%d.%d\n", packet[26], packet[27], packet[28], packet[29]);
            printf("Destination IP: %d.%d.%d.%d\n", packet[30], packet[31], packet[32], packet[33]);
            if (packet[23] == 0x06) {
                printf("It's a TCP packet! Let's eavesdrop on the conversation...\n");
                printf("Source port: %d\n", (packet[34] << 8) | packet[35]);
                printf("Destination port: %d\n", (packet[36] << 8) | packet[37]);
            }
        }
    }

    // Mission accomplished! Close the gateway and bid farewell
    printf("\nOur packet-sniffing adventure has reached its end.\n");
    pcap_close(handle);
    return 0;
}