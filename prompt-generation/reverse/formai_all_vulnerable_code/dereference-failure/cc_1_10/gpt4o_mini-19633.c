//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/types.h>

#define BUFFER_SIZE 65536

void process_ip_packet(unsigned char *buffer, int size) {
    struct iphdr *iph = (struct iphdr *)buffer;
    struct sockaddr_in source, dest;

    source.sin_addr.s_addr = iph->saddr;
    dest.sin_addr.s_addr = iph->daddr;

    printf("IP Packet:\n");
    printf("Source IP: %s\n", inet_ntoa(source.sin_addr));
    printf("Destination IP: %s\n", inet_ntoa(dest.sin_addr));
    printf("Protocol: %d\n", iph->protocol);

    if (iph->protocol == 6) { // TCP
        struct tcphdr *tcph = (struct tcphdr *)(buffer + iph->ihl * 4);
        printf("TCP Packet:\n");
        printf("Source Port: %d\n", ntohs(tcph->source));
        printf("Destination Port: %d\n", ntohs(tcph->dest));
    } else if (iph->protocol == 17) { // UDP
        struct udphdr *udph = (struct udphdr *)(buffer + iph->ihl * 4);
        printf("UDP Packet:\n");
        printf("Source Port: %d\n", ntohs(udph->source));
        printf("Destination Port: %d\n", ntohs(udph->dest));
    }
    printf("\n");
}

void start_firewall() {
    int sock_raw;
    struct sockaddr_in saddr;
    int saddr_len = sizeof(saddr);
    unsigned char *buffer = (unsigned char *)malloc(BUFFER_SIZE);

    sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_IP);
    if (sock_raw < 0) {
        perror("Socket Creation Error");
        exit(EXIT_FAILURE);
    }

    while (1) {
        int data_size = recvfrom(sock_raw, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&saddr, (socklen_t *)&saddr_len);
        if (data_size < 0) {
            perror("Recvfrom Error");
            exit(EXIT_FAILURE);
        }

        process_ip_packet(buffer, data_size);
    }

    free(buffer);
    close(sock_raw);
}

int main() {
    printf("Starting C Firewall...\n");
    start_firewall();
    return 0;
}