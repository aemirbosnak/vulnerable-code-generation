//FormAI DATASET v1.0 Category: Network Ping Test ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <unistd.h>

#define PACKET_SIZE 64
#define PING_TIMEOUT 3

unsigned short checksum(void *b, int len);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <ip_address>\n", argv[0]);
        return 1;
    }

    struct sockaddr_in addr;
    struct hostent *host;

    if ((host = gethostbyname(argv[1])) == NULL) {
        printf("Failed to resolve hostname.\n");
        return 1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    addr.sin_addr.s_addr = *(unsigned long *) host->h_addr_list[0];

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        printf("Failed to create socket.\n");
        return 1;
    }

    char packet[PACKET_SIZE];
    memset(packet, 0, sizeof(packet));
    struct icmp *icmp_hdr = (struct icmp *) packet;

    icmp_hdr->icmp_type = ICMP_ECHO;
    icmp_hdr->icmp_code = 0;
    icmp_hdr->icmp_id = getpid();

    for (int i = 0; i < PACKET_SIZE - sizeof(struct icmp); i++) {
        packet[sizeof(struct icmp) + i] = i;
    }

    icmp_hdr->icmp_cksum = 0;
    icmp_hdr->icmp_cksum = checksum(packet, PACKET_SIZE);

    struct timeval tv;
    tv.tv_sec = PING_TIMEOUT;
    tv.tv_usec = 0;

    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof(tv));

    int sent = sendto(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr *) &addr, sizeof(addr));
    if (sent < 0) {
        printf("Failed to send packet.\n");
        return 1;
    }

    char recv_packet[PACKET_SIZE];
    memset(recv_packet, 0, sizeof(recv_packet));
    int recv_len = sizeof(addr);
    int recv = recvfrom(sockfd, recv_packet, PACKET_SIZE, 0, (struct sockaddr *) &addr, (socklen_t *) &recv_len);

    if (recv < 0) {
        printf("Ping timeout.\n");
    } else {
        struct iphdr *ip_hdr = (struct iphdr *) recv_packet;
        int iphdr_len = ip_hdr->ihl * 4;

        struct icmp *icmp = (struct icmp *) (recv_packet + iphdr_len);
        printf("Received %d bytes from %s: icmp_seq=%d ttl=%d time=%.2fms\n",
               recv, argv[1], icmp->icmp_seq, ip_hdr->ttl, (double) (tv.tv_sec * 1000 + tv.tv_usec / 1000));
    }

    close(sockfd);
    return 0;
}

unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2) {
        sum += *buf++;
    }

    if (len == 1) {
        sum += *(unsigned char *) buf;
    }

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}