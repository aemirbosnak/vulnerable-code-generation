//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>
#include <arpa/inet.h>

// Function to print the packet details
void print_packet_info(const u_char *packet, struct pcap_pkthdr *header) {
    printf("--------------------------------------------------------\n");
    printf("Packet length: %d\n", header->len);
    printf("Packet received at: %s\n", ctime((const time_t *)&header->ts.tv_sec));
    printf("Source MAC: %.2X:%.2X:%.2X:%.2X:%.2X:%.2X\n", 
        packet[6], packet[7], packet[8], packet[9], packet[10], packet[11]);
    printf("Destination MAC: %.2X:%.2X:%.2X:%.2X:%.2X:%.2X\n", 
        packet[0], packet[1], packet[2], packet[3], packet[4], packet[5]);

    // Check if the packet is an IPv4 packet
    if (packet[12] == 0x08 && packet[13] == 0x00) {
        printf("IPv4 packet\n");
        // Extract the source and destination IP addresses
        char src_ip[INET_ADDRSTRLEN];
        char dst_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &packet[26], src_ip, INET_ADDRSTRLEN);
        inet_ntop(AF_INET, &packet[30], dst_ip, INET_ADDRSTRLEN);
        printf("Source IP: %s\n", src_ip);
        printf("Destination IP: %s\n", dst_ip);

        // Check if the packet is a TCP packet
        if (packet[23] == 6) {
            printf("TCP packet\n");
            // Extract the source and destination ports
            printf("Source port: %d\n", ntohs(*(unsigned short *)(packet + 34)));
            printf("Destination port: %d\n", ntohs(*(unsigned short *)(packet + 36)));
        }
        // Check if the packet is a UDP packet
        else if (packet[23] == 17) {
            printf("UDP packet\n");
            // Extract the source and destination ports
            printf("Source port: %d\n", ntohs(*(unsigned short *)(packet + 34)));
            printf("Destination port: %d\n", ntohs(*(unsigned short *)(packet + 36)));
        }
    }
    // Check if the packet is an IPv6 packet
    else if (packet[12] == 0x86 && packet[13] == 0xdd) {
        printf("IPv6 packet\n");
        // TODO: Extract the source and destination IPv6 addresses
    }
}

int main() {
    char *interface = "eth0"; // Change to the interface you want to monitor
    bpf_u_int32 net;
    bpf_u_int32 mask;

    // Get the network and mask for the interface
    if (pcap_lookupnet(interface, &net, &mask, NULL) == -1) {
        perror("pcap_lookupnet() failed");
        return -1;
    }

    // Open the interface for packet capture
    pcap_t *handle = pcap_open_live(interface, BUFSIZ, 1, 1000, NULL);
    if (handle == NULL) {
        perror("pcap_open_live() failed");
        return -1;
    }

    // Start the packet capture loop
    while (1) {
        struct pcap_pkthdr *header;
        const u_char *packet;
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == -1) {
            perror("pcap_next_ex() failed");
            break;
        } else if (res == -2) {
            // Timeout occurred
            continue;
        }

        // Print the packet details
        print_packet_info(packet, header);
    }

    // Close the interface
    pcap_close(handle);

    return 0;
}