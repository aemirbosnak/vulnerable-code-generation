//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <unistd.h>

#define BUF_SIZE 65536

// Function to calculate checksum for TCP packets
unsigned short checksum(void *b, uint16_t len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;
    
    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;
    
    if (len == 1)
        sum += *(unsigned char *)buf;

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

// Function to process TCP packets
void process_packet(unsigned char *buffer, int size) {
    struct iphdr *iph = (struct iphdr *)buffer;
    struct tcphdr *tcph = (struct tcphdr *)(buffer + iph->ihl * 4);

    printf("Packet: SrcIP: %s\tDstIP: %s\n",
           inet_ntoa(*(struct in_addr *)&iph->saddr),
           inet_ntoa(*(struct in_addr *)&iph->daddr));

    // Check for TCP port
    if (ntohs(tcph->dest) == 80) {
        printf("Blocking packet destined for Port 80 (HTTP)\n");
        return;
    }

    printf("Allowing packet\n");
}

// Main function to create raw socket and listen for packets
int main() {
    int sockfd;
    unsigned char *buffer = (unsigned char *)malloc(BUF_SIZE);
    struct sockaddr_in sockaddr;
    int sockaddr_len = sizeof(sockaddr);

    // Create a raw socket to capture packets
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) < 0) {
        perror("Socket creation failed");
        return 1;
    }

    while (1) {
        // Receive packets
        int data_size = recvfrom(sockfd, buffer, BUF_SIZE, 0, (struct sockaddr *)&sockaddr, &sockaddr_len);
        if (data_size < 0) {
            perror("Recvfrom error");
            return 1;
        }
        // Process the received packet
        process_packet(buffer, data_size);
    }

    close(sockfd);
    free(buffer);
    return 0;
}