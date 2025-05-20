//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_PACKET_SIZE 65536

struct packet {
    int seq_num;
    struct timeval send_time;
    char data[MAX_BUFFER_SIZE];
};

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <ip address> <port number> <packet loss rate>\n", argv[0]);
        exit(1);
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);
    float packet_loss_probability = atof(argv[3]);

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("Error setting socket options");
        exit(1);
    }

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(ip_address);
    servaddr.sin_port = htons(port_number);

    int seq_num = 0;
    int total_packets_sent = 0;
    int total_packets_recieved = 0;
    int total_packets_lost = 0;
    int total_bytes_sent = 0;
    int total_bytes_recieved = 0;
    int bytes_sent;
    char buffer[MAX_BUFFER_SIZE];
    struct packet packet_buffer[MAX_PACKET_SIZE];
    struct timeval start_time, end_time;

    gettimeofday(&start_time, NULL);

    while (1) {
        struct packet p;
        p.seq_num = seq_num;
        gettimeofday(&p.send_time, NULL);
        sprintf(p.data, "Packet %d", seq_num);

        if (((float)rand() / RAND_MAX) >= packet_loss_probability) {
            printf("Sending Packet %d\n", seq_num);
            bytes_sent = sendto(sockfd, &p, sizeof(p), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
            if (bytes_sent < 0) {
                perror("Error sending packet");
                exit(1);
            }
            total_packets_sent++;
            total_bytes_sent += bytes_sent;
            packet_buffer[seq_num] = p;
        } else {
            printf("Packet %d lost\n", seq_num);
            total_packets_lost++;
        }

        if (recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL) < 0) {
            printf("Timed out waiting for ACK\n");
        } else {
            printf("Received ACK for Packet %d\n", seq_num);
            total_packets_recieved++;
            total_bytes_recieved += sizeof(struct packet);
        }

        seq_num++;

        if (seq_num >= MAX_PACKET_SIZE) {
            seq_num = 0;
            gettimeofday(&end_time, NULL);
            break;
        }
    }

    close(sockfd);

    float seconds = end_time.tv_sec - start_time.tv_sec + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;

    float throughput = ((float)total_bytes_sent / seconds) / 1000000.0;
    float loss_rate = (float)total_packets_lost / (total_packets_sent + total_packets_lost);
    float delay = ((float)total_bytes_recieved / (float)(total_packets_recieved * sizeof(struct packet))) * 1000.0;

    printf("\n--- QoS Report ---\n");
    printf("Duration: %.2f seconds\n", seconds);
    printf("Total Packets Sent: %d\n", total_packets_sent);
    printf("Total Packets Received: %d\n", total_packets_recieved);
    printf("Total Packets Lost: %d\n", total_packets_lost);
    printf("Throughput: %.2f Mbps\n", throughput);
    printf("Loss Rate: %.2f%%\n", loss_rate * 100);
    printf("Average Delay: %.2f ms\n", delay);

    return 0;
}