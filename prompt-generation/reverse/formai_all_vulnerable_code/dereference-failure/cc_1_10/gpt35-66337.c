//FormAI DATASET v1.0 Category: System process viewer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

// define constants for buffer size
#define BUF_SIZE 256
#define COMM_SIZE 512

// define structure for process information
typedef struct {
    char pid[BUF_SIZE];
    char comm[COMM_SIZE];
    char state[BUF_SIZE];
    char ppid[BUF_SIZE];
    char uid[BUF_SIZE];
    char mem[BUF_SIZE];
} Process;

// function to parse process information from proc
void parseProc(Process *proc, char *pid) {
    // create file paths for process information
    char statusPath[BUF_SIZE];
    char statPath[BUF_SIZE];

    snprintf(statusPath, BUF_SIZE, "/proc/%s/status", pid);
    snprintf(statPath, BUF_SIZE, "/proc/%s/stat", pid);

    // read process status information
    FILE *file = fopen(statusPath, "r");
    char line[BUF_SIZE];
    while (fgets(line, BUF_SIZE, file) != NULL) {
        if (strstr(line, "Name:") != NULL) {
            strcpy(proc->comm, strchr(line, '\t') + 1);
            proc->comm[strcspn(proc->comm, "\n")] = 0;
        }
        else if (strstr(line, "State:") != NULL) {
            strcpy(proc->state, strchr(line, '\t') + 1);
            proc->state[strcspn(proc->state, "\n")] = 0;
        }
        else if (strstr(line, "Uid:") != NULL) {
            strcpy(proc->uid, strchr(line, '\t') + 1);
            proc->uid[strcspn(proc->uid, "\n")] = 0;
        }
        else if (strstr(line, "VmRSS:") != NULL) {
            strcpy(proc->mem, strchr(line, '\t') + 1);
            proc->mem[strcspn(proc->mem, "\n")] = 0;
        }
    }
    fclose(file);

    // read process stat information
    file = fopen(statPath, "r");
    fscanf(file, "%s", proc->pid);
    fscanf(file, "%s", proc->comm);
    fscanf(file, "%s", proc->state);
    fscanf(file, "%s", proc->ppid);
    fclose(file);
}

int main() {
    // print header
    printf("%-10s %-30s %-10s %-10s %-10s %-10s\n", "PID", "COMMAND", "STATE", "PPID", "UID", "MEMORY");

    // open directory to read process IDs
    DIR *dir = opendir("/proc");
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        int pid = atoi(entry->d_name);
        if (pid != 0) {
            // parse process information
            Process proc;
            parseProc(&proc, entry->d_name);

            // print process information
            printf("%-10s %-30s %-10s %-10s %-10s %-10s\n", proc.pid, proc.comm, proc.state, proc.ppid, proc.uid, proc.mem);
        }
    }
    closedir(dir);

    return 0;
}