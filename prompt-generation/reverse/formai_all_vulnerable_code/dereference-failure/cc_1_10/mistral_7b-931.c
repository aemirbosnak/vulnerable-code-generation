//MISTRAL-7B DATASET v1.0 Category: Network Packet Monitoring ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <math.h>

typedef struct {
    u_int16_t src_port;
    u_int16_t dst_port;
    u_int32_t packet_length;
    u_int8_t protocol;
} packet_info;

void print_packet_info(const u_char *packet, const struct pcap_pkthdr *header, int packet_num) {
    packet_info pi;
    bzero(&pi, sizeof(packet_info));

    pi.src_port = ntohs(packet[12] << 8 | packet[13]);
    pi.dst_port = ntohs(packet[14] << 8 | packet[15]);
    pi.packet_length = header->len;
    pi.protocol = packet[1];

    printf("Packet #%d:\n", packet_num);
    printf("Source Port: %d\n", pi.src_port);
    printf("Destination Port: %d\n", pi.dst_port);
    printf("Packet Length: %d bytes\n", pi.packet_length);
    printf("Protocol: %s\n", (pi.protocol == IPPROTO_TCP) ? "TCP" : (pi.protocol == IPPROTO_UDP) ? "UDP" : "Unknown");

    // Perform Shannon information theory calculations here
    // ...
}

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    char filter_exp[] = "ip";
    pcap_t *handle;
    int num_packets = 10;

    if (argc > 1)
        num_packets = atoi(argv[1]);

    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Error: Unable to open the device %s: %s\n", argv[0], errbuf);
        return 1;
    }

    pcap_loop(handle, num_packets, print_packet_info, NULL);
    pcap_close(handle);

    return 0;
}

// Add Shannon information theory calculations here
// ...