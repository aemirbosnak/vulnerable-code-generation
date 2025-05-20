//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <netinet/ip.h>
#include <sys/time.h>
#include <errno.h>

#define PACKET_SIZE 64
#define PING_INTERVAL 1
#define PING_COUNT 4

// Function to calculate checksum
unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2) {
        sum += *buf++;
    }
    if (len == 1) {
        sum += *(unsigned char *)buf;
    }
    
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

// Function to create and send ICMP echo request
void send_ping(int sockfd, struct sockaddr_in *addr, int ping_seq) {
    char packet[PACKET_SIZE];
    struct icmphdr *icmp_hdr = (struct icmphdr *)packet;
    struct timeval start_time, end_time;

    memset(packet, 0, PACKET_SIZE);
    
    icmp_hdr->type = ICMP_ECHO;
    icmp_hdr->code = 0;
    icmp_hdr->checksum = checksum(packet, sizeof(struct icmphdr));
    icmp_hdr->un.echo.sequence = ping_seq;
    icmp_hdr->un.echo.id = getpid();

    gettimeofday(&start_time, NULL);
    if (sendto(sockfd, packet, sizeof(struct icmphdr), 0, (struct sockaddr *)addr, sizeof(*addr)) <= 0) {
        perror("sendto");
    }

    printf("Ping sent to %s with seq %d...\n", inet_ntoa(addr->sin_addr), ping_seq);
    
    // Receive the response
    char recv_buf[PACKET_SIZE];
    socklen_t addr_len = sizeof(*addr);
    ssize_t recv_len = recvfrom(sockfd, recv_buf, sizeof(recv_buf), 0, (struct sockaddr *)addr, &addr_len);

    if (recv_len < 0) {
        perror("recvfrom");
        return;
    }

    gettimeofday(&end_time, NULL);
    long time_taken = (end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_usec - start_time.tv_usec) / 1000;

    struct iphdr *ip_hdr = (struct iphdr *)recv_buf;
    icmp_hdr = (struct icmphdr *)(recv_buf + (ip_hdr->ihl << 2));

    if (icmp_hdr->type == ICMP_ECHOREPLY && icmp_hdr->un.echo.id == getpid()) {
        printf("Reply from %s: bytes=%d seq=%d time=%ld ms\n", inet_ntoa(addr->sin_addr), recv_len, ping_seq, time_taken);
    } else {
        printf("Unexpected ICMP packet received.\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *ip_address = argv[1];
    struct sockaddr_in addr;
    int sockfd;
    int ping_seq = 1;

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_address);
    
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    while (ping_seq <= PING_COUNT) {
        send_ping(sockfd, &addr, ping_seq);
        sleep(PING_INTERVAL);
        ping_seq++;
    }

    close(sockfd);
    return 0;
}