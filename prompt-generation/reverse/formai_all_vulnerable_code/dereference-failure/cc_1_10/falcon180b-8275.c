//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

char *dev = "eth0";
pcap_t *handle;
pcap_dumper_t *dump_handle;

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet received: %d bytes\n", header->len);
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_if_t *devs;
    int i, j;

    if (pcap_findalldevs(&devs, errbuf) == -1) {
        fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
        exit(1);
    }

    for (i = 0; devs[i].name!= NULL; i++) {
        if (strcmp(devs[i].name, dev) == 0) {
            printf("Device found: %s\n", devs[i].name);
            break;
        }
    }

    if (devs[i].name == NULL) {
        fprintf(stderr, "Device not found\n");
        exit(1);
    }

    handle = pcap_open_live(devs[i].name, 65535, 1, 0, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Error in pcap_open_live: %s\n", errbuf);
        exit(1);
    }

    pcap_loop(handle, -1, process_packet, NULL);

    pcap_dump_open(handle, "capture.pcap");

    pcap_loop(handle, -1, process_packet, NULL);

    pcap_dump_close(handle);

    pcap_close(handle);

    return 0;
}