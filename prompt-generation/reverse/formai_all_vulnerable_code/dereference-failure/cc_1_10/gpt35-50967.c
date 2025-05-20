//FormAI DATASET v1.0 Category: System process viewer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_LEN_PROC 2048

struct Process {
    char name[100];
    int pid;
    char state;
    int priority;
};

void display_proc_info(struct Process proc);
void get_process_list();
char get_process_state(int pid);
int get_process_priority(int pid);

int main() {
    printf("Welcome to Process Viewer!\n");
    printf("--------------------------\n");

    get_process_list();

    return 0;
}

void display_proc_info(struct Process proc) {
    printf("%-25s %-10d %-10c %-10d\n", proc.name, proc.pid, proc.state, proc.priority);
}

void get_process_list() {
    DIR* directory = opendir("/proc");

    if (directory == NULL) {
        printf("Error: Unable to open /proc directory.\n");
        exit(1);
    }

    printf("%-25s %-10s %-10s %-10s\n", "Process Name", "PID", "State", "Priority");

    struct dirent* entry;

    while ((entry = readdir(directory)) != NULL) {
        int pid = atoi(entry->d_name);

        if (pid != 0) {
            char proc_filename[MAX_LEN_PROC];

            sprintf(proc_filename, "/proc/%d/stat", pid);

            FILE* fp = fopen(proc_filename, "r");

            if (fp == NULL) {
                continue;
            }

            struct Process proc;
            fscanf(fp, "%d", &proc.pid);
            fscanf(fp, " %s", proc.name);
            fscanf(fp, " %c", &proc.state);
            fscanf(fp, " %*d %*d %*d %*d %*d %*u %*u %*u %*u %*u %*u %*u %*u %*u %*d %d", &proc.priority);

            fclose(fp);

            display_proc_info(proc);
        }
    }

    closedir(directory);
}

char get_process_state(int pid) {
    char proc_filename[MAX_LEN_PROC];
    char state;

    sprintf(proc_filename, "/proc/%d/stat", pid);

    FILE* fp = fopen(proc_filename, "r");

    if (fp == NULL) {
        return '-';
    }

    fscanf(fp, "%*d %*s %c", &state);

    fclose(fp);

    return state;
}

int get_process_priority(int pid) {
    char proc_filename[MAX_LEN_PROC];
    int priority;

    sprintf(proc_filename, "/proc/%d/stat", pid);

    FILE* fp = fopen(proc_filename, "r");

    if (fp == NULL) {
        return -1;
    }

    fscanf(fp, "%*d %*s %*c %*d %*d %*d %*d %*d %*u %*u %*u %*u %*u %*u %*u %*u %d", &priority);

    fclose(fp);

    return priority;
}