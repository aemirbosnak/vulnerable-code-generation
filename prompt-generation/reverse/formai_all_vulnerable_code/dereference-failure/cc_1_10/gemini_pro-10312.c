//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: creative
#include <stdlib.h>
#include <stdio.h>
#include <pcap.h>

char errbuf[PCAP_ERRBUF_SIZE];  // Buffer for error messages

// Function to handle captured packets
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("A packet has been captured!\n");
    printf("Packet length: %d bytes\n", header->len);
    printf("Packet timestamp: %llu\n", header->ts.tv_sec);
    printf("Packet contains: %s\n", packet);
}

int main(int argc, char *argv[]) {
    char *device_name = NULL;  // Device to capture from
    char *filter_exp = "ip";   // Filter expression

    // Parse command-line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-i") == 0) {
            device_name = argv[i + 1];
        } else if (strcmp(argv[i], "-f") == 0) {
            filter_exp = argv[i + 1];
        }
    }

    // Initialize libpcap
    pcap_t *handle = pcap_open_live(device_name, 65535, 1, 1000, errbuf);
    if (!handle) {
        printf("Error opening device: %s", errbuf);
        return EXIT_FAILURE;
    }

    // Set filter on the capture
    struct bpf_program fp;
    if (pcap_compile(handle, &fp, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        printf("Error compiling filter: %s", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Error setting filter: %s", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Start the capture loop
    printf("Packet Hunter is on the hunt!\n");
    pcap_loop(handle, -1, packet_handler, NULL);

    // Cleanup
    pcap_close(handle);
    pcap_freecode(&fp);
    return EXIT_SUCCESS;
}