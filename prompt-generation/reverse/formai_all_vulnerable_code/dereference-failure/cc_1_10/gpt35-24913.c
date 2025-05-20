//FormAI DATASET v1.0 Category: Network Ping Test ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <time.h>

#define PACKET_SIZE     64 // Standard ICMP packet size
#define MAX_HOPS        30 // Maximum number of hops to trace
#define TIMEOUT         4 // Time-out value in seconds

// Calculates internet checksum
unsigned short calculate_checksum(unsigned short *p, int len) {
    unsigned long sum = 0;
    while(len > 1) {
        sum += *p++;
        len -= 2;
    }
    if(len == 1)
        sum += *(unsigned char *)p;
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./pingtest hostname\n");
        exit(1);
    }

    char *hostname = argv[1];

    // Creating socket file descriptor
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if(sockfd < 0) {
        perror("Error: socket creation failed");
        exit(1);
    }

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("Error: hostname resolution failed");
        exit(1);
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr = *((struct in_addr *)host->h_addr);

    printf("Pinging %s with %d bytes of data:\n\n", hostname, PACKET_SIZE);

    int hop_count = 0;
    int success_count = 0;

    // Loop through each hop up to a maximum of MAX_HOPS
    for (hop_count = 1; hop_count <= MAX_HOPS; hop_count++) {
        struct timeval start_time, end_time;
        int packet_size = PACKET_SIZE;
        char packet[PACKET_SIZE];

        // Set packet header
        struct icmp *icmp_hdr = (struct icmp *)packet;
        icmp_hdr->icmp_type = ICMP_ECHO;
        icmp_hdr->icmp_code = 0;
        icmp_hdr->icmp_id = getpid();
        icmp_hdr->icmp_seq = hop_count;

        // Set packet data
        char *data = packet + sizeof(struct icmp);
        for (int i = 0; i < packet_size - sizeof(struct icmp); i++)
            data[i] = i + '0';

        // Set time stamp using gettimeofday()
        gettimeofday(&start_time, NULL);
        icmp_hdr->icmp_cksum = 0;
        icmp_hdr->icmp_cksum = calculate_checksum((unsigned short *)icmp_hdr, packet_size);

        // Send packet with sendto()
        if (sendto(sockfd, packet, packet_size, 0, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            perror("Error: failed to send packet");
            continue;
        }

        // Set timeout for select() and wait for response with recvfrom()
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(sockfd, &read_fds);

        struct timeval timeout;
        timeout.tv_sec = TIMEOUT;
        timeout.tv_usec = 0;

        int ready = select(sockfd + 1, &read_fds, NULL, NULL, &timeout);
        if (ready < 0) {
            perror("Error: select() failed");
            continue;
        } else if (ready == 0) {
            printf("Request timed out.\n\n");
            continue;
        }

        char recv_packet[PACKET_SIZE];
        int len = sizeof(addr);
        if (recvfrom(sockfd, recv_packet, PACKET_SIZE, 0, (struct sockaddr *)&addr, &len) < 0) {
            perror("Error: failed to receive packet");
            continue;
        }

        // Calculate round-trip time (RTT) using gettimeofday()
        gettimeofday(&end_time, NULL);
        double rtt = (double)(end_time.tv_usec - start_time.tv_usec) / 1000.0;
        printf("%d\t%0.3f ms\n", hop_count, rtt);
        success_count++;
    }

    if(success_count == 0) {
        printf("Ping test unsuccessful. No successful hops.\n");
        exit(1);
    }

    printf("\nPing test successful! %d hops reached.\n", success_count);
    return 0;
}