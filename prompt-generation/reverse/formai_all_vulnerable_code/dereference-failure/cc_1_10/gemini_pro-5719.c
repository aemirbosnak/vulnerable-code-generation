//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Linus Torvalds
// Ain't no need to apologize for this masterpiece, Linus!

#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Our beefy packet printing function
void print_packet(const u_char *packet, const struct pcap_pkthdr *hdr) {
    printf("Time: %u.%u\n", hdr->ts.tv_sec, hdr->ts.tv_usec);
    printf("Length: %u\n", hdr->len);
    printf("Data: ");
    for (int i = 0; i < hdr->caplen; i++) {
        printf("%02x ", packet[i]);
        if (i % 16 == 15) {
            printf("\n");
        }
    }
    printf("\n\n");
}

int main() {
    char *dev;
    pcap_t *handle;
    struct bpf_program fp;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Get the default device
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // Open the device
    handle = pcap_open_live(dev, BUFSIZ, 0, -1, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        exit(EXIT_FAILURE);
    }

    // Compile the filter expression
    if (pcap_compile(handle, &fp, "tcp port 80", 0, 0) == -1) {
        fprintf(stderr, "Couldn't compile filter: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Apply the filter
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't set filter: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Loop and print packets
    while (1) {
        struct pcap_pkthdr *hdr;
        const u_char *packet;

        int res = pcap_next_ex(handle, &hdr, &packet);
        if (res == 0) {
            continue;
        } else if (res == -1) {
            fprintf(stderr, "Error reading packet: %s\n", pcap_geterr(handle));
            exit(EXIT_FAILURE);
        }

        print_packet(packet, hdr);
    }

    // Cleanup
    pcap_freecode(&fp);
    pcap_close(handle);

    return EXIT_SUCCESS;
}