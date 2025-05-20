//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <time.h>

#define SNAP_LEN 65535 // Capture all packets, in theory
#define PROMISCUOUS 1  // Set to 1 for promiscuous mode
#define TIMEOUT 1000   // Timeout in milliseconds

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct tm *time_info;
    char time_string[16];
    time_t local_tv_sec;

    local_tv_sec = header->ts.tv_sec;
    time_info = localtime(&local_tv_sec);
    strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);

    printf("Packet Timestamp: %s.%06ld\n", time_string, header->ts.tv_usec);
    printf("Packet Length: %d bytes\n", header->len);
    
    // Print the packet in hex format
    printf("Packet Data:\n");
    for (int i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n\n");
}

void list_devices() {
    pcap_if_t *alldevs;
    char errbuf[PCAP_ERRBUF_SIZE];

    if (pcap_findalldevs(&alldevs, errbuf) < 0) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    printf("Available devices:\n");
    for (pcap_if_t *d = alldevs; d != NULL; d = d->next) {
        printf("- %s\n", d->name);
        if (d->description) {
            printf("  Description: %s\n", d->description);
        }
    }

    pcap_freealldevs(alldevs);
}

int open_device(const char *device) {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    handle = pcap_open_live(device, SNAP_LEN, PROMISCUOUS, TIMEOUT, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device, errbuf);
        return -1;
    }

    return handle;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <device>\n", argv[0]);
        list_devices();
        exit(EXIT_FAILURE);
    }

    const char *device = argv[1];
    pcap_t *handle = open_device(device);
    if (handle == NULL) {
        exit(EXIT_FAILURE);
    }

    printf("Capturing packets on device: %s\n", device);
    pcap_loop(handle, 10, packet_handler, NULL); // Capture 10 packets

    pcap_close(handle);
    printf("Done capturing packets. Exiting...\n");
    return 0;
}