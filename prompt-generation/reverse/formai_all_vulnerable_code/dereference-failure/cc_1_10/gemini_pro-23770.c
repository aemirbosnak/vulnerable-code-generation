//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PACKET_LEN 1024

int main()
{
    char *dev, errbuf[PCAP_ERRBUF_SIZE];

    // Find a network device
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Error finding a network device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Open the network device
    pcap_t *handle = pcap_open_live(dev, MAX_PACKET_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening the network device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Set the filter
    struct bpf_program fp;
    if (pcap_compile(handle, &fp, "type mgt subtype probe req", 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Error compiling the filter: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error setting the filter: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Process the packets
    struct pcap_pkthdr *header;
    const u_char *data;
    while (1) {
        int res = pcap_next_ex(handle, &header, &data);
        if (res == 0) continue;
        if (res == -1) {
            fprintf(stderr, "Error reading the next packet: %s\n", pcap_geterr(handle));
            return EXIT_FAILURE;
        }

        // Get the SSID
        u_int8_t *ssid = data + 34;
        int ssid_len = *ssid;
        ssid++;

        // Print the SSID
        printf("SSID: %.*s\n", ssid_len, ssid);
    }

    // Close the network device
    pcap_close(handle);

    return EXIT_SUCCESS;
}