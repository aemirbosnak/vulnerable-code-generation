//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pcap.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define ETHER_ADDR_LEN 6

typedef struct {
    char *ssid;
    char *bssid;
    int channel;
} network_info_t;

int main() {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    char *dev;
    struct bpf_program fp;
    char filter_exp[] = "type mgt subtype probe-req";
    bpf_u_int32 netmask;
    bpf_u_int32 ip;
    int ret;

    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Error: %s\n", errbuf);
        return 1;
    }

    handle = pcap_open_live(dev, 65535, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error: %s\n", errbuf);
        return 1;
    }

    if (pcap_datalink(handle) != DLT_EN10MB) {
        fprintf(stderr, "Error: This program only supports Ethernet interfaces.\n");
        return 1;
    }

    ret = pcap_lookupnet(dev, &ip, &netmask, errbuf);
    if (ret == -1) {
        fprintf(stderr, "Error: %s\n", errbuf);
        return 1;
    }

    if (pcap_compile(handle, &fp, filter_exp, 0, netmask) == -1) {
        fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
        return 1;
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
        return 1;
    }

    printf("Scanning for wireless networks\n");

    while (1) {
        struct pcap_pkthdr *header;
        const u_char *packet;
        int i;

        ret = pcap_next_ex(handle, &header, &packet);
        if (ret == -1) {
            fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
            return 1;
        }
        if (ret == 0) {
            continue;
        }

        if (packet[0] != 0x80) {
            continue;
        }

        network_info_t network_info;
        network_info.ssid = NULL;
        network_info.bssid = NULL;
        network_info.channel = 0;

        for (i = 24; i < header->len; i++) {
            if (packet[i] == 0x00 && packet[i + 1] == 0x50 && packet[i + 2] == 0xf2) {
                network_info.ssid = (char *)malloc(packet[i + 3]);
                memcpy(network_info.ssid, packet + i + 4, packet[i + 3]);
                network_info.ssid[packet[i + 3]] = '\0';
                i += packet[i + 3] + 3;
            } else if (packet[i] == 0x00 && packet[i + 1] == 0x30 && packet[i + 2] == 0x44) {
                network_info.bssid = (char *)malloc(ETHER_ADDR_LEN);
                memcpy(network_info.bssid, packet + i + 4, ETHER_ADDR_LEN);
                i += ETHER_ADDR_LEN + 3;
            } else if (packet[i] == 0x00 && packet[i + 1] == 0x30 && packet[i + 2] == 0x4a) {
                network_info.channel = packet[i + 9];
                i += 9;
            }
        }

        if (network_info.ssid != NULL && network_info.bssid != NULL && network_info.channel != 0) {
            printf("Found network: %s (%s) on channel %d\n", network_info.ssid, network_info.bssid, network_info.channel);
        }

        if (network_info.ssid != NULL) {
            free(network_info.ssid);
        }
        if (network_info.bssid != NULL) {
            free(network_info.bssid);
        }
    }

    pcap_close(handle);

    return 0;
}