//FormAI DATASET v1.0 Category: Network Ping Test ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define PACKET_SIZE     4096
#define PING_TIMEOUT    2
#define SEQ_NUM     666

int checksum(unsigned short *b, int len);

int main(int argc, char *argv[]) {

    if(argc != 2) {
        printf("Usage: %s <IP>\n",argv[0]);
        return 1;
    }

    struct hostent *host = gethostbyname(argv[1]);
    if(!host) {
        printf("Error: Could not resolve hostname \"%s\"\n",argv[1]);
        return 1;
    }

    struct sockaddr_in ping_addr;
    memset(&ping_addr, 0, sizeof(struct sockaddr_in));
    ping_addr.sin_family = AF_INET;
    memcpy(&ping_addr.sin_addr, host->h_addr, host->h_length);

    int ping_socket = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if(ping_socket == -1) {
        printf("Error: Failed to create ICMP socket.\n");
        return 1;
    }

    char packet[PACKET_SIZE];
    memset(packet,0,sizeof(packet));

    struct icmp *icmp_hdr = (struct icmp*)packet;
    icmp_hdr->icmp_type = ICMP_ECHO;
    icmp_hdr->icmp_code = 0;
    icmp_hdr->icmp_id = getpid() & 0xFFFF;
    icmp_hdr->icmp_seq = SEQ_NUM;
    icmp_hdr->icmp_cksum = 0;
    icmp_hdr->icmp_cksum = checksum((unsigned short*)icmp_hdr, sizeof(struct icmp));

    int ping_packet_size = sizeof(struct icmp);
    struct timeval tv_out;
    tv_out.tv_sec = PING_TIMEOUT;
    tv_out.tv_usec = 0;
    setsockopt(ping_socket, SOL_SOCKET, SO_RCVTIMEO, &tv_out, sizeof(tv_out));

    int sent = sendto(ping_socket, packet, ping_packet_size, 0, (struct sockaddr*)&ping_addr, sizeof(ping_addr));
    if(sent == -1) {
        printf("Error: Failed to send ping request.\n");
        return 1;
    }

    char recv_packet[PACKET_SIZE];
    memset(recv_packet,0,sizeof(recv_packet));

    struct sockaddr_in recv_addr;
    socklen_t recv_addr_len = sizeof(recv_addr);

    int received = recvfrom(ping_socket, recv_packet, sizeof(recv_packet), 0, (struct sockaddr*)&recv_addr, &recv_addr_len);
    if(received == -1) {
        printf("Error: No response received from host.\n");
        return 1;
    }

    struct iphdr *iphdr = (struct iphdr*)recv_packet;
    struct icmp *icmp_resp_hdr = (struct icmp*)(recv_packet + (iphdr->ihl*4));
    if(icmp_resp_hdr->icmp_type == ICMP_ECHOREPLY) {
        printf("Ping successful: %s\n", argv[1]);
    }
    else {
        printf("Ping not successful: %s\n", argv[1]);
    }

    return 0;
}

int checksum(unsigned short *b, int len) {
    unsigned int sum = 0;
    for(; len > 1; len -= 2) {
        sum += *b++;
    }
    if(len == 1) {
        sum += *(unsigned char*)b;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}