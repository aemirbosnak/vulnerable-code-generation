//FormAI DATASET v1.0 Category: Network Ping Test ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>

#define PACKET_SIZE     4096
#define PING_TIMEOUT    2000            // Timeout in milliseconds
#define PING_PACKET_SIZE 64             // ICMP Header is of 64 bytes
#define MAX_HOP_COUNT   128             // Maximum hop count

enum PingResult {
    PING_RESULT_SENT,                   // Ping request sent
    PING_RESULT_RECV,                   // Ping response received
    PING_RESULT_TIMEOUT,                // Ping request timed out
    PING_RESULT_ERR                     // Error during ping
};

// Calculates the checksum for ICMP packet
unsigned short checksum(unsigned short *ptr, int nbytes) {
    unsigned long sum;
    unsigned short odd_byte;
    register short answer;

    sum = 0;
    while (nbytes > 1) {
        sum += *ptr++;
        nbytes -= 2;
    }

    if (nbytes == 1) {
        odd_byte = 0;
        *((u_char *) & odd_byte) = *(u_char *) ptr;
        sum += odd_byte;
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    answer = (short) ~sum;

    return answer;
}

// Sends an ICMP packet to the given address and waits for the response
int ping(struct sockaddr_in *addr, int ttl, int seq) {
    int sockfd, bytes_sent, bytes_received;
    struct timeval ping_timeout = {PING_TIMEOUT / 1000, (PING_TIMEOUT % 1000) * 1000};
    struct icmphdr icmp;
    char packet[PACKET_SIZE];
    struct timeval *sent_time, *recv_time;
    struct timezone tz;
    double rtt;

    bzero(packet, PACKET_SIZE);

    // Fill in ICMP Header
    icmp.type = ICMP_ECHO;
    icmp.code = 0;
    icmp.checksum = 0;
    icmp.un.echo.id = getpid();
    icmp.un.echo.sequence = seq;
    icmp.checksum = checksum((unsigned short *) &icmp, PING_PACKET_SIZE);

    // Fill in Time to Live
    setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(int));

    // Set send and receive timeout
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, &ping_timeout, sizeof(struct timeval));
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &ping_timeout, sizeof(struct timeval));

    bytes_sent = sendto(sockfd, &icmp, sizeof(icmp), 0, (struct sockaddr *) addr, sizeof(struct sockaddr));
    if (bytes_sent < 0) {
        return PING_RESULT_ERR;
    }

    sent_time = malloc(sizeof(struct timeval));
    gettimeofday(sent_time, &tz);

    bytes_received = recv(sockfd, packet, PACKET_SIZE, 0);
    if (bytes_received < 0) {
        free(sent_time);
        return PING_RESULT_TIMEOUT;
    }

    recv_time = malloc(sizeof(struct timeval));
    gettimeofday(recv_time, &tz);

    // Calculate Round Trip Time
    rtt = (double) ((recv_time->tv_sec - sent_time->tv_sec) * 1000) + ((recv_time->tv_usec - sent_time->tv_usec) / 1000);

    free(sent_time);
    free(recv_time);

    if (icmp.type == ICMP_ECHOREPLY) {
        return PING_RESULT_RECV;
    }

    return PING_RESULT_TIMEOUT;
}

int main(int argc, char **argv) {
    struct sockaddr_in addr;
    struct hostent *host_info;
    int ttl, seq, i, ping_res;
    char *hostname;

    if (argc < 2) {
        printf("Usage: %s <hostname/IP>\n", argv[0]);
        return 1;
    }

    hostname = argv[1];

    // Resolve hostname to IP Address
    host_info = gethostbyname(hostname);
    if (host_info == NULL) {
        printf("Error resolving hostname: %s\n", hostname);
        return 1;
    }

    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    bcopy(host_info->h_addr, &(addr.sin_addr.s_addr), host_info->h_length);

    // Send ICMP packets with increasing TTL values
    for (ttl = 1; ttl <= MAX_HOP_COUNT; ttl++) {
        printf("%d. ", ttl);

        // Send 3 ICMP packets for each TTL value
        for (seq = 1; seq <= 3; seq++) {
            ping_res = ping(&addr, ttl, seq);

            if (ping_res == PING_RESULT_SENT) {
                printf("* ");
            } else if (ping_res == PING_RESULT_RECV) {
                printf("IP ");
            } else if (ping_res == PING_RESULT_TIMEOUT) {
                printf("   ");
            } else {
                printf("ERR");
            }
        }

        printf("\n");

        // Stop sending packets if destination is reached
        if (ping_res == PING_RESULT_RECV) {
            break;
        }
    }

    return 0;
}