//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: shape shifting
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_PACKET_SIZE 65536
#define ERR_BUF_SIZE 256

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct in_addr addr;
    printf("Packet captured at %s", ctime((const time_t*)&header->ts.tv_sec));
    printf("Packet length: %d bytes\n", header->len);

    // Print some first bytes of the packet
    printf("Packet Data:\n");
    for (int i = 0; i < header->len && i < MAX_PACKET_SIZE; i++) {
        if (i % 16 == 0) {
            printf("\n%04x ", i);
        }
        printf("%02x ", packet[i]);
    }
    printf("\n\n");
}

void initiate_capture(const char *device) {
    pcap_t *handle;
    char errbuf[ERR_BUF_SIZE];

    // Open the device for capturing
    handle = pcap_open_live(device, MAX_PACKET_SIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device, errbuf);
        return;
    }

    printf("Listening on %s...\n", device);
    pcap_loop(handle, 10, packet_handler, NULL); // Capture 10 packets

    // Cleanup
    pcap_close(handle);
    printf("Capture finished!\n");
}

char* get_device(char *errbuf) {
    pcap_if_t *alldevs;
    pcap_if_t *device;

    // Get the list of all devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "pcap_findalldevs() failed: %s\n", errbuf);
        return NULL;
    }

    printf("Available network devices:\n");
    int count = 0;
    for (device = alldevs; device != NULL; device = device->next) {
        printf("%d. %s", ++count, device->name);
        if (device->description) {
            printf(" (%s)", device->description);
        }
        printf("\n");
    }

    if (count == 0) {
        fprintf(stderr, "No network devices found.\n");
        return NULL;
    }

    // Choose the first device for capture
    char *device_name = alldevs->name;
    pcap_freealldevs(alldevs);
    return device_name;
}

int main() {
    char errbuf[ERR_BUF_SIZE];

    // Get the device name to capture packets
    char *device = get_device(errbuf);
    if (device == NULL) {
        return 1;
    }

    // Begin packet capture process
    initiate_capture(device);
    return 0;
}