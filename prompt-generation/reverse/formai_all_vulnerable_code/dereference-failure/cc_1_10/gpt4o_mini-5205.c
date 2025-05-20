//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define MAX_PINGS 10
#define BUFFER_SIZE 64

typedef struct {
    int packet_sent;
    int packet_received;
    double total_time;
} QoS;

void print_usage() {
    printf("Usage: qos_monitor <hostname> <number_of_pings>\n");
}

void calculate_qos(QoS *qos) {
    printf("\n--- QoS Statistics ---\n");
    printf("Packets Sent: %d\n", qos->packet_sent);
    printf("Packets Received: %d\n", qos->packet_received);
    
    if (qos->packet_sent > 0) {
        double loss_rate = ((qos->packet_sent - qos->packet_received) / (double)qos->packet_sent) * 100;
        printf("Packet Loss: %.2f%%\n", loss_rate);
        
        double avg_time = qos->total_time / qos->packet_received;
        printf("Average Response Time: %.2f ms\n", avg_time);
    }
}

double ping_host(const char *ip_address) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    struct timespec start, end;
    
    sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return -1;
    }
    
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = 0;
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    // Set up ICMP echo request
    const char *ping_data = "Ping";
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    sendto(sockfd, ping_data, strlen(ping_data), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
    
    recvfrom(sockfd, buffer, BUFFER_SIZE, 0, NULL, NULL);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    close(sockfd);
    
    double response_time = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1000000.0;
    
    return response_time;
}

void monitor_qos(const char *hostname, int num_pings) {
    QoS qos = {0, 0, 0.0};
    char ip_address[INET_ADDRSTRLEN];

    struct sockaddr_in sa;
    inet_pton(AF_INET, hostname, &(sa.sin_addr));
    
    // Get the failed-to-reach address
    if (inet_ntop(AF_INET, &(sa.sin_addr), ip_address, sizeof(ip_address)) == NULL) {
        perror("Invalid IP address");
        return;
    }
    
    for (int i = 0; i < num_pings; i++) {
        qos.packet_sent++;
        double response_time = ping_host(ip_address);
        
        if (response_time >= 0) {
            qos.packet_received++;
            printf("Reply from %s: Time=%.2f ms\n", ip_address, response_time);
            qos.total_time += response_time;
        } else {
            printf("Request timed out.\n");
        }
        
        sleep(1);  // Delay between pings
    }
    
    calculate_qos(&qos);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }
    
    const char *hostname = argv[1];
    int num_pings = atoi(argv[2]);
    
    if (num_pings <= 0 || num_pings > MAX_PINGS) {
        printf("Please enter a valid number of pings (1 - %d)\n", MAX_PINGS);
        return EXIT_FAILURE;
    }
    
    monitor_qos(hostname, num_pings);
    return EXIT_SUCCESS;
}