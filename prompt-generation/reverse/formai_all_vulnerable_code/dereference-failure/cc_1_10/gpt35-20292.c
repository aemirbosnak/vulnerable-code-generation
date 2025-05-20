//FormAI DATASET v1.0 Category: Network Ping Test ; Style: creative
/*
 * Network Ping Test Example Program
 * By: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/time.h>

// Define the packet size and timeout
#define PACKET_SIZE 64
#define TIMEOUT 1000

// Calculate the IP header checksum
unsigned short checksum(unsigned short *b, int len) {
    unsigned int sum = 0;
    unsigned short result = 0;
    for (sum = 0; len > 1; len -= 2) {
        sum += *b++;
    }
    if (len == 1) {
        sum += *(unsigned char *)b;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

// Create the ICMP packet
void create_packet(char *packet, int sequence) {
    struct icmp *hdr;
    hdr = (struct icmp *)packet;
    hdr->icmp_type = ICMP_ECHO;
    hdr->icmp_code = 0;
    hdr->icmp_id = htons(getpid());
    hdr->icmp_seq = htons(sequence);
    hdr->icmp_cksum = 0;
    hdr->icmp_cksum = checksum((unsigned short *)hdr, PACKET_SIZE);
}

// Send the ICMP packet
int send_packet(int sockfd, struct sockaddr_in *target, char *packet, int seq) {
    int bytes_sent = 0;
    create_packet(packet, seq);
    bytes_sent = sendto(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr *)target, sizeof(struct sockaddr));
    return bytes_sent;
}

// Receive the ICMP packet
int receive_packet(int sockfd, struct sockaddr_in *target, char *packet, int seq, struct timeval *start_time) {
    fd_set readfds;
    struct timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = TIMEOUT * 1000;
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    int bytes_received = 0;
    int len = sizeof(struct sockaddr);
    struct timeval end_time;
    gettimeofday(&end_time, NULL);
    if ((end_time.tv_usec - start_time->tv_usec) < 0) {
        end_time.tv_sec = end_time.tv_sec - start_time->tv_sec - 1;
        end_time.tv_usec = end_time.tv_usec - start_time->tv_usec + 1000000;
    } else {
        end_time.tv_sec = end_time.tv_sec - start_time->tv_sec;
        end_time.tv_usec = end_time.tv_usec - start_time->tv_usec;
    }
    if (select(sockfd + 1, &readfds, NULL, NULL, &timeout) > 0) {
        bytes_received = recvfrom(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr *)target, &len);
    } else {
        printf("Request timed out\n");
        return -1;
    }
    return bytes_received;
}

// Perform the ping test
void ping(char *host) {
    struct hostent *target;
    struct sockaddr_in target_addr;
    char packet[PACKET_SIZE];
    char recv_packet[PACKET_SIZE];
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(-1);
    }
    target = gethostbyname(host);
    if (target == NULL) {
        perror("Error resolving hostname");
        exit(-1);
    }
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr = *((struct in_addr *)target->h_addr);
    int seq = 0;
    int total_time = 0;
    int num_pings = 4;
    int num_received = 0;
    for (int i = 0; i < num_pings; i++) {
        struct timeval start_time, end_time;
        gettimeofday(&start_time, NULL);
        if (send_packet(sockfd, &target_addr, packet, seq) < 0) {
            printf("Error sending packet\n");
            seq++;
            continue;
        }
        if (receive_packet(sockfd, &target_addr, recv_packet, seq, &start_time) < 0) {
            seq++;
            continue;
        }
        gettimeofday(&end_time, NULL);
        total_time += (end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_usec - start_time.tv_usec) / 1000;
        num_received++;
        printf("Received packet from %s: seq=%d time=%dms\n", host, seq, (end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_usec - start_time.tv_usec) / 1000);
        seq++;
        sleep(1);
    }
    printf("%d packets transmitted, %d packets received, %.0f%% packet loss, average time %dms\n", num_pings, num_received, ((float)(num_pings - num_received) / num_pings) * 100, total_time / num_received);
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return -1;
    }
    ping(argv[1]);
    return 0;
}