//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

void usage(char *progname) {
    printf("Usage: %s <src_ip> <src_port> <dst_ip> <dst_port> <data>\n", progname);
}

int main(int argc, char **argv) {
    if (argc < 6) {
        usage(argv[0]);
        exit(1);
    }

    // Create TCP socket
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) < 0) {
        perror("socket() error");
        exit(1);
    }

    // Set socket options
    const int on = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on)) < 0) {
        perror("setsockopt() error");
        exit(1);
    }

    // Prepare packet data
    char *src_ip = argv[1];
    char *dst_ip = argv[3];
    unsigned short src_port = atoi(argv[2]);
    unsigned short dst_port = atoi(argv[4]);
    char *data = argv[5];

    // Calculate packet length
    int iphdr_len = sizeof(struct iphdr);
    int tcphdr_len = sizeof(struct tcphdr);
    int data_len = strlen(data);
    int packet_len = iphdr_len + tcphdr_len + data_len;

    // Allocate memory for packet
    char *packet = (char *) malloc(packet_len);
    if (!packet) {
        perror("malloc() error");
        exit(1);
    }

    // Prepare IP header
    struct iphdr *iph = (struct iphdr *) packet;
    iph->version = 4;
    iph->ihl = 5;
    iph->tos = 0;
    iph->id = htons(1234);
    iph->frag_off = 0;
    iph->ttl = 255;
    iph->protocol = IPPROTO_TCP;
    iph->saddr = inet_addr(src_ip);
    iph->daddr = inet_addr(dst_ip);
    iph->check = 0;

    // Prepare TCP header
    struct tcphdr *tcph = (struct tcphdr *) (packet + iphdr_len);
    tcph->source = htons(src_port);
    tcph->dest = htons(dst_port);
    tcph->seq = htonl(0);
    tcph->ack_seq = 0;
    tcph->doff = sizeof(struct tcphdr) / 4;
    tcph->fin = 0;
    tcph->syn = 1;
    tcph->rst = 0;
    tcph->psh = 0;
    tcph->ack = 0;
    tcph->urg = 0;
    tcph->window = htons(14600);
    tcph->check = 0;
    tcph->urg_ptr = 0;

    // Prepare TCP pseudoheader for checksum calculation
    struct pseudo_tcp {
        unsigned int src_addr;
        unsigned int dst_addr;
        unsigned char zero;
        unsigned char protocol;
        unsigned short length;
    } p_tcp;

    p_tcp.src_addr = inet_addr(src_ip);
    p_tcp.dst_addr = inet_addr(dst_ip);
    p_tcp.zero = 0;
    p_tcp.protocol = IPPROTO_TCP;
    p_tcp.length = htons(tcphdr_len + data_len);

    // Prepare data
    char *payload = packet + iphdr_len + tcphdr_len;
    memcpy(payload, data, data_len);

    // Calculate TCP checksum
    char tcp_check_data[tcphdr_len + data_len];
    memcpy(tcp_check_data, tcph, tcphdr_len);
    memcpy(tcp_check_data + tcphdr_len, data, data_len);

    int tcp_check_len = tcphdr_len + data_len;
    if (tcp_check_len % 2 != 0) {
        tcp_check_len++;
    }

    unsigned short *tcp_check_buf = (unsigned short *) malloc(tcp_check_len);
    if (!tcp_check_buf) {
        perror("malloc() error");
        exit(1);
    }

    memcpy(tcp_check_buf, tcp_check_data, tcp_check_len);
    unsigned int sum = 0;

    for (int i = 0; i < tcp_check_len / 2; i++) {
        sum += tcp_check_buf[i];
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    tcph->check = ~sum;

    // Send packet
    struct sockaddr_in dst_addr;
    dst_addr.sin_family = AF_INET;
    dst_addr.sin_port = htons(dst_port);
    dst_addr.sin_addr.s_addr = inet_addr(dst_ip);

    if (sendto(sockfd, packet, packet_len, 0, (struct sockaddr *) &dst_addr, sizeof(dst_addr)) < 0) {
        perror("sendto() error");
        exit(1);
    }

    printf("Packet sent successfully\n");

    // Clean up
    free(packet);
    free(tcp_check_buf);
    close(sockfd);
    return 0;
}