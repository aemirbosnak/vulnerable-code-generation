//FormAI DATASET v1.0 Category: Firewall ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFSIZE 1024

const char *BLOCKED_IP = "192.168.1.5";
const int BLOCKED_PORT = 8080;

struct packet_info {
    struct in_addr src_ip;
    struct in_addr dst_ip;
    unsigned short source_port;
    unsigned short dest_port;
    int payload_size;
    char payload[BUFSIZE];
};

void analyze_packet(unsigned char *packet, int packet_size)
{
    struct iphdr *ip_hdr = (struct iphdr *) packet;
    struct tcphdr *tcp_hdr = (struct tcphdr *) (packet + (ip_hdr->ihl << 2));
    struct packet_info *info = (struct packet_info *) malloc(sizeof(struct packet_info));

    info->src_ip = (struct in_addr) { ip_hdr->saddr };
    info->dst_ip = (struct in_addr) { ip_hdr->daddr };
    info->source_port = ntohs(tcp_hdr->th_sport);
    info->dest_port = ntohs(tcp_hdr->th_dport);
    info->payload_size = packet_size - (ip_hdr->ihl << 2) - (tcp_hdr->doff << 2);
    memcpy(info->payload, packet + (ip_hdr->ihl << 2) + (tcp_hdr->doff << 2), info->payload_size);

    if (ip_hdr->protocol == IPPROTO_TCP && strcmp(inet_ntoa(info->src_ip), BLOCKED_IP) == 0 && info->dest_port == BLOCKED_PORT) {
        printf("Blocked incoming packet from %s:%d to %s:%d\n", inet_ntoa(info->src_ip), info->source_port, inet_ntoa(info->dst_ip), info->dest_port);
        free(info);
        return;
    }

    printf("Got packet from %s:%d to %s:%d with %d bytes of payload\n", inet_ntoa(info->src_ip), info->source_port, inet_ntoa(info->dst_ip), info->dest_port, info->payload_size);
    free(info);
}

int main()
{
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("Unable to create socket");
        exit(1);
    }

    struct sockaddr_in addr = { 0 };
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Unable to bind socket");
        exit(1);
    }

    unsigned char buffer[BUFSIZE];
    int packet_size;

    while (1) {
        packet_size = recvfrom(sockfd, buffer, BUFSIZE, 0, NULL, NULL);
        if (packet_size < 0) {
            perror("Unable to receive packet");
            exit(1);
        }

        analyze_packet(buffer, packet_size);
    }

    return 0;
}