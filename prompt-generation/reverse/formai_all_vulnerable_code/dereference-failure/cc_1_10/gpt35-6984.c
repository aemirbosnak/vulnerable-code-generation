//FormAI DATASET v1.0 Category: System process viewer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define PROC_DIR "/proc"

typedef struct Process {
    int pid;
    char name[50];
    char status;
    int ppid;
} Process;

void print_processes(Process **processes, int num_processes);
void free_processes(Process **processes, int num_processes);
int get_number_of_processes();
Process *parse_process_info(char *pid);
char *get_process_status(char *pid);

int main() {
    int num_processes = get_number_of_processes();
    if(num_processes == -1) {
        printf("Error obtaining number of processes\n");
        return -1;
    }

    Process **processes = (Process **) malloc(num_processes * sizeof(Process *));
    for(int i = 0; i < num_processes; i++)
        processes[i] = NULL;

    DIR *dp = opendir(PROC_DIR);
    if(dp == NULL) {
        printf("Error opening /proc directory\n");
        free_processes(processes, num_processes);
        return -1;
    }

    struct dirent *dirp;
    while((dirp = readdir(dp)) != NULL) {
        int pid = atoi(dirp->d_name);
        if(pid == 0) continue;

        char *status = get_process_status(dirp->d_name);
        if(status == NULL) continue;

        Process *process = parse_process_info(dirp->d_name);
        if(process == NULL) {
            free(status);
            continue;
        }

        process->status = status[0];
        free(status);

        processes[pid - 1] = process;
    }

    closedir(dp);

    print_processes(processes, num_processes);
    free_processes(processes, num_processes);
}

void print_processes(Process **processes, int num_processes) {
    printf("%-5s %-20s %-10s %-5s\n", "PID", "NAME", "STATUS", "PPID");
    for(int i = 0; i < num_processes; i++) {
        Process *process = processes[i];
        if(process == NULL) continue;

        printf("%-5d %-20s %-10c %-5d\n", process->pid, process->name, process->status, process->ppid);
    }
}

void free_processes(Process **processes, int num_processes) {
    for(int i = 0; i < num_processes; i++) {
        if(processes[i] != NULL)
            free(processes[i]);
    }

    free(processes);
}

int get_number_of_processes() {
    DIR *dp = opendir(PROC_DIR);
    if(dp == NULL) return -1;

    int num_processes = 0;
    struct dirent *dirp;
    while((dirp = readdir(dp)) != NULL) {
        if(isdigit(dirp->d_name[0]))
            num_processes++;
    }

    closedir(dp);

    return num_processes;
}

Process *parse_process_info(char *pid) {
    char filepath[50];
    snprintf(filepath, 50, "%s/%s/stat", PROC_DIR, pid);

    FILE *fp = fopen(filepath, "r");
    if(fp == NULL) return NULL;

    Process *process = (Process *) malloc(sizeof(Process));
    process->pid = atoi(pid);

    fscanf(fp, "%d (%[^)]) %c %d", &(process->pid), process->name, &(process->status), &(process->ppid));

    fclose(fp);

    return process;
}

char *get_process_status(char *pid) {
    char filepath[50];
    snprintf(filepath, 50, "%s/%s/status", PROC_DIR, pid);

    FILE *fp = fopen(filepath, "r");
    if(fp == NULL) return NULL;

    char *status = (char *) malloc(4);
    char *line = NULL;
    size_t line_size = 0;

    while(getline(&line, &line_size, fp) != -1) {
        if(strncmp(line, "State:", 6) == 0) {
            strncpy(status, line + 7, 1);
            status[1] = '\0';
            break;
        }
    }

    free(line);
    fclose(fp);

    return status;
}