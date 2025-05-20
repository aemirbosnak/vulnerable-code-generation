//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <errno.h>

#define PACKET_COUNT 10
#define HOSTNAME "google.com"

double calculate_average(double* times, int count);
double calculate_variance(double* times, double average, int count);
void report_results(double* latencies, int count);

int main() {
    struct timeval start, end;
    double latencies[PACKET_COUNT];
    char command[256];
    int successful_pings = 0;

    printf("Network Quality of Service (QoS) Monitor\n");
    printf("Pinging %s for %d packets...\n", HOSTNAME, PACKET_COUNT);
    
    for (int i = 0; i < PACKET_COUNT; i++) {
        snprintf(command, sizeof(command), "ping -c 1 %s > /dev/null", HOSTNAME);
        
        gettimeofday(&start, NULL);
        if (system(command) == 0) {
            gettimeofday(&end, NULL);
            long elapsed_time = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
            latencies[i] = (double) elapsed_time;
            successful_pings++;
        } else {
            printf("Ping %d failed with error: %s\n", i + 1, strerror(errno));
            latencies[i] = -1.0;  // Mark failed pings
        }
        
        usleep(100000);  // Wait 100 milliseconds before next ping
    }
    
    report_results(latencies, PACKET_COUNT);
    printf("Total successful pings: %d out of %d\n", successful_pings, PACKET_COUNT);
    
    return 0;
}

void report_results(double* latencies, int count) {
    double sum = 0.0;
    double latency_values[count];
    int valid_count = 0;

    for (int i = 0; i < count; i++) {
        if (latencies[i] >= 0) {
            latency_values[valid_count++] = latencies[i];
            sum += latencies[i];
        }
    }

    if (valid_count > 0) {
        double average = calculate_average(latency_values, valid_count);
        double variance = calculate_variance(latency_values, average, valid_count);
        double jitter = (valid_count > 1) ? sqrt(variance) : 0.0;

        printf("Average Latency: %.2f ms\n", average);
        printf("Packet Loss: %.2f%%\n", (1.0 - ((double)valid_count / count)) * 100);
        printf("Jitter: %.2f ms\n", jitter);
    } else {
        printf("No successful pings to report!\n");
    }
}

double calculate_average(double* times, int count) {
    return (count > 0) ? (times[0] + times[1] + times[2] + (times[3] + times[4] + times[5] + times[6] + times[7] + times[8] + times[9])) / count : 0.0;
}

double calculate_variance(double* times, double average, int count) {
    double variance_sum = 0.0;
    for (int i = 0; i < count; i++) {
        variance_sum += (times[i] - average) * (times[i] - average);
    }
    return variance_sum / count;
}