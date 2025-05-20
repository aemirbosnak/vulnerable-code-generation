//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: rigorous
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SNAP_LEN 1518

int main(int argc, char **argv)
{
    char *device;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr *header;
    const u_char *packet;
    int i;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    device = argv[1];

    handle = pcap_open_live(device, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live(): %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    while (1) {
        header = NULL;
        packet = NULL;
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 0) {
            continue;
        } else if (res == -1) {
            break;
        } else if (res == -2) {
            fprintf(stderr, "pcap_next_ex(): %s\n", pcap_geterr(handle));
            break;
        }

        printf("Packet capture length: %d\n", header->caplen);
        printf("Packet total length: %d\n", header->len);

        for (i = 0; i < header->caplen; i++) {
            printf("%02x ", packet[i]);
        }

        printf("\n\n");
    }

    pcap_close(handle);

    return EXIT_SUCCESS;
}