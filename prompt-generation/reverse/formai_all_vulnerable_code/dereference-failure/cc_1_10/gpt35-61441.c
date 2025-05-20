//FormAI DATASET v1.0 Category: Network Ping Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>

#define ICMP_ECHO_REQUEST 8

struct packet {
    struct icmphdr header;
    char message[64 - sizeof(struct icmphdr)];
};

int checksum(void *b, int len) { 
    unsigned short *buf = b; 
    unsigned int sum = 0; 
    unsigned short result; 

    for ( sum = 0; len > 1; len -= 2 ) 
        sum += *buf++; 
    if ( len == 1 ) 
        sum += *(unsigned char*)buf; 

    sum = (sum >> 16) + (sum & 0xFFFF); 
    sum += (sum >> 16); 
    result = ~sum; 

    return result; 
} 

void ping(struct sockaddr_in *target, int count) {
    int ICMP_socket;
    struct packet pckt;
    struct icmphdr *header = &pckt.header;
    struct timeval tv_out, tv_recv;
    const int timeouts = 3;
    int lost_packets = 0, received_packets = 0;

    ICMP_socket = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if ( ICMP_socket < 0 ) {
        printf("Unable to create ICMP socket\n");
        return;
    }

    memset(&pckt, 0, sizeof(pckt));
    header->type = ICMP_ECHO_REQUEST;
    header->code = 0;
    header->un.echo.id = getpid();

    for (int i = 0; i < sizeof(pckt.message) - 1; i++)
        pckt.message[i] = '0' + i % 10;
    pckt.message[sizeof(pckt.message) - 1] = 0;

    header->checksum = checksum(&pckt, sizeof(pckt));

    tv_out.tv_sec = 1;
    tv_out.tv_usec = 0;

    for (int i = 1; i <= count; i++) {

        if ( sendto(ICMP_socket, &pckt, sizeof(pckt), 0, (struct sockaddr*)target, sizeof(*target)) <= 0 ) {
            printf("Unable to send packet %d\n", i);
            lost_packets++;
            continue;
        }

        int len = sizeof(*target);
        fd_set set;

        FD_ZERO(&set);
        FD_SET(ICMP_socket, &set);

        if ( select(ICMP_socket+1, &set, NULL, NULL, &tv_out) <= 0 ) {
            printf("Packet %d timed out\n", i);
            lost_packets++;
            continue;
        }

        char buffer[64];
        memset(buffer, 0, sizeof(buffer));

        if ( recvfrom(ICMP_socket, buffer, sizeof(buffer), 0, (struct sockaddr*)target, &len) <= 0 ) {
            printf("Unable to receive packet %d\n", i);
            lost_packets++;
            continue;
        }

        received_packets++;
        gettimeofday(&tv_recv, NULL);
        float rtt = (tv_recv.tv_sec-tv_out.tv_sec) * 1000.0 + (tv_recv.tv_usec-tv_out.tv_usec) / 1000.0;
        printf("Received packet %d: %d bytes from %s, rtt = %f ms\n", i, sizeof(buffer), inet_ntoa(target->sin_addr), rtt);
    }

    printf("Lost packets: %d\n", lost_packets);
    printf("Received packets: %d\n", received_packets);

    close(ICMP_socket);
}

int main(int argc, char *argv[]) {

    if ( argc != 2 ) {
        printf("Usage: %s [hostname or IP address to ping]\n", argv[0]);
        return -1;
    }

    struct hostent *host = gethostbyname(argv[1]);

    if ( host == NULL ) {
        printf("Unable to resolve IP address for %s\n", argv[1]);
        return -1;
    }

    struct sockaddr_in target;
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    memcpy(&target.sin_addr.s_addr, host->h_addr, host->h_length);

    printf("Pinging %s (%s):\n", argv[1], inet_ntoa(target.sin_addr));

    ping(&target, 10); // Ping ten times

    return 0;
}