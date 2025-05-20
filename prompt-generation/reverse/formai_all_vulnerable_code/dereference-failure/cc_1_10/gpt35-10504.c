//FormAI DATASET v1.0 Category: System process viewer ; Style: innovative
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

#define MAX_CMD_LENGTH 128
#define MAX_PROCESS_COUNT 1024

// Process info structure
typedef struct {
    int pid;
    char cmd[MAX_CMD_LENGTH];
} ProcInfo;

// Get process info for a given process id
ProcInfo get_proc_info(int pid) {
    ProcInfo info;
    char cmd_file_path[256];
    char tmp_str[256];
    FILE *cmd_file;

    // Get command file path
    sprintf(cmd_file_path, "/proc/%d/cmdline", pid);

    // Open command file
    cmd_file = fopen(cmd_file_path, "r");

    if (cmd_file) {
        // Read command line argument
        if (fgets(tmp_str, sizeof(tmp_str), cmd_file)) {
            // Remove newline character if present
            if (tmp_str[strlen(tmp_str)-1] == '\n') {
                tmp_str[strlen(tmp_str)-1] = '\0';
            }
            strcpy(info.cmd, tmp_str);
        } else {
            // Unable to read command line argument
            sprintf(info.cmd, "unknown");
        }

        // Close command file
        fclose(cmd_file);
    } else {
        // Unable to open command file
        sprintf(info.cmd, "unknown");
    }

    // Set process id
    info.pid = pid;

    return info;
}

int main() {
    DIR *proc_dir;
    struct dirent *dir_entry;
    int pid_list[MAX_PROCESS_COUNT], pid_count = 0;
    int i;
    ProcInfo proc_info;

    // Open /proc directory
    proc_dir = opendir("/proc");

    if (proc_dir) {
        // Read directory entries
        while((dir_entry = readdir(proc_dir))) {
            // Check if directory entry is a process id
            if (isdigit(dir_entry->d_name[0])) {
                // Convert process id string to integer
                pid_list[pid_count++] = atoi(dir_entry->d_name);
            }
        }

        // Close /proc directory
        closedir(proc_dir);

        printf("| %8s | %s\n", "PID", "CMD");

        // Print process info for each process id
        for (i = 0; i < pid_count; i++) {
            proc_info = get_proc_info(pid_list[i]);
            printf("| %8d | %s\n", proc_info.pid, proc_info.cmd);
        }
    } else {
        printf("Error: unable to open /proc directory\n");
    }

    return 0;
}