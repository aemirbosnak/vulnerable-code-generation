//FormAI DATASET v1.0 Category: Network Ping Test ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>

#define ICMP_PACKET_SIZE 64
#define MAX_HOPS 30
#define MAX_TIMEOUT 3
#define MAX_PACKETS 3

typedef unsigned char byte;

uint32_t ip_addr_lookup(const char *ip_addr_string) {
    struct in_addr addr;
    if (!inet_aton(ip_addr_string, &addr)) {
        fprintf(stderr, "Invalid IP address: %s\n", ip_addr_string);
        exit(1);
    }
    return addr.s_addr;
}

long long get_current_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}

uint16_t get_checksum(void *data, int size) {
    uint8_t *ptr = data;
    uint32_t sum = 0;
    for (int i = 0; i < size; i += 2) {
        sum += *(ptr + i) << 8;
        if (i + 1 < size) sum += *(ptr + i + 1);
    }
    while (sum >> 16)
        sum = (sum & 0xFFFF) + (sum >> 16);
    return (uint16_t)~sum;
}

void send_ping(int sockfd, struct sockaddr_in *dest_addr, int ttl, int seq) {
    byte packet[ICMP_PACKET_SIZE] = {0};
    struct icmp *icmp_hdr = (struct icmp *)packet;
    icmp_hdr->icmp_type = ICMP_ECHO;
    icmp_hdr->icmp_code = 0;
    icmp_hdr->icmp_seq = seq;
    icmp_hdr->icmp_id = getpid() & 0xFFFF;
    gettimeofday((struct timeval *)(icmp_hdr + 1), NULL);
    icmp_hdr->icmp_cksum = 0;
    icmp_hdr->icmp_cksum = get_checksum(icmp_hdr, ICMP_PACKET_SIZE);

    if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) == -1) {
        fprintf(stderr, "Can not set TTL option: %s\n", strerror(errno));
        exit(1);
    }
    ssize_t sent_bytes = sendto(sockfd, packet, ICMP_PACKET_SIZE, 0, (struct sockaddr *)dest_addr, sizeof(*dest_addr));
    if (sent_bytes == -1) {
        fprintf(stderr, "Can not send packet: %s\n", strerror(errno));
    }
}

byte *recv_ping(int sockfd, struct sockaddr_in *src_addr, int *ttl, long long *rtt) {
    static byte buffer[ICMP_PACKET_SIZE + sizeof(struct ip)];
    struct sockaddr_in send_addr;
    socklen_t send_addr_len = sizeof(send_addr);
    long long recv_time, send_time;
    while (1) {
        int size = recvfrom(sockfd, buffer, ICMP_PACKET_SIZE + sizeof(struct ip), 0, (struct sockaddr *)&send_addr, &send_addr_len);
        if (size <= 0) {
            fprintf(stderr, "Error receiving packet: %s\n", strerror(errno));
            continue;
        }
        struct ip *ip_hdr = (struct ip *)buffer;
        if (ip_hdr->ip_p != IPPROTO_ICMP || ip_hdr->ip_v != 4) {
            continue;
        }
        struct icmp *icmp_hdr = (struct icmp *)(buffer + sizeof(struct ip));
        if (icmp_hdr->icmp_type != ICMP_ECHOREPLY || icmp_hdr->icmp_id != (getpid() & 0xFFFF)) {
            continue;
        }
        *ttl = ip_hdr->ip_ttl;
        gettimeofday(&send_time, NULL);
        recv_time = get_current_time();
        *rtt = recv_time - ((struct timeval *)icmp_hdr->icmp_data)->tv_sec * 1000 - ((struct timeval *)icmp_hdr->icmp_data)->tv_usec / 1000;
        if (icmp_hdr->icmp_seq >= MAX_PACKETS) {
            send_ping(sockfd, src_addr, *ttl, icmp_hdr->icmp_seq);
        }
        return buffer;
    }
}

void print_usage() {
    fprintf(stderr, "Usage: ping-test [-h] IP_ADDRESS\n");
    exit(1);
}

int main(int argc, char **argv) {
    int ttl = 1;
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd == -1) {
        fprintf(stderr, "Can not open socket: %s\n", strerror(errno));
        exit(1);
    }
    char c;
    while ((c = getopt(argc, argv, "h")) != -1) {
        switch (c) {
            case 'h':
                print_usage();
                break;
            default:
                print_usage();
        }
    }
    argc -= optind;
    argv += optind;

    if (argc != 1) {
        print_usage();
    }

    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = ip_addr_lookup(argv[0]);

    printf("PING %s:\n", argv[0]);
    while (1) {
        for (int i = 0; i < MAX_PACKETS; ++i) {
            long long send_time = get_current_time();
            send_ping(sockfd, &dest_addr, ttl, i);
        }
        int packets_received = 0;
        long long rtt_sum = 0;
        for (int i = 0; i < MAX_PACKETS; ++i) {
            int packet_ttl;
            long long rtt;
            byte* packet = recv_ping(sockfd, &dest_addr, &packet_ttl, &rtt);
            if (packet) {
                ++packets_received;
                rtt_sum += rtt;
            }
        }
        if (packets_received) {
            printf("%d packets sent, %d packets received in %.1lfms\n", MAX_PACKETS, packets_received, (double)rtt_sum / packets_received);
        } else {
            printf("Request timed out.\n");
        }

        if (++ttl > MAX_HOPS)
            break;
        usleep(100000);
    }

    close(sockfd);
    return 0;
}