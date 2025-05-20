//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: sophisticated
#include <stdio.h>
#include <pcap.h>

int main() {
    // Set up the capture filter expression.
    char filter_exp[] = "tcp and port 80";

    // Open a capture device.
    pcap_t *handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, NULL);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", "eth0", pcap_geterr(handle));
        return 1;
    }

    // Compile the filter expression.
    struct bpf_program fp;
    if (pcap_compile(handle, &fp, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    // Set the filter on the capture device.
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 1;
    }

    // Capture packets.
    int packets_captured = 0;
    while (1) {
        struct pcap_pkthdr *header;
        const u_char *packet;

        // Capture a packet.
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == -1) {
            fprintf(stderr, "Couldn't capture packet: %s\n", pcap_geterr(handle));
            break;
        } else if (res == 0) {
            continue;
        }

        // Print the packet header.
        printf("Packet number %d:\n", ++packets_captured);
        printf("  Timestamp: %u.%06u\n", header->ts.tv_sec, header->ts.tv_usec);
        printf("  Length: %d\n", header->len);

        // Print the packet data.
        for (int i = 0; i < header->len; i++) {
            printf("%02x ", packet[i]);
            if (i % 16 == 15) {
                printf("\n");
            }
        }
        printf("\n");
    }

    // Close the capture device.
    pcap_close(handle);

    return 0;
}