//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <errno.h>
#include <time.h>

#define PACKET_SIZE 64
#define PINGS_COUNT 4

// This structure holds the ping statistics
typedef struct {
    int success_count;
    int fail_count;
    double min_time;
    double max_time;
    double total_time;
} PingStats;

// Function to calculate the checksum for ICMP packet
unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;
    if (len == 1)
        sum += *(unsigned char*)buf;
    
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;

    return result;
}

// Function to ping the target
int ping(const char *ip_addr, PingStats *stats) {
    int sockfd;
    struct sockaddr_in addr_ping;
    struct icmp packet;
    struct timeval start_time, end_time;
    socklen_t addrlen = sizeof(addr_ping);
    char recv_buf[PACKET_SIZE];
    int sent_bytes, received_bytes;
    double elapsed_time;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return -1;
    }

    memset(&addr_ping, 0, sizeof(addr_ping));
    addr_ping.sin_family = AF_INET;
    addr_ping.sin_port = 0;
    addr_ping.sin_addr.s_addr = inet_addr(ip_addr);

    memset(&packet, 0, sizeof(packet));
    packet.icmp_type = ICMP_ECHO;
    packet.icmp_id = getpid();
    packet.icmp_seq = 1;
    packet.icmp_cksum = checksum(&packet, sizeof(packet));

    gettimeofday(&start_time, NULL);
    sent_bytes = sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)&addr_ping, sizeof(addr_ping));

    if (sent_bytes <= 0) {
        perror("Ping send failed");
        close(sockfd);
        return -1;
    }

    received_bytes = recvfrom(sockfd, recv_buf, sizeof(recv_buf), 0, (struct sockaddr*)&addr_ping, &addrlen);
    gettimeofday(&end_time, NULL);

    close(sockfd);

    if (received_bytes <= 0) {
        printf("Ping to %s failed\n", ip_addr);
        stats->fail_count++;
        return -1;
    }

    elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000.0 + (end_time.tv_usec - start_time.tv_usec) / 1000.0;
    printf("Ping to %s: %f ms\n", ip_addr, elapsed_time);

    stats->success_count++;
    stats->total_time += elapsed_time;

    // Update min and max
    if (stats->min_time == 0 || elapsed_time < stats->min_time) {
        stats->min_time = elapsed_time;
    }
    if (elapsed_time > stats->max_time) {
        stats->max_time = elapsed_time;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP_ADDRESS>\n", argv[0]);
        return 1;
    }

    PingStats stats = { 0, 0, 0, 0, 0 };
    const char *ip_addr = argv[1];

    printf("Pinging %s with %d packets:\n", ip_addr, PINGS_COUNT);
    for (int i = 0; i < PINGS_COUNT; i++) {
        ping(ip_addr, &stats);
        sleep(1); // Delay between pings
    }

    printf("\n--- Ping statistics for %s ---\n", ip_addr);
    printf("%d packets transmitted, %d received, %d%% packet loss\n",
           stats.success_count + stats.fail_count, stats.success_count, (stats.fail_count * 100) / (stats.success_count + stats.fail_count));
    
    if (stats.success_count > 0) {
        printf("Minimum time: %f ms\n", stats.min_time);
        printf("Maximum time: %f ms\n", stats.max_time);
        printf("Average time: %f ms\n", stats.total_time / stats.success_count);
    }
    
    return 0;
}