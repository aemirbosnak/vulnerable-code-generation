//Falcon2-11B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: unmistakable
#include <stdio.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
    int err;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // Open the network interface for capturing
    handle = pcap_open_live(argv[1], BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        return 1;
    }

    // Loop through the captured packets
    while (1) {
        const u_char *pkt_header;
        const u_char *pkt_data;
        size_t pkt_len;

        // Read the next packet
        err = pcap_next_ex(handle, &pkt_header, &pkt_len);
        if (err == -1) {
            break; // End of file
        }
        if (err == -2) {
            fprintf(stderr, "Error reading packet: %s\n", pcap_geterr(handle));
            break; // Error reading packet
        }

        // Print the packet header
        printf("Packet header: ");
        for (int i = 0; i < 6; i++) {
            printf("%02x", pkt_header[i]);
        }
        printf("\n");

        // Print the packet data
        printf("Packet data: ");
        for (int i = 0; i < pkt_len; i++) {
            printf("%02x", pkt_data[i]);
        }
        printf("\n");
    }

    // Close the network interface
    pcap_close(handle);

    return 0;
}