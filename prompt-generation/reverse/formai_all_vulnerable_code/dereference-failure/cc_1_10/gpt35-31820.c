//FormAI DATASET v1.0 Category: System process viewer ; Style: multivariable
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PID_LEN 10
#define MAX_PROCESS_NAME_LEN 1024
#define MAX_CMDLINE_LEN 2048

// Struct to store process information
struct Process {
    char pid[MAX_PID_LEN];
    char name[MAX_PROCESS_NAME_LEN];
    char cmdline[MAX_CMDLINE_LEN];
};

// Function to check if a string is a number
int is_number(char *str) {
    int i;

    for (i = 0; str[i] != '\0'; ++i) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }

    return 1;
}

// Function to get the list of processes
void get_processes(struct Process *processes, int *num_processes) {
    DIR *dir;
    struct dirent *entry;
    char proc_path[MAX_PROCESS_NAME_LEN];

    *num_processes = 0;

    dir = opendir("/proc");

    if (dir == NULL) {
        perror("Error opening /proc directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir))) {
        if (is_number(entry->d_name)) {
            strcpy(proc_path, "/proc/");
            strcat(proc_path, entry->d_name);
            strcat(proc_path, "/cmdline");

            FILE *fp = fopen(proc_path, "r");

            if (fp == NULL) {
                continue;
            }

            fscanf(fp, "%[^\n]", processes[*num_processes].cmdline);
            fclose(fp);

            if (strlen(processes[*num_processes].cmdline) > 0) {
                strncpy(processes[*num_processes].pid, entry->d_name, MAX_PID_LEN);

                // Parse the process name from the command line
                char *token = strtok(processes[*num_processes].cmdline, "/");
                char *prev_token = token;

                while (token != NULL) {
                    prev_token = token;
                    token = strtok(NULL, "/");
                }

                strncpy(processes[*num_processes].name, prev_token, MAX_PROCESS_NAME_LEN);
                (*num_processes)++;
            }
        }
    }

    closedir(dir);
}

// Function to print the process information
void print_processes(struct Process *processes, int num_processes) {
    int i;

    printf("PID\tName\n");

    for (i = 0; i < num_processes; ++i) {
        printf("%s\t%s\n", processes[i].pid, processes[i].name);
    }
}

int main() {
    struct Process processes[1024];
    int num_processes;

    get_processes(processes, &num_processes);
    print_processes(processes, num_processes);

    return 0;
}