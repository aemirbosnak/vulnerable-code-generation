//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 65536

void print_ip_header(unsigned char *buffer, int size);
void print_tcp_header(unsigned char *buffer, int size);
void error_exit(const char *message);
void start_firewall();

int main() {
    start_firewall();
    return 0;
}

void error_exit(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void print_ip_header(unsigned char *buffer, int size) {
    struct iphdr *iph = (struct iphdr *)buffer;
    struct sockaddr_in source, dest;

    memset(&source, 0, sizeof(source));
    memset(&dest, 0, sizeof(dest));

    source.sin_addr.s_addr = iph->saddr;
    dest.sin_addr.s_addr = iph->daddr;

    printf("IP Header\n");
    printf("   |-IP Version        : %d\n", (unsigned int)iph->version);
    printf("   |-IP Header Length  : %d Bytes\n", ((unsigned int)(iph->ihl))*4);
    printf("   |-Type Of Service   : %d\n", (unsigned int)iph->tos);
    printf("   |-IP Total Length   : %d Bytes\n", ntohs(iph->tot_len));
    printf("   |-Identification     : %d\n", ntohs(iph->id));
    printf("   |-TTL               : %d\n", (unsigned int)iph->ttl);
    printf("   |-Protocol          : %d\n", (unsigned int)iph->protocol);
    printf("   |-Checksum          : %d\n", ntohs(iph->check));
    printf("   |-Source IP        : %s\n", inet_ntoa(source.sin_addr));
    printf("   |-Destination IP   : %s\n", inet_ntoa(dest.sin_addr));
}

void print_tcp_header(unsigned char *buffer, int size) {
    struct iphdr *iph = (struct iphdr *)buffer;
    unsigned short ip_header_length = iph->ihl * 4;
    struct tcphdr *tcph = (struct tcphdr *)(buffer + ip_header_length);

    printf("TCP Header\n");
    printf("   |-Source Port       : %u\n", ntohs(tcph->source));
    printf("   |-Destination Port  : %u\n", ntohs(tcph->dest));
    printf("   |-Sequence Number   : %u\n", ntohl(tcph->seq));
    printf("   |-Acknowledge Number: %u\n", ntohl(tcph->ack_seq));
    printf("   |-TCP Header Length : %d Bytes\n", (unsigned int)(tcph->doff) * 4);
    printf("   |-Urgent Flag      : %d\n", (unsigned int)tcph->urg);
    printf("   |-Acknowledgement Flag : %d\n", (unsigned int)tcph->ack);
    printf("   |-Push Flag        : %d\n", (unsigned int)tcph->psh);
    printf("   |-Reset Flag       : %d\n", (unsigned int)tcph->rst);
    printf("   |-Synchronize Flag  : %d\n", (unsigned int)tcph->syn);
    printf("   |-Finish Flag      : %d\n", (unsigned int)tcph->fin);
    printf("   |-Window           : %d\n", ntohs(tcph->window));
    printf("   |-Checksum         : %d\n", ntohs(tcph->check));
    printf("   |-Urgent Pointer   : %d\n", tcph->urg_ptr);
}

void start_firewall() {
    int sockfd;
    struct sockaddr_in source, addr;
    int addr_len = sizeof(addr);
    int data_size;
    unsigned char *buffer = (unsigned char *)malloc(MAX_BUFFER_SIZE);

    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) < 0) {
        error_exit("Socket Creation Failed");
    }

    while (1) {
        data_size = recvfrom(sockfd, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr *)&addr, (socklen_t*)&addr_len);
        if (data_size < 0) {
            error_exit("Recvfrom Error");
        }

        print_ip_header(buffer, data_size);
        print_tcp_header(buffer, data_size);
        printf("\n----------------------------------------\n");
        
        // Pseudo firewall functionality: dropping SYN packets for demonstration
        struct iphdr *iph = (struct iphdr *)buffer;
        struct tcphdr *tcph = (struct tcphdr *)(buffer + (iph->ihl * 4));
        
        if (tcph->syn == 1 && tcph->ack == 0) {
            printf("SYN Packet Dropped!\n");
            continue; // Skip processing this packet
        }
        
        // Otherwise, let the packet go through (simulate forwarding)
        printf("Packet Allowed!\n");
    }

    close(sockfd);
    free(buffer);
}