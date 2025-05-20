//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/ip_icmp.h>
#include <time.h>
#include <fcntl.h>
#include <signal.h>

#define PING_PKT_S 64
#define PING_SLEEP_RATE 1000000
#define PING_TIMEOUT 1

struct ping_pkt {
    struct icmphdr hdr;
    char msg[PING_PKT_S - sizeof(struct icmphdr)];
};

int sockfd;
int ping_count = 0;
char *target_ip;
struct sockaddr_in addr_ping;

unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;
    
    if (len == 1)
        sum += *(unsigned char *)buf;

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

void send_ping() {
    struct ping_pkt pckt;
    struct timeval tv_out;
    tv_out.tv_sec = PING_TIMEOUT;
    tv_out.tv_usec = 0;

    // Set socket timeout
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv_out, sizeof tv_out);

    // Prepare the packet
    memset(&pckt, 0, sizeof(pckt));
    pckt.hdr.type = ICMP_ECHO;
    pckt.hdr.un.echo.id = getpid();
    pckt.hdr.un.echo.sequence = ping_count++;
    pckt.hdr.checksum = checksum(&pckt, sizeof(pckt));

    // Send the packet
    sendto(sockfd, &pckt, sizeof(pckt), 0, (struct sockaddr*)&addr_ping, sizeof(addr_ping));
}

void receive_ping() {
    struct sockaddr_in r_addr;
    int addr_len = sizeof(r_addr);
    char buf[1024];

    // Receive the packet
    int bytes_received = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)&r_addr, &addr_len);
    
    if (bytes_received <= 0) {
        printf("Request timed out.\n");
        return;
    }

    struct iphdr *ip_hdr = (struct iphdr *) buf;
    struct icmphdr *icmp_hdr = (struct icmphdr *) (buf + (ip_hdr->ihl * 4));

    if (icmp_hdr->type == ICMP_ECHOREPLY && icmp_hdr->un.echo.id == getpid()) {
        printf("Reply from %s: bytes=%d time=%ld ms\n", target_ip, bytes_received, (int)(clock() / (CLOCKS_PER_SEC / 1000)));
    }
}

void ping(const char *ip) {
    target_ip = strdup(ip);  // Allocate memory for the target IP.
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    memset(&addr_ping, 0, sizeof(addr_ping));
    addr_ping.sin_family = AF_INET;
    addr_ping.sin_addr.s_addr = inet_addr(target_ip);

    while (1) {
        send_ping();
        receive_ping();
        usleep(PING_SLEEP_RATE);
    }
}

void sigint_handler(int signum) {
    printf("\nExiting ping program after sending %d packets.\n", ping_count);
    close(sockfd);
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        return 1;
    }

    signal(SIGINT, sigint_handler);  // Handle Ctrl+C gracefully
    ping(argv[1]);
    return 0;
}