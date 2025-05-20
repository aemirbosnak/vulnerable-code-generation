//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define PROC_DIR "/proc"
#define CMDLINE_FILE "comm"
#define STAT_FILE "stat"
#define BUFFER_SIZE 256

struct ProcessInfo {
    pid_t pid;
    char command[BUFFER_SIZE];
    char state[BUFFER_SIZE];
};

void trim_newline(char *str) {
    char *ptr = strchr(str, '\n');
    if (ptr) {
        *ptr = '\0';
    }
}

int get_process_info(pid_t pid, struct ProcessInfo *proc_info) {
    char stat_path[BUFFER_SIZE];
    char cmd_path[BUFFER_SIZE];
    snprintf(stat_path, sizeof(stat_path), "%s/%d/%s", PROC_DIR, pid, STAT_FILE);
    snprintf(cmd_path, sizeof(cmd_path), "%s/%d/%s", PROC_DIR, pid, CMDLINE_FILE);
    
    FILE *stat_file = fopen(stat_path, "r");
    FILE *cmd_file = fopen(cmd_path, "r");
    
    if (!stat_file || !cmd_file) {
        return -1; // Failed to open one of the files
    }
    
    // Read process stat file
    fscanf(stat_file, "%d %s %s", &proc_info->pid, proc_info->command, proc_info->state);
    fclose(stat_file);
    
    // Read command line
    if (fgets(proc_info->command, BUFFER_SIZE, cmd_file) != NULL) {
        trim_newline(proc_info->command);
    }
    fclose(cmd_file);
    
    return 0; // Success
}

int list_processes() {
    struct dirent *entry;
    DIR *dp = opendir(PROC_DIR);
    
    if (dp == NULL) {
        perror("opendir");
        return -1;
    }
    
    printf("%-10s %-30s %-20s\n", "PID", "Command", "State");
    printf("---------------------------------------------------\n");
    
    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_DIR) {
            pid_t pid = atoi(entry->d_name);
            if (pid > 0) { // Only list valid PIDs
                struct ProcessInfo proc_info;
                if (get_process_info(pid, &proc_info) == 0) {
                    printf("%-10d %-30s %-20s\n", proc_info.pid, proc_info.command, proc_info.state);
                }
            }
        }
    }
    
    closedir(dp);
    return 0; // Success
}

int main() {
    printf("Linux Process Viewer\n");
    printf("=====================\n");
    
    if (list_processes() != 0) {
        fprintf(stderr, "Error listing processes.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}