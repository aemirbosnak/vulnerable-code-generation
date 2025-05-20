//FormAI DATASET v1.0 Category: Network Ping Test ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>

#define IP_PACKET_SIZE 64
#define ICMP_PACKET_SIZE 64
#define MAX_HOPS 30

typedef struct {
    struct icmphdr header;
    char message[ICMP_PACKET_SIZE - sizeof(struct icmphdr)];
} icmp_packet;

void usage(char *program) {
    printf("Usage: %s <destination>\n", program);
}

unsigned short calculate_checksum(unsigned short *data, int length) {
    unsigned long sum = 0;
    while (length > 1) {
        sum += *data++;
        length -= 2;
    }
    if (length == 1) {
        sum += *(unsigned char *)data;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    return ~sum;
}

double time_diff(struct timeval t1, struct timeval t2) {
    return (t2.tv_sec - t1.tv_sec) * 1000.0 + (t2.tv_usec - t1.tv_usec) / 1000.0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        usage(argv[0]);
        exit(EXIT_FAILURE);
    }
    char *destination = argv[1];

    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_RAW;
    hints.ai_protocol = IPPROTO_ICMP;
    int status = getaddrinfo(destination, NULL, &hints, &result);
    if (status != 0) {
        printf("Error: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    int ttl = MAX_HOPS;
    setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl));

    icmp_packet packet;
    memset(&packet, 0, sizeof(packet));
    packet.header.type = ICMP_ECHO;
    packet.header.code = 0;
    packet.header.un.echo.id = htons(getpid() & 0xFFFF);
    for (int i = 0; i < sizeof(packet.message) - 1; i++) {
        packet.message[i] = 'A' + i % 26;
    }
    packet.message[sizeof(packet.message) - 1] = 0;
    packet.header.checksum = calculate_checksum((unsigned short *)&packet, sizeof(packet));
    
    int sequence_number = 0;
    struct sockaddr_in receiver_address;
    receiver_address.sin_family = AF_INET;
    receiver_address.sin_addr = ((struct sockaddr_in *)(result->ai_addr))->sin_addr;
    int addr_length = sizeof(receiver_address);

    printf("PING %s (%s):\n", destination, inet_ntoa(receiver_address.sin_addr));
    for (int i = 1; i <= MAX_HOPS; i++) {
        printf("%2d. ", i);

        struct timeval start_time, end_time;
        gettimeofday(&start_time, NULL);
        packet.header.un.echo.sequence = htons(sequence_number++);
        sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&receiver_address, sizeof(receiver_address));
        char receive_buffer[IP_PACKET_SIZE];
        int byte_count = recvfrom(sockfd, receive_buffer, IP_PACKET_SIZE, 0, (struct sockaddr *)&receiver_address, &addr_length);
        gettimeofday(&end_time, NULL);
        double time_elapsed = time_diff(start_time, end_time);

        if (byte_count > 0) {
            struct iphdr *ip_header = (struct iphdr *)receive_buffer;
            int ip_header_length = ip_header->ihl * 4;
            struct icmp *icmp_header = (struct icmp *)(receive_buffer + ip_header_length);
            if (icmp_header->icmp_type == ICMP_TIME_EXCEEDED || icmp_header->icmp_type == ICMP_ECHOREPLY) {
                struct timeval *packet_timestamp = (struct timeval *)(icmp_header->icmp_data);
                printf("%.2f ms", time_elapsed);
                if (icmp_header->icmp_type == ICMP_ECHOREPLY) {
                    printf("  ip=%s", inet_ntoa(*(struct in_addr *)(&ip_header->saddr)));
                }
                printf("\n");
            } else {
                printf("unknown packet received\n");
            }
        } else {
            printf("timeout\n");
        }

        if (receiver_address.sin_addr.s_addr == ((struct sockaddr_in *)(result->ai_addr))->sin_addr.s_addr) {
            break;
        }

        ttl--;
        setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl));
    }

    freeaddrinfo(result);
    close(sockfd);

    return EXIT_SUCCESS;
}