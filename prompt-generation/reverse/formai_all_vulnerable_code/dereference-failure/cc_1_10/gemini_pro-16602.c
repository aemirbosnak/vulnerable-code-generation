//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: puzzling
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PCAP_ERRBUF_SIZE 256

int main(int argc, char **argv) {
    char *device;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "tcp port 80";
    bpf_u_int32 net;
    bpf_u_int32 mask;

    // Enigma device selection
    if (argc == 2) {
        device = argv[1];
    } else {
        printf("Usage: %s [device]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Network mask retrieval
    if (pcap_lookupnet(device, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Error: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // Packet handle acquisition
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // Filter compilation
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Filter application
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Packet capture loop
    while (1) {
        struct pcap_pkthdr *header;
        const unsigned char *packet;
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == -1) {
            fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
            exit(EXIT_FAILURE);
        } else if (res == 0) {
            continue;
        }

        // Packet examination
        printf("Packet length: %d\n", header->len);
        printf("Packet timestamp: %ld.%06ld\n", header->ts.tv_sec, header->ts.tv_usec);
        printf("Packet data:\n");
        for (int i = 0; i < header->len; i++) {
            printf("%02x", packet[i]);
        }
        printf("\n\n");
    }

    // Packet capture termination
    pcap_close(handle);

    return EXIT_SUCCESS;
}