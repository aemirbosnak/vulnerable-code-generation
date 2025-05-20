//FormAI DATASET v1.0 Category: System process viewer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

// define the path to the /proc directory
#define PROC_DIRECTORY "/proc"

// define struct for holding process information
typedef struct process_info {
    char pid[10];
    char name[100];
    char status[10];
    char user_id[10];
} ProcessInfo;

// function to parse process information from proc/<pid>/status
void parse_status_file(char *pid, ProcessInfo *process) {
    char file_path[100];
    sprintf(file_path, "%s/%s/status", PROC_DIRECTORY, pid);

    // open the file
    FILE *fp = fopen(file_path, "r");
    if (fp == NULL) {
        return;
    }

    // read file line by line and parse information
    char line[200];
    while (fgets(line, 200, fp) != NULL) {
        if (strncmp(line, "Name:", 5) == 0) {
            sscanf(line + 5, "%s", process->name);
        } else if (strncmp(line, "State:", 6) == 0) {
            sscanf(line + 6, "%s", process->status);
        } else if (strncmp(line, "Uid:", 4) == 0) {
            sscanf(line + 4, "%*s %s", process->user_id);
        }
    }

    fclose(fp);
}

// main function
int main() {
    printf("PID   |   NAME                                   |   STATUS |   USER\n");

    // open the /proc directory
    DIR *proc_dir = opendir(PROC_DIRECTORY);
    if (proc_dir == NULL) {
        fprintf(stderr, "Failed to open directory %s", PROC_DIRECTORY);
        return 1;
    }

    // read the directory contents
    struct dirent *entry;
    while ((entry = readdir(proc_dir)) != NULL) {
        // skip if entry is not a directory or is the current or parent directory
        if (entry->d_type != DT_DIR || !isdigit(entry->d_name[0])) {
            continue;
        }

        // parse process information
        ProcessInfo process_info;
        strcpy(process_info.pid, entry->d_name);
        parse_status_file(entry->d_name, &process_info);

        // print process information
        printf("%-6s|   %-40s |   %-6s |   %-6s\n", process_info.pid, process_info.name, process_info.status, process_info.user_id);
    }

    closedir(proc_dir);
    return 0;
}