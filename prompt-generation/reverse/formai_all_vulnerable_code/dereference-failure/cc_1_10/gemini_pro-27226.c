//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define ETHERNET_HEADER_LEN 14
#define IP_HEADER_LEN 20
#define TCP_HEADER_LEN 20

typedef struct mac_addr {
    uint8_t mac[6];
} mac_addr_t;

typedef struct ip_addr {
    uint8_t ip[4];
} ip_addr_t;

typedef struct tcp_port {
    uint16_t port;
} tcp_port_t;

typedef struct packet {
    mac_addr_t src_mac;
    mac_addr_t dst_mac;
    uint16_t eth_type;
    ip_addr_t src_ip;
    ip_addr_t dst_ip;
    uint8_t ip_proto;
    tcp_port_t src_port;
    tcp_port_t dst_port;
    uint8_t *payload;
    size_t payload_len;
} packet_t;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *interface = argv[1];

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(interface, 65535, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("pcap_open_live(): %s\n", errbuf);
        return EXIT_FAILURE;
    }

    struct bpf_program fp;
    if (pcap_compile(handle, &fp, "tcp and port 80", 1, 0) < 0) {
        printf("pcap_compile(): %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }
    if (pcap_setfilter(handle, &fp) < 0) {
        printf("pcap_setfilter(): %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    int packets_processed = 0;
    while (1) {
        struct pcap_pkthdr *header;
        const u_char *data;
        int res = pcap_next_ex(handle, &header, &data);
        if (res < 0) {
            printf("pcap_next_ex(): %s\n", pcap_geterr(handle));
            return EXIT_FAILURE;
        } else if (res == 0) {
            continue;
        }

        packets_processed++;

        // Parse the Ethernet header
        packet_t packet;
        memcpy(&packet.src_mac, data, 6);
        memcpy(&packet.dst_mac, data + 6, 6);
        packet.eth_type = ntohs(*(uint16_t *)(data + 12));

        // Parse the IP header
        data += ETHERNET_HEADER_LEN;
        memcpy(&packet.src_ip, data + 12, 4);
        memcpy(&packet.dst_ip, data + 16, 4);
        packet.ip_proto = *(data + 9);

        // Parse the TCP header
        data += IP_HEADER_LEN;
        packet.src_port.port = ntohs(*(uint16_t *)data);
        packet.dst_port.port = ntohs(*(uint16_t *)(data + 2));

        // Get the payload
        packet.payload = (uint8_t *)data + TCP_HEADER_LEN;
        packet.payload_len = header->len - (ETHERNET_HEADER_LEN + IP_HEADER_LEN + TCP_HEADER_LEN);

        // Print the packet info
        printf("Packet %d:\n", packets_processed);
        printf("  Source MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
            packet.src_mac.mac[0], packet.src_mac.mac[1], packet.src_mac.mac[2],
            packet.src_mac.mac[3], packet.src_mac.mac[4], packet.src_mac.mac[5]);
        printf("  Destination MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
            packet.dst_mac.mac[0], packet.dst_mac.mac[1], packet.dst_mac.mac[2],
            packet.dst_mac.mac[3], packet.dst_mac.mac[4], packet.dst_mac.mac[5]);
        printf("  EtherType: 0x%04x\n", packet.eth_type);
        printf("  Source IP: %u.%u.%u.%u\n",
            packet.src_ip.ip[0], packet.src_ip.ip[1], packet.src_ip.ip[2], packet.src_ip.ip[3]);
        printf("  Destination IP: %u.%u.%u.%u\n",
            packet.dst_ip.ip[0], packet.dst_ip.ip[1], packet.dst_ip.ip[2], packet.dst_ip.ip[3]);
        printf("  IP Protocol: %u\n", packet.ip_proto);
        printf("  Source Port: %u\n", packet.src_port.port);
        printf("  Destination Port: %u\n", packet.dst_port.port);
        printf("  Payload:\n");
        for (size_t i = 0; i < packet.payload_len; i++) {
            printf("    %02x", packet.payload[i]);
        }
        printf("\n\n");
    }

    pcap_close(handle);

    return EXIT_SUCCESS;
}