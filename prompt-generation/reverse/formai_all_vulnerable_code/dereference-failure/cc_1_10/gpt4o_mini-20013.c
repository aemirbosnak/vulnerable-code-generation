//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

#define PACKET_SIZE 64
#define TIMEOUT 1
#define MAX_WAIT_TIME 1
#define MAX_PINGS 4

struct ping_packet {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

volatile sig_atomic_t stop_ping = 0;

void int_handler(int dummy) {
    stop_ping = 1;
}

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

void ping(const char *ip_addr) {
    int sockfd;
    struct sockaddr_in addr_ping;
    struct ping_packet packet;
    struct sockaddr_in addr_reply;
    socklen_t addr_len = sizeof(addr_reply);
    char buf[PACKET_SIZE];
    struct timeval start, end;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&addr_ping, 0, sizeof(addr_ping));
    addr_ping.sin_family = AF_INET;
    addr_ping.sin_addr.s_addr = inet_addr(ip_addr);

    packet.hdr.type = ICMP_ECHO;
    packet.hdr.un.echo.id = getpid();
    memset(packet.msg, 'E', sizeof(packet.msg));
    packet.hdr.un.echo.sequence = 1;
    packet.hdr.checksum = checksum(&packet, sizeof(packet));

    int pings_sent = 0;

    while (pings_sent < MAX_PINGS && !stop_ping) {
        gettimeofday(&start, NULL);
        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr_ping, sizeof(addr_ping)) <= 0) {
            perror("Failed to send packet");
            continue;
        }

        int response = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&addr_reply, &addr_len);
        if (response < 0) {
            perror("Receive failed");
        } else {
            gettimeofday(&end, NULL);
            double time_taken = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
            struct iphdr *ip_header = (struct iphdr *)buf;
            struct icmphdr *icmp_header = (struct icmphdr *)(buf + (ip_header->ihl * 4));

            if (icmp_header->type == ICMP_ECHOREPLY && icmp_header->un.echo.id == getpid()) {
                printf("Ping to %s: %d bytes from %s: icmp_seq=%d time=%.2f ms\n",
                    ip_addr, response, ip_addr, icmp_header->un.echo.sequence, time_taken);
            } else {
                printf("Ping to %s: Received unexpected ICMP reply\n", ip_addr);
            }
        }

        sleep(1);
        pings_sent++;
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    signal(SIGINT, int_handler);

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Pinging %s with %d bytes of data:\n", argv[1], PACKET_SIZE);
    ping(argv[1]);
    
    return 0;
}