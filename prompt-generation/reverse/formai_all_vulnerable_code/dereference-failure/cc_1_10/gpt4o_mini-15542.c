//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

typedef struct {
    int pid;
    char name[BUFFER_SIZE];
    char state[32];
    int ppid;
    int pgrp;
    int session;
    int tty_nr;
    unsigned long utime;
    unsigned long stime;
} ProcessInfo;

void printProcessInfo(ProcessInfo *processes, int count) {
    printf("\n%-10s %-30s %-8s %-6s %-6s %-8s %-8s %-8s\n", 
           "PID", "Name", "State", "PPID", "PGRP", "Session", "TTY_NR", "UTIME");
    printf("-----------------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-10d %-30s %-8s %-6d %-6d %-8d %-8d %-8lu\n",
            processes[i].pid, processes[i].name, processes[i].state,
            processes[i].ppid, processes[i].pgrp, processes[i].session,
            processes[i].tty_nr, processes[i].utime);
    }
}

int readProcessInfo(int pid, ProcessInfo *process) {
    char path[BUFFER_SIZE], buffer[BUFFER_SIZE];
    snprintf(path, sizeof(path), "/proc/%d/stat", pid);
    
    FILE *fp = fopen(path, "r");
    if (!fp) return 0;

    fscanf(fp, "%d %s %s %d %d %d %d %lu %lu",
        &process->pid, process->name, process->state,
        &process->ppid, &process->pgrp, &process->session,
        &process->tty_nr, &process->utime, &process->stime);
    
    process->name[strlen(process->name) - 1] = '\0'; // Remove trailing parentheses
    fclose(fp);
    
    return 1;
}

int collectProcesses(ProcessInfo *processes) {
    DIR *dir = opendir("/proc");
    int count = 0;

    if (!dir) {
        perror("Could not open /proc directory");
        return -1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            int pid = atoi(entry->d_name);
            if (readProcessInfo(pid, &processes[count])) {
                count++;
            }
        }
    }
    closedir(dir);
    return count;
}

void displayProcesses() {
    ProcessInfo processes[MAX_PROCESSES];
    int count = collectProcesses(processes);

    if (count < 0) {
        fprintf(stderr, "Error collecting processes.\n");
        return;
    }

    if (count > 0) {
        printProcessInfo(processes, count);
    } else {
        printf("No processes found.\n");
    }
}

int main() {
    printf("----------------------------------------------------\n");
    printf("               Interactive Process Viewer           \n");
    printf("----------------------------------------------------\n");
    while (1) {
        displayProcesses();
        printf("\nPress ENTER to refresh or type 'exit' to quit: ");
        
        char input[10];
        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (strncmp(input, "exit", 4) == 0) break;
        }
        sleep(2);
    }
    printf("Exiting Process Viewer. Goodbye!\n");
    return 0;
}