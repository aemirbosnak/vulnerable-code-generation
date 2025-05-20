//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: recursive
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

void recursive_capture(pcap_t *handle, int num_packets) {
    struct pcap_pkthdr *header;
    const u_char *packet;
    int packets_captured = 0;
    int res;

    while (packets_captured < num_packets) {
        res = pcap_next_ex(handle, &header, &packet);
        if (res == 0) {
            /* Timeout elapsed */
            continue;
        } else if (res == -1) {
            /* An error occurred */
            fprintf(stderr, "Error occurred while capturing packets: %s\n", pcap_geterr(handle));
            break;
        }
        /* Print some information about the packet */
        printf("Packet length: %u bytes\n", header->len);
        
        recursive_capture(handle, num_packets - packets_captured - 1);
        
        packets_captured++;
    }
}

int main() {
    char *dev = "eth0"; /* The device to capture on */
    char errbuf[PCAP_ERRBUF_SIZE]; /* Error string buffer */
    pcap_t *handle; /* Session handle */
    int num_packets = 10; /* Number of packets to capture */

    /* Open the session in promiscuous mode */
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", dev, errbuf);
        return 1;
    }

    /* Start capturing packets recursively */
    recursive_capture(handle, num_packets);

    /* Close the session */
    pcap_close(handle);

    return 0;
}