//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <sys/time.h>

#define PACKET_SIZE 64
#define PING_TIMEOUT 2
#define HOPS_LIMIT 30
#define PROBE_NUM 3

struct sockaddr_in dest_ip;
char dest_ip_str[INET_ADDRSTRLEN];

struct timeval time_start, time_end;

void error(const char *msg) {
    perror(msg);
    exit(0);
}

uint16_t calculate_checksum(uint16_t *addr, int len) {
    uint32_t sum = 0;
    for(;len > 1; len-=2){
        sum += *addr++;
        if(sum & 0x80000000)   
            sum = (sum & 0xFFFF) + (sum >> 16);
    }
    if(len == 1){
        uint16_t tmp;
        *(uint8_t*)(&tmp) = *(uint8_t*)addr;
        sum += tmp;
        if(sum & 0x80000000)    
            sum = (sum & 0xFFFF) + (sum >> 16);
    }
    while(sum >> 16)
        sum = (sum & 0xFFFF) + (sum >> 16);
    return ~sum;
}

int send_ICMP_request(int sockfd, int ttl) {
    struct icmphdr icmp_header;
    memset(&icmp_header, 0, sizeof(struct icmphdr));
    icmp_header.type = ICMP_ECHO;
    icmp_header.code = 0;
    icmp_header.un.echo.id = getpid();
    icmp_header.un.echo.sequence = ttl;
    icmp_header.checksum = calculate_checksum((uint16_t *)&icmp_header, sizeof(icmp_header));

    if(setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) == -1)
        error("Failed to set TTL for socket");

    if(sendto(sockfd, &icmp_header, sizeof(icmp_header), 0, (struct sockaddr *)&dest_ip, sizeof(dest_ip)) == -1)
        error("Failed to send ICMP request");

    return 0;
}

int receive_ICMP_response(int sockfd, char *src_ip_str, int ttl) {
    char buffer[PACKET_SIZE];
    memset(buffer, 0, PACKET_SIZE);
    struct sockaddr_in src_ip;
    socklen_t src_ip_len = sizeof(src_ip);
    struct icmphdr *icmp_header;
    struct iphdr *ip_header;

    gettimeofday(&time_start, NULL);

    int bytes_received = recvfrom(sockfd, buffer, PACKET_SIZE, 0, (struct sockaddr *)&src_ip, &src_ip_len);
    gettimeofday(&time_end, NULL);

    unsigned long time_elapsed = (time_end.tv_sec - time_start.tv_sec) * 1000 + (time_end.tv_usec - time_start.tv_usec) / 1000;

    ip_header = (struct iphdr *)buffer;
    int ip_header_len = ip_header->ihl * 4;
    icmp_header = (struct icmphdr *)(buffer + ip_header_len);

    if(bytes_received == -1)
        error("Failed to receive ICMP response");

    if(icmp_header->type == ICMP_ECHOREPLY) {
        inet_ntop(AF_INET, &(src_ip.sin_addr), src_ip_str, INET_ADDRSTRLEN);
        printf("%d\t%s\t%.2fms\n", ttl, src_ip_str, (float)time_elapsed);
        return icmp_header->un.echo.sequence;
    }

    if(icmp_header->type == ICMP_TIME_EXCEEDED) {
        printf("%d\t*\t%.2fms\n", ttl, (float)time_elapsed);
        return -1;
    }

    return -1;
}

void print_trace_route(int sockfd) {
    char src_ip_str[INET_ADDRSTRLEN];
    int ttl;

    printf("HOP\tIP ADDRESS\tRTT\n");

    for(ttl = 1; ttl <= HOPS_LIMIT; ++ttl) {
        printf("%d\t", ttl);

        int i;
        for (i = 0; i < PROBE_NUM; ++i) {
            send_ICMP_request(sockfd, ttl);
            int seq_number = receive_ICMP_response(sockfd, src_ip_str, ttl);
            if(seq_number != -1) {
                return;
            }
        }

        printf("\n");

        usleep(1000);
    }
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s [destination IP address]\n", argv[0]);
        exit(1);
    }

    memset(&dest_ip, 0, sizeof(dest_ip));
    inet_pton(AF_INET, argv[1], &dest_ip.sin_addr);
    strcpy(dest_ip_str, argv[1]);

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if(sockfd == -1)
        error("Failed to create socket");

    struct timeval timeout;
    timeout.tv_sec = PING_TIMEOUT;
    timeout.tv_usec = 0;

    if(setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&timeout, sizeof(timeout)) == -1)
        error("Failed to set socket receive timeout");

    print_trace_route(sockfd);

    close(sockfd);

    return 0;
}