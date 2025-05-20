//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <signal.h>
#include <time.h>
#include <errno.h>

#define PACKET_SIZE 64
#define TIMEOUT 1

static volatile int run = 1;

void handle_signal(int sig) {
    run = 0;
}

unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2) {
        sum += *buf++;
    }
    if (len == 1) {
        sum += *(unsigned char *)buf;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

void send_icmp_requests(const char *ip_addr, int interval) {
    int sockfd;
    struct sockaddr_in addr_con;
    struct icmphdr icmp_header;
    char packet[PACKET_SIZE];
    struct timespec start_time, end_time;
    long rtt;

    if((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    addr_con.sin_family = AF_INET;
    addr_con.sin_addr.s_addr = inet_addr(ip_addr);
    
    signal(SIGINT, handle_signal);
    
    printf("Sending ICMP requests to %s every %d seconds...\n", ip_addr, interval);

    while(run) {
        memset(packet, 0, PACKET_SIZE);
        memset(&icmp_header, 0, sizeof(icmp_header));

        icmp_header.type = ICMP_ECHO;
        icmp_header.un.echo.id = getpid();
        icmp_header.un.echo.sequence = 1;
        icmp_header.checksum = checksum(&icmp_header, sizeof(icmp_header));
        
        clock_gettime(CLOCK_MONOTONIC, &start_time);

        if (sendto(sockfd, &icmp_header, sizeof(icmp_header), 0, (struct sockaddr *)&addr_con, sizeof(addr_con)) <= 0) {
            perror("Failed to send ICMP request");
        }

        socklen_t addr_len = sizeof(addr_con);
        if (recvfrom(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr *)&addr_con, &addr_len) <= 0) {
            printf("Request timed out.\n");
        } else {
            clock_gettime(CLOCK_MONOTONIC, &end_time);
            rtt = (end_time.tv_nsec - start_time.tv_nsec) / 1000000 + (end_time.tv_sec - start_time.tv_sec) * 1000;
            printf("Received reply from %s, RTT: %ld ms\n", ip_addr, rtt);
        }
        
        sleep(interval);
    }

    close(sockfd);
    printf("QoS monitoring stopped.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <destination_ip> <interval_in_seconds>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *destination_ip = argv[1];
    int interval = atoi(argv[2]);
    
    if (interval <= 0) {
        fprintf(stderr, "Interval must be a positive integer!\n");
        return EXIT_FAILURE;
    }
    
    send_icmp_requests(destination_ip, interval);
    
    return EXIT_SUCCESS;
}