//FormAI DATASET v1.0 Category: System process viewer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROC_LENGTH 1024
#define MAX_PID_LENGTH 256
#define MAX_CMDLINE_LENGTH 2048

int is_all_digits(const char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

void print_header() {
    printf("%-10s %-25s %s\n", "PID", "Command", "State");
}

void print_process_info(const char *pid, const char *cmdline, const char *state) {
    printf("%-10s %-25s %s\n", pid, cmdline, state);
}

int main() {
    DIR *proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("Could not open /proc directory");
        exit(EXIT_FAILURE);
    }

    // Read all process directories
    struct dirent *proc_entry;
    while ((proc_entry = readdir(proc_dir)) != NULL) {
        if (!is_all_digits(proc_entry->d_name)) {
            continue;
        }

        // Get process information
        char pid[MAX_PID_LENGTH];
        strcpy(pid, proc_entry->d_name);

        char proc_file[MAX_PROC_LENGTH];
        sprintf(proc_file, "/proc/%s/cmdline", pid);

        FILE *cmdline_file = fopen(proc_file, "r");
        if (cmdline_file == NULL) {
            continue;
        }

        char cmdline[MAX_CMDLINE_LENGTH];
        fgets(cmdline, MAX_CMDLINE_LENGTH, cmdline_file);

        fclose(cmdline_file);

        // Get process state
        char state;
        sprintf(proc_file, "/proc/%s/stat", pid);

        FILE *stat_file = fopen(proc_file, "r");
        if (stat_file == NULL) {
            continue;
        }

        fscanf(stat_file, "%*d %*s %c", &state);

        fclose(stat_file);

        // Print process information
        print_process_info(pid, cmdline, &state);
    }

    closedir(proc_dir);

    exit(EXIT_SUCCESS);
}