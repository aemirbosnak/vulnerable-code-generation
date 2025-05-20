//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <math.h>

#define BUFSIZE 1024

// Function to calculate the jitter
double calculate_jitter(int *delays, int num_delays) {
    double sum = 0;
    double sum_sq_diff = 0;
    double mean = 0;
    double jitter = 0;

    // Calculate the mean
    for (int i = 0; i < num_delays; i++) {
        sum += delays[i];
    }
    mean = sum / num_delays;

    // Calculate the sum of squared differences
    for (int i = 0; i < num_delays; i++) {
        sum_sq_diff += pow(delays[i] - mean, 2);
    }

    // Calculate the jitter
    jitter = sqrt(sum_sq_diff / num_delays);

    return jitter;
}

// Function to calculate the packet loss
double calculate_packet_loss(int num_packets_sent, int num_packets_received) {
    double packet_loss = 0;

    // Calculate the packet loss
    packet_loss = (1.0 - (double)num_packets_received / num_packets_sent) * 100.0;

    return packet_loss;
}

// Function to calculate the throughput
double calculate_throughput(int num_bytes_sent, double duration) {
    double throughput = 0;

    // Calculate the throughput
    throughput = (double)num_bytes_sent / duration / 1024 / 1024;

    return throughput;
}

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in servaddr;
    int num_packets_sent = 0;
    int num_packets_received = 0;
    int delays[BUFSIZE];
    int num_delays = 0;
    int num_bytes_sent = 0;
    double start_time = 0;
    double end_time = 0;
    double duration = 0;
    double jitter = 0;
    double packet_loss = 0;
    double throughput = 0;

    // Check the command line arguments
    if (argc != 3) {
        printf("Usage: %s <server_ip_address> <server_port>\n", argv[0]);
        exit(1);
    }

    // Create a UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Set the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    // Set the start time
    start_time = time(NULL);

    // Send and receive packets
    while (1) {
        char buf[BUFSIZE];
        int n;
        struct timeval tv;
        int delay;

        // Send a packet
        memset(buf, 0, sizeof(buf));
        sprintf(buf, "Hello, world! %d", num_packets_sent);
        n = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
        if (n < 0) {
            perror("sendto");
            exit(1);
        }

        // Receive a packet
        memset(buf, 0, sizeof(buf));
        n = recvfrom(sockfd, buf, sizeof(buf), 0, NULL, NULL);
        if (n < 0) {
            perror("recvfrom");
            exit(1);
        }

        // Calculate the delay
        gettimeofday(&tv, NULL);
        delay = (tv.tv_sec - start_time) * 1000 + (tv.tv_usec - start_time * 1000000) / 1000;
        delays[num_delays++] = delay;

        // Increment the number of packets sent and received
        num_packets_sent++;
        num_packets_received++;

        // Increment the number of bytes sent
        num_bytes_sent += n;

        // Calculate the duration
        end_time = time(NULL);
        duration = end_time - start_time;

        // Calculate the jitter
        jitter = calculate_jitter(delays, num_delays);

        // Calculate the packet loss
        packet_loss = calculate_packet_loss(num_packets_sent, num_packets_received);

        // Calculate the throughput
        throughput = calculate_throughput(num_bytes_sent, duration);

        // Print the statistics
        printf("Jitter: %.3f ms\n", jitter);
        printf("Packet loss: %.3f %%\n", packet_loss);
        printf("Throughput: %.3f Mbps\n", throughput);
    }

    // Close the socket
    close(sockfd);

    return 0;
}