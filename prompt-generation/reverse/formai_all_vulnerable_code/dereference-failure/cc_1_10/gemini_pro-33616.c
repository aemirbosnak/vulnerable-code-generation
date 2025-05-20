//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: ultraprecise
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_BYTES 2048

int main(int argc, char **argv) {
    char *device = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = NULL;
    struct pcap_pkthdr header;
    const u_char *packet = NULL;
    int i = 0;

    if (argc == 2) {
        device = argv[1];
    } else {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    handle = pcap_open_live(device, MAX_BYTES, 0, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    while (1) {
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 1) {
            printf("Packet %d: %d bytes\n", i++, header.len);
            for (int j = 0; j < header.len; j++) {
                printf("%02X ", packet[j]);
                if ((j + 1) % 16 == 0) {
                    printf("\n");
                }
            }
            printf("\n\n");
        } else if (res == 0) {
            continue;
        } else {
            fprintf(stderr, "Error capturing packet: %s\n", pcap_geterr(handle));
            break;
        }
    }

    pcap_close(handle);
    return EXIT_SUCCESS;
}