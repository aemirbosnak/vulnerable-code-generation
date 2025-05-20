//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <netinet/ip_icmp.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <errno.h>

#define BUFFER_SIZE 65536

void process_packet(unsigned char *buffer, int size) {
    struct iphdr *iph = (struct iphdr *)buffer;
    
    switch (iph->protocol) {
        case IPPROTO_TCP: {
            struct tcphdr *tcph = (struct tcphdr *)(buffer + iph->ihl * 4);
            printf("TCP Packet\n");
            printf("Source IP: %s\n", inet_ntoa(*(struct in_addr *)&iph->saddr));
            printf("Destination IP: %s\n", inet_ntoa(*(struct in_addr *)&iph->daddr));
            printf("Source Port: %u\n", ntohs(tcph->source));
            printf("Destination Port: %u\n", ntohs(tcph->dest));
            break;
        }
        case IPPROTO_UDP: {
            struct udphdr *udph = (struct udphdr *)(buffer + iph->ihl * 4);
            printf("UDP Packet\n");
            printf("Source IP: %s\n", inet_ntoa(*(struct in_addr *)&iph->saddr));
            printf("Destination IP: %s\n", inet_ntoa(*(struct in_addr *)&iph->daddr));
            printf("Source Port: %u\n", ntohs(udph->source));
            printf("Destination Port: %u\n", ntohs(udph->dest));
            break;
        }
        case IPPROTO_ICMP: {
            struct icmphdr *icmph = (struct icmphdr *)(buffer + iph->ihl * 4);
            printf("ICMP Packet\n");
            printf("Source IP: %s\n", inet_ntoa(*(struct in_addr *)&iph->saddr));
            printf("Destination IP: %s\n", inet_ntoa(*(struct in_addr *)&iph->daddr));
            break;
        }
        default:
            printf("Unknown Protocol: %d\n", iph->protocol);
            break;
    }
    printf("----------------------------------------------------------\n");
}

int main() {
    int sockfd;
    struct sockaddr saddr;
    int saddr_len = sizeof(saddr);
    unsigned char *buffer = (unsigned char *)malloc(BUFFER_SIZE);
    
    // Create a raw socket to capture packets
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    while (1) {
        // Receive packets
        int bytes_received = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, &saddr, (socklen_t*)&saddr_len);
        if (bytes_received < 0) {
            perror("Recvfrom error");
            break;
        }
        
        // Process received packet
        process_packet(buffer, bytes_received);
    }

    // Clean up
    free(buffer);
    close(sockfd);
    return 0;
}