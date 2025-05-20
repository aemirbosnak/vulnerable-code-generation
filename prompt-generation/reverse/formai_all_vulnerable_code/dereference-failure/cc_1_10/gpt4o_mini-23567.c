//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define PROC_PATH "/proc/"
#define MAX_PATH 256
#define MAX_LINE 256

typedef struct {
    int pid;
    char name[256];
    char state[16];
} Process;

int is_integer(const char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (!isdigit(s[i])) {
            return 0;
        }
    }
    return 1;
}

void read_process_info(Process *proc) {
    char path[MAX_PATH];
    char line[MAX_LINE];
    FILE *status_file;

    sprintf(path, "%s%d/status", PROC_PATH, proc->pid);
    status_file = fopen(path, "r");
    if (!status_file) {
        return;
    }

    while (fgets(line, sizeof(line), status_file)) {
        if (sscanf(line, "Name:\t%s", proc->name) == 1) {
            continue;
        }
        if (sscanf(line, "State:\t%s", proc->state) == 1) {
            continue;
        }
    }

    fclose(status_file);
}

void list_processes() {
    DIR *proc_dir;
    struct dirent *entry;

    if (!(proc_dir = opendir(PROC_PATH))) {
        perror("opendir");
        return;
    }

    printf("%-6s %-20s %-10s\n", "PID", "Name", "State");
    printf("%-6s %-20s %-10s\n", "---", "----", "-----");

    while ((entry = readdir(proc_dir)) != NULL) {
        if (is_integer(entry->d_name)) {
            Process proc;
            proc.pid = atoi(entry->d_name);
            read_process_info(&proc);
            printf("%-6d %-20s %-10s\n", proc.pid, proc.name, proc.state);
        }
    }

    closedir(proc_dir);
}

int main() {
    printf("Process Viewer - A Glimpse into Active Processes\n");
    printf("==================================================\n");
    list_processes();
    printf("==================================================\n");
    return 0;
}