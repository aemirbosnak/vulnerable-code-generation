//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#include <errno.h>
#include <time.h>

#define PACKET_SIZE 64
#define PING_COUNT 4

// Function to calculate the checksum for ICMP packets
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

// Function to create an ICMP packet
struct icmp *create_icmp_packet(int seq) {
    struct icmp *icmp_packet = (struct icmp *)malloc(PACKET_SIZE);
    if (!icmp_packet) {
        fprintf(stderr, "Failed to allocate memory for ICMP packet\n");
        exit(EXIT_FAILURE);
    }

    icmp_packet->icmp_type = ICMP_ECHO;
    icmp_packet->icmp_code = 0;
    icmp_packet->icmp_id = getpid();
    icmp_packet->icmp_seq = seq;
    memset(icmp_packet->icmp_data, 0, PACKET_SIZE - 8);
    icmp_packet->icmp_cksum = checksum(icmp_packet, PACKET_SIZE);

    return icmp_packet;
}

// Function to send ICMP echo requests and receive replies
void ping(const char *ip_addr) {
    struct sockaddr_in addr;
    int sockfd;
    int n;
    struct icmp *icmp_packet;
    char recv_buffer[PACKET_SIZE];
    socklen_t addr_len = sizeof(addr);
    struct timeval start, end;
    
    // Create raw socket
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    addr.sin_addr.s_addr = inet_addr(ip_addr);

    for (int i = 0; i < PING_COUNT; i++) {
        icmp_packet = create_icmp_packet(i + 1);
        gettimeofday(&start, NULL);

        // Send ICMP request
        n = sendto(sockfd, icmp_packet, PACKET_SIZE, 0, (struct sockaddr*)&addr, sizeof(addr));
        if (n <= 0) {
            perror("Sendto error");
            free(icmp_packet);
            continue;
        }

        // Receive ICMP reply
        n = recvfrom(sockfd, recv_buffer, sizeof(recv_buffer), 0, (struct sockaddr*)&addr, &addr_len);
        gettimeofday(&end, NULL);

        if (n < 0) {
            perror("Recvfrom error");
        } else {
            struct iphdr *ip_header = (struct iphdr *)recv_buffer;
            struct icmp *icmp_response = (struct icmp *)(recv_buffer + (ip_header->ihl * 4));

            if (icmp_response->icmp_type == ICMP_ECHOREPLY && icmp_response->icmp_id == getpid()) {
                double time_taken = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
                printf("Reply from %s: seq=%d time=%.2f ms\n", ip_addr, icmp_response->icmp_seq, time_taken);
            } else {
                printf("Received non-echo reply\n");
            }
        }

        free(icmp_packet);
        sleep(1);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Pinging %s with %d packets:\n", argv[1], PING_COUNT);
    ping(argv[1]);

    return 0;
}