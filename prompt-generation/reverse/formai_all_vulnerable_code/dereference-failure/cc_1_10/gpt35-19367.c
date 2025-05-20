//FormAI DATASET v1.0 Category: System process viewer ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<dirent.h>

#define PROC_DIRECTORY "/proc/"

typedef struct {
    char name[50];
    char state;
    int pid;
    int ppid;
    int priority;
} process;

int count_processes();
void print_processes(process* processes, int count);

int main() {
    int count = count_processes();
    process* processes = NULL;
    if(count > 0) {
        processes = (process*) malloc(count * sizeof(process));
        int i = 0;
        DIR *proc_dir = opendir(PROC_DIRECTORY);
        struct dirent *entry;
        while((entry = readdir(proc_dir)) != NULL) {
            if(isdigit(entry->d_name[0])) {
                char filename[256];
                snprintf(filename, sizeof(filename), "%s%s/stat", PROC_DIRECTORY, entry->d_name);
                FILE *fd = fopen(filename, "r");
                if(fd) {
                    fscanf(fd, "%d %s %c %d %d", &(processes[i].pid), processes[i].name, &(processes[i].state), &(processes[i].ppid), &(processes[i].priority));
                    fclose(fd);
                    i++;
                }
            }
        }
        closedir(proc_dir);
    }
    print_processes(processes, count);
    if(processes) free(processes);
    return 0;
}

// Count number of processes
int count_processes() {
    int count = 0;
    DIR *proc_dir = opendir(PROC_DIRECTORY);
    struct dirent *entry;
    while((entry = readdir(proc_dir)) != NULL) {
        if(isdigit(entry->d_name[0])) {
            count++;
        }
    }
    closedir(proc_dir);
    return count;
}

// Print processes
void print_processes(process* processes, int count) {
    printf("Number of processes: %d\n\n", count);
    for(int i=0; i<count; i++) {
        printf("PID: %d\n", processes[i].pid);
        printf("Name: %s\n", processes[i].name);
        printf("State: %c\n", processes[i].state);
        printf("PPID: %d\n", processes[i].ppid);
        printf("Priority: %d\n\n", processes[i].priority);
    }
}