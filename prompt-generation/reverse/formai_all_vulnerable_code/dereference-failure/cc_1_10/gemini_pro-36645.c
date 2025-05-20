//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: immersive
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <string.h>

#define PROMISCUOUS 1
#define NONBLOCKING 1

void usage() {
    printf("Usage: packet_monitor <interface>\n");
    printf("Example: packet_monitor eth0\n");
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 2)
        usage();

    char *device = argv[1];
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    handle = pcap_open_live(device, 65535, PROMISCUOUS, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        exit(1);
    }

    if (pcap_setnonblock(handle, NONBLOCKING, errbuf) == -1) {
        fprintf(stderr, "Error setting nonblocking mode: %s\n", errbuf);
        exit(1);
    }

    struct pcap_pkthdr *header;
    const u_char *data;
    while (1) {
        int res = pcap_next_ex(handle, &header, &data);
        if (res == 0) {
            // Timeout expired
            continue;
        } else if (res == -1) {
            // An error occurred
            fprintf(stderr, "Error reading packet: %s\n", pcap_geterr(handle));
            exit(1);
        } else {
            // A packet was received
            printf("Packet received:\n");
            printf(" - Length: %d bytes\n", header->len);
            printf(" - Capture time: %s\n", ctime((const time_t *)&header->ts.tv_sec));
            printf(" - Data: ");
            for (int i = 0; i < header->len; i++) {
                printf("%02x ", data[i]);
            }
            printf("\n\n");
        }
    }

    pcap_close(handle);
    return 0;
}