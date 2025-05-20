//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define PACKET_SIZE 64
#define TIMEOUT 1
#define NUM_PACKETS 10

// Function to calculate the checksum of ICMP packets
unsigned short checksum(void *b, int len) {
    unsigned short *p = b;
    unsigned int sum = 0;
    unsigned short answer = 0;

    for (int i = 0; i < len / 2; i++)
        sum += p[i];

    if (len & 1) {
        sum += ((unsigned char *)b)[len - 1];
    }

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    answer = ~sum;

    return answer;
}

// Function to send pings and monitor QoS
void monitor_quality(const char *ip_address) {
    int sockfd;
    struct sockaddr_in addr;
    struct icmp icmp_packet;
    struct timeval start, end;
    int sent = 0, received = 0;
    long total_time = 0;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_address);

    // Send packets and wait for responses
    for (int i = 0; i < NUM_PACKETS; i++) {
        memset(&icmp_packet, 0, sizeof(icmp_packet));
        icmp_packet.icmp_type = ICMP_ECHO;
        icmp_packet.icmp_seq = i;
        icmp_packet.icmp_id = getpid();
        icmp_packet.icmp_cksum = checksum(&icmp_packet, sizeof(icmp_packet));

        gettimeofday(&start, NULL);
        if (sendto(sockfd, &icmp_packet, sizeof(icmp_packet), 0,
                   (struct sockaddr *)&addr, sizeof(addr)) <= 0) {
            perror("Failed to send packet");
        } else {
            sent++;
            char buffer[PACKET_SIZE];
            socklen_t addr_len = sizeof(addr);
            fd_set readfds;
            struct timeval tv;

            // Setting timeout for receiving
            tv.tv_sec = TIMEOUT;
            tv.tv_usec = 0;
            FD_ZERO(&readfds);
            FD_SET(sockfd, &readfds);

            // Wait for a response
            if (select(sockfd + 1, &readfds, NULL, NULL, &tv) > 0) {
                recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&addr, &addr_len);
                gettimeofday(&end, NULL);
                long time_taken = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
                total_time += time_taken;
                received++;
                printf("Reply from %s: time=%ld ms\n", ip_address, time_taken);
            } else {
                printf("Request timed out.\n");
            }
        }
        sleep(1);
    }

    close(sockfd);

    if (sent > 0) {
        printf("\n--- %s ping statistics ---\n", ip_address);
        printf("%d packets transmitted, %d received, %.1f%% packet loss\n", sent, received,
               (1 - (float)received / sent) * 100);
        if (received > 0) {
            printf("Average round-trip time: %.2f ms\n", (float)total_time / received);
        }
    } else {
        printf("No packets sent.\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *ip_address = argv[1];
    monitor_quality(ip_address);

    return EXIT_SUCCESS;
}