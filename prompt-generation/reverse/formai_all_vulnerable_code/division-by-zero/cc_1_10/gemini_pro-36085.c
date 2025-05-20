//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/time.h>

// Measuring time
uint64_t get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (uint64_t)tv.tv_sec * 1000000 + tv.tv_usec;
}

// Busy looping
void delay(uint64_t duration) {
    uint64_t start = get_time();
    while (get_time() - start < duration) ;
}

// Main
int main() {
    uint64_t durations[10] = {0};
    int i, j, k;

    for (i = 0; i < sizeof(durations) / sizeof(durations[0]); i += 2) {
        uint64_t start = get_time();
        int x = 0;
        while (get_time() - start < 2000000) {
            x += 1;
        }
        durations[i] = get_time() - start;
        durations[i+1] = x;
    }

    printf("Loaded\n");

    // Pick the least three values
    uint64_t min_durations[3] = {0};
    for (i = 0; i < sizeof(min_durations) / sizeof(min_durations[0]); i++) {
        min_durations[i] = durations[i];
    }

    for (i = sizeof(min_durations) / sizeof(min_durations[0]); i < sizeof(durations) / sizeof(durations[0]); i++) {
        for (j = 0; j < sizeof(min_durations) / sizeof(min_durations[0]); j++) {
            if (durations[i] < min_durations[j]) {
                for (k = sizeof(min_durations) / sizeof(min_durations[0]) - 1; k > j; k--) {
                    min_durations[k] = min_durations[k-1];
                }
                min_durations[j] = durations[i];
                break;
            }
        }
    }

    uint64_t sum_duration = 0;
    for (i = 0; i < sizeof(min_durations) / sizeof(min_durations[0]); i++) {
        sum_duration += min_durations[i];
    }

    uint64_t iops = min_durations[0] * min_durations[1] / sum_duration;
    double speed = iops / 1000.0 / 1000.0;

    printf("Speed: %.2f MB/s\n", speed);

    return 0;
}