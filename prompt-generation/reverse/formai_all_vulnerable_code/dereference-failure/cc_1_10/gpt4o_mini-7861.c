//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>
#include <errno.h>

volatile sig_atomic_t stop_monitoring = 0;

void handle_sigint(int sig) {
    stop_monitoring = 1;
}

double calculate_latency(struct timeval start, struct timeval end) {
    double latency = (end.tv_sec - start.tv_sec) * 1000.0 + 
                     (end.tv_usec - start.tv_usec) / 1000.0; // milliseconds
    return latency;
}

void ping_host(const char *host, int interval) {
    char command[128];
    struct timeval start, end;
    int packets_sent = 0, packets_received = 0;

    while (!stop_monitoring) {
        gettimeofday(&start, NULL);
        
        // Execute ping command
        snprintf(command, sizeof(command), "ping -c 1 -W 1 %s > /dev/null 2>&1", host);
        int result = system(command);
        
        gettimeofday(&end, NULL);
        
        packets_sent++;
        
        if (result == 0) {
            packets_received++;
            double latency = calculate_latency(start, end);
            printf("Ping to %s successful! Latency: %.2f ms\n", host, latency);
        } else {
            printf("Ping to %s failed!\n", host);
        }
        
        printf("Packets sent: %d, Packets received: %d, Packet loss: %.2f%%\n", 
               packets_sent, packets_received, 
               100.0 * (packets_sent - packets_received) / packets_sent);
        
        sleep(interval);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <interval>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *host = argv[1];
    int interval = atoi(argv[2]);
    
    if (interval <= 0) {
        fprintf(stderr, "Interval must be a positive integer.\n");
        return EXIT_FAILURE;
    }

    printf("Starting QoS monitor for host: %s every %d seconds...\n", host, interval);
    
    // Set up signal handling for graceful termination
    signal(SIGINT, handle_sigint);
    
    ping_host(host, interval);
    
    printf("\nMonitoring stopped. Goodbye!\n");
    
    return EXIT_SUCCESS;
}