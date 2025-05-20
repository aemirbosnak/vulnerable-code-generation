//FormAI DATASET v1.0 Category: System process viewer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PROC_DIRS 65535
#define MB 1048576

typedef struct {
    char *name;
    pid_t pid;
    long int size;
    char *status;
} Process;

int proc_count = 0;
Process *procs;

int is_number(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i]))
            return 0;
    }
    return 1;
}

void process_memory_info(pid_t pid, long int *size) {
    char path[50];
    sprintf(path, "/proc/%d/statm", pid);
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        return;
    }
    fscanf(fp, "%ld", size);
    fclose(fp);
}

void process_stat_info(pid_t pid, char **name, char **status) {
    char path[50];
    sprintf(path, "/proc/%d/status", pid);
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        return;
    }
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "Name:", 5) == 0) {
            char *name_start = line + 6;
            char *name_end = name_start + strcspn(name_start, "\n");
            *name_end = '\0';
            *name = strdup(name_start);
        } else if (strncmp(line, "State:", 6) == 0) {
            char *status_start = line + 7;
            char *status_end = status_start + strcspn(status_start, "\n");
            *status_end = '\0';
            *status = strdup(status_start);
        }
    }
    fclose(fp);
}

void list_processes() {
    DIR *proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(proc_dir)) != NULL) {
        if (is_number(entry->d_name)) {
            pid_t pid = atoi(entry->d_name);

            if (pid != getpid() && pid != getppid()) {
                long int size = 0;
                char *name = NULL;
                char *status = NULL;

                process_memory_info(pid, &size);
                process_stat_info(pid, &name, &status);

                if (name != NULL) {
                    Process proc = {.name = name, .pid = pid, .size = size * getpagesize() / MB, .status = status};
                    procs[proc_count++] = proc;
                }
            }
        }
    }

    closedir(proc_dir);
}

void print_processes() {
    printf("  %-15s %-15s %-10s %-s\n", "NAME", "PID", "SIZE(MB)", "STATUS");
    printf("=============================================\n");
    for (int i = 0; i < proc_count; i++) {
        printf("  %-15s %-15d %-10ld %-s\n", procs[i].name, procs[i].pid, procs[i].size, procs[i].status);
    }
}

int main() {
    procs = (Process *) malloc(sizeof(Process) * MAX_PROC_DIRS);
    memset(procs, 0, sizeof(Process) * MAX_PROC_DIRS);
    list_processes();
    print_processes();
    return 0;
}