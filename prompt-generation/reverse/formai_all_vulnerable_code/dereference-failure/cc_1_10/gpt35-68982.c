//FormAI DATASET v1.0 Category: Network Ping Test ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PACKET_SIZE 64

struct packet {
    struct icmphdr icmp;
    char data[PACKET_SIZE - sizeof(struct icmphdr)];
};

unsigned short in_cksum(unsigned short *addr, int len) {
    unsigned short *w = addr;
    int sum = 0;
    unsigned short answer = 0;

    while (len > 1) {
        sum += *w++;
        len -= 2;
    }

    if (len == 1) {
        *(unsigned char *)(&answer) = *(unsigned char *)w;
        sum += answer;
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    answer = ~sum;

    return answer;
}

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    const char *ip_address = argv[1];

    struct hostent *host = gethostbyname(ip_address);
    if (!host) {
        fprintf(stderr, "Error: unable to resolve host %s\n", ip_address);
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Error: unable to create socket");
        return 1;
    }

    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        perror("Error: unable to set socket timeout");
        return 1;
    }

    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    memcpy(&dest_addr.sin_addr, host->h_addr, host->h_length);

    struct packet ping_packet;
    memset(&ping_packet, 0, sizeof(ping_packet));
    ping_packet.icmp.type = ICMP_ECHO;
    ping_packet.icmp.code = 0;
    ping_packet.icmp.checksum = in_cksum((unsigned short *)&ping_packet, sizeof(ping_packet));

    int sequence = 0;

    while (1) {
        struct timeval start_time, end_time;
        gettimeofday(&start_time, NULL);

        ping_packet.icmp.un.echo.sequence = sequence++;
        ping_packet.icmp.checksum = 0;
        ping_packet.icmp.checksum = in_cksum((unsigned short *)&ping_packet, sizeof(ping_packet));

        ssize_t bytes_sent = sendto(sockfd, &ping_packet, sizeof(ping_packet), 0,
            (struct sockaddr *)&dest_addr, sizeof(dest_addr));
        if (bytes_sent < 0) {
            perror("Error: unable to send packet");
            continue;
        }

        char recv_buffer[IP_MAXPACKET];
        ssize_t bytes_received = recv(sockfd, &recv_buffer, sizeof(recv_buffer), 0);
        if (bytes_received < 0) {
            printf("Request timed out.\n");
            continue;
        }

        gettimeofday(&end_time, NULL);
        double elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000.0 +
            (end_time.tv_usec - start_time.tv_usec) / 1000.0;

        struct iphdr *ip_header = (struct iphdr *)recv_buffer;
        struct icmphdr *icmp_header = (struct icmphdr *)(recv_buffer + ip_header->ihl * 4);

        if (icmp_header->type == ICMP_ECHOREPLY) {
            printf("Ping reply from %s: icmp_seq=%d time=%.2f ms\n",
                ip_address, icmp_header->un.echo.sequence, elapsed_time);
        } else {
            printf("Invalid ICMP packet received.\n");
        }

        sleep(1);
    }

    close(sockfd);

    return 0;
}