//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define CMD_SIZE 256

void print_process(const char *pid) {
    char stat_file[BUFFER_SIZE], cmd_file[BUFFER_SIZE];
    FILE *fp;
    char command[CMD_SIZE];
    int ppid, pgrp, session;
    char tty[16], state;
    unsigned long utime, stime, cutime, cstime;

    // Prepare file paths
    snprintf(stat_file, sizeof(stat_file), "/proc/%s/stat", pid);
    snprintf(cmd_file, sizeof(cmd_file), "/proc/%s/cmdline", pid);

    // Read process stats
    fp = fopen(stat_file, "r");
    if (fp) {
        fscanf(fp, "%*d %*s %c %s %d %d %d %lu %lu %lu %lu", &state, tty, &ppid, &pgrp, &session, &utime, &stime, &cutime, &cstime);
        fclose(fp);
    } else {
        return; // failed to open stat file 
    }

    // Read command line
    fp = fopen(cmd_file, "r");
    if (fp) {
        fgets(command, sizeof(command), fp);
        fclose(fp);
    } else {
        snprintf(command, sizeof(command), "[Unknown Command]");
    }

    // Print process information
    printf("%-10s %-6s %c %-10d %-10d %-10d %lu.%lu s\n",
           pid, tty, state, ppid, pgrp, session,
           (utime + stime) / sysconf(_SC_CLK_TCK), 
           (utime + stime) % sysconf(_SC_CLK_TCK));
    printf("Command: %s\n", command[0] ? command : "[Unknown Command]");
    printf("--------------------------------------------------\n");
}

void list_processes(const char *search_term) {
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir("/proc"))) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Check if entry is a number (PID)
        if (entry->d_type == DT_DIR) {
            int is_pid = 1;
            for (char *p = entry->d_name; *p; ++p) {
                if (!isdigit(*p)) {
                    is_pid = 0;
                    break;
                }
            }
            if (is_pid) {
                // Filter by search term
                if (search_term == NULL || strstr(entry->d_name, search_term) != NULL) {
                    print_process(entry->d_name);
                }
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    printf("Simple Process Viewer\n");
    printf("======================\n");
    printf("PID      TTY    S PPID      PGRP      SESSION   TIME\n");
    printf("--------------------------------------------------\n");

    const char *search_term = (argc > 1) ? argv[1] : NULL;
    list_processes(search_term);

    return 0;
}