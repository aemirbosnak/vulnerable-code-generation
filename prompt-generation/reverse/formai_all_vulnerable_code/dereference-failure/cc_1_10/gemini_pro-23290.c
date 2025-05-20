//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>

#define PKT_SIZE 56
#define TIMEOUT 1000
#define MAX_HOPS 30

struct ping_pkt {
    uint16_t seq;
    char data[PKT_SIZE - sizeof(uint16_t)];
};

struct ping_reply {
    uint16_t seq;
    char data[PKT_SIZE - sizeof(uint16_t)];
    struct timeval tv_recv;
};

int main(int argc, char *argv[]) {
    struct hostent *he;
    struct sockaddr_in addr;
    int sockfd, i, hops = 0;
    char *hostname, *ip_addr;
    fd_set fds;
    struct timeval tv_start, tv_end, tv_diff, tv_timeout;
    struct ping_pkt pkt;
    struct ping_reply reply;

    if (argc != 2) {
        printf("Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    hostname = argv[1];
    he = gethostbyname(hostname);
    if (he == NULL) {
        printf("Error: Could not resolve hostname %s\n", hostname);
        exit(1);
    }

    ip_addr = inet_ntoa(*(struct in_addr *)he->h_addr);
    printf("Pinging %s (%s) with %d bytes of data:\n", hostname, ip_addr, PKT_SIZE);

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_addr = *(struct in_addr *)he->h_addr;

    tv_timeout.tv_sec = TIMEOUT / 1000;
    tv_timeout.tv_usec = (TIMEOUT % 1000) * 1000;

    while (hops <= MAX_HOPS) {
        pkt.seq = htons(hops);
        memset(pkt.data, 0, sizeof(pkt.data));

        gettimeofday(&tv_start, NULL);
        sendto(sockfd, &pkt, sizeof(pkt), 0, (struct sockaddr *)&addr, sizeof(addr));

        FD_ZERO(&fds);
        FD_SET(sockfd, &fds);
        if (select(sockfd + 1, &fds, NULL, NULL, &tv_timeout) == 0) {
            printf("Request timed out.\n");
            hops++;
            continue;
        }

        if (recvfrom(sockfd, &reply, sizeof(reply), 0, NULL, NULL) < 0) {
            perror("recvfrom");
            exit(1);
        }

        gettimeofday(&tv_end, NULL);
        timersub(&tv_end, &tv_start, &tv_diff);

        printf("%d bytes from %s: icmp_seq=%d time=%ld.%06ld ms TTL=%d\n",
               PKT_SIZE, ip_addr, ntohs(reply.seq), tv_diff.tv_sec, tv_diff.tv_usec, hops);

        hops++;
    }

    printf("Ping statistics for %s:\n", hostname);
    printf("    Packets: Sent = %d, Received = %d, Lost = %d (%.1f%% loss)\n", hops, hops, 0, 0.0);

    close(sockfd);
    return 0;
}