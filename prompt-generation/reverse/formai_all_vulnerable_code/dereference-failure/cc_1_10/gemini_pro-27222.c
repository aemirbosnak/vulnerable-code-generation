//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: mathematical
#include <stdio.h>
#include <pcap.h>

int main() {
    // Define the capture filter
    char *filter = "port 80";

    // Open the capture device
    pcap_t *handle = pcap_open_live("eth0", 65535, 1, 1000, NULL);

    // Compile the capture filter
    struct bpf_program fp;
    if (pcap_compile(handle, &fp, filter, 0, 0) == -1) {
        perror("pcap_compile");
        return -1;
    }

    // Set the capture filter
    if (pcap_setfilter(handle, &fp) == -1) {
        perror("pcap_setfilter");
        return -1;
    }

    // Capture packets
    int count = 0;
    while (1) {
        struct pcap_pkthdr *header;
        const unsigned char *data;

        int res = pcap_next_ex(handle, &header, &data);
        if (res == -1) {
            perror("pcap_next_ex");
            break;
        } else if (res == 0) {
            continue;
        }

        count++;

        // Process the packet
        printf("Packet %d: %d bytes\n", count, header->len);
        for (int i = 0; i < header->len; i++) {
            printf("%02X ", data[i]);
        }
        printf("\n");
    }

    // Close the capture device
    pcap_close(handle);

    return 0;
}