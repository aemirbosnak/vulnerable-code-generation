//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <time.h>

#define PACKET_SIZE 64
#define PING_COUNT 10

// Structure to hold the statistics
typedef struct {
    int sent;
    int received;
    double total_time;
} Stats;

Stats stats;

// Function to calculate the checksum for ICMP
unsigned short checksum(void *b, int len) {    
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (int i = 0; i < len / 2; i++)
        sum += buf[i];

    if (len % 2) sum += ((unsigned char *)buf)[len - 1];

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

// Function to send a ping
void send_ping(int sockfd, struct sockaddr_in *addr, int seq) {
    struct icmphdr icmp_hdr;
    char packet[PACKET_SIZE];
    struct timespec time_start, time_end;

    memset(packet, 0, sizeof(packet));
    icmp_hdr.type = ICMP_ECHO;
    icmp_hdr.code = 0;
    icmp_hdr.un.echo.id = getpid();
    icmp_hdr.un.echo.sequence = seq;
    icmp_hdr.checksum = checksum(&icmp_hdr, sizeof(icmp_hdr));

    clock_gettime(CLOCK_MONOTONIC, &time_start); // Start time
    sendto(sockfd, &icmp_hdr, sizeof(icmp_hdr), 0, (struct sockaddr *)addr, sizeof(*addr));
    stats.sent++;

    // Wait for the response
    char buffer[PACKET_SIZE];
    socklen_t addr_len = sizeof(*addr);
    recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)addr, &addr_len);
    clock_gettime(CLOCK_MONOTONIC, &time_end); // End time

    // Calculate round-trip time
    double rtt = (time_end.tv_sec - time_start.tv_sec) * 1000.0; // Convert seconds to ms
    rtt += (time_end.tv_nsec - time_start.tv_nsec) / 1000000.0; // Convert ns to ms
    printf("Reply from %s: seq=%d time=%.2f ms\n", inet_ntoa(addr->sin_addr), seq, rtt);
    stats.received++;
    stats.total_time += rtt;
}

// Function to handle SIGINT for graceful exit
void handle_signal(int signal) {
    printf("\n--- Ping statistics ---\n");
    printf("%d packets transmitted, %d received, %.2f%% packet loss\n",
           stats.sent, stats.received,
           ((double)(stats.sent - stats.received) / stats.sent) * 100);
    if (stats.received > 0) {
        printf("Average time=%.2f ms\n", stats.total_time / stats.received);
    }
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    signal(SIGINT, handle_signal);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&stats, 0, sizeof(stats));

    printf("Pinging %s with %d bytes of data:\n", argv[1], PACKET_SIZE);

    for (int i = 1; i <= PING_COUNT; i++) {
        send_ping(sockfd, &addr, i);
        sleep(1); // Wait for a second between pings
    }

    // Cleanup
    close(sockfd);
    return 0;
}