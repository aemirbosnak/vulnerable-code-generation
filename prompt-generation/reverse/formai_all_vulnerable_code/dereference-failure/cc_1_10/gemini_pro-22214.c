//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: all-encompassing
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKET_SIZE 65535

struct packet_data {
    struct pcap_pkthdr header;
    unsigned char *data;
};

static void packet_callback(
    u_char *user,
    const struct pcap_pkthdr *header,
    const unsigned char *data
) {
    struct packet_data *packet = (struct packet_data *)user;
    packet->header = *header;
    packet->data = malloc(header->caplen);
    memcpy(packet->data, data, header->caplen);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <interface> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *interface = argv[1];
    char *output_file = argv[2];

    FILE *fp = fopen(output_file, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", output_file);
        return EXIT_FAILURE;
    }

    pcap_t *handle = pcap_open_live(interface, MAX_PACKET_SIZE, 1, 1000, NULL);
    if (handle == NULL) {
        fprintf(stderr, "Error opening interface %s\n", interface);
        return EXIT_FAILURE;
    }

    struct packet_data packet;

    pcap_loop(handle, -1, packet_callback, &packet);

    pcap_close(handle);

    fwrite(&packet.header, sizeof(packet.header), 1, fp);
    fwrite(packet.data, packet.header.caplen, 1, fp);

    fclose(fp);

    return EXIT_SUCCESS;
}