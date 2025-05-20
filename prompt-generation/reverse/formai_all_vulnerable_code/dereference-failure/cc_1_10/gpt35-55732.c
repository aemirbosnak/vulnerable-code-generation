//FormAI DATASET v1.0 Category: Network Ping Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define PING_PKT_S 64

struct icmp_ping_hdr {
    uint8_t type;
    uint8_t code;
    uint16_t checksum;
    uint16_t identifier;
    uint16_t sequence_no;
    struct timeval timestamp;
};

uint16_t calc_checksum(void *data, int size) {
    uint16_t *p = (uint16_t*)data;
    uint32_t sum = 0;
    while (size > 1) {
        sum += *p;
        p++;
        size -= 2;
    }
    if (size) {
        sum += *(uint8_t*)p;
    }
    while (sum >> 16) {
        sum = (sum & 0xFFFF) + (sum >> 16);
    }
    return ~sum;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s IP_address\n", argv[0]);
        exit(1);
    }
    int sockfd, rc;
    struct sockaddr_in addr_ping, addr_recv;
    struct icmp_ping_hdr pkt_send, pkt_recv;
    memset(&pkt_send, 0, sizeof(pkt_send));
    pkt_send.type = 8;
    pkt_send.code = 0;
    pkt_send.identifier = getpid() & 0xFFFF;
    for (int i = 0; i < PING_PKT_S - sizeof(pkt_send); i++) {
        *(char*)(pkt_send.timestamp.tv_usec + i) = i & 0xFF;
    }
    pkt_send.checksum = calc_checksum(&pkt_send, PING_PKT_S);

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        printf("socket() failed\n");
        exit(1);
    }

    memset(&addr_ping, 0, sizeof(addr_ping));
    addr_ping.sin_family = AF_INET;
    addr_ping.sin_addr.s_addr = inet_addr(argv[1]);

    memset(&addr_recv, 0, sizeof(addr_recv));
    socklen_t len = sizeof(addr_recv);

    for (int i = 1; i <= 4; i++) {
        printf("Ping %s: icmp_seq=%d time=", argv[1], i);

        pkt_send.sequence_no = i;
        pkt_send.timestamp.tv_sec = time(NULL);
        pkt_send.timestamp.tv_usec = 0;
        pkt_send.checksum = calc_checksum(&pkt_send, PING_PKT_S);
        rc = sendto(sockfd, &pkt_send, PING_PKT_S, 0, (struct sockaddr*)&addr_ping, sizeof(addr_ping));
        if (rc < 0 || rc != PING_PKT_S) {
            printf("sendto() failed\n");
            close(sockfd);
            exit(1);
        }

        rc = recvfrom(sockfd, &pkt_recv, sizeof(pkt_recv), 0, (struct sockaddr*)&addr_recv, &len);
        if (rc < 0) {
            printf("recvfrom() failed\n");
            close(sockfd);
            exit(1);
        }

        if (pkt_recv.type == 0 && pkt_recv.identifier == pkt_send.identifier && pkt_recv.sequence_no == pkt_send.sequence_no) {
            uint16_t time_taken = (pkt_recv.timestamp.tv_sec - pkt_send.timestamp.tv_sec) * 1000 + (pkt_recv.timestamp.tv_usec - pkt_send.timestamp.tv_usec) / 1000;
            printf("%dms\n", time_taken);
        } else {
            printf("failed\n");
        }
        memset(&pkt_recv, 0, sizeof(pkt_recv));
        usleep(1000);
    }

    close(sockfd);
    return 0;
}