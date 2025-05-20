//MISTRAL-7B DATASET v1.0 Category: CPU usage monitor ; Style: minimalist
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/sysinfo.h>
#include <string.h>
#include <time.h>

#define CPU_FILE "/proc/stat"
#define BUF_SIZE 256
#define IDX_TOTAL 2
#define IDX_IDLE 3
#define IDX_NICE 4
#define IDX_SYSTEM 5
#define IDX_USER 6
#define IDX_IOWAIT 7
#define IDX_IRQ 8
#define IDX_SOFTIRQ 9

int main() {
    struct stat st;
    char cpu_stat[BUF_SIZE];
    char *token[10];
    int total, idle, nice, system, user, iowait, irq, softirq, cpu;

    while (1) {
        memset(cpu_stat, 0, BUF_SIZE);
        if (readlink(CPU_FILE, cpu_stat, BUF_SIZE - 1) > 0) {
            sscanf(cpu_stat, "%*s %d %d %d %d %d %d %d %d %d %d %d",
                   &total, &idle, &nice, &system, &user, &iowait,
                   &irq, &softirq, &cpu);

            printf("\nCPU USAGE:\n");
            printf("Total: %d\n", total);
            printf("Idle: %d\n", idle);
            printf("User: %d\n", user);
            printf("System: %d\n", system);

            int usage = ((total - idle) * 100) / total;
            printf("CPU usage: %.2f%%\n", usage);

            sleep(1);
        } else {
            perror("Error reading cpu stat file");
            sleep(1);
        }
    }

    return 0;
}