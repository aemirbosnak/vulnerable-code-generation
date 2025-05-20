//FormAI DATASET v1.0 Category: Network Ping Test ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

#define PACKET_SIZE 64
#define MAX_HOPS 30
#define TIMEOUT 1

// Calculate checksum for ICMP packet
unsigned short in_cksum(unsigned short * p, int n) {
    unsigned short answer;
    int sum = 0;
    unsigned short odd_byte;
    while (n > 1) {
        sum += *p++;
        n -= 2;
    }
    if (n == 1) {
        odd_byte = 0;
        *((unsigned char *) &odd_byte) = *(unsigned char *) p;
        sum += odd_byte;
    }
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    answer = ~sum;
    return answer;
}

// Send ICMP packet to hostname/IP address
int send_icmp(int sockfd, struct sockaddr * dst_addr, int ttl, int seq) {
    char packet[PACKET_SIZE];
    struct icmp * icmp_hdr;
    icmp_hdr = (struct icmp *) packet;
    icmp_hdr->icmp_type = ICMP_ECHO;
    icmp_hdr->icmp_code = 0;
    icmp_hdr->icmp_id = getpid() & 0xFFFF;
    icmp_hdr->icmp_seq = seq;
    memset(&icmp_hdr->icmp_data, 0xa5, PACKET_SIZE - sizeof(struct icmp));
    icmp_hdr->icmp_cksum = 0;
    icmp_hdr->icmp_cksum = in_cksum((unsigned short *) icmp_hdr, PACKET_SIZE);
    // Set TTL value
    const int on = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(int)) < 0) {
        perror("setsockopt ttl");
        return -1;
    }
    // Send packet
    if (sendto(sockfd, packet, PACKET_SIZE, 0, dst_addr, sizeof(*dst_addr)) <= 0) {
        perror("sendto");
        return -1;
    }
    return 0;
}

// Wait for ICMP packet response
int recv_icmp(int sockfd, int ttl, struct timeval * send_time) {
    char packet[PACKET_SIZE];
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(sockfd, &fds);
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    int rc = select(sockfd + 1, &fds, NULL, NULL, &timeout);
    if (rc < 0) {
        perror("select");
        return -1;
    } else if (rc == 0) {
        return -2;
    }
    // Receive packet
    if (recvfrom(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr *) &addr, &addr_len) < 0) {
        perror("recvfrom");
        return -1;
    }
    // Check ICMP response type/code
    struct iphdr * ip_hdr;
    struct icmp * icmp_hdr;
    struct timeval recv_time, diff;
    gettimeofday(&recv_time, NULL);
    ip_hdr = (struct iphdr *) packet;
    icmp_hdr = (struct icmp *) (packet + (ip_hdr->ihl << 2));
    if (icmp_hdr->icmp_type == ICMP_ECHOREPLY && icmp_hdr->icmp_id == (getpid() & 0xFFFF)) {
        timersub(&recv_time, send_time, &diff);
        double rtt = diff.tv_sec * 1000 + diff.tv_usec / 1000.0;
        printf("%d  %.3fms  %s\n", ttl, rtt, inet_ntoa(addr.sin_addr));
        return 0;
    } else if (icmp_hdr->icmp_type == ICMP_TIME_EXCEEDED) {
        printf("%d  *  %s\n", ttl, inet_ntoa(addr.sin_addr));
        return -3;
    }
    return -1;
}

int main(int argc, char ** argv) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s <hostname/IP address>\n", argv[0]);
        return -1;
    }
    // Resolve hostname/IP address
    struct hostent * host;
    if ((host = gethostbyname(argv[1])) == NULL) {
        fprintf(stderr, "gethostbyname error\n");
        return -1;
    }
    // Create raw socket
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("socket");
        return -1;
    }
    // Set socket options to receive ICMP packets
    int on = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &on, sizeof(on)) < 0) {
        perror("setsockopt broadcast");
        return -1;
    }
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0) {
        perror("setsockopt reuseaddr");
        return -1;
    }
    // Set timeout for recvfrom
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("setsockopt rcvtimeo");
        return -1;
    }
    // Start ping test
    printf("Pinging %s...\n", argv[1]);
    int ttl = 0;
    while (++ttl <= MAX_HOPS) {
        if (send_icmp(sockfd, (struct sockaddr *) host->h_addr_list[0], ttl, ttl) < 0) {
            break;
        }
        int n = 0;
        while (++n <= 3) {
            struct timeval send_time;
            gettimeofday(&send_time, NULL);
            if (recv_icmp(sockfd, ttl, &send_time) == 0) {
                break;
            }
        }
        if (n > 3) {
            printf("%d  ***\n", ttl);
        }
    }
    return 0;
}