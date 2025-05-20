//FormAI DATASET v1.0 Category: Network Ping Test ; Style: Ada Lovelace
// Ada Lovelace style C Network Ping Test example program

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/time.h>

#define PACKET_SIZE 64
#define DEFAULT_TIMEOUT 2
#define DEFAULT_MAX_HOPS 30
#define MAX_PACKETS 3

char *dst_addr_str; // Destination Address String

struct sockaddr_in dest_addr; // Destination Address
struct timeval send_time, recv_time; // Send and Receive Timestamps
char send_buf[PACKET_SIZE], recv_buf[PACKET_SIZE]; // Send and Receive Buffers

int sockfd; // Socket File Descriptor
int packets_received; // Packets Received Counter

bool has_reached_max_hops(void);
void send_packet(int ttl);
void receive_packet(void);
double time_diff(struct timeval start, struct timeval end);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <destination_ip_address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Set Destination Address String
    dst_addr_str = argv[1];

    // Create Socket
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set Timeout
    struct timeval timeout = { DEFAULT_TIMEOUT, 0 };
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&timeout, sizeof(timeout)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Set Maximum Hops
    int max_hops = DEFAULT_MAX_HOPS;
    if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, &max_hops, sizeof(max_hops)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Resolve Destination Address
    struct hostent *he;
    if ((he = gethostbyname(dst_addr_str)) == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(0);
    dest_addr.sin_addr = *((struct in_addr *)he->h_addr_list[0]);

    // Send and Receive Packets
    int ttl = 1;
    while (!has_reached_max_hops()) {
        printf("%d ", ttl); // Print TTL
        fflush(stdout);

        for (int i = 0; i < MAX_PACKETS; i++) {
            send_packet(ttl);
            receive_packet();
            usleep(1000);
        }

        double avg_rtt = ((double)time_diff(send_time, recv_time) / 1000) / MAX_PACKETS;
        printf("%.3f ms\n", avg_rtt); // Print Average Round-Trip Time

        if (packets_received > 0 && dest_addr.sin_addr.s_addr == *((in_addr_t *)recv_buf + 12)) {
            printf("Pinging %s, Maximum TTL = %d\n", dst_addr_str, max_hops);
            exit(EXIT_SUCCESS);
        }

        ttl++;
        packets_received = 0;
    }

    printf("Destination Unreachable\n");
    exit(EXIT_SUCCESS);
}

bool has_reached_max_hops(void) {
    if (packets_received > 0 || dest_addr.sin_addr.s_addr == INADDR_NONE) {
        return true;
    }

    return false;
}

void send_packet(int ttl) {
    memset(send_buf, 0, sizeof(send_buf));

    struct icmphdr *icmp = (struct icmphdr *)send_buf;
    icmp->type = ICMP_ECHO;
    icmp->code = 0;
    icmp->checksum = 0;
    icmp->un.echo.id = getpid();
    icmp->un.echo.sequence = ttl;

    struct timeval *tv = (struct timeval *)(icmp + 1);
    gettimeofday(tv, NULL);

    icmp->checksum = htons(~(ICMP_ECHO << 8));

    if (sendto(sockfd, send_buf, PACKET_SIZE, 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0) {
        perror("sendto");
    }

    gettimeofday(&send_time, NULL);
}

void receive_packet(void) {
    memset(recv_buf, 0, sizeof(recv_buf));

    struct sockaddr_in recv_addr;
    socklen_t recv_addr_len = sizeof(recv_addr);
    if (recvfrom(sockfd, recv_buf, PACKET_SIZE, 0, (struct sockaddr *)&recv_addr, &recv_addr_len) < 0) {
        if (errno == EAGAIN) {
            return;
        }

        perror("recvfrom");
    }

    gettimeofday(&recv_time, NULL);

    packets_received++;

    struct iphdr *ip = (struct iphdr *)recv_buf;
    int ip_header_len = ip->ihl * 4;
    struct icmphdr *icmp = (struct icmphdr *)(recv_buf + ip_header_len);
    if (icmp->type == ICMP_ECHOREPLY || icmp->type == ICMP_DEST_UNREACH) {
        if (icmp->type == ICMP_DEST_UNREACH) {
            if (icmp->code == ICMP_NET_UNREACH) {
                printf("Destination Network Unreachable\n");
                exit(EXIT_FAILURE);
            } else if (icmp->code == ICMP_HOST_UNREACH) {
                printf("Destination Host Unreachable\n");
                exit(EXIT_FAILURE);
            } else if (icmp->code == ICMP_PORT_UNREACH) {
                printf("Destination Port Unreachable\n");
                exit(EXIT_FAILURE);
            } else {
                printf("Destination Unreachable\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

double time_diff(struct timeval start, struct timeval end) {
    double sec_diff = (double)(end.tv_sec - start.tv_sec) * 1000;
    double usec_diff = (double)(end.tv_usec - start.tv_usec) / 1000;

    return sec_diff + usec_diff;
}