//FormAI DATASET v1.0 Category: Network Ping Test ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>

#define PING_PKT_SIZE 64
#define MAX_PING_COUNT 10

unsigned short calc_sum(unsigned short *ptr, size_t length) {
    unsigned long sum = 0;
    while (length > 1) {
        sum += *ptr++;
        length -= 2;
    }
    if (length == 1) sum += *(unsigned char*) ptr;
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    return (unsigned short) (~sum);
}

void ping(int sockfd, struct sockaddr *addr, int count) {
    struct icmp pkt;
    memset(&pkt, 0, sizeof(pkt));
    pkt.icmp_type = ICMP_ECHO;
    pkt.icmp_code = 0;
    pkt.icmp_id = getpid();
    for (int seq = 1; seq <= count; seq++) {
        pkt.icmp_seq = seq;
        pkt.icmp_cksum = 0;
        pkt.icmp_cksum = calc_sum((unsigned short*) &pkt, PING_PKT_SIZE);
        sendto(sockfd, &pkt, sizeof(pkt), 0, addr, sizeof(*addr));
        struct timeval tv;
        gettimeofday(&tv, NULL);
        printf("PING %s (%s) %d bytes data in ICMP sequence %d time=%.2fms\n",
            inet_ntoa(((struct sockaddr_in*) addr)->sin_addr),
            inet_ntoa(((struct sockaddr_in*) addr)->sin_addr),
            PING_PKT_SIZE, seq, (float) tv.tv_usec / 1000);
        struct sockaddr_in sender;
        socklen_t sender_len = sizeof(sender);
        unsigned char buffer[512];
        ssize_t recv_bytes = recvfrom(sockfd, buffer, sizeof(buffer), 0, 
            (struct sockaddr*) &sender, &sender_len);
        if (recv_bytes >= 0) {
            struct iphdr *ip_hdr = (struct iphdr*) buffer;
            struct icmp *icmp_hdr = (struct icmp*) (buffer + (ip_hdr->ihl * 4));
            if ((icmp_hdr->icmp_type == ICMP_ECHOREPLY) && (icmp_hdr->icmp_hun.ih_idseq.icd_id == getpid()) &&
                (icmp_hdr->icmp_hun.ih_idseq.icd_seq == seq)) {
                struct timeval tv_r;
                gettimeofday(&tv_r, NULL);
                printf("%d bytes from %s time=%.2fms\n", recv_bytes,
                    inet_ntoa(sender.sin_addr), (float) ((tv_r.tv_usec - tv.tv_usec) / 1000));
            }
        }
        usleep(1000000);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <hostname/IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    struct hostent *host = gethostbyname(argv[1]);
    if (!host) {
        printf("Unknown host '%s'\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in addr_in;
    memset(&addr_in, 0, sizeof(addr_in));
    memcpy(&addr_in.sin_addr, host->h_addr_list[0], host->h_length);
    addr_in.sin_family = AF_INET;
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    ping(sockfd, (struct sockaddr*) &addr_in, MAX_PING_COUNT);
    close(sockfd);
    return 0;
}