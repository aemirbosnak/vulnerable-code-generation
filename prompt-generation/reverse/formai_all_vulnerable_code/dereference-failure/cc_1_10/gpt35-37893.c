//FormAI DATASET v1.0 Category: Network Ping Test ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <netdb.h>

#define ICMP_ECHO_REQUEST 8
#define ICMP_HEADER_SIZE sizeof(struct icmp)
#define IP_HEADER_SIZE sizeof(struct ip)
#define BUFFER_SIZE 1024

// Function to calculate the checksum of the icmp packet
unsigned short checksum(unsigned short *ptr, int nbytes) {
    unsigned long sum = 0;
    while (nbytes > 1) {
        sum += *ptr++;
        nbytes -= 2;
    }
    if (nbytes == 1) {
        sum += *(unsigned char*)ptr;
    }
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}

// Function to print error message and exit program
void error(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    // Check if correct number of arguments are provided
    if (argc != 2) {
        error("Usage: ./ping hostname");
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        error("Error creating socket");
    }

    // Set timeout
    struct timeval timeout;
    timeout.tv_sec = 2;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        error("Error setting timeout");
    }

    // Resolve hostname to IP address
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        error("Error resolving hostname");
    }

    // Initialize sockaddr_in structure
    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr = *(struct in_addr*)host->h_addr_list[0];

    // Send ICMP packets and receive responses
    int sent = 0, received = 0;
    for (int seq = 1; seq <= 10; seq++) {
        // Prepare icmp packet
        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);
        struct icmp *icmp = (struct icmp*)buffer;
        icmp->icmp_type = ICMP_ECHO_REQUEST;
        icmp->icmp_code = 0;
        icmp->icmp_id = getpid();
        icmp->icmp_seq = seq;
        icmp->icmp_cksum = 0;
        icmp->icmp_cksum = checksum((unsigned short*)icmp, ICMP_HEADER_SIZE);

        // Get current time
        struct timeval start;
        gettimeofday(&start, NULL);

        // Send icmp packet
        if (sendto(sockfd, buffer, ICMP_HEADER_SIZE, 0, (struct sockaddr*)&dest_addr, sizeof(dest_addr)) <= 0) {
            fprintf(stdout, "Packet %d: Error sending icmp packet\n", seq);
            continue;
        }
        sent++;

        // Receive icmp packet
        struct sockaddr_in sender_addr;
        socklen_t sender_len = sizeof(sender_addr);
        if (recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&sender_addr, &sender_len) <= 0) {
            fprintf(stdout, "Packet %d: Timed out\n", seq);
            continue;
        }

        // Get current time
        struct timeval end;
        gettimeofday(&end, NULL);

        // Extract icmp header and payload
        struct ip *ip = (struct ip*)buffer;
        struct icmp *icmp_resp = (struct icmp*)(buffer + IP_HEADER_SIZE);
        int payload_size = ntohs(ip->ip_len) - IP_HEADER_SIZE - ICMP_HEADER_SIZE;

        // Verify icmp packet
        if (icmp_resp->icmp_type != ICMP_ECHOREPLY || icmp_resp->icmp_id != getpid() || icmp_resp->icmp_seq != seq) {
            fprintf(stdout, "Packet %d: Invalid icmp packet\n", seq);
            continue;
        }

        // Print statistics
        double rtt = ((end.tv_sec - start.tv_sec) * 1000) + ((end.tv_usec - start.tv_usec) / 1000.0);
        fprintf(stdout, "Packet %d: Received icmp reply from %s (%d bytes in %0.2f ms)\n", seq, inet_ntoa(sender_addr.sin_addr), payload_size, rtt);
        received++;
    }

    // Print overall statistics
    fprintf(stdout, "\nPing statistics for %s:\n", argv[1]);
    fprintf(stdout, "Packets: Sent=%d, Received=%d, Lost=%d (%0.2f%% loss)\n", sent, received, sent - received, ((sent - received) * 100.0) / sent);

    // Close socket
    close(sockfd);

    return 0;
}