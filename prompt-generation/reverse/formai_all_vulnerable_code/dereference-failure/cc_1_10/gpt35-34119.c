//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <net/ethernet.h>
#include <pcap.h>

#define MAX_PACKET_SIZE 2000

typedef struct packet_data {
    struct timeval time;
    int size;
    char src_ip[16];
    char dst_ip[16];
} packet_data;

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;

    if (argc != 2) {
        printf("Usage: %s [network-interface]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    handle = pcap_open_live(argv[1], MAX_PACKET_SIZE, 1, 1000, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live(): %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    if (pcap_compile(handle, &fp, "ip", 0, 0) == -1) {
        fprintf(stderr, "pcap_compile() failed\n");
        exit(EXIT_FAILURE);
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "pcap_setfilter() failed\n");
        exit(EXIT_FAILURE);
    }

    packet_data packet;
    struct pcap_pkthdr header;
    const struct ether_header *eth_header;
    const struct iphdr *ip_header;
    const struct tcphdr *tcp_header;
    const struct udphdr *udp_header;
    const char *payload;

    while (1) {
        const u_char *packet_pointer = pcap_next(handle, &header);

        if (packet_pointer == NULL) {
            continue;
        }

        eth_header = (struct ether_header *) packet_pointer;
        packet_pointer += sizeof(struct ether_header);

        if (ntohs(eth_header->ether_type) != ETHERTYPE_IP) {
            continue;
        }

        ip_header = (struct iphdr *) packet_pointer;
        packet_pointer += sizeof(struct iphdr);

        if (ip_header->protocol == IPPROTO_TCP) {
            tcp_header = (struct tcphdr *) packet_pointer;
            packet_pointer += sizeof(struct tcphdr);
            payload = (const char *) packet_pointer;
            packet.size = ntohs(ip_header->tot_len);
            strncpy(packet.src_ip, inet_ntoa((struct in_addr) {ip_header->saddr}), 16);
            strncpy(packet.dst_ip, inet_ntoa((struct in_addr) {ip_header->daddr}), 16);
        } else if (ip_header->protocol == IPPROTO_UDP) {
            udp_header = (struct udphdr *) packet_pointer;
            packet_pointer += sizeof(struct udphdr);
            payload = (const char *) packet_pointer;
            packet.size = ntohs(ip_header->tot_len);
            strncpy(packet.src_ip, inet_ntoa((struct in_addr) {ip_header->saddr}), 16);
            strncpy(packet.dst_ip, inet_ntoa((struct in_addr) {ip_header->daddr}), 16);
        }

        gettimeofday(&packet.time, NULL);

        printf("Time: %ld.%06ld | ", packet.time.tv_sec, packet.time.tv_usec);
        printf("Size: %d | ", packet.size);
        printf("Src IP: %s | ", packet.src_ip);
        printf("Dst IP: %s\n", packet.dst_ip);
    }

    pcap_close(handle);

    return 0;
}