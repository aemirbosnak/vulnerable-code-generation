//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define ICMP_TYPE_ECHO_REQUEST  8
#define ICMP_TYPE_ECHO_REPLY    0
#define ICMP_CODE_ECHO_REQUEST  0
#define ICMP_CODE_ECHO_REPLY   0

struct icmp_packet {
    uint8_t type;
    uint8_t code;
    uint16_t checksum;
    uint16_t identifier;
    uint16_t sequence_number;
    uint8_t data[0];
};

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: ping <destination address>\n");
        exit(1);
    }

    struct sockaddr_in dest_addr;
    if (inet_aton(argv[1], &dest_addr.sin_addr) == 0) {
        printf("Invalid destination address\n");
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    struct icmp_packet packet;
    memset(&packet, 0, sizeof(packet));
    packet.type = ICMP_TYPE_ECHO_REQUEST;
    packet.code = ICMP_CODE_ECHO_REQUEST;
    packet.identifier = (uint16_t)getpid();
    packet.sequence_number = 0;
    strcpy((char *)packet.data, "Hello, world!");

    struct sockaddr_in send_addr;
    memset(&send_addr, 0, sizeof(send_addr));
    send_addr.sin_family = AF_INET;
    send_addr.sin_addr = *(&dest_addr.sin_addr);
    send_addr.sin_port = 0;

    int bytes_sent = sendto(sockfd, &packet, sizeof(packet), 0,
            (struct sockaddr *)&send_addr, sizeof(send_addr));
    if (bytes_sent < 0) {
        perror("sendto");
        exit(1);
    }

    struct sockaddr_in recv_addr;
    socklen_t recv_addr_len = sizeof(recv_addr);
    char buffer[1024];
    int bytes_received = recvfrom(sockfd, buffer, sizeof(buffer), 0,
            (struct sockaddr *)&recv_addr, &recv_addr_len);
    if (bytes_received < 0) {
        perror("recvfrom");
        exit(1);
    }

    struct icmp_packet *recv_packet = (struct icmp_packet *)buffer;
    if (recv_packet->type != ICMP_TYPE_ECHO_REPLY || recv_packet->code != ICMP_CODE_ECHO_REPLY) {
        printf("Received packet is not an echo reply\n");
        exit(1);
    }

    if (recv_packet->identifier != (uint16_t)getpid()) {
        printf("Received packet is not addressed to us\n");
        exit(1);
    }

    printf("Received echo reply from %s\n", inet_ntoa(recv_addr.sin_addr));

    close(sockfd);

    return 0;
}