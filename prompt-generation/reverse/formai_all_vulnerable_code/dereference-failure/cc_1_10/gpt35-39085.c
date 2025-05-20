//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <netinet/ip_icmp.h>

#define PACKET_SIZE 1024

// function to compute the checksum for IP Header
unsigned short calculateIPChecksum(unsigned short *ptr,int length) {
    int sum = 0;
    unsigned short answer = 0;
    unsigned short *w = ptr;
    int nleft = length;
    
    while (nleft > 1) {
        sum += *w++;
        nleft -= 2;
    }
    
    if (nleft == 1) {
        *(unsigned char *)(&answer) = *(unsigned char *)w;
        sum += answer;
    }
    
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    answer = ~sum;
    return answer;
}

// function to compute the checksum for TCP/UDP headers
unsigned short calculateTCPUDPChecksum(unsigned short *ptr,int length,unsigned char *pseudo) {
    int sum = 0;
    unsigned short answer = 0;
    unsigned short *w = ptr;
    int nleft = length;
    
    while (nleft > 1) {
        sum += *w++;
        nleft -= 2;
    }
    
    sum += *pseudo;
    sum += *(pseudo+1);
    sum += *(pseudo+2);
    sum += *(pseudo+3);
    sum += *(pseudo+4);
    sum += htons(length);
    
    while(sum >> 16)
        sum = (sum >> 16) + (sum & 0xffff);
    
    answer = ~sum;
    return answer;
}

int main() {
    int raw_socket = socket(PF_INET, SOCK_RAW, IPPROTO_TCP);
    if(raw_socket < 0)
    {
        perror("Unable to create raw socket");
        return 1;
    }
    
    char packet_buffer[PACKET_SIZE];
    memset(packet_buffer, 0, PACKET_SIZE);
    
    // IP Header
    struct iphdr *ip_header = (struct iphdr *) packet_buffer;
    ip_header->version = 4;
    ip_header->ihl = 5;
    ip_header->tos = 0;
    ip_header->tot_len = htons(PACKET_SIZE);
    ip_header->id = htons(54321);
    ip_header->frag_off = htons(0);
    ip_header->ttl = 64;
    ip_header->protocol = IPPROTO_TCP;
    ip_header->check = 0;
    ip_header->saddr = inet_addr("192.168.0.2");
    ip_header->daddr = inet_addr("192.168.0.1");
    ip_header->check = calculateIPChecksum((unsigned short *)packet_buffer, sizeof(struct iphdr));
    
    // TCP Header
    struct tcphdr *tcp_header = (struct tcphdr *) (packet_buffer + sizeof(struct iphdr));
    tcp_header->source = htons(12345);
    tcp_header->dest = htons(80);
    tcp_header->seq = htons(1);
    tcp_header->ack = 0;
    tcp_header->doff = 5;
    tcp_header->syn = 1;
    tcp_header->window = htons(65535);
    tcp_header->check = 0;
    tcp_header->urg_ptr = 0;
    
    // Pseudo Header
    unsigned char *pseudo_header = malloc(sizeof(unsigned char) * 12);
    *(unsigned int *)(pseudo_header) = inet_addr("192.168.0.2");
    *(unsigned int *)(pseudo_header+4) = inet_addr("192.168.0.1");
    *(pseudo_header+8) = 0;
    *(pseudo_header+9) = IPPROTO_TCP;
    *(unsigned short *)(pseudo_header+10) = htons(sizeof(struct tcphdr));
    
    tcp_header->check = calculateTCPUDPChecksum((unsigned short *)tcp_header, sizeof(struct tcphdr), pseudo_header);
    
    // Send packet to destination
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(80);
    sin.sin_addr.s_addr = inet_addr("192.168.0.1");
    
    int send_status = sendto(raw_socket, packet_buffer, PACKET_SIZE, 0, (struct sockaddr *)&sin, sizeof(sin));
    if(send_status < 0)
    {
        perror("Unable to send packet");
        return 1;
    }
    
    return 0;
}