//FormAI DATASET v1.0 Category: Network Ping Test ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>

#define IP_HEADER_LENGTH 20
#define ICMP_HEADER_LENGTH 8
#define PACKET_SIZE 64
#define PING_WAIT_TIME 1

struct icmp_header {
    uint8_t type;
    uint8_t code;
    uint16_t checksum;
    uint16_t identifier;
    uint16_t sequence_number;
};

unsigned short calculate_checksum(unsigned short *paddress, int length) {
    unsigned short checksum = 0;
    while (length > 1) {
        checksum += *paddress++;
        length -= sizeof(unsigned short);
    }
    if (length) {
        checksum += *(unsigned char*)paddress;
    }
    checksum = (checksum >> 16) + (checksum & 0xFFFF);
    checksum += (checksum >> 16);
    return ~checksum;
}

void ping(int sockfd, struct sockaddr_in *ping_addr, char *ping_ip) {
    char packet[PACKET_SIZE];
    struct icmp_header *icmp_hdr = (struct icmp_header*) packet;
    icmp_hdr->type = ICMP_ECHO;
    icmp_hdr->code = 0;
    icmp_hdr->identifier = getpid() & 0xFFFF;
    icmp_hdr->sequence_number = 0;
    memset(packet + sizeof(struct icmp_header), rand() % 256, PACKET_SIZE - sizeof(struct icmp_header));
    icmp_hdr->checksum = calculate_checksum((unsigned short*) icmp_hdr, PACKET_SIZE);
    if (sendto(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr*) ping_addr, sizeof(struct sockaddr)) <= 0) {
        fprintf(stderr, "ping: sendto error: %s\n", strerror(errno));
        return;
    }
    char packet_received[PACKET_SIZE];
    struct sockaddr_in recv_addr;
    socklen_t addr_len = sizeof(recv_addr);
    if (recvfrom(sockfd, packet_received, PACKET_SIZE, 0, (struct sockaddr*) &recv_addr, &addr_len) <= 0) {
        printf("%s down\n", ping_ip);
        return;
    }
    struct icmp_header *icmp_hdr_received = (struct icmp_header*) packet_received;
    if (icmp_hdr_received->type == ICMP_ECHOREPLY) {
        printf("%s up\n", ping_ip);
        return;
    }
    printf("%s down\n", ping_ip);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s <ping_ip>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        fprintf(stderr, "ping: socket error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in ping_addr;
    memset(&ping_addr, 0, sizeof(ping_addr));
    ping_addr.sin_family = AF_INET;
    if (inet_pton(AF_INET, argv[1], &ping_addr.sin_addr) <= 0) {
        fprintf(stderr, "ping: inet_pton error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    srand(time(NULL));
    while (1) {
        ping(sockfd, &ping_addr, argv[1]);
        sleep(PING_WAIT_TIME);
    }
    close(sockfd);
    return 0;
}