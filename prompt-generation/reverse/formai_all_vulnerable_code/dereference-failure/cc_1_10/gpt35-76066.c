//FormAI DATASET v1.0 Category: System process viewer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PATH 4096

// Struct for holding process information
typedef struct {
    char name[50];
    char state[20];
    int pid;
    int ppid;
    int uid;
} process_t;

// Function to retrieve process information from /proc
int get_process_info(process_t *proc, int pid) {
    char proc_path[MAX_PATH];
    FILE *fp;

    sprintf(proc_path, "/proc/%d/status", pid);

    fp = fopen(proc_path, "r");
    if(fp == NULL) {
        return 0;
    }

    char line[256];
    while(fgets(line, sizeof(line), fp)) {
        if(strncmp(line, "Name:", 5) == 0) {
            sscanf(line+5, "%s", proc->name);
        } else if(strncmp(line, "State:", 6) == 0) {
            sscanf(line+6, "%s", proc->state);
        } else if(strncmp(line, "Pid:", 4) == 0) {
            sscanf(line+4, "%d", &proc->pid);
        } else if(strncmp(line, "PPid:", 5) == 0) {
            sscanf(line+5, "%d", &proc->ppid);
        } else if(strncmp(line, "Uid:", 4) == 0) {
            sscanf(line+4, "%d", &proc->uid);
        }
    }

    fclose(fp);

    return 1;
}

// Function to check if a string can be converted to an integer
int is_integer(char *str) {
    int i;
    for(i = 0; str[i] != '\0'; i++) {
        if(!isdigit(str[i])) {
            return 0;
        }
    }

    return 1;
}

int main(int argc, char **argv) {
    DIR *proc_dir;
    struct dirent *proc_entry;
    process_t *procs = NULL;
    int num_procs = 0;
    int i;

    // Open /proc directory
    proc_dir = opendir("/proc");
    if(proc_dir == NULL) {
        perror("Error opening /proc");
        exit(1);
    }

    // Loop through /proc directory and count number of processes
    while((proc_entry = readdir(proc_dir)) != NULL) {
        if(is_integer(proc_entry->d_name)) {
            num_procs++;
            procs = realloc(procs, num_procs * sizeof(process_t));
            if(!get_process_info(&procs[num_procs-1], atoi(proc_entry->d_name))) {
                num_procs--;
                procs = realloc(procs, num_procs * sizeof(process_t));
            }
        }
    }

    // Close /proc directory
    closedir(proc_dir);

    // Display process information
    printf("%-20s %-10s %-10s %-10s %-10s\n", "Name", "State", "PID", "PPID", "UID");
    for(i = 0; i < num_procs; i++) {
        printf("%-20s %-10s %-10d %-10d %-10d\n", procs[i].name, procs[i].state, procs[i].pid, procs[i].ppid, procs[i].uid);
    }

    // Free process information memory
    free(procs);

    return 0;
}