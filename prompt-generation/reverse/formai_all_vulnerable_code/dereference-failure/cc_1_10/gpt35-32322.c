//FormAI DATASET v1.0 Category: Network Ping Test ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>

#define BUFSIZE 1500
#define ICMP_ECHO 8
#define ICMP_ECHOREPLY 0

struct icmp_hdr {
    uint8_t type;
    uint8_t code;
    uint16_t chksum;
    uint16_t id;
    uint16_t seq;
    time_t timestamp;
};

uint16_t checksum(void *addr, int len);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Unknown host %s\n", hostname);
        exit(1);
    }

    printf("Pinging %s...\n", hostname);
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket() error");
        exit(1);
    }

    struct sockaddr_in destaddr;
    bzero(&destaddr, sizeof(destaddr));
    destaddr.sin_family = AF_INET;
    destaddr.sin_addr = *((struct in_addr *)host->h_addr);

    int seq = 0;
    while (seq < 5) {
        seq++;
        char buf[BUFSIZE];
        bzero(buf, BUFSIZE);
        struct icmp_hdr *hdr = (struct icmp_hdr *)buf;
        hdr->type = ICMP_ECHO;
        hdr->code = 0;
        hdr->id = getpid();
        hdr->seq = seq;
        hdr->timestamp = time(NULL);
        hdr->chksum = 0;
        hdr->chksum = checksum(hdr, sizeof(struct icmp_hdr));

        int bytes_sent = sendto(sockfd, buf, sizeof(struct icmp_hdr), 0,
                                (struct sockaddr *)&destaddr, sizeof(destaddr));
        if (bytes_sent < 0) {
            perror("sendto() error");
        }

        struct sockaddr_in fromaddr;
        socklen_t fromlen;
        uint8_t recvbuf[BUFSIZE];
        bzero(recvbuf, BUFSIZE);
        fromlen = sizeof(fromaddr);
        int bytes_recv = recvfrom(sockfd, recvbuf, BUFSIZE, 0,
                                  (struct sockaddr *)&fromaddr, &fromlen);
        if (bytes_recv < 0) {
            perror("recvfrom() error");
        }

        struct icmp_hdr *reply_hdr = (struct icmp_hdr *)recvbuf;
        if (reply_hdr->type == ICMP_ECHOREPLY) {
            printf("%d bytes from %s: icmp_seq=%d ttl=%d time=%ld ms\n",
                   bytes_recv, inet_ntoa(fromaddr.sin_addr), reply_hdr->seq,
                   reply_hdr->code, time(NULL) - reply_hdr->timestamp);
        } else {
            printf("Error: received ICMP type %d\n", reply_hdr->type);
        }
    }

    close(sockfd);
    return 0;
}

uint16_t checksum(void *addr, int len) {
    uint32_t sum = 0;
    uint16_t *ptr = (uint16_t *)addr;
    for (int i = 0; i < len / 2; i++) {
        sum += *ptr++;
    }
    if (len % 2) {
        sum += *((uint8_t *)addr + len - 1);
    }
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return (uint16_t)(~sum);
}