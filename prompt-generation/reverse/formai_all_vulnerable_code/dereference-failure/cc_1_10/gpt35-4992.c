//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define MAX_BUFFER_SIZE 1024

struct QoS_Data {
    int packet_count;
    float avg_delay;
    float avg_jitter;
};

volatile sig_atomic_t running = 1;

void signal_handler(int signum) {
    running = 0;
}

void print_QoS_Data(struct QoS_Data *data) {
    printf("Packet count: %d\n", data->packet_count);
    printf("Average delay: %.2f ms\n", data->avg_delay);
    printf("Average jitter: %.2f ms\n", data->avg_jitter);
}

void monitor_QoS(int socket_fd, struct sockaddr_in server_addr, int interval) {
    struct QoS_Data data = {0, 0, 0};
    
    while (running) {
        struct timeval send_time, recv_time;
        char buffer[MAX_BUFFER_SIZE] = {0};
        int buffer_size = sizeof(buffer);
        
        // Send packet to server
        gettimeofday(&send_time, NULL);
        if (sendto(socket_fd, buffer, buffer_size, 0, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
            perror("Error sending packet to server");
            exit(1);
        }
        
        // Receive echoed packet from server
        socklen_t server_addr_len = sizeof(server_addr);
        if (recvfrom(socket_fd, buffer, buffer_size, 0, (struct sockaddr *)&server_addr, &server_addr_len) == -1) {
            perror("Error receiving packet from server");
            exit(1);
        }
        gettimeofday(&recv_time, NULL);
        
        // Calculate delay and jitter
        float delay = 1000 * ((recv_time.tv_sec - send_time.tv_sec) * 1000 + (recv_time.tv_usec - send_time.tv_usec) / 1000.0);
        float jitter = (data.avg_jitter * data.packet_count + abs(delay - data.avg_delay)) / (data.packet_count + 1);
        
        // Update QoS data
        data.packet_count += 1;
        data.avg_delay = (data.avg_delay * (data.packet_count - 1) + delay) / data.packet_count;
        data.avg_jitter = jitter;
        
        // Print QoS data
        print_QoS_Data(&data);
        
        // Wait for interval duration
        sleep(interval);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <server IP address> <server port number> <monitoring interval>\n", argv[0]);
        exit(1);
    }
    
    int server_port = atoi(argv[2]);
    if (server_port == 0) {
        printf("Invalid port number\n");
        exit(1);
    }
    
    int monitoring_interval = atoi(argv[3]);
    if (monitoring_interval <= 0) {
        printf("Invalid monitoring interval\n");
        exit(1);
    }
    
    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        printf("Invalid IP address\n");
        exit(1);
    }
    
    int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socket_fd == -1) {
        perror("Error creating socket");
        exit(1);
    }
    
    // Register signal handler for SIGINT and SIGTERM
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);
    
    monitor_QoS(socket_fd, server_addr, monitoring_interval);
    
    close(socket_fd);
    
    return 0;
}