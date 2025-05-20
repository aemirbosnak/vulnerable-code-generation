//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME 100

int get_cpu_usage(pid_t pid, char *process_name, int *cpu_percentage) {
    char filename[64];
    sprintf(filename, "/proc/%d/stat", pid);
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening stat file");
        return -1;
    }
    char line[1024];
    fgets(line, sizeof(line), file);
    fclose(file);
    char *token = strtok(line, " ");
    int total_cpu_time = atoi(token);
    token = strtok(NULL, " ");
    int current_cpu_time = atoi(token);
    int cpu_time_diff = current_cpu_time - total_cpu_time;
    *cpu_percentage = (cpu_time_diff * 100) / (current_cpu_time - total_cpu_time);
    return 0;
}

int main() {
    int num_processes = 0;
    pid_t processes[MAX_PROCESSES];
    char process_names[MAX_PROCESSES][MAX_PROCESS_NAME];
    int cpu_percentages[MAX_PROCESSES];
    while (num_processes < MAX_PROCESSES) {
        printf("Enter process ID (or -1 to stop): ");
        scanf("%d", &processes[num_processes]);
        if (processes[num_processes] == -1) {
            break;
        }
        strcpy(process_names[num_processes], "");
        get_cpu_usage(processes[num_processes], process_names[num_processes], &cpu_percentages[num_processes]);
        printf("Process %d (%s): %d%%\n", processes[num_processes], process_names[num_processes], cpu_percentages[num_processes]);
        num_processes++;
    }
    return 0;
}