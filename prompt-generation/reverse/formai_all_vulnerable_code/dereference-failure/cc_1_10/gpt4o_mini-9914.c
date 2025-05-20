//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>

#define MAX_PINGS 10
#define BUFFER_SIZE 64

typedef struct {
    int total_pings;
    int pings_received;
    double total_latency;
    char target_ip[INET_ADDRSTRLEN]; 
} QoSMonitor;

void print_usage() {
    printf("Usage: qos_monitor <target_ip> <total_pings>\n");
}

void init_monitor(QoSMonitor *monitor, const char *target_ip, int total_pings) {
    strcpy(monitor->target_ip, target_ip);
    monitor->total_pings = total_pings;
    monitor->pings_received = 0;
    monitor->total_latency = 0.0;
}

double ping_server(const char *target_ip) {
    struct timespec start, end;
    char cmd[128];
    snprintf(cmd, sizeof(cmd), "ping -c 1 %s > /dev/null", target_ip);
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    int result = system(cmd);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    if (result != 0) {
        return -1; // ping failed
    }

    return (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec); // return latency in nanoseconds
}

void monitor_qos(QoSMonitor *monitor) {
    printf("Monitoring QoS for %s...\n", monitor->target_ip);
    
    for (int i = 0; i < monitor->total_pings; i++) {
        double latency = ping_server(monitor->target_ip);
        if (latency >= 0) {
            monitor->pings_received++;
            monitor->total_latency += latency;
            printf("Ping %d: Latency = %.2f ms\n", i + 1, latency / 1e6);
        } else {
            printf("Ping %d: Failed\n", i + 1);
        }
        sleep(1);
    }
    
    printf("\n--- QoS Statistics ---\n");
    printf("Total Pings: %d\n", monitor->total_pings);
    printf("Pings Received: %d\n", monitor->pings_received);
    if (monitor->pings_received > 0) {
        printf("Average Latency: %.2f ms\n", (monitor->total_latency / monitor->pings_received) / 1e6);
    } else {
        printf("Average Latency: N/A (all pings failed)\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    char *target_ip = argv[1];
    int total_pings = atoi(argv[2]);
    
    if (total_pings > MAX_PINGS || total_pings < 1) {
        printf("Error: Total pings must be between 1 and %d.\n", MAX_PINGS);
        return EXIT_FAILURE;
    }

    QoSMonitor monitor;
    init_monitor(&monitor, target_ip, total_pings);
    monitor_qos(&monitor);

    return EXIT_SUCCESS;
}