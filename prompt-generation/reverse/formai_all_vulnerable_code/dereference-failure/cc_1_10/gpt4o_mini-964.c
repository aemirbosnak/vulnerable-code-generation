//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAX_PINGS 5
#define TIMEOUT 1
#define BUFFER_SIZE 64

typedef struct {
    char ip_address[16];
    int total_sent;
    int total_received;
    float packet_loss;
    float average_rtt;
    struct timespec response_times[MAX_PINGS];
} QosMonitor;

void initialize_monitor(QosMonitor *monitor, const char *ip) {
    strncpy(monitor->ip_address, ip, 16);
    monitor->total_sent = 0;
    monitor->total_received = 0;
    monitor->packet_loss = 0.0;
    monitor->average_rtt = 0.0;
    memset(monitor->response_times, 0, sizeof(monitor->response_times));
}

void calculate_statistics(QosMonitor *monitor) {
    monitor->packet_loss = (1.0f - ((float)monitor->total_received / monitor->total_sent)) * 100.0f;
    if (monitor->total_received > 0) {
        long total_rtt = 0;
        for (int i = 0; i < monitor->total_received; ++i) {
            total_rtt += (monitor->response_times[i].tv_sec * 1000) + (monitor->response_times[i].tv_nsec / 1000000);
        }
        monitor->average_rtt = total_rtt / monitor->total_received;
    }
}

int send_ping(const char *ip) {
    int sockfd;
    struct sockaddr_in addr;
    char buffer[BUFFER_SIZE];
    struct icmp *icmp_hdr;
    int sent, addr_len = sizeof(addr);

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return -1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);

    memset(buffer, 0, BUFFER_SIZE);
    icmp_hdr = (struct icmp *)buffer;
    icmp_hdr->icmp_type = ICMP_ECHO;
    icmp_hdr->icmp_seq = 1;
    icmp_hdr->icmp_id = getpid();
    sent = sendto(sockfd, buffer, sizeof(struct icmp), 0, (struct sockaddr *)&addr, addr_len);
    close(sockfd);

    return (sent == sizeof(struct icmp)) ? 0 : -1;
}

int receive_ping(QosMonitor *monitor) {
    int sockfd, addr_len, received;
    struct sockaddr_in addr;
    char buffer[BUFFER_SIZE];
    
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return -1;
    }

    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

    addr_len = sizeof(addr);
    received = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&addr, &addr_len);

    if (received > 0) {
        struct iphdr *ip_hdr = (struct iphdr *)buffer;
        struct icmp *icmp_hdr = (struct icmp *)(buffer + (ip_hdr->ihl * 4));

        if (icmp_hdr->icmp_type == ICMP_ECHOREPLY) {
            clock_gettime(CLOCK_MONOTONIC, &monitor->response_times[monitor->total_received]);
            monitor->total_received++;
        }
    }

    close(sockfd);
    return received;
}

void print_statistics(QosMonitor *monitor) {
    printf("\n--- Ping Statistics for %s ---\n", monitor->ip_address);
    printf("Packets Sent: %d, Packets Received: %d, Packet Loss: %.2f%%\n",
           monitor->total_sent, monitor->total_received, monitor->packet_loss);
    printf("Average Round Trip Time (RTT): %.2f ms\n", monitor->average_rtt);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ip_address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    QosMonitor monitor;
    initialize_monitor(&monitor, argv[1]);

    for (int i = 0; i < MAX_PINGS; i++) {
        monitor.total_sent++;
        if (send_ping(monitor.ip_address) == 0) {
            receive_ping(&monitor);
        }
        usleep(1000000); // wait for one second
    }

    calculate_statistics(&monitor);
    print_statistics(&monitor);
    
    return EXIT_SUCCESS;
}