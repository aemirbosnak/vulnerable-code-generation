//FormAI DATASET v1.0 Category: Firewall ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <unistd.h>

/* Structure of an IP Header */
typedef struct iphdr IPHeader;
/* Structure of a TCP Header */
typedef struct tcphdr TCPHeader;

/* Function to handle incoming packets */
void handle_packet(unsigned char* buffer, int size);

int main() {
    int sock_raw;
    struct sockaddr_in saddr;

    // Create a raw socket to sniff packets
    sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);

    if(sock_raw < 0) {
        printf("Error creating socket. Aborting...\n");
        return 1;
    }

    // Set the socket to sniff TCP packets
    int tcp_protocol = IPPROTO_TCP;
    setsockopt(sock_raw, IPPROTO_IP, IP_HDRINCL, &tcp_protocol, sizeof(tcp_protocol));

    // Bind the socket to any available interface
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = INADDR_ANY;
    saddr.sin_port = 0;

    if(bind(sock_raw, (struct sockaddr*)&saddr, sizeof(saddr)) < 0) {
        printf("Error binding socket. Aborting...\n");
        return 1;
    }

    // Start processing incoming packets
    printf("Starting Firewall...\n");
    unsigned char buffer[65536];
    int recv_size;

    while(1) {
        recv_size = recv(sock_raw, buffer, sizeof(buffer), 0);
        if(recv_size > 0) {
            handle_packet(buffer, recv_size);
        }
    }

    return 0;
}

/* Implementation of the packet handler */
void handle_packet(unsigned char* buffer, int size) {
    IPHeader* iphdr = (IPHeader*)buffer;

    // Only process TCP packets
    if(iphdr->protocol != IPPROTO_TCP) {
        return;
    }

    TCPHeader* tcphdr = (TCPHeader*)(buffer + sizeof(IPHeader));

    // Block packets coming from specific source port
    if(ntohs(tcphdr->source) == 80) { // Block all incoming packets from port 80
        printf("Packet blocked from port 80. Source IP: %s\n", inet_ntoa(iphdr->saddr));
        return;
    }

    // Block packets coming from specific IP address
    char* block_ip = "192.168.0.2";
    if(strcmp(inet_ntoa(iphdr->saddr), block_ip) == 0) {
        printf("Packet blocked from IP address %s\n", block_ip);
        return;
    }

    // Pass the packet through
    printf("Packet allowed from source IP address %s and source port %d\n", inet_ntoa(iphdr->saddr), ntohs(tcphdr->source));
    return;
}