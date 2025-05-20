//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: curious
#include <stdlib.h>
#include <stdio.h>
#include <pcap/pcap.h>

/* A structure to hold our packet data. */
typedef struct {
    uint32_t src_ip;
    uint32_t dst_ip;
    uint16_t src_port;
    uint16_t dst_port;
    uint8_t protocol;
    uint16_t length;
    char *data;
} packet_data;

/* A function to print out the contents of a packet. */
void print_packet(packet_data *packet) {
    printf("Source IP: %u\n", packet->src_ip);
    printf("Destination IP: %u\n", packet->dst_ip);
    printf("Source Port: %u\n", packet->src_port);
    printf("Destination Port: %u\n", packet->dst_port);
    printf("Protocol: %u\n", packet->protocol);
    printf("Length: %u\n", packet->length);
    printf("Data: %s\n", packet->data);
}

/* The main function. */
int main() {
    pcap_t *handle;
    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter_exp[] = "tcp and src port 80";
    bpf_u_int32 mask;
    bpf_u_int32 net;
    int i;

    /* Get a device to capture on. */
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find a default device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    /* Open the device for capture. */
    handle = pcap_open_live(dev, 65535, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return EXIT_FAILURE;
    }

    /* Compile the filter expression. */
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter expression: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    /* Set the filter. */
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't set filter: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    /* Loop and capture packets. */
    for (i = 0; i < 100; i++) {
        struct pcap_pkthdr *header;
        const u_char *data;

        /* Wait for a packet to arrive. */
        int res = pcap_next_ex(handle, &header, &data);
        if (res == -1) {
            fprintf(stderr, "Couldn't capture packet: %s\n", pcap_geterr(handle));
            return EXIT_FAILURE;
        } else if (res == 0) {
            continue;
        }

        /* Parse the packet data. */
        packet_data packet;
        packet.src_ip = *(uint32_t *)data;
        packet.dst_ip = *(uint32_t *)(data + 4);
        packet.src_port = *(uint16_t *)(data + 12);
        packet.dst_port = *(uint16_t *)(data + 14);
        packet.protocol = *(data + 9);
        packet.length = header->len;
        packet.data = (char *)(data + 16);

        /* Print out the packet data. */
        print_packet(&packet);
    }

    /* Close the device. */
    pcap_close(handle);

    return EXIT_SUCCESS;
}