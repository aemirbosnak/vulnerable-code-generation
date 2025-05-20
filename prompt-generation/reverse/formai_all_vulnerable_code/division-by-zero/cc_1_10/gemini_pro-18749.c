//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: scalable
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define INTERVAL 1 // in seconds

typedef struct {
    time_t last_time;
    unsigned long last_total;
    unsigned long last_idle;
} cpu_info_t;

static cpu_info_t cpu_info = {0};

static unsigned long read_cpu_usage(void) {
    char buf[4096];
    FILE *fp = fopen("/proc/stat", "r");

    if (fp == NULL) {
        return 0;
    }

    while (fgets(buf, sizeof(buf), fp) != NULL) {
        if (strncmp(buf, "cpu ", 4) == 0) {
            unsigned long total, idle, user, nice, system, irq, softirq, steal, guest, guest_nice;
            sscanf(buf, "cpu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu", &total, &idle, &user, &nice, &system, &irq, &softirq, &steal, &guest, &guest_nice);
            return total - idle;
        }
    }

    fclose(fp);
    return 0;
}

static void update_cpu_usage(void) {
    cpu_info.last_time = time(NULL);
    cpu_info.last_total = read_cpu_usage();
    cpu_info.last_idle = cpu_info.last_total - read_cpu_usage();
}

static float get_cpu_usage(void) {
    unsigned long total, idle, usage;

    total = read_cpu_usage();
    idle = total - read_cpu_usage();
    usage = total - cpu_info.last_total;
    usage -= idle - cpu_info.last_idle;
    usage = (usage * 1000) / (total - cpu_info.last_total);

    return usage / 1000.0;
}

static void print_cpu_usage(void) {
    printf("CPU usage: %.1f%%\n", get_cpu_usage());
}

int main(void) {
    update_cpu_usage();

    while (1) {
        sleep(INTERVAL);
        update_cpu_usage();
        print_cpu_usage();
    }

    return 0;
}