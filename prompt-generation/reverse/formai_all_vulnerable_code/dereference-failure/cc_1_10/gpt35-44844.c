//FormAI DATASET v1.0 Category: Network Ping Test ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PING_PACKET_SIZE    64
#define PING_TIMEOUT        2
#define PING_PORT           0   // Use default port (ICMP)

// Header for ICMP (Internet Control Message Protocol) packet
typedef struct icmp_header
{
    uint8_t type;
    uint8_t code;
    uint16_t checksum;
    uint16_t id;
    uint16_t seq_num;
} icmp_header_t;

/*
 * Calculates the checksum for an ICMP packet
 * @param packet: ICMP data packet
 * @param size: size of the packet
 * @return checksum value
 */
uint16_t calculate_checksum(void *packet, int size)
{
    uint16_t *buf = (uint16_t *) packet;
    uint32_t sum = 0;
    uint16_t result;

    for (sum = 0; size > 1; size -= 2)
        sum += *buf++;

    if (size == 1)
        sum += *(uint8_t *) buf;

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;

    return result;
}

/*
 * Sends an ICMP echo request to the specified host
 * @param hostname: the host to ping
 * @return 1 if successful, 0 otherwise
 */
int ping(char *hostname)
{
    int sock, status, bytes_received, num_retries = 3;
    struct addrinfo hints, *res;
    char ip[INET_ADDRSTRLEN];
    uint8_t packet[PING_PACKET_SIZE];
    struct timeval timeout;
    icmp_header_t *icmp;

    // Get IP address of host
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_RAW; // Raw socket
    hints.ai_protocol = IPPROTO_ICMP; // ICMP protocol

    if ((status = getaddrinfo(hostname, NULL, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return 0;
    }

    struct sockaddr_in *addr = (struct sockaddr_in *)res->ai_addr;
    inet_ntop(AF_INET, &(addr->sin_addr), ip, INET_ADDRSTRLEN);

    // Create socket
    if ((sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("socket");
        return 0;
    }

    // Set timeout value for the socket
    timeout.tv_sec = PING_TIMEOUT;
    timeout.tv_usec = 0;

    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char *)&timeout, sizeof(timeout)) < 0) {
        perror("setsockopt");
        return 0;
    }

    // Initialize ICMP packet
    memset(packet, 0, PING_PACKET_SIZE);
    icmp = (icmp_header_t *) packet;
    icmp->type = 8; // ICMP echo request
    icmp->id = getpid();

    // Calculate checksum
    icmp->checksum = calculate_checksum(packet, PING_PACKET_SIZE);

    // Send ICMP packet to host
    bytes_received = 0;
    while (num_retries--) {
        if (sendto(sock, packet, PING_PACKET_SIZE, 0, (struct sockaddr*)&addr, sizeof(struct sockaddr)) < 0) {
            perror("sendto");
            break;
        }

        // Wait for response
        uint8_t recv_packet[PING_PACKET_SIZE];
        socklen_t recv_len = sizeof(struct sockaddr);
        struct sockaddr_in recv_addr;
        memset(&recv_addr, 0, sizeof(recv_addr));

        if ((bytes_received = recvfrom(sock, recv_packet, PING_PACKET_SIZE, 0, (struct sockaddr *)&recv_addr, &recv_len)) > 0) {
            icmp_header_t *icmp_reply = (icmp_header_t *)recv_packet;

            if (icmp_reply->type == 0 && icmp_reply->id == getpid()) {
                printf("%s is alive!\n", hostname);
                return 1;
            }
        }
    }

    printf("%s is not responding.\n", hostname);

    close(sock);
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 0;
    }

    ping(argv[1]);

    return 0;
}