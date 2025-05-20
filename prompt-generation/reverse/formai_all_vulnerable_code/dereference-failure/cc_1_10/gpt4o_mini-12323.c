//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>

#define SNAP_LEN 1518
#define PROMISCUOUS 1
#define TIMEOUT 1000

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct tm *tm;
    char timestr[16];
    tm = localtime(&header->ts.tv_sec);
    strftime(timestr, sizeof(timestr), "%H:%M:%S", tm);

    printf("Packet captured at %s.%06d\n", timestr, (int) header->ts.tv_usec);
    printf("Packet length: %d bytes\n", header->len);
    
    // Display first 16 bytes of the packet
    printf("Packet data (first 16 bytes): ");
    for (int i = 0; i < 16 && i < header->len; i++) {
        printf("%02x ", packet[i]);
    }
    printf("\n\n");
}

void list_devices() {
    pcap_if_t *alldevsp, *device;
    char errbuf[PCAP_ERRBUF_SIZE];

    printf("Searching for network devices...\n");
    if (pcap_findalldevs(&alldevsp, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return;
    }

    printf("Available devices:\n");
    for (device = alldevsp; device != NULL; device = device->next) {
        printf(" - %s\n", device->name);
    }

    pcap_freealldevs(alldevsp);
}

int main(int argc, char *argv[]) {
    char *device_name;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        list_devices();
        return EXIT_FAILURE;
    }

    device_name = argv[1];
    handle = pcap_open_live(device_name, SNAP_LEN, PROMISCUOUS, TIMEOUT, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Unable to open the interface %s: %s\n", device_name, errbuf);
        return EXIT_FAILURE;
    }

    printf("Capturing packets on %s...\n", device_name);
    pcap_loop(handle, 10, packet_handler, NULL);  // Capture 10 packets

    printf("Capture completed.\n");

    pcap_close(handle);
    return EXIT_SUCCESS;
}