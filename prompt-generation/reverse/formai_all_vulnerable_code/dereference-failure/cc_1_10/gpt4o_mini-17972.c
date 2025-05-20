//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <errno.h>

#define MAX_PINGS 100
#define LOG_FILE "qos_log.txt"

void log_results(const char *target, int ping_count, double *latencies, int failures) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        printf("Could not open log file: %s\n", strerror(errno));
        return;
    }
    
    fprintf(log_file, "QoS Results for %s\n", target);
    fprintf(log_file, "Pings Sent: %d, Losses: %d\n", ping_count, failures);
    
    double total_lat = 0.0;
    int successful_pings = ping_count - failures;
    for (int i = 0; i < successful_pings; i++) {
        total_lat += latencies[i];
    }
    
    if (successful_pings > 0) {
        double average_lat = total_lat / successful_pings;
        fprintf(log_file, "Average Latency: %.2f ms\n", average_lat);
    } else {
        fprintf(log_file, "All pings failed.\n");
    }

    fclose(log_file);
}

double get_ping_time(const char *target) {
    struct timeval start, end;
    char command[100];
    snprintf(command, sizeof(command), "ping -c 1 -W 1 %s > /dev/null", target);
    
    gettimeofday(&start, NULL);
    int result = system(command);
    gettimeofday(&end, NULL);
    
    if(result != 0) {
        return -1.0; // Indicates failure
    }
    
    double latency = (end.tv_sec - start.tv_sec) * 1000.0; // seconds to ms
    latency += (end.tv_usec - start.tv_usec) / 1000.0; // microseconds to ms
    return latency;
}

void monitor_qos(const char *target, int count) {
    double latencies[MAX_PINGS];
    int failures = 0;
    
    for (int i = 0; i < count; i++) {
        latencies[i] = get_ping_time(target);
        if (latencies[i] < 0) {
            printf("Ping failed to %s\n", target);
            failures++;
        } else {
            printf("Response from %s: %.2f ms\n", target, latencies[i]);
        }
        sleep(1); // Wait a second between pings
    }

    log_results(target, count, latencies, failures);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <target_ip> <number_of_pings>\n", argv[0]);
        return 1;
    }
    
    const char *target_ip = argv[1];
    int ping_count = atoi(argv[2]);
    
    if (ping_count <= 0 || ping_count > MAX_PINGS) {
        printf("Please specify a valid number of pings (1-%d).\n", MAX_PINGS);
        return 1;
    }

    printf("Starting QoS monitor for %s with %d pings...\n", target_ip, ping_count);
    monitor_qos(target_ip, ping_count);
    
    printf("QoS Monitoring completed. Results saved in %s\n", LOG_FILE);
    return 0;
}