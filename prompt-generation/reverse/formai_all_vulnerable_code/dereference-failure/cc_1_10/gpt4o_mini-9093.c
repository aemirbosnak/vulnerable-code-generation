//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <time.h>

#define BUFFER_SIZE 1024

// Function prototypes
void print_usage(const char *prog_name);
void monitor_network(const char *interface, int duration);
void get_network_statistics(const char *interface, float *packet_loss, float *latency, float *bandwidth);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *interface = argv[1];
    int duration = atoi(argv[2]);

    if (duration <= 0) {
        fprintf(stderr, "Duration must be a positive integer.\n");
        exit(EXIT_FAILURE);
    }

    monitor_network(interface, duration);

    return 0;
}

void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <interface> <duration>\n", prog_name);
}

void monitor_network(const char *interface, int duration) {
    float packet_loss, latency, bandwidth;
    time_t start_time = time(NULL);
    
    printf("Monitoring network QoS on interface: %s for %d seconds...\n", interface, duration);
    
    while (difftime(time(NULL), start_time) < duration) {
        get_network_statistics(interface, &packet_loss, &latency, &bandwidth);
        
        printf("Packet Loss: %.2f%%, Latency: %.2f ms, Bandwidth: %.2f Kbps\n",
               packet_loss, latency, bandwidth);
        sleep(1); // Monitor every second
    }
}

void get_network_statistics(const char *interface, float *packet_loss, float *latency, float *bandwidth) {
    struct ifreq ifr;
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Fetch interface statistics
    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, interface, IFNAMSIZ - 1);
    if (ioctl(sockfd, SIOCGIFMTU, &ifr) < 0) {
        perror("IOCTL error");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Simulate QoS values for demonstration purposes
    *packet_loss = rand() % 10; // Random packet loss between 0-9%
    *latency = (rand() % 100) + 1; // Random latency between 1-100 ms
    *bandwidth = (rand() % 10000) + 1000; // Random bandwidth between 1000-11000 Kbps
    
    close(sockfd);
}