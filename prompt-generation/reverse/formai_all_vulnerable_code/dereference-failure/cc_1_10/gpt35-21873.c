//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: surrealist
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Surrealist Packet Capturer!\n\n");

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "port 80";
    bpf_u_int32 mask;
    bpf_u_int32 net;

    int num_packets = 10;

    printf("Initializing capture on eth0...\n\n");

    if (pcap_lookupnet("eth0", &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Can't get netmask for device eth0\n");
        net = 0;
        mask = 0;
    }

    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device eth0: %s\n", errbuf);
        return 2;
    }

    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 2;
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 2;
    }

    printf("\nAttaching to packets...\n\n");

    int packets_captured = 0;
    struct pcap_pkthdr header;
    const u_char *packet;

    while (packets_captured < num_packets) {
        printf("Packet %d:\n\n", packets_captured);

        packet = pcap_next(handle, &header);

        if (packet == NULL) {
            printf("No packet found.\n\n");
        } else {
            printf("Packet capture length: %d\n", header.caplen);
            printf("Packet real length: %d\n\n", header.len);

            int i;
            for (i = 0; i < header.caplen; i++) {
                printf("%02x ", packet[i]);
            }
            printf("\n\n");

            printf("Packet captured successfully.\n\n");
        }

        packets_captured++;
    }

    printf("Packet capture complete!\n\n");

    pcap_close(handle);

    return 0;
}