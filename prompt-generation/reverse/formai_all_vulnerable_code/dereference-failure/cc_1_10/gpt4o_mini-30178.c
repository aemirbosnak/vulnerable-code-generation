//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <signal.h>
#include <time.h>

#define PACKET_SIZE 64
#define PING_COUNT 4
#define TIMEOUT 2

struct ping_packet {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

void handle_alarm(int signum) {
    return; 
}

unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;
    
    if (len == 1)
        sum += *(unsigned char*)buf;
    
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    
    return result;
}

void send_ping(int sockfd, struct sockaddr_in *dest_addr, int seq) {
    struct ping_packet packet;
    memset(&packet, 0, sizeof(packet));
    packet.hdr.type = ICMP_ECHO;
    packet.hdr.un.echo.id = getpid();
    packet.hdr.un.echo.sequence = seq;
    packet.hdr.checksum = checksum(&packet, sizeof(packet));
    
    if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)dest_addr, sizeof(*dest_addr)) <= 0) {
        perror("sendto failed");
    }
}

void receive_ping(int sockfd, int seq) {
    struct sockaddr_in r_addr;
    socklen_t len = sizeof(r_addr);
    char buffer[PACKET_SIZE];
    struct iphdr *ip_header;
    struct icmphdr *icmp_header;
    int n;

    n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&r_addr, &len);
    
    if (n <= 0) {
        perror("recvfrom failed");
        return;
    }
    
    ip_header = (struct iphdr *)buffer;
    icmp_header = (struct icmphdr *)(buffer + (ip_header->ihl * 4));
    
    if (icmp_header->type == ICMP_ECHOREPLY && 
        icmp_header->un.echo.id == getpid() && 
        icmp_header->un.echo.sequence == seq) {
        
        printf("Reply from %s: bytes=%d seq=%d time=%.2f ms\n", 
               inet_ntoa(r_addr.sin_addr), n, seq, (n - sizeof(struct iphdr)) / 10.0);
    }
}

void ping(const char *ip_addr) {
    int sockfd;
    struct sockaddr_in dest_addr;
    struct sigaction sa;
    int seq;

    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(0);
    
    if (inet_pton(AF_INET, ip_addr, &dest_addr.sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    sa.sa_handler = handle_alarm;
    sigaction(SIGALRM, &sa, NULL);

    for (seq = 1; seq <= PING_COUNT; seq++) {
        send_ping(sockfd, &dest_addr, seq);
        alarm(TIMEOUT);
        receive_ping(sockfd, seq);
        sleep(1);
    }
    
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Pinging %s with %d bytes of data:\n", argv[1], PACKET_SIZE);
    ping(argv[1]);

    return 0;
}