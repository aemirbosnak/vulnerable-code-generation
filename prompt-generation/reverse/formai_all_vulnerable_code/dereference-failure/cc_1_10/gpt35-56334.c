//FormAI DATASET v1.0 Category: System process viewer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define MAX_STRING_LENGTH 256

typedef struct process {
    char pid[MAX_STRING_LENGTH];
    char name[MAX_STRING_LENGTH];
    char status[MAX_STRING_LENGTH];
    unsigned long mem;
} process_t;

void print_processes(process_t *processes, int num_processes);
int is_number(char *str);
void get_process_info(char *pid, process_t *process);
void get_processes(process_t *processes, int *num_processes);

int main() {
    process_t processes[256];
    int num_processes;

    get_processes(processes, &num_processes);
    print_processes(processes, num_processes);

    return 0;
}

void get_processes(process_t *processes, int *num_processes) {
    DIR *dir;
    struct dirent *entry;
    char path[MAX_PATH_LENGTH];

    *num_processes = 0;
    dir = opendir("/proc");

    if (dir == NULL) {
        printf("Error opening /proc directory\n");
        exit(1);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (is_number(entry->d_name)) {
            get_process_info(entry->d_name, &processes[*num_processes]);
            (*num_processes)++;
        }
    }

    closedir(dir);
}

void get_process_info(char *pid, process_t *process) {
    char path[MAX_PATH_LENGTH], buffer[MAX_STRING_LENGTH];
    FILE *status;

    sprintf(path, "/proc/%s/status", pid);
    status = fopen(path, "r");

    if (status == NULL) {
        printf("Error opening file %s\n", path);
        exit(1);
    }

    fgets(buffer, MAX_STRING_LENGTH, status);
    fgets(buffer, MAX_STRING_LENGTH, status);
    sscanf(buffer, "Name: %[^\n]", process->name);
    fgets(buffer, MAX_STRING_LENGTH, status);
    sscanf(buffer, "State: %[^\n]", process->status);
    fgets(buffer, MAX_STRING_LENGTH, status);
    fgets(buffer, MAX_STRING_LENGTH, status);
    fgets(buffer, MAX_STRING_LENGTH, status);
    sscanf(buffer, "VmSize: %lu", &process->mem);

    fclose(status);
    strcpy(process->pid, pid);
}

void print_processes(process_t *processes, int num_processes) {
    int i;

    printf("PID\t\tName\t\tStatus\t\tMemory\n");

    for (i = 0; i < num_processes; i++) {
        printf("%s\t\t%s\t\t%s\t\t%lu kB\n",
                processes[i].pid, processes[i].name, processes[i].status,
                processes[i].mem);
    }
}

int is_number(char *str) {
    while (*str) {
        if (!isdigit(*str++)) {
            return 0;
        }
    }

    return 1;
}