//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <time.h>

const int MIN_BANDWIDTH = 100000; // Minimum bandwidth in bits/sec
const int MAX_PACKET_SIZE = 1500; // Maximum packet size in bytes

int main(int argc, char *argv[]) {
    if(argc < 4) {
        fprintf(stderr, "Usage: %s <dst-ip> <dst-port> <packet-interval>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Parse command line arguments
    char* dst_ip = argv[1];
    int dst_port = atoi(argv[2]);
    int packet_interval = atoi(argv[3]);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set socket QoS options
    int qos = 0x08; // Expedited Forwarding (EF)
    if(setsockopt(sockfd, IPPROTO_IP, IP_TOS, &qos, sizeof(qos)) < 0) {
        perror("setsockopt");
    }

    // Set socket timeout to 1 second
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    if(setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("setsockopt");
    }

    // Initialize destination address
    struct sockaddr_in dst_addr;
    memset(&dst_addr, 0, sizeof(dst_addr));
    dst_addr.sin_family = AF_INET;
    if(inet_aton(dst_ip, &dst_addr.sin_addr) == 0) {
        perror("inet_aton");
        exit(EXIT_FAILURE);
    }
    dst_addr.sin_port = htons(dst_port);

    // Generate random data packet
    char data[MAX_PACKET_SIZE];
    srand(time(NULL));
    for(int i = 0; i < MAX_PACKET_SIZE; i++) {
        data[i] = rand() % 255;
    }

    // Start sending packets
    printf("Starting QoS monitor...\n");
    int seq_num = 0, bytes_sent = 0, bytes_rcvd = 0;
    time_t start = time(NULL);
    while(1) {
        // Send data packet
        int bytes = sendto(sockfd, data, sizeof(data), 0, 
            (struct sockaddr *)&dst_addr, sizeof(dst_addr));
        if(bytes < 0) {
            perror("sendto");
            exit(EXIT_FAILURE);
        }
        seq_num++;
        bytes_sent += bytes;

        // Receive ack
        char ack[MAX_PACKET_SIZE];
        int addrlen = sizeof(dst_addr);
        bytes = recvfrom(sockfd, ack, sizeof(ack), 0, 
            (struct sockaddr *)&dst_addr, &addrlen);

        // Calculate network throughput and packet loss rate
        if(bytes > 0) {
            bytes_rcvd += bytes;
            double elapsed_time = difftime(time(NULL), start);
            double throughput = bytes_rcvd / elapsed_time;
            double loss_rate = 1 - (seq_num * sizeof(data) / (double)bytes_sent);
            printf("Throughput = %lf bps, Loss rate = %lf\n", throughput * 8, loss_rate);
        }

        // Wait for next packet interval
        usleep(packet_interval);
    }

    return 0;
}