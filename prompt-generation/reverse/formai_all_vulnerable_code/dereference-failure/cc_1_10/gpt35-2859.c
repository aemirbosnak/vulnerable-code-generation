//FormAI DATASET v1.0 Category: Network Ping Test ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define PING_TIMEOUT 2 // Ping timeout in seconds.
#define PING_INTERVAL 1 // Ping interval in seconds.

struct ping_pkt {
    struct icmphdr hdr;
    char msg[64 - sizeof(struct icmphdr)];
};

unsigned short checksum(void *buf, int len) {
    unsigned short *word = buf;
    unsigned int sum = 0;

    while (len > 1) {
        sum += *word++;
        len -= 2;
    }

    if (len == 1) {
        sum += *(unsigned char*)word;
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);

    return (unsigned short)(~sum);
}

void ping(struct sockaddr_in addr) {
    int sock;
    int ttl = 64;
    char *ip = inet_ntoa(addr.sin_addr);

    if ((sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("socket");
        exit(1);
    }

    if (setsockopt(sock, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) < 0) {
        perror("setsockopt");
        exit(1);
    }

    while (1) {
        struct ping_pkt pckt;
        struct sockaddr_in r_addr;
        socklen_t len = sizeof(r_addr);
        int recv_size;
        struct timespec start, end;

        memset(&pckt, 0, sizeof(pckt));
        pckt.hdr.type = ICMP_ECHO;
        pckt.hdr.un.echo.id = htons(getpid() & 0xffff);
        gettimeofday(&start, NULL);
        sprintf(pckt.msg, "%d", rand() % 1000);
        pckt.hdr.checksum = checksum(&pckt, sizeof(pckt));

        if (sendto(sock, &pckt, sizeof(pckt), 0, (struct sockaddr*)&addr, sizeof addr) < 0) {
            perror("sendto");
            exit(1);
        }

        if ((recv_size = recvfrom(sock, &pckt, sizeof(pckt), 0, (struct sockaddr*)&r_addr, &len)) < 0) {
            perror("recvfrom");
            exit(1);
        }

        gettimeofday(&end, NULL);

        printf("Reply from %s: bytes=%d time=%ldms TTL=%d\n", ip, recv_size - sizeof(struct icmphdr), (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000, ttl);

        sleep(PING_INTERVAL);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    struct hostent *host = gethostbyname(argv[1]);

    if (!host) {
        perror("gethostbyname");
        exit(1);
    }

    for (int i = 0; host->h_addr_list[i]; i++) {
        struct in_addr in = *(struct in_addr*)host->h_addr_list[i];
        struct sockaddr_in addr = {
            .sin_family = AF_INET,
            .sin_addr = in
        };

        ping(addr);
    }

    return 0;
}