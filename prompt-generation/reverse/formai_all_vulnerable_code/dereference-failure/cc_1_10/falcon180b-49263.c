//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SAMPLES 100

typedef struct {
    time_t timestamp;
    size_t ram_usage;
} RamUsageSample;

static RamUsageSample samples[MAX_SAMPLES];
static int sample_count = 0;

static void log_ram_usage() {
    size_t total_ram_usage = 0;

    for (int i = 0; i < sample_count; i++) {
        total_ram_usage += samples[i].ram_usage;
    }

    printf("Total RAM usage: %zu bytes\n", total_ram_usage);
}

static void add_sample() {
    if (sample_count >= MAX_SAMPLES) {
        return;
    }

    size_t ram_usage = malloc_usable_size(0);

    samples[sample_count].timestamp = time(NULL);
    samples[sample_count].ram_usage = ram_usage;

    sample_count++;
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < 100000; i++) {
        int* ptr = malloc(rand() % 1024);
        memset(ptr, 0, rand() % 1024);
        free(ptr);

        add_sample();
    }

    log_ram_usage();

    return 0;
}