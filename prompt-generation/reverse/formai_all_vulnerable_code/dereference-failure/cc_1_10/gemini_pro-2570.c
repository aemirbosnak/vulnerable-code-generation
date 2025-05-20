//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX_HOPS 30
#define MAX_PACKET_SIZE 64
#define ICMP_ECHO_REQUEST 8
#define ICMP_ECHO_REPLY 0

struct icmp_packet {
    uint8_t type;
    uint8_t code;
    uint16_t checksum;
    uint16_t identifier;
    uint16_t sequence_number;
    uint32_t timestamp;
    char data[MAX_PACKET_SIZE - 8];
};

struct sockaddr_in sockaddr_in;
struct timeval start_time, end_time;

int create_socket() {
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

void construct_icmp_packet(struct icmp_packet *packet, uint16_t identifier, uint16_t sequence_number) {
    packet->type = ICMP_ECHO_REQUEST;
    packet->code = 0;
    packet->checksum = 0;
    packet->identifier = identifier;
    packet->sequence_number = sequence_number;
    packet->timestamp = (uint32_t)time(NULL);
    memset(packet->data, 0, MAX_PACKET_SIZE - 8);
}

uint16_t calculate_checksum(struct icmp_packet *packet, int length) {
    uint16_t checksum = 0;
    for (int i = 0; i < length; i += 2) {
        checksum += (packet->data[i] << 8) | packet->data[i + 1];
    }
    while (checksum >> 16) {
        checksum = (checksum & 0xffff) + (checksum >> 16);
    }
    return ~checksum;
}

void send_icmp_packet(int sockfd, struct sockaddr_in *addr, struct icmp_packet *packet, int length) {
    packet->checksum = calculate_checksum(packet, length);
    if (sendto(sockfd, packet, length, 0, (struct sockaddr *)addr, sizeof(*addr)) == -1) {
        perror("sendto");
        exit(EXIT_FAILURE);
    }
}

int receive_icmp_packet(int sockfd, struct sockaddr_in *addr, struct icmp_packet *packet) {
    socklen_t addr_len = sizeof(*addr);
    int length = recvfrom(sockfd, packet, sizeof(*packet), 0, (struct sockaddr *)addr, &addr_len);
    if (length == -1) {
        perror("recvfrom");
        exit(EXIT_FAILURE);
    }
    return length;
}

int ping(const char *host, int timeout) {
    int sockfd = create_socket();
    sockaddr_in.sin_family = AF_INET;
    sockaddr_in.sin_addr.s_addr = inet_addr(host);
    if (sockaddr_in.sin_addr.s_addr == INADDR_NONE) {
        perror("inet_addr");
        exit(EXIT_FAILURE);
    }
    uint16_t identifier = (uint16_t)getpid();
    uint16_t sequence_number = 0;
    struct icmp_packet packet;
    struct icmp_packet reply;
    for (int hop = 1; hop <= MAX_HOPS; hop++) {
        construct_icmp_packet(&packet, identifier, sequence_number++);
        gettimeofday(&start_time, NULL);
        send_icmp_packet(sockfd, &sockaddr_in, &packet, sizeof(packet));
        int length = receive_icmp_packet(sockfd, &sockaddr_in, &reply);
        gettimeofday(&end_time, NULL);
        if (length == -1) {
            continue;
        }
        if (reply.type == ICMP_ECHO_REPLY && reply.identifier == identifier && reply.sequence_number == --sequence_number) {
            double elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000.0 + (end_time.tv_usec - start_time.tv_usec) / 1000.0;
            printf("%d hops to %s, RTT = %.3f ms\n", hop, host, elapsed_time);
            return hop;
        }
    }
    printf("Could not ping %s\n", host);
    return -1;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int timeout = 1000;
    ping(argv[1], timeout);
    return EXIT_SUCCESS;
}