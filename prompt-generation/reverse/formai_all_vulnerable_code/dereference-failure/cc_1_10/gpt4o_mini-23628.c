//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_PROCESSES 1024
#define MAX_LINE_LENGTH 256
#define STATUS_FILE_PATH "/proc/%s/status"

typedef struct {
    int pid;
    char name[50];
    char state[20];
} Process;

void clear_screen() {
    printf("\033[H\033[J");
}

void display_process_info(Process *processes, int count) {
    printf("+------+-----------------------------+-----------+\n");
    printf("| PID  | Name                        | State     |\n");
    printf("+------+-----------------------------+-----------+\n");
    for (int i = 0; i < count; i++) {
        printf("| %-4d | %-27s | %-9s |\n", processes[i].pid, processes[i].name, processes[i].state);
    }
    printf("+------+-----------------------------+-----------+\n");
}

int read_process_status(int pid, Process *process) {
    char status_file[MAX_LINE_LENGTH];
    snprintf(status_file, sizeof(status_file), STATUS_FILE_PATH, pid);
    
    FILE *file = fopen(status_file, "r");
    if (!file) return -1;
    
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "Name:\t%s", process->name) == 1) {
            // Remove newline
            process->name[strcspn(process->name, "\n")] = 0;
        }
        else if (sscanf(line, "State:\t%s", process->state) == 1) {
            // Remove newline
            process->state[strcspn(process->state, "\n")] = 0;
        }
    }
    
    process->pid = pid;
    fclose(file);
    return 0;
}

void list_processes(Process *processes, int *count) {
    DIR *dir = opendir("/proc");
    if (dir == NULL) return;

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            int pid = atoi(entry->d_name);
            if (read_process_status(pid, &processes[*count]) == 0) {
                (*count)++;
            }
        }
    }
    closedir(dir);
}

void sort_processes(Process *processes, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (processes[i].pid > processes[j].pid) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int count = 0;

    while (true) {
        clear_screen();
        
        list_processes(processes, &count);
        sort_processes(processes, count);
        display_process_info(processes, count);
        
        printf("Press 'q' to quit or any other key to refresh...\n");

        char input = getchar();
        while (getchar() != '\n');  // Clear input buffer
        if (input == 'q') break;

        sleep(2);  // Refresh every 2 seconds
    }

    return 0;
}