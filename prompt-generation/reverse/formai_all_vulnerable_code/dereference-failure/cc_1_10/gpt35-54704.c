//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_bar(int num) {
    for (int i = 0; i < num; i++) {
        printf("█");
    }
    printf("\n");
}

int main() {
    int usage;
    while (1) {
        FILE* fp = fopen("/proc/stat", "r");
        if (!fp) {
            perror("Failed to open stat file");
            exit(1);
        }

        char buffer[1024];
        fgets(buffer, 1024, fp);
        fclose(fp);

        char* token = strtok(buffer, " ");
        int user = atoi(strtok(NULL, " "));
        int nice = atoi(strtok(NULL, " "));
        int system = atoi(strtok(NULL, " "));
        int idle = atoi(strtok(NULL, " "));
        int iowait = atoi(strtok(NULL, " "));
        int irq = atoi(strtok(NULL, " "));
        int softirq = atoi(strtok(NULL, " "));

        int total_cpu_time = user + nice + system + idle + iowait + irq+ softirq;
        int prev_idle = idle;
        int prev_total_cpu_time = total_cpu_time;

        sleep(1);

        fp = fopen("/proc/stat", "r");
        if (!fp) {
            perror("Failed to open stat file");
            exit(1);
        }

        fgets(buffer, 1024, fp);
        fclose(fp);

        token = strtok(buffer, " ");
        user = atoi(strtok(NULL, " "));
        nice = atoi(strtok(NULL, " "));
        system = atoi(strtok(NULL, " "));
        idle = atoi(strtok(NULL, " "));
        iowait = atoi(strtok(NULL, " "));
        irq = atoi(strtok(NULL, " "));
        softirq = atoi(strtok(NULL, " "));

        total_cpu_time = user + nice + system + idle + iowait + irq + softirq;

        float diff_idle = idle - prev_idle;
        float diff_total_cpu_time = total_cpu_time - prev_total_cpu_time;

        usage = 100 * (diff_total_cpu_time - diff_idle) / diff_total_cpu_time;

        printf("CPU Usage: %d%%\n", usage);
        print_bar(usage / 2);
    }
}