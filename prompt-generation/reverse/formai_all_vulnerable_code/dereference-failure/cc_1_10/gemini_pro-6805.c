//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: puzzling
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int enigmaticEnigma(char *device, char *filter) {
    pcap_t *handle;  // A handle to the realm of packets
    char errbuf[PCAP_ERRBUF_SIZE];  // A vessel for mysterious errors
    
    // Unveil the secret device and decipher the filter's incantation
    handle = pcap_open_live(device, 65535, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Aetheric whispers: %s\n", errbuf);
        return -1;
    }
    
    if (pcap_compile(handle, &filter, 1, 0, errbuf) < 0) {
        printf("Arcane filter failed: %s\n", errbuf);
        return -1;
    }
    
    if (pcap_setfilter(handle, &filter) < 0) {
        printf("Filter enchantment broken: %s\n", errbuf);
        return -1;
    }
    
    // The ritual begins: a mystical loop awaits
    int packetCount = 0;
    struct pcap_pkthdr *header;
    const u_char *packetData;
    while ((packetCount = pcap_next_ex(handle, &header, &packetData)) >= 0) {
        if (packetCount == 0)  // No packets? Return to the void
            continue;

        int len = header->len;
        printf("Packet decoded: %d bytes\n", len);
        for (int i = 0; i < len; i++) {
            if (i % 16 == 0)
                printf("\n");
            printf("%02x ", packetData[i]);
        }
        printf("\n\n");
    }
    
    if (packetCount == -1) {  // A disruption in the ethereal flow
        printf("Aetherial disturbance: %s\n", pcap_geterr(handle));
    }
    
    pcap_close(handle);  // Seal the gateway to the packet realm
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s [device] [filter]\n", argv[0]);
        return -1;
    }
    
    if (enigmaticEnigma(argv[1], argv[2]) < 0)
        return -1;
    
    return 0;
}