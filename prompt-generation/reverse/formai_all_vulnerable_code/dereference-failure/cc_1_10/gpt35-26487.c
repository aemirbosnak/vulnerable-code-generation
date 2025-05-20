//FormAI DATASET v1.0 Category: System process viewer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_PID_LENGTH 8
#define MAX_CMDLINE_LENGTH 1024

typedef struct {
    char name[MAX_CMDLINE_LENGTH];
    char state;
    pid_t pid;
    pid_t ppid;
    unsigned long int utime;
    unsigned long int stime;
} Process;

void print_process_info(Process process) {
    printf("%8d  %8d  %c  %lu.%lu  %s\n", process.pid, process.ppid,
        process.state, process.utime, process.stime, process.name);
}

int is_number(char *str) {
    int i;
    for (i = 0; str[i]; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

void read_process_info(pid_t pid, Process *process) {
    char filename[MAX_CMDLINE_LENGTH];
    FILE *file;
    sprintf(filename, "/proc/%d/stat", pid);
    file = fopen(filename, "r");
    if (file) {
        fscanf(file, "%d", &(process->pid));
        fscanf(file, " %s", process->name);
        fscanf(file, " %c", &(process->state));
        fscanf(file, " %d", &(process->ppid));
        fseek(file, 15, SEEK_CUR);
        fscanf(file, "%lu", &(process->utime));
        fscanf(file, "%lu", &(process->stime));
        fclose(file);
    }
}

void list_processes() {
    DIR *dir;
    struct dirent *entry;
    Process process;
    char pid[MAX_PID_LENGTH];
    dir = opendir("/proc");
    if (dir) {
        while ((entry = readdir(dir)) != NULL) {
            if (is_number(entry->d_name)) {
                memset(&process, '\0', sizeof(process));
                strcpy(pid, entry->d_name);
                read_process_info(atoi(pid), &process);
                print_process_info(process);
            }
        }
        closedir(dir);
    }
}

int main() {
    printf("%8s  %8s  %s\n", "PID", "PPID", "CMD");
    list_processes();
    return 0;
}