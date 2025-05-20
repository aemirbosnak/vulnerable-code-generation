//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: automated
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>

#define MAX_PACKET_SIZE 65535
#define SNAPLEN 65535

void print_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet size: %d\n", header->len);
    printf("Packet data: ");
    for (int i = 0; i < header->len; i++) {
        printf("%02X ", packet[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    char *dev = "eth0";
    struct bpf_program filter;
    char filter_exp[] = "tcp and port 80";
    int optimize = 1;
    int netmask = 0xffffff00;
    int ret;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <device>\n", argv[0]);
        exit(1);
    }

    dev = argv[1];

    // Open the device for capturing
    handle = pcap_open_live(dev, SNAPLEN, 1, 0, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live() failed: %s\n", errbuf);
        exit(1);
    }

    // Compile the filter expression
    ret = pcap_compile(handle, &filter, filter_exp, 1, netmask);
    if (ret == -1) {
        fprintf(stderr, "pcap_compile() failed\n");
        exit(1);
    }

    // Set the filter
    ret = pcap_setfilter(handle, &filter);
    if (ret == -1) {
        fprintf(stderr, "pcap_setfilter() failed\n");
        exit(1);
    }

    // Loop to capture packets
    while (1) {
        struct pcap_pkthdr header;
        const u_char *packet;

        ret = pcap_next_ex(handle, &header, &packet);
        if (ret == -1) {
            if (errno == EAGAIN) {
                continue;
            } else {
                fprintf(stderr, "pcap_next_ex() failed: %s\n", strerror(errno));
                exit(1);
            }
        }

        if (header.caplen > MAX_PACKET_SIZE) {
            printf("Packet is too large\n");
        } else {
            print_packet(NULL, &header, packet);
        }
    }

    // Close the device
    pcap_close(handle);

    return 0;
}