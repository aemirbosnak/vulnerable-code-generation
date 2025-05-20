//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <time.h>

#define PACKET_SIZE 64

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

void die(const char *s) {
    perror(s);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname or IP>\n", argv[0]);
        return 1;
    }

    const char *hostname = argv[1];
    struct sockaddr_in addr;
    int sockfd, n;
    struct icmp packet;
    struct sockaddr_in response_addr;
    socklen_t addr_len = sizeof(response_addr);
    char buf[PACKET_SIZE];

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        die("Socket creation failed");
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    if (inet_pton(AF_INET, hostname, &addr.sin_addr) <= 0) {
        die("Invalid address");
    }

    memset(&packet, 0, sizeof(packet));
    packet.icmp_type = ICMP_ECHO;
    packet.icmp_code = 0;
    packet.icmp_id = getpid();
    packet.icmp_seq = 1;
    packet.icmp_cksum = checksum(&packet, sizeof(packet));

    for (int i = 0; i < 4; i++) {
        clock_t start_time, end_time;
        double elapsed_time;

        start_time = clock();
        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr)) <= 0) {
            die("Failed to send packet");
        }

        n = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&response_addr, &addr_len);
        end_time = clock();

        if (n < 0) {
            fprintf(stderr, "Request timed out.\n");
        } else {
            struct icmp *icmp_response = (struct icmp *)(buf + (buf[0] & 0x0F) * 4);
            if (icmp_response->icmp_type == ICMP_ECHOREPLY && icmp_response->icmp_id == packet.icmp_id) {
                elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;
                printf("Reply from %s: bytes=%d time=%.2f ms\n", hostname, n, elapsed_time);
            } else {
                fprintf(stderr, "Received non-echo reply or invalid ID\n");
            }
        }
        usleep(1000000);  // Wait for 1 second before the next ping
    }

    close(sockfd);
    return 0;
}