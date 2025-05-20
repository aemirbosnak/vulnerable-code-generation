//LLAMA2-13B DATASET v1.0 Category: CPU usage monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>

#define CPU_THRESHOLD 80
#define SAMPLING_RATE 1000

struct perf_data {
    int pid;
    int start_time;
    int end_time;
    int cpu_usage;
};

static void print_usage(struct perf_data *data) {
    char *format = "%5s %d.%03d%%";
    char buffer[256];
    snprintf(buffer, sizeof(buffer), format, "CPU", data->cpu_usage);
    printf(buffer);
}

static void get_cpu_usage(struct perf_data *data) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    data->end_time = ts.tv_sec;
    data->cpu_usage = (int)(((double)ts.tv_nsec * 1000000000.0) / (double)(data->end_time - data->start_time));
}

int main(int argc, char *argv[]) {
    int i, j, k;
    struct perf_data *data;

    if (argc < 2) {
        printf("Usage: %s <PID>\n", argv[0]);
        exit(1);
    }

    data = malloc(sizeof(struct perf_data) * (argc - 1));
    if (!data) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (i = 1; i < argc; i++) {
        data[i - 1].pid = atoi(argv[i]);
        data[i - 1].start_time = clock();
    }

    while (1) {
        for (i = 0; i < argc; i++) {
            get_cpu_usage(&data[i]);
            print_usage(&data[i]);
            usleep(SAMPLING_RATE * 1000);
        }
    }

    return 0;
}