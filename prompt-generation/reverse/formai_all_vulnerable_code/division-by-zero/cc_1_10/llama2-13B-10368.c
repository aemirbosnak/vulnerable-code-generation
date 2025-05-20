//LLAMA2-13B DATASET v1.0 Category: CPU usage monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/time.h>
#include <math.h>

#define CPU_THRESHOLD 80
#define CPU_SAMPLING_RATE 1000

struct cpu_usage {
    unsigned long long total;
    unsigned long long idle;
    unsigned long long user;
    unsigned long long nice;
    unsigned long long system;
    unsigned long long idle_time;
    unsigned long long last_sample;
};

static void init_cpu_usage(struct cpu_usage *cpu) {
    memset(cpu, 0, sizeof(*cpu));
    cpu->total = 0;
    cpu->idle = 0;
    cpu->user = 0;
    cpu->nice = 0;
    cpu->system = 0;
    cpu->idle_time = 0;
    cpu->last_sample = 0;
}

static void update_cpu_usage(struct cpu_usage *cpu) {
    unsigned long long now;
    unsigned long long delta;

    now = syscall(SYS_time);
    delta = now - cpu->last_sample;
    cpu->last_sample = now;

    cpu->total += delta;
    cpu->idle += delta;
    cpu->user += (delta - cpu->idle) * (cpu->user / 100);
    cpu->nice += (delta - cpu->idle) * (cpu->nice / 100);
    cpu->system += (delta - cpu->idle) * (cpu->system / 100);

    cpu->idle_time += delta;

    if (cpu->idle_time >= CPU_SAMPLING_RATE) {
        cpu->idle_time -= CPU_SAMPLING_RATE;
        cpu->total -= CPU_SAMPLING_RATE;
        cpu->user -= CPU_SAMPLING_RATE * (cpu->user / 100);
        cpu->nice -= CPU_SAMPLING_RATE * (cpu->nice / 100);
        cpu->system -= CPU_SAMPLING_RATE * (cpu->system / 100);
    }
}

static void print_cpu_usage(struct cpu_usage *cpu) {
    printf("CPU Usage:\n");
    printf("  Total: %llu\n", cpu->total);
    printf("  Idle: %llu\n", cpu->idle);
    printf("  User: %llu (%2.2f%%)\n", cpu->user,
            (cpu->user * 100) / cpu->total);
    printf("  Nice: %llu (%2.2f%%)\n", cpu->nice,
            (cpu->nice * 100) / cpu->total);
    printf("  System: %llu (%2.2f%%)\n", cpu->system,
            (cpu->system * 100) / cpu->total);
    printf("  Idle Time: %llu\n", cpu->idle_time);
}

int main(void) {
    struct cpu_usage cpu;

    init_cpu_usage(&cpu);

    while (1) {
        update_cpu_usage(&cpu);
        print_cpu_usage(&cpu);

        if (cpu.idle_time >= CPU_THRESHOLD) {
            printf("CPU idle time exceeds threshold (%llu > %llu)\n",
                    cpu.idle_time, CPU_THRESHOLD);
        }

        usleep(100000);
    }

    return 0;
}