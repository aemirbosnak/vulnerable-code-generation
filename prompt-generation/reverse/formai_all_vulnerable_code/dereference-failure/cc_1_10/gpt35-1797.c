//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: scientific
/*
 * C Network Quality of Service (QoS) Monitor Example Program
 * Author: AI Chatbot
 * Date: May 2021
 * Description: This program measures and reports the QoS of a network based on a set of defined metrics.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <math.h>

// Define maximum packet size
#define MAX_PKT_SIZE 65535
#define MAX_HOSTNAME_SIZE 1024

// Define struct to store statistics
struct stats {
    int packets_sent;
    int packets_received;
    float min_rtt;
    float max_rtt;
    float avg_rtt;
    float stddev_rtt;
};

// Function prototype for measuring RTT
double measure_rtt(struct timespec *begin, struct timespec *end);

// Function to compute statistics from measured RTTs
void compute_statistics(struct timespec *rtt, int packet_count, struct stats *statistics);

int main(int argc, char *argv[]) {
    // Initialize variables
    char hostname[MAX_HOSTNAME_SIZE];
    char ip[INET_ADDRSTRLEN];
    int packets_to_send = 10;
    int icmp_socket;
    int ttl = 64; // Time-to-live for ICMP packets
    struct sockaddr_in server_address;
    struct timespec rtt[packets_to_send];
    struct stats statistics = {0};
    struct hostent *host_info;
    double timeout = 3.0; // Default timeout

    // Check if hostname and number of packets are provided in command line arguments
    if (argc < 2) {
        printf("Usage: %s hostname [packets]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Set hostname and number of packets
    strncpy(hostname, argv[1], MAX_HOSTNAME_SIZE);
    if (argc > 2) {
        packets_to_send = atoi(argv[2]);
        if (packets_to_send <= 0) {
            printf("Invalid number of packets: %s\n", argv[2]);
            exit(EXIT_FAILURE);
        }
    }

    // Get IP address of hostname
    host_info = gethostbyname(hostname);
    if (host_info == NULL) {
        printf("Could not resolve hostname: %s\n", hostname);
        exit(EXIT_FAILURE);
    }
    inet_ntop(host_info->h_addrtype, host_info->h_addr_list[0], ip, INET_ADDRSTRLEN);

    // Create Internet Control Message Protocol (ICMP) socket
    icmp_socket = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (icmp_socket < 0) {
        perror("Error creating ICMP socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(icmp_socket, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) < 0) {
        perror("Error setting TTL option");
        exit(EXIT_FAILURE);
    }

    // Set timeout for recvfrom() function
    if (setsockopt(icmp_socket, SOL_SOCKET, SO_RCVTIMEO, (const char *)&timeout, sizeof(timeout)) < 0) {
        perror("Error setting recvfrom() timeout");
        exit(EXIT_FAILURE);
    }

    // Initialize server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(ip);

    // Loop through packets to send
    for (int i = 1; i <= packets_to_send; i++) {
        // Send ICMP echo request
        struct icmp *icmp_header;
        char packet[MAX_PKT_SIZE];
        memset(&packet, 0, sizeof(packet));
        icmp_header = (struct icmp *)packet;
        icmp_header->icmp_type = ICMP_ECHO;
        icmp_header->icmp_id = getpid();
        icmp_header->icmp_seq = i;
        icmp_header->icmp_cksum = 0;
        icmp_header->icmp_cksum = htons(~(ICMP_ECHO << 8));

        struct timespec begin, end;
        clock_gettime(CLOCK_MONOTONIC, &begin);

        if (sendto(icmp_socket, &packet, sizeof(packet), 0, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
            printf("Packet %d: Send Error\n", i);
            continue;
        }
        statistics.packets_sent++;

        // Receive ICMP echo reply
        struct sockaddr_in sender_address;
        socklen_t sender_address_len = sizeof(sender_address);
        char recv_packet[MAX_PKT_SIZE];
        memset(&recv_packet, 0, sizeof(recv_packet));
        if (recvfrom(icmp_socket, &recv_packet, sizeof(recv_packet), 0, (struct sockaddr *)&sender_address, &sender_address_len) < 0) {
            printf("Packet %d: Receive Error\n", i);
            continue;
        }

        // Measure RTT
        clock_gettime(CLOCK_MONOTONIC, &end);
        double rtt_sec = measure_rtt(&begin, &end);
        rtt[i-1].tv_sec = floor(rtt_sec);
        rtt[i-1].tv_nsec = (rtt_sec - rtt[i-1].tv_sec) * 1000000000;

        // Update statistics
        statistics.packets_received++;
        if (i == 1) {
            statistics.min_rtt = rtt_sec;
            statistics.max_rtt = rtt_sec;
            statistics.avg_rtt = rtt_sec;
            statistics.stddev_rtt = 0.0;
        } else {
            statistics.min_rtt = fmin(statistics.min_rtt, rtt_sec);
            statistics.max_rtt = fmax(statistics.max_rtt, rtt_sec);
            statistics.avg_rtt = ((statistics.avg_rtt * (i-1)) + rtt_sec) / i;
            double sum = 0.0;
            for (int j = 0; j < i; j++) {
                sum += pow((rtt[j].tv_sec + (rtt[j].tv_nsec / 1000000000.0)) - statistics.avg_rtt, 2);
            }
            statistics.stddev_rtt = sqrt(sum / i);
        }

        // Print packet information
        printf("Packet %d: %ld.%09ld seconds\n", i, rtt[i-1].tv_sec, rtt[i-1].tv_nsec);
    }

    // Compute statistics and print results
    compute_statistics(rtt, packets_to_send, &statistics);
    printf("\n--- %s ping statistics ---\n", hostname);
    printf("%d packets transmitted, %d received, %.0f%% packet loss\n", packets_to_send, statistics.packets_received, ((float)(statistics.packets_sent - statistics.packets_received) / statistics.packets_sent) * 100);
    printf("rtt min/avg/max/stddev = %.3f/%.3f/%.3f/%.3f seconds\n", statistics.min_rtt, statistics.avg_rtt, statistics.max_rtt, statistics.stddev_rtt);

    // Close socket
    close(icmp_socket);

    return 0;
}

// Function to measure RTT between two timespec structs
double measure_rtt(struct timespec *begin, struct timespec *end) {
    return (double)(end->tv_sec - begin->tv_sec) + ((double)(end->tv_nsec - begin->tv_nsec) / 1000000000.0);
}

// Function to compute statistics from measured RTTs
void compute_statistics(struct timespec *rtt, int packet_count, struct stats *statistics) {
    for (int i = 0; i < packet_count; i++) {
        double rtt_sec = rtt[i].tv_sec + (rtt[i].tv_nsec / 1000000000.0);
        if (i == 0) {
            statistics->min_rtt = rtt_sec;
            statistics->max_rtt = rtt_sec;
            statistics->avg_rtt = rtt_sec;
            statistics->stddev_rtt = 0.0;
        } else {
            statistics->min_rtt = fmin(statistics->min_rtt, rtt_sec);
            statistics->max_rtt = fmax(statistics->max_rtt, rtt_sec);
            statistics->avg_rtt = ((statistics->avg_rtt * i) + rtt_sec) / (i+1);
            double sum = 0.0;
            for (int j = 0; j <= i; j++) {
                sum += pow((rtt[j].tv_sec + (rtt[j].tv_nsec / 1000000000.0)) - statistics->avg_rtt, 2);
            }
            statistics->stddev_rtt = sqrt(sum / (i+1));
        }
    }
}