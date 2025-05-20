//FormAI DATASET v1.0 Category: Network Ping Test ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <time.h>

#define PING_DATA_SIZE 64
#define PING_TIMEOUT_SEC 1

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

int ping(char *ip_addr, int seq) {
    struct hostent *he;
    struct sockaddr_in addr;
    int sock;
    struct icmp icmp_pkt;
    char packet[PING_DATA_SIZE + sizeof(struct icmp)];
    int ping_len;
    int ret;
    struct timeval t1, t2;
    clock_t start, end;

    he = gethostbyname(ip_addr);
    if (he == NULL) {
        return -1;
    }
    addr.sin_family = AF_INET;
    memcpy(&addr.sin_addr, he->h_addr_list[0], he->h_length);
    sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock < 0) {
        return -1;
    }
    memset(&icmp_pkt, 0, sizeof(icmp_pkt));
    icmp_pkt.icmp_type = ICMP_ECHO;
    icmp_pkt.icmp_code = 0;
    icmp_pkt.icmp_id = getpid() & 0xFFFF;
    icmp_pkt.icmp_seq = seq & 0xFFFF;
    memset(packet, 0, sizeof(packet));
    memcpy(packet, &icmp_pkt, sizeof(icmp_pkt));
    ping_len = PING_DATA_SIZE + sizeof(icmp_pkt);
    icmp_pkt.icmp_cksum = checksum(packet, ping_len);
    memcpy(packet, &icmp_pkt, sizeof(icmp_pkt));
    start = clock();
    gettimeofday(&t1, NULL);
    ret = sendto(sock, packet, ping_len, 0, (struct sockaddr *)&addr, sizeof(addr));
    if (ret < 0) {
        return -1;
    }
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(sock, &readfds);
    struct timeval timeout;
    timeout.tv_sec = PING_TIMEOUT_SEC;
    timeout.tv_usec = 0;
    ret = select(sock + 1, &readfds, NULL, NULL, &timeout);
    if (ret <= 0) {
        return -1;
    }
    int resplen;
    char resp[1024];
    memset(resp, 0, sizeof(resp));
    resplen = recv(sock, resp, sizeof(resp), 0);
    if (resplen < 0) {
        return -1;
    }
    end = clock();
    gettimeofday(&t2, NULL);
    double time_taken = ((double)(t2.tv_usec - t1.tv_usec) / 1000000 + (double)(t2.tv_sec - t1.tv_sec));
    printf("%d bytes from %s: icmp_seq=%d ttl=%d time=%f ms\n", resplen - sizeof(struct iphdr) - sizeof(struct icmphdr), ip_addr, seq, ((struct iphdr *)&resp)->ttl, time_taken * 1000);
    close(sock);
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <ip address> [num of pings]\n", argv[0]);
        return 1;
    }
    int count = 10;
    if (argc > 2) {
        count = atoi(argv[2]);
    }
    for (int i = 0; i < count; i++) {
        int ret = ping(argv[1], i);
        if (ret == -1) {
            printf("%s: no response\n", argv[1]);
            continue;
        }
        usleep(1000000);
    }
}