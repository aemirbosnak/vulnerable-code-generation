//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <net/ethernet.h>

void analyze_packet(unsigned char *packet, int length);

int main(int argc, char *argv[]) {
    int sd;
    unsigned char *buffer;
    ssize_t buffer_length;
    struct sockaddr_in server_address;
    socklen_t addr_len = sizeof(server_address);

    if ((sd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) < 0) { // Protocol type TCP
        perror("socket() error");
        exit(EXIT_FAILURE);
    }

    while (1) {
        buffer = (unsigned char *) malloc(65536); // Allocate memory to receive packet
        buffer_length = recvfrom(sd, buffer, 65536, 0, (struct sockaddr *) &server_address, &addr_len); // Receive packet
        analyze_packet(buffer, buffer_length); // Analyze packet
        free(buffer); // Release memory allocated to buffer
    }

    close(sd); // Close socket
    return 0;
}

void analyze_packet(unsigned char *packet, int length) {
    struct ether_header *eth_header = (struct ether_header *) packet; // Ethernet header
    struct iphdr *ip_header = (struct iphdr *) (packet + sizeof(struct ether_header)); // IP header
    struct tcphdr *tcp_header = (struct tcphdr *) (packet + sizeof(struct ether_header) + sizeof(struct iphdr)); // TCP header
    struct hostent *host_entry;
    char source_address[18], dest_address[18];

    if (ntohs(eth_header->ether_type) != ETHERTYPE_IP) { // Check if IP protocol
        fprintf(stderr, "Not an IP packet\n");
        return;
    }

    // Convert source and destination IP addresses to readable format
    snprintf(
        source_address,
        sizeof(source_address),
        "%d.%d.%d.%d",
        (ntohl(ip_header->saddr) >> 24) & 0xff,
        (ntohl(ip_header->saddr) >> 16) & 0xff,
        (ntohl(ip_header->saddr) >> 8) & 0xff,
        (ntohl(ip_header->saddr)) & 0xff
    );

    snprintf(
        dest_address,
        sizeof(dest_address),
        "%d.%d.%d.%d",
        (ntohl(ip_header->daddr) >> 24) & 0xff,
        (ntohl(ip_header->daddr) >> 16) & 0xff,
        (ntohl(ip_header->daddr) >> 8) & 0xff,
        (ntohl(ip_header->daddr)) & 0xff
    );

    // Get host name from source IP address
    host_entry = gethostbyaddr(&ip_header->saddr, sizeof(ip_header->saddr), AF_INET);

    printf("Packet captured from %s (%s)\n", host_entry->h_name, source_address);
    printf("\tSource Port: %d\n", ntohs(tcp_header->source));
    printf("\tDestination Port: %d\n", ntohs(tcp_header->dest));
    printf("\tSequence Number: %u\n", ntohl(tcp_header->seq));
    printf("\tAcknowledge Number: %u\n", ntohl(tcp_header->ack_seq));
    printf("\tHeader Length: %d\n", tcp_header->doff);
    printf("\tTCP Flags: ");
    if (tcp_header->urg) printf("[URG] ");
    if (tcp_header->ack) printf("[ACK] ");
    if (tcp_header->psh) printf("[PSH] ");
    if (tcp_header->rst) printf("[RST] ");
    if (tcp_header->syn) printf("[SYN] ");
    if (tcp_header->fin) printf("[FIN] ");
    printf("\n");
    printf("\tData Offset: %d bytes\n", tcp_header->doff * 4);
    printf("\tWindow Size: %d\n", ntohs(tcp_header->window));
    printf("\tChecksum: %d\n", ntohs(tcp_header->check));
}