//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define INTERFACE "eth0"
#define MONITOR_INTERVAL 5

void get_network_quality(float *packet_loss, float *latency) {
    // Simulates network quality monitoring
    // In a real application, actual ping tests and packet statistics would be gathered

    // Simulating random packet loss and latency
    *packet_loss = (float)(rand() % 100) / 100.0; // Packet loss 0% to 100%
    *latency = (float)(rand() % 100); // Latency 0ms to 100ms
}

void print_network_report(float packet_loss, float latency) {
    printf("\n--- Network Quality Report ---\n");
    printf("Packet Loss: %.2f%%\n", packet_loss * 100);
    printf("Latency: %.2f ms\n", latency);
    printf("------------------------------\n");
}

void get_interface_ip(const char *iface) {
    struct ifreq ifr;
    int sock = socket(AF_INET, SOCK_DGRAM, 0);

    if (sock < 0) {
        perror("Socket error");
        exit(EXIT_FAILURE);
    }

    strncpy(ifr.ifr_name, iface, IFNAMSIZ-1);
    ioctl(sock, SIOCGIFADDR, &ifr);
    
    close(sock);
    
    struct sockaddr_in *ipaddr = (struct sockaddr_in *)&ifr.ifr_addr;
    printf("Interface %s IP: %s\n", iface, inet_ntoa(ipaddr->sin_addr));
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    // Get IP address of the interface
    get_interface_ip(INTERFACE);

    while (1) {
        float packet_loss, latency;
        get_network_quality(&packet_loss, &latency);
        print_network_report(packet_loss, latency);
        
        sleep(MONITOR_INTERVAL); // Sleep for defined interval
    }

    return 0;
}