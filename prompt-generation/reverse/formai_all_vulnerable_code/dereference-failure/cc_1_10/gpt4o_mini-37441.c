//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <signal.h>
#include <netinet/ip_icmp.h>
#include <sys/time.h>

#define PACKET_SIZE 64
#define PING_COUNT 4

static volatile int running = 1;

void handle_sigint(int sig) {
    running = 0;
}

struct ping_packet {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;
    if (len == 1)
        sum += *(unsigned char *)buf;
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

void ping(const char *ip_address) {
    int sockfd;
    struct sockaddr_in addr;
    struct ping_packet packet;
    struct timeval start_time, end_time;
    double rtt;
    struct icmphdr *icmp_header;
    int sent = 0, received = 0;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_address);

    memset(&packet, 0, sizeof(packet));
    packet.hdr.type = ICMP_ECHO;
    packet.hdr.un.echo.id = getpid();
    strcpy(packet.msg, "Ping packet");

    printf("Pinging %s with %d bytes of data:\n", ip_address, PACKET_SIZE);

    // Unified Signal Handling
    signal(SIGINT, handle_sigint);

    while (sent < PING_COUNT && running) {
        packet.hdr.un.echo.sequence = sent + 1;
        packet.hdr.checksum = checksum(&packet, sizeof(packet));

        gettimeofday(&start_time, NULL);
        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr)) <= 0) {
            perror("Send failed");
            break;
        }

        char buffer[PACKET_SIZE];
        struct sockaddr_in r_addr;
        socklen_t addr_len = sizeof(r_addr);
        if (recvfrom(sockfd, &buffer, sizeof(buffer), 0, (struct sockaddr *)&r_addr, &addr_len) > 0) {
            gettimeofday(&end_time, NULL);
            packet.hdr.type = ICMP_ECHO; // Reset header type for receiving
            icmp_header = (struct icmphdr *)buffer + (sizeof(struct iphdr));
            if (icmp_header->type == ICMP_ECHOREPLY) {
                end_time.tv_sec -= start_time.tv_sec;
                end_time.tv_usec -= start_time.tv_usec;
                rtt = end_time.tv_sec * 1000.0 + end_time.tv_usec / 1000.0; // Convert to ms
                printf("Reply from %s: bytes=%d time=%.2f ms\n", ip_address, PACKET_SIZE, rtt);
                received++;
            } else {
                printf("Received non-echo reply from %s\n", ip_address);
            }
        } else {
            printf("Request timed out.\n");
        }
        sent++;
        sleep(1);
    }

    // Summary Statistics
    printf("\n--- %s ping statistics ---\n", ip_address);
    printf("%d packets transmitted, %d received, lost %d (%.1f%% loss)\n",
           sent, received, sent - received, ((sent - received) / (float)sent) * 100);

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    ping(argv[1]);
    return EXIT_SUCCESS;
}