//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pcap.h>

#define MAX_PACKET_SIZE 65535

struct packet_header {
    uint32_t ts_sec;     // Timestamp seconds
    uint32_t ts_usec;    // Timestamp microseconds
    uint32_t incl_len;   // Number of bytes of included data
    uint32_t orig_len;   // Actual length of packet
};

struct ip_header {
    uint8_t version;       // Version of IP
    uint8_t header_length; // Length of IP header in 32-bit words
    uint8_t type_of_service; // Type of service
    uint16_t total_length;  // Total length of IP packet
    uint16_t identification; // Identification
    uint16_t flags;          // Flags
    uint8_t ttl;            // Time to live
    uint8_t protocol;       // Protocol
    uint16_t checksum;      // Header checksum
    uint32_t source_ip;     // Source IP address
    uint32_t destination_ip; // Destination IP address
};

struct tcp_header {
    uint16_t source_port;   // Source port
    uint16_t destination_port; // Destination port
    uint32_t sequence_number; // Sequence number
    uint32_t acknowledgment_number; // Acknowledgment number
    uint8_t data_offset;        // Data offset
    uint8_t flags;              // Flags
    uint16_t window;            // Window size
    uint16_t checksum;          // Header checksum
    uint16_t urgent_pointer;    // Urgent pointer
};

struct udp_header {
    uint16_t source_port;   // Source port
    uint16_t destination_port; // Destination port
    uint16_t length;          // Length of UDP packet
    uint16_t checksum;        // Header checksum
};

void print_packet(const u_char *data, int size) {
    struct packet_header *ph = (struct packet_header *)data;
    printf("Timestamp: %u.%06u s\n", ph->ts_sec, ph->ts_usec);
    printf("Included length: %u bytes\n", ph->incl_len);
    printf("Original length: %u bytes\n\n", ph->orig_len);

    struct ip_header *iph = (struct ip_header *)(data + sizeof(struct packet_header));
    printf("IP Version: %u\n", iph->version);
    printf("IP Header Length: %u bytes\n", iph->header_length * 4);
    printf("Type of Service: %u\n", iph->type_of_service);
    printf("Total Length: %u bytes\n", ntohs(iph->total_length));
    printf("Identification: %u\n", ntohs(iph->identification));
    printf("Flags: %u\n", ntohs(iph->flags));
    printf("TTL: %u\n", iph->ttl);
    printf("Protocol: %u\n", iph->protocol);
    printf("Checksum: %u\n", ntohs(iph->checksum));
    printf("Source IP: %s\n", inet_ntoa(*(struct in_addr *)&iph->source_ip));
    printf("Destination IP: %s\n\n", inet_ntoa(*(struct in_addr *)&iph->destination_ip));

    if (iph->protocol == IPPROTO_TCP) {
        struct tcp_header *tcph = (struct tcp_header *)(data + sizeof(struct packet_header) + sizeof(struct ip_header));
        printf("TCP Source Port: %u\n", ntohs(tcph->source_port));
        printf("TCP Destination Port: %u\n", ntohs(tcph->destination_port));
        printf("TCP Sequence Number: %u\n", ntohl(tcph->sequence_number));
        printf("TCP Acknowledgment Number: %u\n", ntohl(tcph->acknowledgment_number));
        printf("TCP Data Offset: %u bytes\n", tcph->data_offset * 4);
        printf("TCP Flags: %u\n", tcph->flags);
        printf("TCP Window Size: %u bytes\n", ntohs(tcph->window));
        printf("TCP Checksum: %u\n", ntohs(tcph->checksum));
        printf("TCP Urgent Pointer: %u bytes\n\n", ntohs(tcph->urgent_pointer));
    } else if (iph->protocol == IPPROTO_UDP) {
        struct udp_header *udph = (struct udp_header *)(data + sizeof(struct packet_header) + sizeof(struct ip_header));
        printf("UDP Source Port: %u\n", ntohs(udph->source_port));
        printf("UDP Destination Port: %u\n", ntohs(udph->destination_port));
        printf("UDP Length: %u bytes\n", ntohs(udph->length));
        printf("UDP Checksum: %u\n\n", ntohs(udph->checksum));
    }

    printf("Payload:\n");
    for (int i = 0; i < size - sizeof(struct packet_header) - sizeof(struct ip_header) - sizeof(struct tcp_header); i++) {
        printf("%02x ", data[i + sizeof(struct packet_header) + sizeof(struct ip_header) + sizeof(struct tcp_header)]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n\n");
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        return -1;
    }

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(argv[1], MAX_PACKET_SIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device: %s\n", errbuf);
        return -1;
    }

    while (1) {
        struct pcap_pkthdr *header;
        const u_char *data;
        int res = pcap_next_ex(handle, &header, &data);
        if (res == 0) {
            continue;
        } else if (res == -1) {
            fprintf(stderr, "Error reading packet: %s\n", pcap_geterr(handle));
            break;
        } else if (res == -2) {
            fprintf(stderr, "EOF reached\n");
            break;
        }

        print_packet(data, header->len);
    }

    pcap_close(handle);
    return 0;
}