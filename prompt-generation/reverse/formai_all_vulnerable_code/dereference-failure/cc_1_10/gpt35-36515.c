//FormAI DATASET v1.0 Category: Network Ping Test ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>

#define ICMP_ECHO_REQUEST 8
#define ICMP_ECHO_REPLY 0
#define ICMP_CODE 0
#define BUFFER_SIZE 1024

typedef struct {
    uint8_t type;
    uint8_t code;
    uint16_t checksum;
    uint16_t identifier;
    uint16_t sequence_number;
} icmp_header;

typedef struct {
    struct timeval send_time;
    struct sockaddr_in address;
} ping_packet;

int get_socket(void) {
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

unsigned short checksum(void *data, unsigned int len) {
    unsigned int sum = 0;
    unsigned short *buf = (unsigned short *)data;
    while (len > 1) {
        sum += *buf++;
        len -= sizeof(unsigned short);
    }
    if (len) {
        sum += *(unsigned char*)buf;
    }
    while (sum >> 16) {
        sum = (sum & 0xFFFF) + (sum >> 16);
    }
    return (unsigned short)(~sum);
}

void send_ping(int sockfd, struct sockaddr_in address, unsigned short seq_num) {
    icmp_header header = {
        .type = ICMP_ECHO_REQUEST,
        .code = ICMP_CODE,
        .identifier = getpid(),
        .sequence_number = seq_num,
    };
    header.checksum = checksum(&header, sizeof(header));
    ping_packet packet = {
        .send_time = {0},
        .address = address,
    };
    if (sendto(sockfd, &header, sizeof(header), 0, (struct sockaddr*)&address, sizeof(address)) == -1) {
        perror("sendto");
        exit(EXIT_FAILURE);
    }
    gettimeofday(&packet.send_time, NULL);
    printf("Ping sent to %s with id %d and seq %d\n", inet_ntoa(address.sin_addr), header.identifier, header.sequence_number);
}

void receive_ping(int sockfd, ping_packet *packets, int packet_count) {
    char buffer[BUFFER_SIZE];
    struct sockaddr_in address;
    socklen_t addr_len = sizeof(struct sockaddr_in);
    while (true) {
        int bytes_received = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&address, &addr_len);
        if (bytes_received == -1) {
            perror("recvfrom");
            exit(EXIT_FAILURE);
        }
        icmp_header *header = (icmp_header *)buffer;
        if (header->type == ICMP_ECHO_REPLY && header->identifier == getpid()) {
            for (int i = 0; i < packet_count; i++) {
                if (memcmp(&address, &packets[i].address, sizeof(struct sockaddr_in)) == 0 && header->sequence_number == packets[i].send_time.tv_usec) {
                    struct timeval current_time;
                    gettimeofday(&current_time, NULL);
                    long diff = (current_time.tv_sec - packets[i].send_time.tv_sec) * 1000 + (current_time.tv_usec - packets[i].send_time.tv_usec) / 1000;
                    printf("%d bytes from %s: icmp_seq=%d ttl=%d time=%ld ms\n", bytes_received, inet_ntoa(address.sin_addr), header->sequence_number, ICMP_ECHO_REPLY, diff);
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s [hostname/IP address]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    struct addrinfo hints = {
        .ai_family = AF_INET,
        .ai_socktype = SOCK_RAW,
        .ai_protocol = IPPROTO_ICMP,
    };
    struct addrinfo *address_info;
    if (getaddrinfo(argv[1], NULL, &hints, &address_info) != 0) {
        perror("getaddrinfo");
        exit(EXIT_FAILURE);
    }
    ping_packet packets[4];
    for (int i = 0; i < 4; i++) {
        send_ping(get_socket(), *(struct sockaddr_in*)address_info->ai_addr, i);
        memcpy(&packets[i].address, address_info->ai_addr, sizeof(struct sockaddr_in));
        packets[i].send_time.tv_usec = i;
        usleep(1000); // wait for 1ms
    }
    freeaddrinfo(address_info);
    receive_ping(get_socket(), packets, 4);
    return 0;
}