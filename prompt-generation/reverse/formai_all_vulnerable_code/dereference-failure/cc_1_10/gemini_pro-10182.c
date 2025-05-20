//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_SIZE 1024

// Function to calculate the checksum of a packet
unsigned short checksum(unsigned short *buf, int nwords)
{
    unsigned long sum;
    for (sum = 0; nwords > 0; nwords--)
    {
        sum += *buf++;
        if (sum & 0x80000000)
            sum = (sum & 0xFFFF) + (sum >> 16);
    }
    return ~(sum & 0xFFFF);
}

// Function to create a ping packet
char *create_ping_packet(unsigned short id, unsigned short seq)
{
    char *packet = malloc(MAX_SIZE);
    memset(packet, 0, MAX_SIZE);

    // ICMP header
    packet[0] = 8; // ICMP type (echo request)
    packet[1] = 0; // ICMP code
    packet[2] = 0; // ICMP checksum (will be calculated later)
    packet[3] = 0; // ICMP identifier
    packet[4] = id >> 8; // ICMP sequence number (high byte)
    packet[5] = id & 0xFF; // ICMP sequence number (low byte)
    packet[6] = seq >> 8; // ICMP timestamp (high byte)
    packet[7] = seq & 0xFF; // ICMP timestamp (low byte)

    // Payload
    for (int i = 8; i < MAX_SIZE; i++)
    {
        packet[i] = i;
    }

    // Calculate the checksum
    unsigned short *buf = (unsigned short *)packet;
    int nwords = MAX_SIZE / 2;
    packet[2] = checksum(buf, nwords);

    return packet;
}

// Function to send a ping packet
int send_ping_packet(int sockfd, struct sockaddr_in *addr, char *packet, int len)
{
    int n = sendto(sockfd, packet, len, 0, (struct sockaddr *)addr, sizeof(struct sockaddr_in));
    if (n < 0)
    {
        perror("sendto");
        return -1;
    }
    return n;
}

// Function to receive a ping packet
int receive_ping_packet(int sockfd, struct sockaddr_in *addr, char *packet, int len)
{
    int n = recvfrom(sockfd, packet, len, 0, (struct sockaddr *)addr, (socklen_t *)sizeof(struct sockaddr_in));
    if (n < 0)
    {
        perror("recvfrom");
        return -1;
    }
    return n;
}

// Function to print the ping statistics
void print_ping_statistics(int sent, int received, double min_rtt, double max_rtt, double avg_rtt)
{
    printf("Ping statistics:\n");
    printf("  Packets sent: %d\n", sent);
    printf("  Packets received: %d\n", received);
    printf("  Packet loss: %d%% (%d packets lost)\n", (sent - received) * 100 / sent, sent - received);
    printf("  Minimum RTT: %f ms\n", min_rtt);
    printf("  Maximum RTT: %f ms\n", max_rtt);
    printf("  Average RTT: %f ms\n", avg_rtt);
}

// Main function
int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s <destination_ip> <num_packets>\n", argv[0]);
        return 1;
    }

    // Get the destination IP address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0)
    {
        perror("socket");
        return 1;
    }

    // Set the IP header options
    int optval = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &optval, sizeof(optval)) < 0)
    {
        perror("setsockopt");
        return 1;
    }

    // Get the number of packets to send
    int num_packets = atoi(argv[2]);

    // Send the ping packets
    int sent = 0, received = 0;
    double min_rtt = 99999999.0, max_rtt = 0.0, avg_rtt = 0.0;
    for (int i = 0; i < num_packets; i++)
    {
        // Create the ping packet
        char *packet = create_ping_packet(i, i);

        // Send the ping packet
        if (send_ping_packet(sockfd, &addr, packet, MAX_SIZE) < 0)
        {
            perror("send_ping_packet");
            continue;
        }
        sent++;

        // Receive the ping packet
        char recv_packet[MAX_SIZE];
        struct sockaddr_in recv_addr;
        socklen_t recv_addr_len = sizeof(struct sockaddr_in);
        clock_t start = clock();
        int n = receive_ping_packet(sockfd, &recv_addr, recv_packet, MAX_SIZE);
        clock_t end = clock();
        if (n < 0)
        {
            perror("receive_ping_packet");
            continue;
        }
        received++;

        // Calculate the RTT
        double rtt = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;

        // Update the ping statistics
        if (rtt < min_rtt)
            min_rtt = rtt;
        if (rtt > max_rtt)
            max_rtt = rtt;
        avg_rtt += rtt;

        // Free the packet
        free(packet);
    }

    // Close the socket
    close(sockfd);

    // Print the ping statistics
    print_ping_statistics(sent, received, min_rtt, max_rtt, avg_rtt / received);

    return 0;
}