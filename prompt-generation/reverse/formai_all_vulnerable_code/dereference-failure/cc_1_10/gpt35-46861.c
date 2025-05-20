//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: peaceful
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/ether.h>

int main(int argc, char **argv) {

    if (argc != 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        exit(1);
    }

    char *interface = argv[1];
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(interface, BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL) {
        printf("Couldn't open device %s: %s\n", interface, errbuf);
        exit(1);
    }

    printf("Packet Capturing on interface %s...\n", interface);

    struct pcap_pkthdr *header;
    const u_char *packet;

    while (pcap_next_ex(handle, &header, &packet) >= 0) {

        printf("======================================\n");
        printf("Packet captured.\n");

        struct ether_header *eth_header = (struct ether_header *) packet;

        printf("Source MAC Address: %s\n", ether_ntoa((const struct ether_addr *) eth_header->ether_shost));
        printf("Destination MAC Address: %s\n", ether_ntoa((const struct ether_addr *) eth_header->ether_dhost));

        uint16_t eth_type = ntohs(eth_header->ether_type);
        printf("Ethernet Type: 0x%04x\n", eth_type);

        if (eth_type == ETHERTYPE_IP) {

            printf("Protocol: IP\n");

            uint8_t *ip_packet = (uint8_t *)(packet + sizeof(struct ether_header));

            uint8_t ip_version = ((*ip_packet & 0xF0) >> 4);

            if (ip_version == 4) {

                printf("IP Version: IPv4\n");

                uint8_t ip_header_len = ((*ip_packet & 0x0F) * 4);
                printf("IP Header Length: %d bytes\n", ip_header_len);

                in_addr_t src_ip = *((in_addr_t *)(ip_packet + 12));
                in_addr_t dst_ip = *((in_addr_t *)(ip_packet + 16));

                char src_ip_str[INET_ADDRSTRLEN];
                char dst_ip_str[INET_ADDRSTRLEN];

                inet_ntop(AF_INET, &src_ip, src_ip_str, INET_ADDRSTRLEN);
                inet_ntop(AF_INET, &dst_ip, dst_ip_str, INET_ADDRSTRLEN);

                printf("Source IP Address: %s\n", src_ip_str);
                printf("Destination IP Address: %s\n", dst_ip_str);

                uint8_t ip_protocol = *(ip_packet + 9);

                printf("IP Protocol: %d\n", ip_protocol);

                if (ip_protocol == IPPROTO_TCP) {

                    printf("Protocol: TCP\n");

                    uint8_t *tcp_packet = (uint8_t *)(ip_packet + ip_header_len);
                    uint16_t src_port = ntohs(*((uint16_t *)tcp_packet));
                    uint16_t dst_port = ntohs(*((uint16_t *)(tcp_packet + 2)));

                    printf("Source Port: %d\n", src_port);
                    printf("Destination Port: %d\n", dst_port);

                    uint8_t tcp_header_len = ((*((uint8_t *)(tcp_packet + 12))) >> 4) * 4;
                    printf("TCP Header Length: %d bytes\n", tcp_header_len);

                } else if (ip_protocol == IPPROTO_UDP) {

                    printf("Protocol: UDP\n");

                    uint8_t *udp_packet = (uint8_t *)(ip_packet + ip_header_len);
                    uint16_t src_port = ntohs(*((uint16_t *)udp_packet));
                    uint16_t dst_port = ntohs(*((uint16_t *)(udp_packet + 2)));

                    printf("Source Port: %d\n", src_port);
                    printf("Destination Port: %d\n", dst_port);

                } else {
                    printf("Unknown IP Protocol: %d", ip_protocol);
                }

            } else {
                printf("Invalid IP Version: %d", ip_version);
            }

        } else if (eth_type == ETHERTYPE_ARP) {
            printf("Protocol: ARP\n");
        } else {
            printf("Unknown Ethernet Type: 0x%04x", eth_type);
        }

        printf("\n\n");
    }

    pcap_close(handle);
    return 0;
}