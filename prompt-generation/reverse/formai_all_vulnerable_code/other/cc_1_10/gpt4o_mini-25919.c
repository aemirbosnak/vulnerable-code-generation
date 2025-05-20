//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define BUFFER_SIZE 1024
#define INTERFACE "eth0"

void obtain_ip_address(char *ip_address) {
    int fd;
    struct ifreq ifr;

    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    strncpy(ifr.ifr_name, INTERFACE, IFNAMSIZ - 1);
    ifr.ifr_name[IFNAMSIZ - 1] = '\0';

    if (ioctl(fd, SIOCGIFADDR, &ifr) < 0) {
        perror("IOCTL request failed");
        close(fd);
        exit(EXIT_FAILURE);
    }

    close(fd);
    struct sockaddr_in *addr = (struct sockaddr_in *)&ifr.ifr_addr;
    strcpy(ip_address, inet_ntoa(addr->sin_addr));
}

void print_network_quality(int packet_loss, int latency) {
    printf("Network Quality Metrics:\n");
    printf("Packet Loss: %d%%\n", packet_loss);
    printf("Latency: %d ms\n", latency);
    if (packet_loss > 0) {
        printf("Warning: Packet loss detected! Consider troubleshooting.\n");
    }
    if (latency > 100) {
        printf("Warning: High latency detected! Check your connection.\n");
    }
}

void simulate_packet_loss(int *packet_loss, int *latency) {
    // Simulate packet loss
    *packet_loss = rand() % 10; // Randomly between 0 and 9%
    // Simulate latency
    *latency = 50 + rand() % 200; // Latency between 50 and 249 ms
}

void monitor_qos() {
    char ip_address[INET_ADDRSTRLEN];
    int packet_loss, latency;

    obtain_ip_address(ip_address);
    printf("Monitoring QoS for IP Address: %s\n", ip_address);

    while (1) {
        simulate_packet_loss(&packet_loss, &latency);
        print_network_quality(packet_loss, latency);
        sleep(2); // Sleep for 2 seconds before the next check
    }
}

int main() {
    srand((unsigned int)time(NULL));
    monitor_qos();
    return 0;
}