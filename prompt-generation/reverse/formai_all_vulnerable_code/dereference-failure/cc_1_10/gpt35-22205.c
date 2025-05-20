//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: Cryptic
#include <stdio.h>
#include <pcap/pcap.h>

/* Function to print data in hex format */
void print_hex(const u_char *data, int length) {
    int i;
    for(i=0; i < length; i++) {
        printf("%02X ",*(data+i));
        if ((i+1)%16 == 0) printf("\n");
    }
    printf("\n");
}

int main(int argc, char *argv[]) {

    pcap_t *handle;
    char error_buffer[PCAP_ERRBUF_SIZE];
    struct bpf_program filter;
    bpf_u_int32 subnet_mask, ip;

    // Create a network packet monitoring handle
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, error_buffer);

    // Get the subnet mask and IP address for the device we're monitoring
    pcap_lookupnet("eth0", &ip, &subnet_mask, error_buffer);

    // Compile the filter expression
    pcap_compile(handle, &filter, "src port 80", 1, subnet_mask);

    // Set the filter
    pcap_setfilter(handle, &filter);

    // Start monitoring loop
    int packet_count = 0;
    struct pcap_pkthdr header;
    const u_char *packet;

    while(packet_count < 10 && (packet = pcap_next(handle, &header))) {

        printf("Packet received on %ld:%ld\n", header.ts.tv_sec, header.ts.tv_usec);
        printf("Packet length: %d\n", header.len);
        print_hex(packet, header.len);
        packet_count++;
    }

    // Close the network packet monitoring handle
    pcap_close(handle);

    return 0;
}