//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROC_NAME_LEN 256
#define MAX_CPU_STATS_LEN 32

typedef struct {
    char* cpu_stats[MAX_CPU_STATS_LEN];
    int stats_len;
} CpuStats;

typedef struct {
    int pid;
    char* name;
    char* state;
    float cpu_usage;
} Process;

CpuStats* read_cpu_stats() {
    FILE* fp = fopen("/proc/stat", "r");
    char buf[1024];
    fgets(buf, sizeof(buf), fp);
    CpuStats* stats = (CpuStats*) malloc(sizeof(CpuStats));
    stats->stats_len = 0;
    char* token = strtok(buf, " ");
    while(token != NULL) {
        if (strncmp(token, "cpu", 3) == 0) {
            stats->cpu_stats[stats->stats_len++] = strdup(token);
        }
        token = strtok(NULL, " ");
    }
    fclose(fp);
    return stats;
}

float calculate_cpu_usage(CpuStats* prev_stats, CpuStats* current_stats) {
    float prev_idle_time = 0.0f, current_idle_time = 0.0f;
    float prev_total_time = 0.0f, current_total_time = 0.0f;
    for (int i = 0; i < prev_stats->stats_len; i++) {
        prev_total_time += atoi(prev_stats->cpu_stats[i]);
        current_total_time += atoi(current_stats->cpu_stats[i]);
        if (i == 3) {
            prev_idle_time = atoi(prev_stats->cpu_stats[i]);
            current_idle_time = atoi(current_stats->cpu_stats[i]);
        }
    }
    float delta_idle_time = current_idle_time - prev_idle_time;
    float delta_total_time = current_total_time - prev_total_time;
    return ((delta_total_time - delta_idle_time) / delta_total_time) * 100.0f;
}

Process* get_all_processes() {
    Process* processes = NULL;
    int num_processes = 0;
    char status_filepath[256];
    FILE* fp;
    char buf[1024];
    char* token;
    for (int i = 1; i <= 32768; i++) {
        sprintf(status_filepath, "/proc/%d/status", i);
        if (access(status_filepath, F_OK) != -1) {
            fp = fopen(status_filepath, "r");
            while(fgets(buf, sizeof(buf), fp)) {
                if (strncmp(buf, "Name:", 5) == 0) {
                    token = strtok(buf, " ");
                    token = strtok(NULL, " ");
                    char* name = strdup(token);
                    processes = (Process*) realloc(processes, sizeof(Process) * ++num_processes);
                    processes[num_processes - 1].name = name;
                    processes[num_processes - 1].pid = i;
                    break;
                }
            }
            fclose(fp);
        }
    }
    return processes;
}

float get_cpu_usage_for_pid(int pid, CpuStats* prev_stats, CpuStats* current_stats) {
    char stat_filepath[256];
    FILE* fp;
    sprintf(stat_filepath, "/proc/%d/stat", pid);
    fp = fopen(stat_filepath, "r");
    char buf[1024];
    char* token;
    Process process;
    process.cpu_usage = 0;
    while(fgets(buf, sizeof(buf), fp)) {
        int i = 0;
        token = strtok(buf, " ");
        while(token != NULL) {
            switch(++i) {
                case 1:
                    process.pid = atoi(token);
                    break;
                case 2:
                    process.name = strdup(token);
                    break;
                case 3:
                    process.state = strdup(token);
                    break;
                case 14:
                    process.cpu_usage = calculate_cpu_usage(prev_stats, current_stats);
                    break;
            }
            token = strtok(NULL, " ");
        }
    }
    fclose(fp);
    for (int i = 0; i < prev_stats->stats_len; i++) {
        free(prev_stats->cpu_stats[i]);
    }
    free(prev_stats);
    return process.cpu_usage;
}

void print_process_stats(Process* processes, int num_processes, CpuStats* prev_stats, CpuStats* current_stats) {
    printf("%-10s %-30s %-10s %-10s\n", "PID", "Name", "State", "CPU Usage");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < num_processes; i++) {
        float cpu_usage = get_cpu_usage_for_pid(processes[i].pid, prev_stats, current_stats);
        printf("%-10d %-30s %-10s %-10f\n", processes[i].pid, processes[i].name, processes[i].state, cpu_usage);
    }
}

int main() {
    CpuStats* prev_stats = read_cpu_stats();
    Process* processes = get_all_processes();
    int num_processes = 0;
    while(processes[num_processes++].pid != 0);
    num_processes--;
    sleep(1);
    while(1) {
        system("clear");
        printf("**** PROCESS CPU USAGE MONITOR ****\n\n");
        CpuStats* current_stats = read_cpu_stats();
        print_process_stats(processes, num_processes, prev_stats, current_stats);
        memcpy(prev_stats, current_stats, sizeof(CpuStats));
        sleep(1);
    }
    return 0;
}