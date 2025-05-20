//FormAI DATASET v1.0 Category: Firewall ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdint.h>

#define MAX_PACKET_SIZE 4096

typedef struct parameters {
    char* ip; 
    char* port;
} parameters_t;

typedef struct {
    uint32_t ip_src;
    uint32_t ip_dst;
    uint8_t zero;
    uint8_t protocol;
    uint16_t length;
} pseudo_header;

void usage() {
    printf("Usage: ./firewall [ip] [port]\n");
    exit(0);
}

parameters_t parse_arguments(int argc, char* argv[]) {
    parameters_t parameters;
    if (argc != 3) {
        usage();
    }
    parameters.ip = strdup(argv[1]);
    parameters.port = strdup(argv[2]);
    return parameters;
}

uint16_t csum(uint16_t* buf, int nwords) {
    uint32_t sum;
    for (sum = 0; nwords > 0; nwords--) {
        sum += *buf++;
    }
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return ~sum;
}

uint16_t tcp_checksum(pseudo_header* pseudo_hdr, uint8_t* tcp_segment, uint16_t tcp_length) {
    uint16_t* tcp_segment_h = (uint16_t*) tcp_segment;
    pseudo_hdr->length = htons(tcp_length);
    uint16_t* src_addr_h = (uint16_t*) &(pseudo_hdr->ip_src);
    uint16_t* dst_addr_h = (uint16_t*) &(pseudo_hdr->ip_dst);

    int tcp_segment_words = tcp_length / 2;

    uint32_t sum = 0;
    sum += *src_addr_h;
    sum += *(src_addr_h + 1);
    sum += *dst_addr_h;
    sum += *(dst_addr_h + 1);
    sum += htons(pseudo_hdr->zero);
    sum += htons(pseudo_hdr->protocol);
    sum += htons(tcp_length);

    return csum((uint16_t*) pseudo_hdr, sizeof(pseudo_header) / 2) + csum(tcp_segment_h, tcp_segment_words) - tcp_length;
}

void process_packet(unsigned char* buffer, int size, parameters_t parameters) {
    // Parse IP header
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    
    uint8_t* ip_hdr = buffer;
    int iphdr_size = (*ip_hdr & 0xf) * 4; // Get the IP header length
    sin.sin_addr.s_addr = *(uint32_t*) (ip_hdr + 16);

    // Check if packet is for our ip
    char* ip_str = inet_ntoa(sin.sin_addr);
    if (strcmp(ip_str, parameters.ip) != 0) {
        printf("DROPPED: Packet not for IP %s\n", parameters.ip);
        return;
    }

    // Parse TCP header
    uint8_t* tcp_hdr = buffer + iphdr_size;
    int tcphdr_size = (*((uint8_t*) tcp_hdr + 12) & 0xf0) >> 2; // Get the TCP header length
    uint8_t* tcp_data = buffer + tcphdr_size + iphdr_size;
    int tcp_data_size = size - tcphdr_size - iphdr_size;
    uint16_t tcp_port = htons(*(uint16_t*) tcp_hdr);

    // Check if packet is for our port
    if (tcp_port != atoi(parameters.port)) {
        printf("DROPPED: Packet not for port %s\n", parameters.port);
        return;
    }

    // Calculate and verify TCP checksum
    pseudo_header pseudo_hdr;
    pseudo_hdr.ip_src = *(uint32_t*) ip_hdr + 12;
    pseudo_hdr.ip_dst = *(uint32_t*) ip_hdr + 16;
    pseudo_hdr.zero = 0;
    pseudo_hdr.protocol = IPPROTO_TCP;
    uint16_t tcp_checksum_raw = *(uint16_t*) ((uint8_t*) tcp_hdr + 16);
    *(uint16_t*) ((uint8_t*) tcp_hdr + 16) = 0;
    if (tcp_checksum(&pseudo_hdr, tcp_hdr, tcp_data_size) != tcp_checksum_raw) {
        printf("DROPPED: Invalid TCP checksum\n");
        return;
    }

    // Print TCP payload
    printf("ACCEPTED: ");
    for (int i = 0; i < tcp_data_size; i++) {
        printf("%c", tcp_data[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    parameters_t parameters = parse_arguments(argc, argv);

    int fd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (fd < 0) {
        perror("socket() error");
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[MAX_PACKET_SIZE];
    while (1) {
        memset(buffer, 0, MAX_PACKET_SIZE);
        int size = recv(fd, buffer, sizeof(buffer), 0);
        if (size < 0) {
            perror("recv() error");
            break;
        }
        process_packet(buffer, size, parameters);
    }

    close(fd);
    return 0;
}