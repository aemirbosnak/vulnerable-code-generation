//FormAI DATASET v1.0 Category: Network Ping Test ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>

#define ECHO_REQUEST 8
#define ECHO_REPLY 0
#define PACKET_SIZE 4096
#define MAX_WAIT_TIME 5
#define MAX_NO_PACKETS 3

struct ping_pkt {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

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

int ping(struct sockaddr_in *addr) {
    int sockfd, i, addr_len, pkt_no = 0, msg_count = 0;
    struct ping_pkt pkt;
    struct sockaddr_in r_addr;
    struct timeval start_time, end_time, tv;
    double rtt, total_time = 0;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        printf("\nSocket could not be created : %s\n", strerror(errno));
        return 1;
    }
    
    memset(&r_addr, 0, sizeof(r_addr));
    addr_len = sizeof(*addr);

    printf("Pinging %s [%s] with %d bytes of data\n", 
            inet_ntoa(addr->sin_addr), 
            inet_ntoa(addr->sin_addr), 
            (int) sizeof(struct ping_pkt));
            
    while (msg_count < MAX_NO_PACKETS) {
        pkt_no++;
        gettimeofday(&start_time, NULL);
        bzero(&pkt, sizeof(pkt));

        pkt.hdr.type = ECHO_REQUEST;
        pkt.hdr.un.echo.id = getpid();
        for (i = 0; i < sizeof(pkt.msg) - 1; i++)
            pkt.msg[i] = i + '0';
        pkt.msg[i] = 0;
        pkt.hdr.un.echo.sequence = pkt_no;
        pkt.hdr.checksum = checksum(&pkt, sizeof(pkt));

        usleep(1000);
        if (sendto(sockfd, &pkt, sizeof(pkt), 0, (struct sockaddr*) addr, addr_len) <= 0) {
            printf("\nPacket sending failed: %s\n", strerror(errno));
            continue;
        }

        tv.tv_sec = MAX_WAIT_TIME;
        tv.tv_usec = 0;
        if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
            printf("\nError setting timeout: %s\n", strerror(errno));
            continue;
        }

        if (recvfrom(sockfd, &pkt, sizeof(pkt), 0, (struct sockaddr*) &r_addr, &addr_len) > 0) {
            gettimeofday(&end_time, NULL);

            if (pkt.hdr.type == ECHO_REPLY) {
                printf("%d bytes from %s: icmp_seq=%u ttl=%d time=%.2lf ms\n",
                        sizeof(pkt.msg), inet_ntoa(r_addr.sin_addr), pkt.hdr.un.echo.sequence,
                        (int) pkt.hdr.un.echo.id, (double) (end_time.tv_usec - start_time.tv_usec) / 1000 + 
                         (double) (end_time.tv_sec - start_time.tv_sec) * 1000);
            } else {
                printf("Got ICMP packet with type %d\n", pkt.hdr.type);
            }

            msg_count++;
            total_time += (double) (end_time.tv_usec - start_time.tv_usec) / 1000 + 
                          (double) (end_time.tv_sec - start_time.tv_sec) * 1000;
        } else {
            printf("Ping timed out\n");
        }
    }

    printf("Ping statistics for %s:\n Packets: Sent = %d, Received = %d, Lost = %d (%d%% loss),\n",
            inet_ntoa(addr->sin_addr), pkt_no, msg_count, pkt_no - msg_count, 100 - msg_count * 100 / pkt_no);
    if (msg_count > 0)
        printf("Approximate round trip times in milli-seconds:\n Minimum = %.2f ms, Maximum = %.2f ms, Average = %.2f ms\n",
                total_time / msg_count, total_time / msg_count, total_time / msg_count);

    close(sockfd);
    return 0;
}

int main(int argc, char *argv[]) {
    struct sockaddr_in addr;
    struct in_addr ip_addr;

    if (argc != 2) {
        printf("Usage: %s <ip_address>\n", argv[0]);
        return 1;
    }

    if (inet_aton(argv[1], &ip_addr) == 0) {
        printf("Invalid IP address: %s\n", argv[1]);
        return 1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = ip_addr.s_addr;

    ping(&addr);

    return 0;
}