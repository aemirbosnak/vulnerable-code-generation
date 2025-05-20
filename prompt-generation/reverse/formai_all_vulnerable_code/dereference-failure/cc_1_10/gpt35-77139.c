//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: energetic
#include <stdio.h>
#include <pcap.h>

int main(int argc, char *argv[]) {

    char *device_name = "eth0";
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // Step 1: Open live pcap session on `device_name`
    handle = pcap_open_live(device_name, BUFSIZ, 1, 1000, error_buffer);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device_name, error_buffer);
        return 1;
    }

    // Step 2: Compile filter expression
    struct bpf_program filter;
    char filter_expression[] = "port 80";
    if (pcap_compile(handle, &filter, filter_expression, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Could not parse filter %s: %s\n", filter_expression, pcap_geterr(handle));
        return 1;
    }

    // Step 3: Apply filter
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Could not apply filter %s: %s\n", filter_expression, pcap_geterr(handle));
        return 1;
    }

    // Step 4: Capture packets
    struct pcap_pkthdr header;    // The header that pcap gives us
    const unsigned char *packet; // The actual packet
    int packet_counter = 0;

    while (1) {
        packet = pcap_next(handle, &header); // Get one packet

        if (packet == NULL) { // Timeout occurred
            continue;
        }

        printf("Packet #%d:\n", ++packet_counter);
        printf("Packet length: %d\n", header.len);
        printf("Timestamp seconds: %d\n", header.ts.tv_sec);
        printf("Timestamp microseconds: %d\n", header.ts.tv_usec);

        // Print packet in hex format
        for (int i = 0; i < header.len; i++) {
            printf("%02x ", packet[i]);
            if ((i + 1) % 16 == 0) {
                printf("\n");
            }
        }
        printf("\n\n");
    }

    pcap_close(handle); // Close the handle
    return 0;
}