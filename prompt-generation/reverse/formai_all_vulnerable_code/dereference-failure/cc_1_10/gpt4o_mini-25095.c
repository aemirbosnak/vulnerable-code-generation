//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define DEFAULT_PORT 8080
#define NUM_OF_PINGS 5

typedef struct {
    char ip[INET_ADDRSTRLEN];
    int port;
    int response_time; // in milliseconds
    int packet_loss; // in percentage
} QoSStatistics;

void ping_server(const char *ip_addr, int port, QoSStatistics *qos) {
    struct sockaddr_in server_addr;
    int sockfd;
    char send_buff[BUFFER_SIZE];
    char recv_buff[BUFFER_SIZE];
    struct timespec start_time, end_time;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip_addr, &server_addr.sin_addr);

    int success_count = 0;

    for (int i = 0; i < NUM_OF_PINGS; i++) {
        clock_gettime(CLOCK_MONOTONIC, &start_time);

        sendto(sockfd, "Ping", strlen("Ping"), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
        recvfrom(sockfd, recv_buff, BUFFER_SIZE, 0, NULL, NULL);

        clock_gettime(CLOCK_MONOTONIC, &end_time);
        
        long time_taken = (end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_nsec - start_time.tv_nsec) / 1000000;
        qos->response_time += time_taken;

        if (strcmp(recv_buff, "Echo") == 0) {
            success_count++;
        }
        
        usleep(1000000); // Wait for 1 second before next ping
    }

    close(sockfd);
    
    if (NUM_OF_PINGS > 0) {
        qos->packet_loss = ((NUM_OF_PINGS - success_count) * 100) / NUM_OF_PINGS;
        qos->response_time /= success_count > 0 ? success_count : 1; // Avoid division by zero
    }
}

void print_QoS_statistics(QoSStatistics *qos) {
    printf("Quality of Service Statistics:\n");
    printf("IP Address: %s\n", qos->ip);
    printf("Port: %d\n", qos->port);
    printf("Average Response Time: %d ms\n", qos->response_time);
    printf("Packet Loss: %d%%\n", qos->packet_loss);
}

int main(int argc, char *argv[]) {
    QoSStatistics qos;
    
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS> <PORT>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strncpy(qos.ip, argv[1], sizeof(qos.ip));
    qos.port = atoi(argv[2]);
    qos.response_time = 0;
    qos.packet_loss = 0;

    printf("Monitoring Quality of Service...\n");
    
    ping_server(qos.ip, qos.port, &qos);
    print_QoS_statistics(&qos);

    return 0;
}