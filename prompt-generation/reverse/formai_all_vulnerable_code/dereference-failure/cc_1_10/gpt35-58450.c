//FormAI DATASET v1.0 Category: System process viewer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

// define some constants
#define PROCESS_PATH "/proc/"
#define MAX_PATH_LENGTH 1024

// define a struct to hold process information
struct process_info {
    int pid;                      // process ID
    char name[MAX_PATH_LENGTH];   // process name
    char state[MAX_PATH_LENGTH];  // state of the process
    int priority;                 // priority of the process
    int memory;                   // memory usage of the process
};

// declare function to get process ID from process directory name
int get_pid_from_proc_dirname(const char *proc_dirname) {
    char *endptr;
    return strtol(proc_dirname, &endptr, 10);
}

// declare function to parse the status file for a process and fill in the process_info struct
void parse_status_file(const char *path, struct process_info *p_info) {
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        perror("Error opening status file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_PATH_LENGTH];
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "Name: %s", p_info->name) == 1) {
            continue;
        }

        if (sscanf(line, "State: %s", p_info->state) == 1) {
            continue;
        }

        if (sscanf(line, "Priority: %d", &p_info->priority) == 1) {
            continue;
        }

        if (sscanf(line, "VmRSS: %d", &p_info->memory) == 1) {
            // memory usage is in kilobytes, so convert to bytes
            p_info->memory *= 1024;
            continue;
        }
    }

    fclose(fp);
}

// declare function to fill in process_info struct for a given process ID
void fill_in_process_info(int pid, struct process_info *p_info) {
    // construct the path to the status file for the process
    char status_path[MAX_PATH_LENGTH];
    snprintf(status_path, sizeof(status_path), "%s%d/status", PROCESS_PATH, pid);

    // parse the status file and fill in the process_info struct
    parse_status_file(status_path, p_info);

    // fill in the process ID
    p_info->pid = pid;
}

// declare function to print the process_info struct in a nice format
void print_process_info(const struct process_info *p_info) {
    printf("%10d    %-32s    %-6s    %7d    %10d\n", p_info->pid, p_info->name, p_info->state, p_info->priority, p_info->memory);
}

int main() {
    DIR *proc_dir = opendir(PROCESS_PATH);
    if (proc_dir == NULL) {
        perror("Error opening process directory");
        exit(EXIT_FAILURE);
    }

    // print header
    printf("%10s    %-32s    %-6s    %7s    %10s\n", "PID", "NAME", "STATE", "PRIORITY", "MEMORY");

    struct dirent *proc_entry;
    while ((proc_entry = readdir(proc_dir))) {
        // skip non-process directory entries
        if (proc_entry->d_type != DT_DIR) {
            continue;
        }

        // skip "." and ".." directory entries
        if (strcmp(proc_entry->d_name, ".") == 0 || strcmp(proc_entry->d_name, "..") == 0) {
            continue;
        }

        // get the process ID from the directory name
        int pid = get_pid_from_proc_dirname(proc_entry->d_name);

        // fill in the process_info struct for the process
        struct process_info p_info;
        fill_in_process_info(pid, &p_info);

        // print the process_info struct
        print_process_info(&p_info);
    }

    closedir(proc_dir);

    return 0;
}