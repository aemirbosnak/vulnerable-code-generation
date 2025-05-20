//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <time.h>

#define IPVERSION 4
#define TCPPROTOCOL 6
#define MAX_BUFFER_SIZE 2048

void log_qos_metrics(unsigned long num_packets, unsigned long total_bytes);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host_address> <port_number>\n", argv[0]);
        exit(1);
    }

    // Create a socket for sending TCP packets
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket creation failed");
        exit(1);
    }

    // Resolve the hostname to an IP address
    struct hostent *he = gethostbyname(argv[1]);
    if (he == NULL) {
        perror("failed to resolve hostname");
        close(sockfd);
        exit(1);
    }

    // Create a socket address structure
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(atoi(argv[2])),
        .sin_addr = *((struct in_addr *)he->h_addr)
    };
    memset(&server_addr.sin_zero, 0, sizeof(server_addr.sin_zero));

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connection failed");
        close(sockfd);
        exit(1);
    }

    // Send some packets and calculate the QoS metrics
    unsigned long num_packets = 0;
    unsigned long total_bytes = 0;
    char buffer[MAX_BUFFER_SIZE];
    ssize_t num_bytes;

    while ((num_bytes = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0) {
        if (write(sockfd, buffer, num_bytes) == -1) {
            perror("write failed");
            close(sockfd);
            exit(1);
        }

        num_packets++;
        total_bytes += num_bytes;
    }

    log_qos_metrics(num_packets, total_bytes);

    close(sockfd);
    return 0;
}

void log_qos_metrics(unsigned long num_packets, unsigned long total_bytes) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char timestamp[64];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm);

    double average_packet_size = (double)total_bytes / num_packets;
    double throughput = (double)total_bytes / (1024 * 1024);
    int packet_loss = (int)(100 - ((double)num_packets / num_packets) * 100);

    printf("[%s] Average Packet Size: %.2f bytes\n", timestamp, average_packet_size);
    printf("[%s] Throughput: %.2f Mbps\n", timestamp, throughput);
    printf("[%s] Packet Loss: %d%%\n", timestamp, packet_loss);
}