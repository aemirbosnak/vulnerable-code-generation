//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>

#define MAX_QOS 100
#define BUFFER_SIZE 1024

// Structure for Quality of Service info
typedef struct {
    char interface[IFNAMSIZ];
    float latency;   // in ms
    float jitter;    // in ms
    float packet_loss; // in percentage
} QoSInfo;

// Function to simulate the retrieval of network metrics
void get_qos_metrics(QoSInfo* qos) {
    qos->latency = (rand() % 100) + (rand() % 1000) / 1000.0; // Latency between 0 and 199.999 ms
    qos->jitter = (rand() % 50) + (rand() % 500) / 1000.0;     // Jitter between 0 and 49.999 ms
    qos->packet_loss = (rand() % 10) + (rand() % 1000) / 1000.0; // Packet loss between 0 and 9.999%
}

// Function to print QoS Metrics in a Cyberpunk style
void print_qos_info(QoSInfo* qos) {
    printf("\033[1;32m[Net-Node] QoS Metrics: \033[0m\n");
    printf("\033[1;34mInterface: \033[0m%s\n", qos->interface);
    printf("\033[1;35mLatency: \033[0m%.3f ms\n", qos->latency);
    printf("\033[1;33mJitter: \033[0m%.3f ms\n", qos->jitter);
    printf("\033[1;36mPacket Loss: \033[0m%.3f%%\n", qos->packet_loss);
    printf("\033[1;31m[Net-Node] Metrics Updated! \033[0m\n");
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "\033[1;31mUsage: %s <interface_name>\033[0m\n", argv[0]);
        return EXIT_FAILURE;
    }

    srand(time(NULL)); // Seed random number generator
    QoSInfo qos;
    strncpy(qos.interface, argv[1], IFNAMSIZ - 1); 
    qos.interface[IFNAMSIZ - 1] = '\0';

    while (1) {
        get_qos_metrics(&qos);
        print_qos_info(&qos);
        sleep(2); // Update every 2 seconds
    }
    return EXIT_SUCCESS;
}