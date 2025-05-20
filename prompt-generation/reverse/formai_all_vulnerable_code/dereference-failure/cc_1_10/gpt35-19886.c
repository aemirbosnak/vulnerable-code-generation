//FormAI DATASET v1.0 Category: Network Ping Test ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PACKET_SIZE 64
#define MAX_COUNT 10

void usage(const char *program_name) {
    printf("Usage: %s <host>\n", program_name);
}

void error(const char *message) {
    printf("Error: %s\n", message);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        usage(argv[0]);
        return 1;
    }

    struct hostent *host;
    struct sockaddr_in send_addr;
    struct icmphdr icmp_header;
    struct timeval tv;
    char send_packet[PACKET_SIZE], rcv_packet[PACKET_SIZE];
    int sockfd, rcv_len, send_len, ttl, i, j, ttl_reached, timeout_reached, count;
    float rtt;
    char sender_ip[20];

    // get host info
    if ((host = gethostbyname(argv[1])) == NULL) {
        error("could not obtain host information");
    }

    // create socket
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        error("could not create socket");
    }

    // set TTL socket option
    ttl = 64;
    if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) != 0) {
        error("could not set socket TTL option");
    }

    // fill send_addr struct
    memset(&send_addr, 0, sizeof(send_addr));
    send_addr.sin_family = AF_INET;
    send_addr.sin_addr = *((struct in_addr*) host->h_addr);

    // prepare ICMP header
    icmp_header.type = ICMP_ECHO;
    icmp_header.code = 0;
    icmp_header.checksum = 0;
    icmp_header.un.echo.id = getpid();

    // prepare send_packet
    memset(send_packet, 0, PACKET_SIZE);
    memcpy(send_packet, &icmp_header, sizeof(icmp_header));
    gettimeofday((struct timeval *) (send_packet + sizeof(icmp_header)), NULL);

    printf("Starting pong test for host %s...\n\n", argv[1]);

    for (count = 1; count <= MAX_COUNT; ++count) {
        printf("Ping number %d:\n", count);

        // set ICMP sequence number
        icmp_header.un.echo.sequence = count;

        // reset send_packet checksum
        icmp_header.checksum = 0;
        memcpy(send_packet, &icmp_header, sizeof(icmp_header));

        // calculate send_packet checksum
        icmp_header.checksum = 0;
        for (i = 0; i < PACKET_SIZE; i += 2) {
            icmp_header.checksum += *(unsigned short*) (send_packet + i);
        }

        icmp_header.checksum = (icmp_header.checksum >> 16) + (icmp_header.checksum & 0xffff);
        icmp_header.checksum += (icmp_header.checksum >> 16);

        // copy the calculated checksum into send_packet
        memcpy(send_packet, &icmp_header, sizeof(icmp_header));

        // record send time
        gettimeofday(&tv, NULL);

        // send packet
        if ((send_len = sendto(sockfd, send_packet, PACKET_SIZE, 0, (struct sockaddr*) &send_addr, sizeof(send_addr))) <= 0) {
            error("could not send packet");
        }

        // reset timeout_reached flag
        timeout_reached = 0;

        // receive packet loop
        for (;;) {
            // receive packet
            rcv_len = recv(sockfd, rcv_packet, PACKET_SIZE, 0);

            // if no packet received or timeout reached, break loop
            if (rcv_len <= 0) {
                timeout_reached = 1;
                break;
            }

            // extract sender IP address
            inet_ntop(AF_INET, &((struct sockaddr_in*) &send_addr)->sin_addr, sender_ip, sizeof(sender_ip));

            // extract ICMP header from received packet
            struct icmphdr *rcv_icmp_header = (struct icmphdr*) (rcv_packet + sizeof(struct iphdr));

            // check if received packet is an ICMP reply
            if (rcv_icmp_header->type == ICMP_ECHOREPLY && rcv_icmp_header->un.echo.id == getpid()) {
                if (rcv_icmp_header->un.echo.sequence != count) {
                    continue;
                }

                // calculate round-trip time
                gettimeofday(&tv, NULL);
                rtt = (float) (tv.tv_usec - *((int*) (rcv_packet + sizeof(struct iphdr) + sizeof(struct icmphdr)))) / 1000;

                printf("%d bytes from %s: icmp_seq=%d ttl=%d time=%.3f ms\n", rcv_len - sizeof(struct iphdr) - sizeof(struct icmphdr), sender_ip, rcv_icmp_header->un.echo.sequence, *((unsigned char*) (rcv_packet + sizeof(struct iphdr) + 8)), rtt);

                break;
            }
        }

        if (timeout_reached) {
            printf("No reply from %s within a timeout reached\n", argv[1]);
        }

        printf("\n");

        sleep(1);
    }

    // close socket
    close(sockfd);

    return 0;
}