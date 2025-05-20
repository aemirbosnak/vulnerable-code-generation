//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <time.h>

#define MAX_TRIES 10
#define BUFFER_SIZE 1024

void check_interface(const char *interface) {
    int sockfd;
    struct ifreq ifr;
    struct sockaddr_in addr;
    
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    strncpy(ifr.ifr_name, interface, IFNAMSIZ - 1);
    if (ioctl(sockfd, SIOCGIFADDR, &ifr) < 0) {
        perror("ioctl");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    memcpy(&addr, &ifr.ifr_addr, sizeof(addr));
    close(sockfd);

    printf("Monitoring interface: %s\n", interface);
    printf("IP Address: %s\n", inet_ntoa(addr.sin_addr));
}

double calculate_latency(const char *host) {
    struct timespec start, end;
    char command[BUFFER_SIZE];
    double latency;

    snprintf(command, sizeof(command), "ping -c 1 -W 1 %s > /dev/null", host);
    clock_gettime(CLOCK_MONOTONIC, &start);
    system(command);
    clock_gettime(CLOCK_MONOTONIC, &end);

    latency = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    return latency / 1e6; // convert to milliseconds
}

double calculate_packet_loss(const char *host) {
    char command[BUFFER_SIZE];
    double loss_percentage = 0.0;

    snprintf(command, sizeof(command), "ping -c %d %s | grep 'loss' | awk -F',' '{print $3}' | awk '{print $1}'", MAX_TRIES, host);
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        perror("popen");
        return -1;
    }
    
    fscanf(fp, "%lf", &loss_percentage);
    pclose(fp);
    return loss_percentage;
}

double calculate_jitter(const char *host) {
    double latencies[MAX_TRIES];
    double jitter = 0.0;
    double latency;

    for(int i = 0; i < MAX_TRIES; i++) {
        latency = calculate_latency(host);
        if (latency < 0) return -1;

        latencies[i] = latency;
        usleep(100000); // wait for 100 ms before next ping
    }

    for (int i = 1; i < MAX_TRIES; i++) {
        jitter += (latencies[i] - latencies[i - 1]) * (latencies[i] - latencies[i - 1]);
    }
    
    return sqrt(jitter / (MAX_TRIES - 1)); // standard deviation as jitter
}

void monitor_qos(const char *interface, const char *host) {
    check_interface(interface);

    double packet_loss = calculate_packet_loss(host);
    double latency = calculate_latency(host);
    double jitter = calculate_jitter(host);

    printf("\n--- QoS Metrics for %s ---\n", host);
    printf("Packet Loss: %.2f%%\n", packet_loss);
    printf("Latency: %.2f ms\n", latency);
    printf("Jitter: %.2f ms\n", jitter);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <interface> <host>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *interface = argv[1];
    const char *host = argv[2];

    monitor_qos(interface, host);

    return EXIT_SUCCESS;
}