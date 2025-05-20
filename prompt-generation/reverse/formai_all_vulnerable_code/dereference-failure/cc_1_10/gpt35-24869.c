//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter_exp[] = "ip";
    bpf_u_int32 net;
    const u_char *packet;
    struct pcap_pkthdr header;

    // Open live capture session
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);

    // Check for errors
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device: %s\n", errbuf);
        return(1);
    }

    // Compile filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(1);
    }

    // Apply the compiled filter
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(1);
    }

    // Capture packets
    int packet_count = 0;
    while ((packet = pcap_next(handle, &header)) != NULL && packet_count < 100) {
        printf("Packet %d:\n", packet_count+1);
        printf("Length: %d bytes\n", header.len);
        printf("Capture Time: %s", ctime(&header.ts.tv_sec));
        printf("-------------------------\n");

        // Display packet data
        for (int i = 0; i < header.len; i++) {
            printf("%02x ", packet[i]);
            if ((i+1) % 16 == 0) printf("\n"); // Line break every 16 bytes
        }
        printf("\n\n");
        packet_count++;
    }

    // Clean up
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}