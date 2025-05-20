//FormAI DATASET v1.0 Category: Network Ping Test ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define ICMP_ECHO_REQUEST 8

struct icmp_packet {
    struct icmphdr hdr;
    char msg[BUFFER_SIZE - sizeof(struct icmphdr)];
};

void calculate_time_diff(struct timeval *start, struct timeval *end, struct timeval *time_diff) {
    time_diff->tv_sec = end->tv_sec - start->tv_sec;
    time_diff->tv_usec = end->tv_usec - start->tv_usec;
    if (time_diff->tv_usec < 0) {
        time_diff->tv_sec--;
        time_diff->tv_usec += 1000000;
    }
}

unsigned short checksum(unsigned short *buffer, int size) {
    unsigned long checksum = 0;
    while (size > 1) {
        checksum += *buffer++;
        size -= sizeof(unsigned short);
    }
    if (size) {
        checksum += *(unsigned char*)buffer;
    }
    checksum = (checksum >> 16) + (checksum & 0xffff);
    checksum += (checksum >> 16);
    return (unsigned short)(~checksum);
}

int send_ping(int sockfd, struct sockaddr_in *ping_address) {
    struct icmp_packet packet;
    struct timeval start_time, end_time, time_diff;
    memset(&packet, 0, sizeof(struct icmp_packet));
    packet.hdr.type = ICMP_ECHO_REQUEST;
    packet.hdr.un.echo.id = (unsigned short)getpid();
    for (int i = 0; i < BUFFER_SIZE - sizeof(struct icmp_packet); i++) {
        packet.msg[i] = i + '0';
    }
    packet.hdr.checksum = checksum((unsigned short*)&packet, sizeof(struct icmp_packet));
    gettimeofday(&start_time, NULL);
    if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)ping_address, sizeof(struct sockaddr_in)) <= 0) {
        printf("Error in sendto\n");
        return -1;
    }
    int len;
    char buffer[BUFFER_SIZE];
    len = sizeof(struct sockaddr_in);
    if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)ping_address, &len) <= 0) {
        printf("Error in recvfrom\n");
        return -1;
    }
    gettimeofday(&end_time, NULL);
    calculate_time_diff(&start_time, &end_time, &time_diff);
    printf("Ping response received in %ld.%06ld sec\n", time_diff.tv_sec, time_diff.tv_usec);
    return 0;
}

int main(int argc, char *argv[]) {
    int sockfd;
    int ping_count = 0;
    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 0;
    }
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Error in resolving hostname\n");
        return -1;
    }
    struct sockaddr_in ping_address;
    memset(&ping_address, 0, sizeof(struct sockaddr_in));
    ping_address.sin_family = AF_INET;
    ping_address.sin_addr = *((struct in_addr*) host->h_addr);
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        printf("Error in socket\n");
        return -1;
    }
    printf("Ping test to hostname: %s\n", argv[1]);
    while (ping_count < 10) {
        printf("Pinging...%s\n", argv[1]);
        if (send_ping(sockfd, &ping_address) < 0) {
            printf("Ping failed\n");
        }
        ping_count++;
        sleep(1);
    }
    close(sockfd);
    return 0;
}