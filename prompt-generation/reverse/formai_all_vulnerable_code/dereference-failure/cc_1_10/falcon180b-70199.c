//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pcap.h>
#include <errno.h>
#include <unistd.h>

struct packet_info {
    u_int8_t *packet;
    size_t size;
};

void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct packet_info *info = (struct packet_info *) args;
    info->packet = (u_int8_t *) packet;
    info->size = header->len;
}

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    char filter_str[100];
    struct bpf_program filter;
    int optimize = 1;
    int net = 1;
    int mask = 0xffffff00;
    int promisc = 0;
    int timeout = 1000;
    int packet_count = 0;
    struct packet_info packet_info;

    if (argc!= 3) {
        printf("Usage: %s <interface> <filter>\n", argv[0]);
        exit(1);
    }

    strcpy(filter_str, argv[2]);

    /* Open the session */
    handle = pcap_open_live(argv[1], 65535, promisc, timeout, errbuf);
    if (handle == NULL) {
        printf("Error opening adapter: %s\n", errbuf);
        exit(2);
    }

    /* Compile the filter expression */
    if (pcap_compile(handle, &filter, filter_str, optimize, mask) == -1) {
        printf("Error compiling filter expression: %s\n", pcap_geterr(handle));
        exit(3);
    }

    /* Set the filter */
    if (pcap_setfilter(handle, &filter) == -1) {
        printf("Error setting filter: %s\n", pcap_geterr(handle));
        exit(4);
    }

    /* Loop to capture packets */
    while ((packet_count < 10) && (pcap_dispatch(handle, 1, handle_packet, (u_char *) &packet_info) == 0)) {
        printf("Packet %d:\n", packet_count + 1);
        printf("Packet size: %d bytes\n", packet_info.size);
        printf("Packet data: ");
        for (int i = 0; i < packet_info.size; i++) {
            printf("%02x ", packet_info.packet[i]);
        }
        printf("\n");
        packet_count++;
    }

    /* Close the session */
    pcap_freecode(&filter);
    pcap_close(handle);

    return 0;
}