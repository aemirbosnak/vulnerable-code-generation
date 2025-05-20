//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <sys/time.h>

#define PACKET_SIZE 64
#define PORT_NO 0
#define PING_TIMEOUT 2

u_int16_t packet_seq_num = 1;

void print_usage(char *prog_name) {
    fprintf(stderr, "USAGE: %s <IP address> <num_of_pings>\n", prog_name);
}

int calculate_checksum(u_int16_t *buf, int buf_len) {
    int sum = 0;
    u_int16_t *ptr = buf;

    for (int i = 0; i < buf_len / 2; i++) {
        sum += *ptr++;

        if (sum & 0x80000000) {
            sum = (sum & 0xFFFF) + (sum >> 16);
        }
    }

    while (sum >> 16) {
        sum = (sum & 0xFFFF) + (sum >> 16);
    }

    return ~sum;
}

struct timeval get_time_diff(struct timeval start_time, struct timeval end_time) {
    struct timeval diff;

    diff.tv_sec  = end_time.tv_sec - start_time.tv_sec;
    diff.tv_usec = end_time.tv_usec - start_time.tv_usec;

    if (diff.tv_usec < 0) {
        diff.tv_sec--;
        diff.tv_usec += 1000000;
    }

    return diff;
}

void ping_address(char *ip_addr) {
    struct sockaddr_in ping_addr;
    int sockfd, addr_len, ping_reply_len;
    struct timeval start_time, end_time, time_diff;
    u_int8_t ping_packet[PACKET_SIZE];
    struct iphdr *ip_hdr = (struct iphdr*) ping_packet;
    struct icmphdr *icmp_hdr = (struct icmphdr*) (ping_packet + sizeof(struct iphdr));
    pid_t pid = getpid();
    int num_of_pings = 10; /* default */

    memset(ping_packet, 0, PACKET_SIZE);

    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("ERROR: Failed to create socket");
        exit(EXIT_FAILURE);
    }

    ping_addr.sin_family = AF_INET;
    ping_addr.sin_port = htons(PORT_NO);
    ping_addr.sin_addr.s_addr = inet_addr(ip_addr);
    addr_len = sizeof(ping_addr);

    /* Set ICMP packet header */
    icmp_hdr->type = ICMP_ECHO;
    icmp_hdr->code = 0;
    icmp_hdr->un.echo.id = htons(pid);

    while (num_of_pings > 0) {
        gettimeofday(&start_time, NULL);

        icmp_hdr->un.echo.sequence = htons(packet_seq_num++);
        icmp_hdr->checksum = 0;
        icmp_hdr->checksum = calculate_checksum((u_int16_t*) icmp_hdr, sizeof(struct icmphdr));

        if (sendto(sockfd, ping_packet, PACKET_SIZE, 0, (struct sockaddr*) &ping_addr, addr_len) <= 0) {
            perror("ERROR: Failed to send ICMP packet");
        }

        ping_reply_len = 0;

        /* Wait for incoming ICMP packet */
        if ((ping_reply_len = recvfrom(sockfd, ping_packet, PACKET_SIZE, 0, (struct sockaddr*) &ping_addr, &addr_len)) < 0) {
            perror("ERROR: Failed waiting for ICMP packet");
        }

        gettimeofday(&end_time, NULL);

        time_diff = get_time_diff(start_time, end_time);

        struct iphdr *recv_ip_hdr = (struct iphdr*) ping_packet;
        u_int16_t recv_id = 0;

        if (recv_ip_hdr->protocol == IPPROTO_ICMP) {
            struct icmphdr *recv_icmp_hdr = (struct icmphdr*) (ping_packet + sizeof(struct iphdr));

            if (recv_icmp_hdr->type == ICMP_ECHOREPLY) {
                recv_id = ntohs(recv_icmp_hdr->un.echo.id);
            }
        }

        if (recv_id != pid) {
            fprintf(stderr, "ERROR: Wrong packet ID (%d) received!\n", recv_id);
            continue;
        }

        printf("%d bytes from %s: icmp_seq=%d ttl=%d time=%.3f ms\n", ping_reply_len, ip_addr, packet_seq_num - 1, recv_ip_hdr->ttl, time_diff.tv_sec * 1000.0 + time_diff.tv_usec / 1000.0);

        num_of_pings--;
        sleep(PING_TIMEOUT);
    }

    close(sockfd);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip_addr = argv[1];
    int num_of_pings = 10;

    if (argc == 3) {
        num_of_pings = atoi(argv[2]);

        if (num_of_pings <= 0) {
            fprintf(stderr, "ERROR: Invalid number of pings specified (%d)\n", num_of_pings);
            exit(EXIT_FAILURE);
        }
    }

    ping_address(ip_addr);

    return 0;
}