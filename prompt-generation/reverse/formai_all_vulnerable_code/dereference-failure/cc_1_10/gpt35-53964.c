//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: lively
#include <pcap.h> // pcap library

// function to print the packet
void print_packet_info(const u_char *packet) {
    printf("Packet Information: \n");
    printf("--------------------\n");

    // print the packet
    for(int i = 0; i < sizeof(packet); i++) {
        printf("%02X ", packet[i]);
        if((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    pcap_t *handle; // packet capture handle
    char errbuf[PCAP_ERRBUF_SIZE]; // error buffer
    struct bpf_program fp; // compiled filter program
    char filter_exp[] = "port 80"; // filter expression
    bpf_u_int32 net; // IP
    bpf_u_int32 mask; // subnet mask
    struct pcap_pkthdr header; // packet header
    const u_char *packet; // packet data

    // look up the network and subnet mask from the capture device
    if(pcap_lookupnet("eth0", &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Error: %s\n", errbuf);
        return 1;
    }

    // open the capture device for packet capture
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if(handle == NULL) {
        fprintf(stderr, "Error: unable to open device: %s\n", errbuf);
        return 2;
    }

    // compile and apply the filter on the capture device
    if(pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Error: could not compile filter: %s\n", pcap_geterr(handle));
        return 3;
    }
    if(pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error: could not set filter: %s\n", pcap_geterr(handle));
        return 4;
    }

    // loop through the captured packets and print their information
    while(1) {
        packet = pcap_next(handle, &header);
        printf("Received packet at time %s\n", ctime((const time_t*)&header.ts.tv_sec));
        print_packet_info(packet);
    }

    // clean up
    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}