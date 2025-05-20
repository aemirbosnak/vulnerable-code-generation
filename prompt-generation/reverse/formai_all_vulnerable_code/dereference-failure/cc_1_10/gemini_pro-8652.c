//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <pcap/bpf.h>

#define BUFSIZ 1024

struct wifi_signal {
    int channel;
    int rssi;
    char *ssid;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *interface = argv[1];

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(interface, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    struct bpf_program filter;
    if (pcap_compile(handle, &filter, "type mgt subtype probe-req", 1, 0) < 0) {
        fprintf(stderr, "pcap_compile: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    if (pcap_setfilter(handle, &filter) < 0) {
        fprintf(stderr, "pcap_setfilter: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    struct pcap_pkthdr *header;
    const unsigned char *data;
    while (pcap_next_ex(handle, &header, &data) >= 0) {
        struct wifi_signal signal;

        signal.channel = data[26];
        signal.rssi = data[27];

        int ssid_len = data[32];
        signal.ssid = malloc(ssid_len + 1);
        memcpy(signal.ssid, data + 33, ssid_len);
        signal.ssid[ssid_len] = '\0';

        printf("Channel: %d, RSSI: %d, SSID: %s\n", signal.channel, signal.rssi, signal.ssid);

        free(signal.ssid);
    }

    pcap_close(handle);

    return EXIT_SUCCESS;
}