//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netinet/ip.h>

// Global variables
pcap_t *handle;  // Handle to the capture device
struct pcap_pkthdr *header;  // Header of the captured packet
const u_char *packet;  // Pointer to the captured packet data
int packet_count = 0;  // Count of captured packets

// Function to print the data in a packet
void print_packet(u_char *packet) {
    // Get the IP header
    struct ip *ip_header = (struct ip *) packet;

    // Get the TCP/UDP header
    if (ip_header->ip_p == IPPROTO_TCP) {
        struct tcphdr *tcp_header = (struct tcphdr *) (packet + ip_header->ip_hl * 4);

        // Print the TCP header
        printf("TCP Header\n");
        printf("Source Port: %d\n", ntohs(tcp_header->source));
        printf("Destination Port: %d\n", ntohs(tcp_header->dest));
        printf("Sequence Number: %u\n", ntohl(tcp_header->seq));
        printf("Acknowledgement Number: %u\n", ntohl(tcp_header->ack_seq));
        printf("Data Offset: %d\n", tcp_header->doff * 4);
        printf("Flags: 0x%x\n", tcp_header->fin | tcp_header->syn | tcp_header->rst | tcp_header->psh | tcp_header->ack | tcp_header->urg);
        printf("Window Size: %d\n", ntohs(tcp_header->window));
        printf("Checksum: 0x%x\n", ntohs(tcp_header->check));

        // Print the TCP payload
        printf("TCP Payload:\n");
        printf("%s\n", packet + ip_header->ip_hl * 4 + tcp_header->doff * 4);
    } else if (ip_header->ip_p == IPPROTO_UDP) {
        struct udphdr *udp_header = (struct udphdr *) (packet + ip_header->ip_hl * 4);

        // Print the UDP header
        printf("UDP Header\n");
        printf("Source Port: %d\n", ntohs(udp_header->source));
        printf("Destination Port: %d\n", ntohs(udp_header->dest));
        printf("Length: %d\n", ntohs(udp_header->len));
        printf("Checksum: 0x%x\n", ntohs(udp_header->check));

        // Print the UDP payload
        printf("UDP Payload:\n");
        printf("%s\n", packet + ip_header->ip_hl * 4 + sizeof(struct udphdr));
    } else {
        printf("Unknown protocol\n");
    }
}

// Function to capture packets
void capture_packets() {
    // Loop forever capturing packets
    while (1) {
        // Capture a packet
        int res = pcap_next_ex(handle, &header, &packet);

        // Check if the packet was captured successfully
        if (res == 1) {
            // Increment the packet count
            packet_count++;

            // Print the packet data
            print_packet(packet);

            // Print a newline
            printf("\n");
        } else if (res == 0) {
            // No packets were captured
            continue;
        } else {
            // An error occurred while capturing the packet
            fprintf(stderr, "Error capturing packet: %s\n", pcap_geterr(handle));
            break;
        }
    }
}

// Main function
int main() {
    // Open the network interface
    handle = pcap_open_live("eth0", 65535, 1, 1000, NULL);

    // Check if the network interface was opened successfully
    if (handle == NULL) {
        fprintf(stderr, "Error opening network interface: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Start capturing packets
    capture_packets();

    // Close the network interface
    pcap_close(handle);

    return 0;
}