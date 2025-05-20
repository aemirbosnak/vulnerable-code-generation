//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <time.h>
#include <signal.h>

#define PACKET_SIZE 64
#define NUMBER_OF_PINGS 5
#define TIMEOUT 1

struct ping_packet {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

int ping_socket;
struct sockaddr_in dest_addr;

unsigned short calculate_checksum(void *b, int len) {
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

void send_ping(char *ip_addr) {
    struct ping_packet packet;
    packet.hdr.type = ICMP_ECHO;
    packet.hdr.un.echo.id = getpid();
    for (int i = 0; i < sizeof(packet.msg) - 1; i++)
        packet.msg[i] = 'A';
    packet.msg[sizeof(packet.msg) - 1] = 0;
    packet.hdr.un.echo.sequence = 1;

    packet.hdr.checksum = calculate_checksum(&packet, sizeof(packet));

    if (sendto(ping_socket, &packet, sizeof(packet), 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) <= 0) {
        perror("Send failed");
    }
}

void receive_ping() {
    char buffer[PACKET_SIZE];
    socklen_t addr_len = sizeof(dest_addr);
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    if (setsockopt(ping_socket, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv) < 0) {
        perror("Set socket options failed");
    }

    if (recvfrom(ping_socket, buffer, sizeof(buffer), 0, (struct sockaddr *)&dest_addr, &addr_len) <= 0) {
        printf("Request timed out.\n");
    } else {
        struct iphdr *ip_hdr = (struct iphdr *)buffer;
        struct icmphdr *icmp_hdr = (struct icmphdr *)(buffer + (ip_hdr->ihl << 2));
        
        if (icmp_hdr->type == ICMP_ECHOREPLY) {
            printf("Received ping response from %s: seq=%d\n", inet_ntoa(dest_addr.sin_addr), icmp_hdr->un.echo.sequence);
        } else {
            printf("Received unexpected packet type %d\n", icmp_hdr->type);
        }
    }
}

void cleanup() {
    close(ping_socket);
    printf("Socket closed. Exiting...\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    atexit(cleanup);

    ping_socket = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (ping_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;

    if (inet_pton(AF_INET, argv[1], &dest_addr.sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < NUMBER_OF_PINGS; i++) {
        printf("Pinging %s...\n", argv[1]);
        send_ping(argv[1]);
        receive_ping();
        sleep(1);
    }

    return 0;
}