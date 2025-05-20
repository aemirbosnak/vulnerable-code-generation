//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: Sherlock Holmes
// It was a dark and stormy night in the city of London, and I found myself sitting in front of my computer
// trying to unravel a mystery that had been keeping me up at night. The task at hand was to develop a unique
// C Network Packet Monitoring program that could capture and analyze network packets to expose any suspicious
// activity. I lit my pipe, took a sip of my tea and began to type away.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/if_ether.h>
#include <net/ethernet.h>

void capture_packet(unsigned char* buffer, int size) {
    struct ethhdr *eth = (struct ethhdr*)(buffer);
    struct iphdr *ip = (struct iphdr*)(buffer + sizeof(struct ethhdr));
    
    printf("Source MAC: %02x:%02x:%02x:%02x:%02x:%02x\n", eth->h_source[0], eth->h_source[1], eth->h_source[2], eth->h_source[3], eth->h_source[4], eth->h_source[5]);
    printf("Destination MAC: %02x:%02x:%02x:%02x:%02x:%02x\n", eth->h_dest[0], eth->h_dest[1], eth->h_dest[2], eth->h_dest[3], eth->h_dest[4], eth->h_dest[5]);
    printf("Protocol: %d\n", eth->h_proto);
    
    printf("\tSource IP: %s\n", inet_ntoa(*(struct in_addr *)&(ip->saddr)));
    printf("\tDestination IP: %s\n", inet_ntoa(*(struct in_addr *)&(ip->daddr)));
}

int main() {
    int sock_raw;
    socklen_t saddr_size;
    struct sockaddr saddr;
    unsigned char *buffer = (unsigned char *)malloc(65536);
    
    sock_raw = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if(sock_raw < 0) {
        fprintf(stderr, "ERROR: Socket creation failed\n");
        return 1;
    }
    
    while(1) {
        saddr_size = sizeof(saddr);
        int count = recvfrom(sock_raw, buffer, 65536, 0, &saddr, &saddr_size);
        if(count < 0) {
            fprintf(stderr, "ERROR: Packet capture failed\n");
            return 1;
        }
        capture_packet(buffer, count);
    }
    
    close(sock_raw);
    free(buffer);
    return 0;
}