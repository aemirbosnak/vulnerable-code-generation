//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <arpa/inet.h>

#define MAX_PKT_SIZE 2048

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct tm *tm_info;
    char time_string[64];
    
    tm_info = localtime(&header->ts.tv_sec);
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", tm_info);
    
    printf("Packet captured at: %s\n", time_string);
    printf("Packet length: %d bytes\n", header->len);
    
    // Frame Control for IEEE 802.11
    printf("Packet Data:\n");
    for(int i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);
        if (i % 16 == 15)
            printf("\n");
    }
    printf("\n-----------------------------------------------------\n");
}

void start_sniffing(char *dev) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // Open the device for sniffing
    handle = pcap_open_live(dev, MAX_PKT_SIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", dev, errbuf);
        return;
    }

    // Start capturing packets
    pcap_loop(handle, 0, packet_handler, NULL);

    // Close the handle
    pcap_close(handle);
}

void list_devices() {
    pcap_if_t *alldevs;
    pcap_if_t *device;

    if (pcap_findalldevs(&alldevs, NULL) != 0) {
        fprintf(stderr, "Error in pcap_findalldevs: %s\n", pcap_geterr(NULL));
        return;
    }

    printf("Available devices:\n");
    for (device = alldevs; device != NULL; device = device->next) {
        printf("%s\n", device->name);
    }

    pcap_freealldevs(alldevs);
}

int main() {
    char dev[100];

    printf("Network Packet Monitoring Tool\n");
    printf("==============================\n");

    // List available devices
    list_devices();

    printf("Enter the name of the device to sniff: ");
    fgets(dev, sizeof(dev), stdin);
    dev[strcspn(dev, "\n")] = 0; // Remove newline character

    // Start sniffing on the selected device
    start_sniffing(dev);

    return 0;
}