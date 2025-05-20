//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

#define MAX_PACKET_SIZE 65535

typedef struct {
    struct iphdr ip_header;
    struct udphdr udp_header;
    char payload[MAX_PACKET_SIZE];
} udp_packet_t;

typedef struct {
    struct iphdr ip_header;
    struct tcphdr tcp_header;
    char payload[MAX_PACKET_SIZE];
} tcp_packet_t;

void display_udp_packet(udp_packet_t* packet) {
    struct sockaddr_in src_addr, dest_addr;
    printf("Received UDP packet:\n");
    printf("Source IP: %s\n", inet_ntoa(*(struct in_addr*)&packet->ip_header.saddr));
    printf("Destination IP: %s\n", inet_ntoa(*(struct in_addr*)&packet->ip_header.daddr));
    printf("Source Port: %d\n", ntohs(packet->udp_header.source));
    printf("Destination Port: %d\n", ntohs(packet->udp_header.dest));
    printf("Payload: %s\n", packet->payload);
}

void display_tcp_packet(tcp_packet_t* packet) {
    struct sockaddr_in src_addr, dest_addr;
    printf("Received TCP packet:\n");
    printf("Source IP: %s\n", inet_ntoa(*(struct in_addr*)&packet->ip_header.saddr));
    printf("Destination IP: %s\n", inet_ntoa(*(struct in_addr*)&packet->ip_header.daddr));
    printf("Source Port: %d\n", ntohs(packet->tcp_header.source));
    printf("Destination Port: %d\n", ntohs(packet->tcp_header.dest));
    printf("Payload: %s\n", packet->payload);
}

int main(int argc, char* argv[]) {
    int sock_fd;
    struct sockaddr_in server_addr, client_addr;
    int server_port, client_port;
    int optval = 1;
    socklen_t addrlen;

    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // create socket
    sock_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock_fd == -1) {
        perror("socket()");
        exit(EXIT_FAILURE);
    }

    // set socket options
    if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        perror("setsockopt()");
        exit(EXIT_FAILURE);
    }

    // bind to server socket
    memset(&server_addr, 0, sizeof(server_addr));
    server_port = atoi(argv[1]);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind()");
        exit(EXIT_FAILURE);
    }

    printf("Packet monitoring started on port %d...\n", server_port);

    while (1) {
        udp_packet_t udp_packet;
        tcp_packet_t tcp_packet;
        char buffer[MAX_PACKET_SIZE];

        // receive packet
        addrlen = sizeof(client_addr);
        memset(&client_addr, 0, addrlen);
        memset(buffer, 0, sizeof(buffer));
        int packet_len = recvfrom(sock_fd, buffer, sizeof(buffer), 0, (struct sockaddr*)&client_addr, &addrlen);
        if (packet_len == -1) {
            perror("recvfrom()");
            exit(EXIT_FAILURE);
        }

        // parse packet
        memcpy(&udp_packet, buffer, packet_len);
        memcpy(&tcp_packet, buffer, packet_len);

        if (ntohs(udp_packet.udp_header.dest) == server_port) {
            display_udp_packet(&udp_packet);
        } else if (ntohs(tcp_packet.tcp_header.dest) == server_port) {
            display_tcp_packet(&tcp_packet);
        }
    }

    close(sock_fd);
    return 0;
}