//FormAI DATASET v1.0 Category: System process viewer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

#define MAX_PID_LENGTH 12
#define MAX_CMDLINE_LENGTH 1024

struct process {
    char pid[MAX_PID_LENGTH];
    char cmdline[MAX_CMDLINE_LENGTH];
};

void print_header() {
    printf("%-12s%s\n", "PID", "CMDLINE");
}

void print_process(struct process p) {
    printf("%-12s%s\n", p.pid, p.cmdline);
}

int is_number(const char *s) {
    while (*s) {
        if (!isdigit(*s))
            return 0;
        s++;
    }

    return 1;
}

int read_cmdline(const char *pid, char *cmdline) {
    char proc_file_path[MAX_PID_LENGTH + 32];
    snprintf(proc_file_path, sizeof(proc_file_path), "/proc/%s/cmdline", pid);

    FILE *fp = fopen(proc_file_path, "r");

    if (fp == NULL) {
        return -1;
    }

    fgets(cmdline, MAX_CMDLINE_LENGTH, fp);

    fclose(fp);

    return 0;
}

void list_processes() {
    DIR *dirproc = opendir("/proc");
    struct dirent *entry;

    while ((entry = readdir(dirproc)) != NULL) {
        if (!is_number(entry->d_name))
            continue;

        struct process p;
        strcpy(p.pid, entry->d_name);

        if (read_cmdline(p.pid, p.cmdline) != 0) {
            continue;
        }

        print_process(p);
    }

    closedir(dirproc);
}

int main(void) {
    print_header();

    list_processes();

    return 0;
}