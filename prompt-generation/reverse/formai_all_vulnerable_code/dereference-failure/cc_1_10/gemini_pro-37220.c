//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SNAP_LEN 1518

struct wifi_header {
    u_char  frame_control;
    u_char  frame_control1;
    u_char  duration_id[2];
    u_char  addr1[6];
    u_char  addr2[6];
    u_char  addr3[6];
    u_char  seq_ctrl[2];
};

struct dot11_beacon {
    u_char  timestamp[8];
    u_char  beacon_int[2];
    u_char  cap_info[2];
};

void print_usage() {
    printf("Usage: wireless_network_scanner <interface>\n");
    printf("Example: wireless_network_scanner wlan0\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return -1;
    }

    char *dev = argv[1];
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(dev, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return -1;
    }

    while (1) {
        struct pcap_pkthdr *header;
        const u_char *packet;
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == -1) {
            fprintf(stderr, "Error reading packet: %s\n", pcap_geterr(handle));
            break;
        } else if (res == 0) {
            continue;
        }

        struct wifi_header *wifi_hdr = (struct wifi_header *)packet;
        if (wifi_hdr->frame_control & 0x80) {
            continue;
        }

        struct dot11_beacon *beacon = (struct dot11_beacon *)(packet + sizeof(struct wifi_header));
        u_char *ssid = (u_char *)(packet + sizeof(struct wifi_header) + sizeof(struct dot11_beacon));
        int ssid_len = packet[sizeof(struct wifi_header) + sizeof(struct dot11_beacon) + 1];

        printf("BSSID: %02x:%02x:%02x:%02x:%02x:%02x\n",
            wifi_hdr->addr3[0], wifi_hdr->addr3[1], wifi_hdr->addr3[2],
            wifi_hdr->addr3[3], wifi_hdr->addr3[4], wifi_hdr->addr3[5]);
        printf("SSID: %s\n", ssid);
        printf("Channel: %d\n", packet[sizeof(struct wifi_header) + sizeof(struct dot11_beacon) + 3]);
        printf("\n");
    }

    pcap_close(handle);
    return 0;
}