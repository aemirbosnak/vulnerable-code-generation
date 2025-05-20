//FormAI DATASET v1.0 Category: System process viewer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 1024

typedef struct process_info {
    char name[MAX_LENGTH];
    char status[MAX_LENGTH];
    int pid;
    int ppid;
} process_info;

// Returns a list of process_info structs
process_info* get_process_list(int* total_processes) {
    DIR* proc_dir = opendir("/proc");
    struct dirent* entry;
    process_info* process_list = malloc(sizeof(process_info) * 100);
    int process_count = 0;

    while ((entry = readdir(proc_dir)) != NULL) {
        char path[MAX_LENGTH];
        snprintf(path, MAX_LENGTH - 1, "/proc/%s", entry->d_name);

        if (!isdigit(entry->d_name[0])) {
            continue;
        }

        FILE* status_file = fopen(strcat(path, "/status"), "r");

        if (status_file == NULL) {
            continue;
        }

        char line[MAX_LENGTH];
        char* name = NULL;
        char* status = NULL;
        int pid = 0;
        int ppid = 0;

        while (fgets(line, MAX_LENGTH, status_file)) {
            char field[MAX_LENGTH];
            char* value = strchr(line, ':');

            if (value != NULL) {
                *value++ = '\0';
                sscanf(value, " %s", field);

                if (strcmp(line, "Name") == 0) {
                    name = malloc(strlen(field) + 1);
                    strncpy(name, field, strlen(field) + 1);
                } else if (strcmp(line, "State") == 0) {
                    status = malloc(strlen(field) + 1);
                    strncpy(status, field, strlen(field) + 1);
                } else if (strcmp(line, "Pid") == 0) {
                    pid = atoi(value);
                } else if (strcmp(line, "PPid") == 0) {
                    ppid = atoi(value);
                }
            }
        }

        fclose(status_file);

        if (name == NULL || status == NULL || pid == 0 || ppid == 0) {
            continue;
        }

        process_info process;
        strncpy(process.name, name, strlen(name) + 1);
        strncpy(process.status, status, strlen(status) + 1);
        process.pid = pid;
        process.ppid = ppid;

        process_list[process_count++] = process;

        free(name);
        name = NULL;
        free(status);
        status = NULL;
    }

    closedir(proc_dir);

    *total_processes = process_count;

    return process_list;
}

// Prints the process info to the console
void print_process_info(process_info process) {
    printf("%-25s%-10s%-10d%-10d\n", process.name, process.status, process.pid, process.ppid);
}

// Main function
int main() {
    int total_processes;
    process_info* process_list = get_process_list(&total_processes);

    printf("%-25s%-10s%-10s%-10s\n", "Name", "Status", "PID", "PPID");

    for (int i = 0; i < total_processes; i++) {
        print_process_info(process_list[i]);
    }

    free(process_list);

    return 0;
}