//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>
#include <time.h>

#define MAX_MESSAGE_LEN 1024
#define MAX_PORT 65535
#define TIMEOUT_SEC 2

/* Struct to hold packet data */
typedef struct Packet {
    struct timeval timestamp;
    size_t length;
} Packet;

/* Global variables */
int sock_fd;
unsigned int num_packets_sent = 0;
unsigned int num_packets_received = 0;
unsigned long long total_packet_size = 0;
unsigned long long total_rtt_us = 0;
Packet packet_data[MAX_MESSAGE_LEN];

/* Signal handler for SIGINT */
void sigint_handler(int sig) {
    printf("\n--- Statistics ---\n");
    printf("%u packets transmitted, %u received, %.2f%% packet loss\n", num_packets_sent, num_packets_received, ((float)(num_packets_sent - num_packets_received) / num_packets_sent) * 100);
    printf("Average round-trip time: %.2f us\n", (float)total_rtt_us / num_packets_received);
    close(sock_fd);
    exit(0);
}

/* Function to calculate timestamp difference */
long long time_diff(struct timeval *start, struct timeval *end) {
    return ((end->tv_sec - start->tv_sec) * 1000000LL) + (end->tv_usec - start->tv_usec);
}

/* Function to calculate checksum of packet */
unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;
    
    for (sum = 0; len > 1; len -= 2) {
        sum += *buf++;
    }

    if (len == 1) {
        sum += *(unsigned char*)buf;
    }

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

/* Function to send packet */
int send_packet(int seq_num, struct sockaddr_in *dest_addr, size_t size) {
    num_packets_sent++;
    Packet pckt;
    pckt.length = size;
    gettimeofday(&pckt.timestamp, NULL);
    memcpy(&packet_data[seq_num], &pckt, sizeof(pckt));

    // Create packet
    char msg_buffer[MAX_MESSAGE_LEN];
    memset(msg_buffer, 0, sizeof(msg_buffer));
    snprintf(msg_buffer, sizeof(msg_buffer), "Ping!");

    // Add sequence number to packet
    char temp_msg_buffer[MAX_MESSAGE_LEN];
    memset(temp_msg_buffer, 0, sizeof(temp_msg_buffer));
    snprintf(temp_msg_buffer, sizeof(temp_msg_buffer), "%d:%s", seq_num, msg_buffer);

    // Calculate checksum
    unsigned short chksum_val = checksum(temp_msg_buffer, strlen(temp_msg_buffer));

    // Add checksum to packet
    char packet_buffer[MAX_MESSAGE_LEN];
    memset(packet_buffer, 0, sizeof(packet_buffer));
    snprintf(packet_buffer, sizeof(packet_buffer), "%d:%s:%d", seq_num, msg_buffer, chksum_val);

    if (sendto(sock_fd, packet_buffer, strlen(packet_buffer), 0, (struct sockaddr*)dest_addr, sizeof(*dest_addr)) < 0) {
        fprintf(stderr, "Failed to send packet: %s\n", strerror(errno));
        return -1;
    }

    return 0;
}

/* Function to receive packet */
int recv_packet(int seq_num, struct timeval *recv_time) {
    char recv_buffer[MAX_MESSAGE_LEN];
    memset(recv_buffer, 0, sizeof(recv_buffer));
    struct sockaddr_in src_addr;
    socklen_t addrlen = sizeof(src_addr);
    int packet_size = recvfrom(sock_fd, recv_buffer, sizeof(recv_buffer), 0, (struct sockaddr*)&src_addr, &addrlen);

    if (packet_size < 0) {
        fprintf(stderr, "Error receiving packet: %s\n", strerror(errno));
        return -1;
    }

    // Parse sequence number, message and checksum from packet
    char seq_num_str[10], msg_buffer[MAX_MESSAGE_LEN], chksum_str[10];
    memset(seq_num_str, 0, sizeof(seq_num_str));
    memset(msg_buffer, 0, sizeof(msg_buffer));
    memset(chksum_str, 0, sizeof(chksum_str));
    sscanf(recv_buffer, "%[^:]:%[^:]:%[^:]s", seq_num_str, msg_buffer, chksum_str);
    int packet_seq_num = atoi(seq_num_str);
    unsigned short chksum_val = atoi(chksum_str);

    // Verify checksum
    char temp_msg_buffer[MAX_MESSAGE_LEN];
    memset(temp_msg_buffer, 0, sizeof(temp_msg_buffer));
    snprintf(temp_msg_buffer, sizeof(temp_msg_buffer), "%d:%s", packet_seq_num, msg_buffer);
    unsigned short calc_chksum = checksum(temp_msg_buffer, strlen(temp_msg_buffer));

    if (chksum_val != calc_chksum) {
        fprintf(stderr, "Packet checksum mismatch for sequence number %d\n", packet_seq_num);
        return -1;
    }

    // Update statistics
    num_packets_received++;
    Packet pckt = packet_data[packet_seq_num];
    long long rtt_us = time_diff(&pckt.timestamp, recv_time);
    total_rtt_us += rtt_us;
    total_packet_size += pckt.length;

    return 0;
}

/* Function to run QoS test */
void run_qos_test(struct sockaddr_in *dest_addr) {
    struct timeval recv_time;
    int seq_num = 0;

    while (1) {
        // Send packet
        if (send_packet(seq_num, dest_addr, sizeof("Ping!")) < 0) {
            continue;
        }

        // Wait for response
        fd_set read_set;
        FD_ZERO(&read_set);
        FD_SET(sock_fd, &read_set);
        struct timeval timeout;
        timeout.tv_sec = TIMEOUT_SEC;
        timeout.tv_usec = 0;
        int retval = select(sock_fd + 1, &read_set, NULL, NULL, &timeout);

        // Timeout, resend packet
        if (retval == 0) {
            printf("Request timed out for sequence number %d\n", seq_num);
            continue;
        }

        // Error, skip packet
        if (retval < 0) {
            fprintf(stderr, "Error waiting for response: %s\n", strerror(errno));
            continue;
        }

        // Receive packet
        gettimeofday(&recv_time, NULL);
        if (recv_packet(seq_num, &recv_time) < 0) {
            continue;
        }

        // Increment sequence number
        seq_num++;
    }
}

int main(int argc, char **argv) {
    // Check arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }
    char *host = argv[1];
    int port = atoi(argv[2]);
    if (port < 1 || port > MAX_PORT) {
        fprintf(stderr, "Invalid port number: %d\n", port);
        exit(1);
    }

    // Create socket
    if ((sock_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        fprintf(stderr, "Failed to create socket: %s\n", strerror(errno));
        exit(1);
    }

    // Set signal handler for SIGINT
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = sigint_handler;
    if (sigaction(SIGINT, &sa, NULL) < 0) {
        fprintf(stderr, "Failed to set signal handler: %s\n", strerror(errno));
        close(sock_fd);
        exit(1);
    }

    // Set socket options
    int opt_val = 1;
    if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &opt_val, sizeof(opt_val)) < 0) {
        fprintf(stderr, "Failed to set socket option: %s\n", strerror(errno));
        close(sock_fd);
        exit(1);
    }

    // Set destination address
    struct hostent *he;
    if ((he = gethostbyname(host)) == NULL) {
        fprintf(stderr, "Failed to resolve hostname %s: %s\n", host, strerror(errno));
        exit(1);
    }
    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(port);
    dest_addr.sin_addr = *((struct in_addr*)he->h_addr);

    // Run QoS test
    run_qos_test(&dest_addr);

    return 0;
}