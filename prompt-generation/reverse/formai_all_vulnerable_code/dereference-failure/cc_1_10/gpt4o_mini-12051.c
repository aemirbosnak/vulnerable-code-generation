//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pcap.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_SSID_LEN 32
#define SNAPLEN 1024
#define DEVICE_NAME "wlan0"  // Change this to your wireless interface

struct wifi_packet {
    u_int8_t frame_ctl[2];
    u_int8_t duration[2];
    u_int8_t addr1[6]; // Destination Address
    u_int8_t addr2[6]; // Source Address
    u_int8_t addr3[6]; // BSSID
    u_int8_t seq_ctl[2];   
    u_int8_t phy[10]; // Might contain other useful fields
};

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct wifi_packet *wifi_pkt = (struct wifi_packet *)(packet + 16);  // Skip the radiotap header

    // Assumed to be in a management frame (Beacon)
    if (packet[0] == 0x80) { // Check for management frame type
        char ssid[MAX_SSID_LEN + 1] = {0};
        int ssid_len = packet[37]; // 37 offset where SSID length is stored 

        if (ssid_len > MAX_SSID_LEN) {
            ssid_len = MAX_SSID_LEN; // Avoid overflow
        }
        
        memcpy(ssid, packet + 38, ssid_len); // 38 is where SSID starts
        ssid[ssid_len] = '\0';  // Null-terminate
        
        printf("SSID: %s | BSSID: %02x:%02x:%02x:%02x:%02x:%02x\n",
                ssid,
                wifi_pkt->addr3[0], wifi_pkt->addr3[1],
                wifi_pkt->addr3[2], wifi_pkt->addr3[3],
                wifi_pkt->addr3[4], wifi_pkt->addr3[5]);
    }
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_if_t *alldevs, *device;

    // Find all available devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return 1;
    }

    // Print the devices found
    printf("Available devices:\n");
    for (device = alldevs; device != NULL; device = device->next) {
        printf("%s\n", device->name);
    }

    // Open the device for receiving packets
    pcap_t *handle = pcap_open_live(DEVICE_NAME, SNAPLEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device %s: %s\n", DEVICE_NAME, errbuf);
        return 2;
    }

    // Set the promiscuous mode
    if (pcap_set_promisc(handle, 1) < 0) {
        fprintf(stderr, "Error setting promiscuous mode: %s\n", pcap_geterr(handle));
        return 3;
    }

    // Start capturing packets
    printf("Starting to scan for wireless networks...\n");
    pcap_loop(handle, 0, packet_handler, NULL);

    // Cleanup
    pcap_close(handle);
    pcap_freealldevs(alldevs);
    
    return 0;
}