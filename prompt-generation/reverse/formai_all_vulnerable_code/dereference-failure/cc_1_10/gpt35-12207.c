//FormAI DATASET v1.0 Category: Network Ping Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/time.h>

#define MAX_PACKET_SIZE 65536

// Define IP header struct
struct IPHeader {
    unsigned char ip_hl:4,
                  ip_v:4;
    unsigned char ip_tos;
    unsigned short ip_len;
    unsigned short ip_id;
    unsigned short ip_off;
    unsigned char ip_ttl;
    unsigned char ip_p;
    unsigned short ip_sum;
    struct in_addr ip_src, ip_dst;
};

// Define ICMP header struct
struct ICMPHeader {
    unsigned char type;
    unsigned char code;
    unsigned short checksum;
    unsigned short id;
    unsigned short sequence;
    struct timeval timestamp;
};

// Calculate checksum for packet
unsigned short computeChecksum(unsigned char *packet, int packetSize) {
    unsigned long sum = 0;
    unsigned short *ptr = (unsigned short *)packet;
    
    for (int i = 0; i < packetSize; i += 2) {
        sum += ntohs(*ptr++);
    }
    
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    
    return (unsigned short)(~sum);
}

// Send ICMP echo request to given host
int sendPing(int sock, struct sockaddr *addr, int sequence) {
    struct ICMPHeader icmp_header;
    
    memset(&icmp_header, 0, sizeof(icmp_header));
    
    icmp_header.type = 8;
    icmp_header.code = 0;
    icmp_header.id = getpid() & 0xFFFF;
    icmp_header.sequence = sequence;
    gettimeofday(&icmp_header.timestamp, NULL);
    
    icmp_header.checksum = computeChecksum((unsigned char *)&icmp_header, sizeof(icmp_header));
    
    if (sendto(sock, &icmp_header, sizeof(icmp_header), 0, addr, sizeof(struct sockaddr)) == -1) {
        return -1;
    }
    
    return 0;
}

// Receive ICMP echo reply and calculate RTT
int receivePing(int sock, int sequence, struct sockaddr *addr, long *rtt) {
    unsigned char buffer[MAX_PACKET_SIZE];
    memset(buffer, 0, MAX_PACKET_SIZE);
    
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);
    
    int addr_size = sizeof(struct sockaddr);
    int bytes_received = recvfrom(sock, buffer, MAX_PACKET_SIZE, 0, addr, &addr_size);
    
    gettimeofday(&end_time, NULL);
    
    if (bytes_received == -1) {
        return -1;
    }
    
    struct IPHeader *ip_header = (struct IPHeader *)buffer;
    int ip_header_length = ip_header->ip_hl * 4;
    
    struct ICMPHeader *icmp_header = (struct ICMPHeader *)(buffer + ip_header_length);
    
    if (icmp_header->type == 0 && icmp_header->id == (getpid() & 0xFFFF) && icmp_header->sequence == sequence) {
        *rtt = (end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_usec - start_time.tv_usec) / 1000;
        return 0;
    }
    
    return -1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <hostname or IP address>\n", argv[0]);
        return 1;
    }
    
    char *hostname = argv[1];
    struct hostent *host = gethostbyname(hostname);
    if (!host) {
        printf("Error: Could not resolve hostname.\n");
        return 1;
    }
    
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock == -1) {
        printf("Error: Failed to create raw socket.\n");
        return 1;
    }
    
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    memcpy(&addr.sin_addr, host->h_addr_list[0], sizeof(struct in_addr));
    
    char ip_str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(addr.sin_addr), ip_str, INET_ADDRSTRLEN);
    printf("Pinging %s (%s):\n", hostname, ip_str);
    
    long rtt_sum = 0;
    long rtt_min = 999999;
    long rtt_max = 0;
    int packets_received = 0;
    int sequence = 1;
    
    for (int i = 0; i < 10; i++) {
        if (sendPing(sock, (struct sockaddr *)&addr, sequence) == -1) {
            printf("Error: Failed to send ping.\n");
            continue;
        }
        
        long rtt;
        if (receivePing(sock, sequence, (struct sockaddr *)&addr, &rtt) == -1) {
            printf("Timeout\n");
            continue;
        }
        
        printf("Reply from %s: time=%ldms\n", ip_str, rtt);
        
        rtt_sum += rtt;
        if (rtt < rtt_min) {
            rtt_min = rtt;
        }
        if (rtt > rtt_max) {
            rtt_max = rtt;
        }
        packets_received++;
        
        sequence++;
        usleep(500000);
    }
    
    if (packets_received == 0) {
        printf("Ping did not receive any packets.\n");
        return 1;
    }
    
    long rtt_avg = rtt_sum / packets_received;
    float packet_loss_percent = (1 - (float)packets_received / 10) * 100;
    
    printf("\nPing statistics for %s:\n", ip_str);
    printf("    Packets: Sent = 10, Received = %d, Lost = %d (%.0f%% loss)\n", packets_received, 10 - packets_received, packet_loss_percent);
    printf("Approximate round trip times in milli-seconds:\n");
    printf("    Minimum = %ldms, Maximum = %ldms, Average = %ldms\n", rtt_min, rtt_max, rtt_avg);
    
    close(sock);
    
    return 0;
}