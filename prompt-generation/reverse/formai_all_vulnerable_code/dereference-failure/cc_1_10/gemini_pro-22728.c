//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define ICMP_ECHO_REQUEST 8
#define ICMP_ECHO_REPLY 0
#define ICMP_MIN_OVERHEAD 8

typedef struct {
    uint8_t type;
    uint8_t code;
    uint16_t checksum;
    uint16_t id;
    uint16_t seq;
    char data[32];
} icmp_packet;

void send_ping(int sockfd, struct sockaddr_in *addr, int seq) {
    icmp_packet packet;

    memset(&packet, 0, sizeof(packet));
    packet.type = ICMP_ECHO_REQUEST;
    packet.code = 0;
    packet.checksum = 0;
    packet.id = getpid();
    packet.seq = seq;
    memcpy(packet.data, "PING", 4);

    int len = sizeof(icmp_packet);
    packet.checksum = checksum((unsigned short *)&packet, len);

    sendto(sockfd, &packet, len, 0, (struct sockaddr *)addr, sizeof(*addr));
}

int receive_ping(int sockfd, struct sockaddr_in *addr) {
    socklen_t addr_len = sizeof(*addr);
    icmp_packet packet;

    int n = recvfrom(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)addr, &addr_len);
    if (n < 0) {
        return -1;
    }

    if (packet.type == ICMP_ECHO_REPLY && packet.id == getpid()) {
        return 0;
    }

    return 1;
}

int checksum(unsigned short *buf, int len) {
    unsigned long sum = 0;

    while (len > 1) {
        sum += *buf++;
        len -= 2;
    }

    if (len) {
        sum += *(unsigned char *)buf;
    }

    sum = (sum & 0xffff) + (sum >> 16);
    sum = (sum & 0xffff) + (sum >> 16);

    return ~sum;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s host\n", argv[0]);
        return 1;
    }

    struct hostent *he = gethostbyname(argv[1]);
    if (!he) {
        fprintf(stderr, "Could not resolve host %s\n", argv[1]);
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = *(in_addr_t *)he->h_addr_list[0];

    printf("PING %s (%s):\n", argv[1], inet_ntoa(addr.sin_addr));

    struct timeval start, end;
    int seq = 1;
    int sent = 0;
    int received = 0;
    int lost = 0;

    while (1) {
        gettimeofday(&start, NULL);
        send_ping(sockfd, &addr, seq);
        sent++;

        int n = receive_ping(sockfd, &addr);
        if (n == 0) {
            gettimeofday(&end, NULL);
            long elapsed = ((end.tv_sec - start.tv_sec) * 1000) + ((end.tv_usec - start.tv_usec) / 1000);
            printf("Reply from %s: seq=%d time=%ld ms\n", inet_ntoa(addr.sin_addr), seq, elapsed);
            received++;
        } else if (n == -1) {
            perror("recvfrom");
            break;
        } else {
            lost++;
            printf("Request timed out.\n");
        }

        seq++;
        sleep(1);
    }

    printf("\n--- %s ping statistics ---\n", argv[1]);
    printf("%d packets transmitted, %d packets received, %d%% packet loss\n", sent, received, (lost * 100) / sent);

    close(sockfd);

    return 0;
}